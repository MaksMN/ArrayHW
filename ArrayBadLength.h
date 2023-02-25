#pragma once
#include <exception>

class ArrayBadLength : public std::exception
{
public:
    virtual const char *what() const noexcept override
    {
        return "ERROR: Bad length!";
    }
};