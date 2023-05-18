#include "intcell.hpp"

int IntCell::toInt() const
{
    return m_value;
}

double IntCell::toDouble() const
{
    return static_cast<double>(m_value);
}

std::string IntCell::toString() const
{
    return std::to_string(m_value);
}

void IntCell::setValue(const std::string& value)
{
    m_value = std::stoi(value);
}

void IntCell::setValue(const int value)
{
    m_value = value;
}