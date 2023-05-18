#include "doublecell.hpp"

int DoubleCell::toInt() const
{
    return static_cast<int>(m_value);
}

double DoubleCell::toDouble() const
{
    return m_value;
}

std::string DoubleCell::toString() const
{
    return std::to_string(m_value);
}

void DoubleCell::setValue(const std::string& value)
{
    m_value = std::stod(value);
}

void DoubleCell::setValue(const double value)
{
    m_value = value;
}
