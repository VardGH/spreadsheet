#ifndef SPREADSHEET_HPP
#define SPREADSHEET_HPP

#include "cell.hpp"

#include <string>
#include <vector>

class SpreadSheet
{
public:
    SpreadSheet(const int row = 2, const int col = 2)
        : m_cells(row, std::vector<Cell*>(col, nullptr))
    {
    }
    
    ~SpreadSheet() = default;

public:
    void setCellAt(const int row, const int col, const std::string& val);
    void setCellAt(const int row, const int col, Cell* cell);

    const Cell* getCellAt(const int row, const int col) const;

    int getRow() const;
    int getCol() const;

    void addRow(const int count = 1);
    void addCol(const int count = 1);

    void removeRow(const int row);
    void removeCol(const int col);

    void print() const;

private:
    bool isValidCell(const int row, const int col) const;
private:
    std::vector<std::vector<Cell*>> m_cells;
};

#endif // SPREADSHEET_HPP