#ifndef INTCELL_HPP
#define INTCELL_HPP

#include "cell.hpp"

class IntCell : public Cell
{
public:

    IntCell() 
        : m_value(0) 
    {
    }

    ~IntCell() = default;

public:
    int toInt() const override;
    double toDouble() const override;
    std::string toString() const override;

    void setValue(const std::string& value) override;
    void setValue(const int value);

private:
    int m_value;
};

#endif  // INTCELL_HPP