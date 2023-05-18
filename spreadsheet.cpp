#include "spreadsheet.hpp"
#include <iostream>
#include "stringcell.hpp"

bool SpreadSheet::isValidCell(const int row, const int col) const
{
    return row >= 0 && row < m_cells.size() && col >= 0 && col < m_cells[0].size();
}

void SpreadSheet::setCellAt(const int row, const int col, const std::string& val)
{
    if (isValidCell(row, col)) {
        if (m_cells[row][col] != nullptr) {
            m_cells[row][col]->setValue(val);
        } else {
            m_cells[row][col] = new StringCell();
            m_cells[row][col]->setValue(val);
        }
    } else {
        throw std::out_of_range("Row or column index out of range.");
    }
}

void SpreadSheet::setCellAt(const int row, const int col, Cell* cell)
{
    if (isValidCell(row, col)) {
        delete m_cells[row][col];
        m_cells[row][col] = cell;
    } else {
        throw std::out_of_range("Row or column index out of range.");
    }
}

const Cell* SpreadSheet::getCellAt(const int row, const int col) const
{
    if (isValidCell(row, col)) {
        return m_cells[row][col];
    } else {
        throw std::out_of_range("Invalid cell coordinates.");
    }
}

int SpreadSheet::getRow() const
{
    return m_cells.size();
}

int SpreadSheet::getCol() const
{
    if (m_cells.empty()) {
        return 0;
    }
    return m_cells[0].size();
}

void SpreadSheet::addRow(const int row)
{
    if(row < 0) {
        throw std::out_of_range("Row index is negative");
    }

    int col = getCol();
    m_cells.resize(m_cells.size() + row, std::vector<Cell*>(col, nullptr));
}

void SpreadSheet::addCol(const int col)
{
    if(col < 0) {
        throw std::out_of_range("Column index is negative");
    }

    for (auto& row : m_cells) {
        row.resize(row.size() + col, nullptr);
    }
}

void SpreadSheet::removeRow(const int row)
{
    if (row >= 0 && row < m_cells.size())
    {
        for (auto& cell : m_cells[row]) {
            delete cell;
        }
        m_cells.erase(m_cells.begin() + row);
    } else {
        throw std::out_of_range("Row index out of range");
    }
}

void SpreadSheet::removeCol(const int col)
{
    if (col >= 0 && !m_cells.empty() && col < m_cells[0].size()) {
        for (auto& row : m_cells) {
            delete row[col];
            row.erase(row.begin() + col);
        }
    } else {
        throw std::out_of_range("Col index out of range");
    }
}

void SpreadSheet::print() const
{
    for (const auto& row : m_cells) {
        for (const auto& cell : row) {
            if (cell != nullptr) {
                std::cout << cell->toString() << "\t";
            } else {
                std::cout << "null\t";
            }
        }
        std::cout << std::endl;
    }
}
