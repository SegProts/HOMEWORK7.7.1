#pragma once
class IntegerArray
{
private:
    int m_length{}; //длина контейнера
    int* m_data{}; //начало контейнера

public:
    
    IntegerArray() = default;

    //Конструктор(создание контейнера)
    IntegerArray(int length) : m_length{ length } {}

    //Удаление контейнера
    ~IntegerArray() {}

    //Удаление элемента с контейнера
    void deleteItem(int index) {}

    //Получить элемент кеонтейнера по индексу
    int getItem(int index) {}

};

