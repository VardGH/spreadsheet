#include "stringcell.hpp"

int StringCell::toInt() const
{
    return std::stoi(m_value);
}

double StringCell::toDouble() const
{
    return std::stod(m_value);
}

std::string StringCell::toString() const
{
    return m_value;
}

void StringCell::setValue(const std::string& value)
{
    m_value = value;
}
