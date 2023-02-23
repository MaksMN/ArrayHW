#include "Array.h"
#include <climits>

template <typename T>Array<T>::Array(int length) : m_length{length}
{
    if (length < 0)
    {
        throw ArrayBadLength();
    }
    if (length > 0)
    {
        m_data = new T[length]{};
    }
}

template <typename T>Array<T>::Array(const Array &a)
{
    reallocate(a.getLength());
    for (int index{0}; index < m_length; ++index)
    {
        m_data[index] = a.m_data[index];
    }
}

template <typename T>Array<T>::~Array()
{
    delete[] m_data;
}

template <typename T> void Array<T>::Array::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

template <typename T> int &Array<T>::operator[](int index)
{
    if (index < 0 || index > m_length || m_length == 0)
    {
        throw ArrayBadRange();
    }
    return m_data[index];
}

template <typename T> void Array<T>::reallocate(int newLength)
{
    if (newLength <= 0 || newLength == m_length)
    {
        throw ArrayBadLength();
    }
    erase();
    if (newLength <= 0)
        return;
    m_data = new int[newLength];
    m_length = newLength;
}

template <typename T> void Array<T>::resize(int newLength)
{
    if (newLength <= 0 || newLength == m_length)
    {
        throw ArrayBadLength();
    }
    int *data{new int[newLength]};
    if (m_length > 0)
    {
        int elementsToCopy{(newLength > m_length) ? m_length : newLength};

        for (int index{0}; index < elementsToCopy; ++index)
        {
            data[index] = m_data[index];
        }
    }
    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

template <typename T> Array<T>& Array<T>::operator=(const Array &a)
{
    if (&a == this)
    {
        return *this;
    }
    reallocate(a.getLength());
    for (int index{0}; index < m_length; ++index)
    {
        m_data[index] = a.m_data[index];
    }
    return *this;
}

template <typename T> void Array<T>::insertBefore(int value, int index)
{
    if (index < 0 || index > m_length)
    {
        throw ArrayBadRange();
    }
    int *data{new int[m_length + 1]};
    for (int before{0}; before < index; ++before)
    {
        data[before] = m_data[before];
    }
    data[index] = value;
    for (int after{index}; after < m_length; ++after)
    {
        data[after + 1] = m_data[after];
    }
    delete[] m_data;
    m_data = data;
    ++m_length;
}

template <typename T> void Array<T>::remove(int index)
{
    if (index < 0 || index > m_length)
    {
        throw ArrayBadRange();
    }
    if (m_length == 1)
    {
        erase();
        return;
    }
    int *data{new int[m_length - 1]};
    for (int before{0}; before < index; ++before)
    {
        data[before] = m_data[before];
    }
    for (int after{index + 1}; after < m_length; ++after)
    {
        data[after - 1] = m_data[after];
    }
    delete[] m_data;
    m_data = data;
    --m_length;
}

template <typename T> int Array<T>::search(int value)
{
    for (int i = 0; i < getLength(); i++)
    {
        if (m_data[i] == value)
        {
            return i;
        }
    }
    throw ArrayNotFound();
}

template <typename T> Array<T> Array<T>::searchAll(int value)
{
    Array results;
    for (int i = 0; i < getLength(); i++)
    {
        if (m_data[i] == value)
        {
            results.insertAtEnd(i);
        }
    }
    if (results.getLength() > 0)
    {
        return results;
    }
    else
    {
        throw ArrayNotFound();
    }
}

template <typename T> void Array<T>::listValues(std::string message, bool showIndexes)
{
    std::cout << message;
    for (int i = 0; i < getLength(); i++)
    {
        if (showIndexes)
        {
            std::cout << "[" << i << "]=>";
        }
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}