#ifndef STRINGCELL_HPP
#define STRINGCELL_HPP

#include "cell.hpp"
#include <string>

class StringCell : public Cell
{
public:
    StringCell() 
        : m_value("") 
    {
    }

    ~StringCell() = default;

public:
    int toInt() const override;
    double toDouble() const override;
    std::string toString() const override;

    void setValue(const std::string& value) override;

private:
    std::string m_value;
};

#endif  // STRINGCELL_HPP
