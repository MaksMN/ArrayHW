
#include "Array.h"

// класс для тестов
class Test
{
private:
    int var;

public:
    Test() = default;
    Test(int v)
    {
        var = v;
    }
    ~Test() = default;
    int getVar()
    {
        return var;
    }
    void setVar(int v)
    {
        var = v;
    }

    bool operator==(Test x)
    {
        return (this->getVar() == x.getVar());
    }
};

// Выводит список методов getVar() во всех элементах Array<Test>
void ListTest(Array<Test> test, std::string msg = "Массив _Test[i].getVar(); ")
{
    std::cout << msg;
    for (int i{0}; i < test.getLength(); i++)
    {
        std::cout << test[i].getVar() << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arrayCount{10};

    // Создание контейнеров
    Array<int> _int(arrayCount);
    Array<double> _double(arrayCount);
    Array<std::string> _string(arrayCount);
    Array<Test> _Test(arrayCount);

    // Заполнение контейнеров рандомными данными
    for (int i{0}; i < arrayCount; i++)
    {
        _int[i] = std::rand() % 50;
        _double[i] = (double)(std::rand() % 50 / 3.3 + 0.3);
        _string[i] = {(char)(65 + std::rand() % 26), (char)(97 + std::rand() % 26), (char)(97 + std::rand() % 26), '\0'};
        Test t(std::rand() % 100);
        _Test[i] = t;
    }

    // Вывести списки значений
    _string.listValues("Массив строк: ");
    _double.listValues("Массив double: ");
    _int.listValues("Массив int: ");
    ListTest(_Test);

    // Скопировать контейнеры
    Array<int> _int2 = _int;
    _int2.listValues("Копия массива int: ");
    Array<double> _double2 = _double;
    _double2.listValues("Копия массива double: ");
    Array<std::string> _string2 = _string;
    _string2.listValues("Копия массива string: ");
    Array<Test> _Test2 = _Test;
    ListTest(_Test2, "Копия массива _Test[i].getVar(); ");

    // получить доступ к любому элементу контейнера по индексу
    std::cout << "Доступ по индексу: "
              << "_int[4] = " << _int[4] << " | _string[3] = " << _string[3] << " | _Test[5].getVar() = " << _Test[5].getVar() << std::endl;

    // изменить размер контейнера;
    _int.resize(15);
    _double.resize(5);
    _string.resize(12);
    _Test.resize(5);

    std::cout << "Массивы после изменения размера: " << std::endl;
    _string.listValues("Массив строк: ");
    _double.listValues("Массив double: ");
    _int.listValues("Массив int: ");
    ListTest(_Test);

    // вставить элемент в контейнер;

    _int.insertBefore(111111, 1);
    _double.insertBefore(888.888, 2);
    _string.insertBefore("AAA", 3);

    std::cout << "Массивы после вставки элемента: " << std::endl;
    _string.listValues("Массив строк: ");
    _double.listValues("Массив double: ");
    _int.listValues("Массив int: ");

    // удалить элемент из контейнера.
    _int.remove(5);
    _double.remove(5);
    _string.remove(5);

    std::cout << "Массивы после удаления элемента: " << std::endl;
    _string.listValues("Массив строк: ");
    _double.listValues("Массив double: ");
    _int.listValues("Массив int: ");

    // поиск
    int index;
    Test _test(555);
    _Test.insertBefore(_test, 3);
    index = _Test.search(_test); // у произвольных типов должен быть переопределен оператор ==
    std::cout << "В массиве _Test найден класс (Test _test(555);) под индексом: " << index << std::endl;

    _Test.insertBefore(_test, 3);
    _Test.insertBefore(_test, 3);
    _Test.insertBefore(_test, 3);

    Array<int> searchAll;
    searchAll = _Test.searchAll(_test);
    std::cout << "В массиве _Test найдены классы (Test _test(555);) под индексами: ";
    searchAll.listValues("", false);

    _string.insertBefore("BBB", 3);
    _string.insertBefore("BBB", 3);
    _string.insertBefore("BBB", 3);

    searchAll.erase();
    searchAll = _string.searchAll("BBB");
    searchAll.listValues("В массиве _string найдены строки BBB под индексами: ", false);

    return 0;
}