#pragma once
#include <iostream>
#include <cassert>
#include <exception>
#include "ArrayBadRange.h"
#include "ArrayBadLength.h"
#include "ArrayNotFound.h"

/// @brief Создает массив
template <typename T> class Array
{
private:
    int m_length{};
    T* m_data{};
    int null_ptr = 0;

public:
    Array() = default;

    /// @brief Создает массив указанной длинны
    /// @param <int>length Длина массива
    Array(int length);

    /// @brief Конструктор копирования
    /// @param <Array>a
    Array(const Array &a);

    ~Array();

    /// @brief Удаляет все элементы массива
    void erase();

    int &operator[](int index);

    /// @brief Меняет размер массива с удалением существующих элементов.
    /// @exception ArrayBadLength
    /// @param <int>newLength Новая длинна массива.
    void reallocate(int newLength);

    /// @brief Меняет размер массива. Существующие элементы сохранены.
    /// @exception ArrayBadLength
    /// @param <int>newLength Новая длинна массива.
    void resize(int newLength);

    Array& operator=(const Array &a);

    /// @brief Добавляет в массив элемент перед указанным индексом
    /// @exception ArrayBadRange
    /// @param value Значение нового элемента
    /// @param index Индекс перед которым будет создан новый элемент
    void insertBefore(int value, int index);

    /// @brief Удаляет из массива элемент с указанным индексом
    /// @exception ArrayBadRange
    /// @param index Индекс перед которым будет создан новый элемент
    void remove(int index);

    /// @brief Добавляет элемент в начало массива
    /// @param value Значение нового элемента
    void insertAtBeginning(int value) { insertBefore(value, 0); }

    /// @brief Добавляет элемент в конец массива
    /// @param value Значение нового элемента
    void insertAtEnd(int value) { insertBefore(value, m_length); }

    /// @brief Возвращает длину массива
    /// @return int
    int getLength() const { return m_length; }

    /// @brief Поиск элемента по значению
    /// @exception ArrayNoFoundException
    /// @param value
    /// @return Индекс первого найденного элемента в массиве
    int search(int value);

    /// @brief Поиск всех элементов по значению
    /// @exception ArrayNoFoundException
    /// @param value
    /// @return Массив Array с найденными элементами.
    Array searchAll(int value);

    /// @brief Выводит на экран список всех элементов массива
    /// @param message Сообщение перед выводом списка
    void listValues(std::string message, bool showIndexes = true);
};