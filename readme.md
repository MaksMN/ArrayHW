# Модуль 8.8. Домашнее задание

Контейнер данных.
Разработать шаблонный класс Array — динамический массив на базе класса ArrayInt, который был сделан в предыдущем модуле, но с использованием техники программирования на шаблонных классах и функциях.

**Функциональность контейнера:** 
* создать контейнер
```cpp
Array<T> array(length);
```
* скопировать контейнер;
```cpp
Array<T> array(length);
Array<T> array2();
array2 = array;
```
* получить доступ к любому элементу контейнера по индексу;
```cpp
int x = array[index];
```
* изменить размер контейнера;
```cpp
array.resize(newLength); // меняет размер без потери данных. Усечение при уменьшении размера.
array.reallocate(); // меняет размер с потерей всех данных
```
* вставить элемент в контейнер;
```cpp
array.insertBefore(value, index); // Вставляет новый элемент в указанный индекс без потери данных.
```
* удалить элемент из контейнера;
```cpp
array.remove(index); 
```
* вставка в начало и конец;
```cpp
array.insertAtBeginning(value);
array.insertAtEnd(value);
```
* поиск в контейнере элемента по значению;
```cpp
int index = array.search(value); // Возвращает первый найденный индекс или исключение ArrayNotFound
```
* поиск в контейнере всех элементов по значению.
```cpp
Array<T> search;
search = array.searchAll(value); 
// Возвращает объект Array со всеми найденными индексами или исключение ArrayNotFound
```
* При поиске произвольных типов, в них должен быть переопределен оператор ==
* исключения: 
  - ArrayBadRange
  - ArrayBadLength
  - ArrayNotFound