#pragma once
#include <exception>

class ArrayNotFound : public std::exception
{
public:
    virtual const char *what() const noexcept override
    {
        return "ERROR: Search result not found!";
    }
};