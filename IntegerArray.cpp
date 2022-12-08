#include "IntegerArray.h"

//Удаление контейнера
IntegerArray::~IntegerArray()
{
    delete[] m_data;
}

//Удаление элемента с контейнера
void IntegerArray::deleteItem(int index)
{
}

//Получить элемент кеонтейнера по индексу
int IntegerArray::getItem(int index)
{
    return 0;
}
