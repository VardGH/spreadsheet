#ifndef CELL_HPP
#define CELL_HPP

#include <string>

class Cell
{
public:

    Cell() 
        : m_value("") 
    {
    }

    virtual ~Cell() = default;

public:
    // getters
    virtual int toInt() const = 0;
    virtual double toDouble() const = 0;
    virtual std::string toString() const = 0;
    //setters
    virtual void setValue(const std::string& value) = 0;

protected:
    std::string m_value;
};

#endif  //CELL_HPP