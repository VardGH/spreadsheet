#ifndef DOUBLECELL_HPP
#define DOUBLECELL_HPP

#include "cell.hpp"

class DoubleCell : public Cell
{
public:
    DoubleCell() 
        : m_value(0.0) 
    {
    }

    ~DoubleCell() = default;

public:
    int toInt() const override;
    double toDouble() const override;
    std::string toString() const override;

    void setValue(const std::string& value) override;
    void setValue(const double value);

private:
    double m_value;
};

#endif  // DOUBLECELL_HPP
