#include "test.hpp"
#include "spreadsheet.hpp"
#include "doublecell.hpp"
#include "stringcell.hpp"
#include "intcell.hpp"

#include <iostream>

namespace test
{

void test_spreadsheet()
{
    try
    {
        // sheet(3,3)
        SpreadSheet sheet(3, 3);

        // IntCell
        sheet.setCellAt(0, 0, new IntCell());
        sheet.setCellAt(0, 0, "13");
        
        // StringCell
        sheet.setCellAt(1, 0, new StringCell());
        sheet.setCellAt(1, 0, "I'll");

        // StringCell
        sheet.setCellAt(1, 1, new StringCell());
        sheet.setCellAt(1, 1, "be");

        sheet.setCellAt(1, 2, new StringCell());
        sheet.setCellAt(1, 2, "back");


        // DoubleCell
        sheet.setCellAt(2, 2, new DoubleCell());
        sheet.setCellAt(2, 2, "3.14");

        // print
        sheet.print();

        // addRow()
        sheet.addRow(2);

        // IntCell
        sheet.setCellAt(3, 1, new IntCell());
        sheet.setCellAt(3, 1, "10");

        // DoubleCell
        sheet.setCellAt(4, 2, new DoubleCell());
        sheet.setCellAt(4, 2, "3.15");

        // print
        std::cout << "After addRow" << std::endl;
        sheet.print();

        // clean up memory
        for (int i = 0; i < sheet.getRow(); ++i) {
            for (int j = 0; j < sheet.getCol(); ++j) {
                delete sheet.getCellAt(i, j);
            }
        }

    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
}

} // namespace test