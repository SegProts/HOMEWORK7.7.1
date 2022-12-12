#pragma once
#include <iostream>

class IntegerArray
{
private:
    int m_length; //длина контейнера
    int* m_data{}; //начало контейнера
public:
    
    IntegerArray() = default;

	void printInfo(int length)
	{
		std::cout << "m_data(" << m_data << ")" << std::endl;
		for (int i = 0; i < length; i++)
		{
			std::cout << "m_data[" << i << "] = " << m_data[i] << std::endl;
		}
		std::cout << std::endl;
	}

    //Конструктор(создание контейнера)
	IntegerArray(int length) : m_length(length)
	{
		if (length > 0)
		{
			m_data = new int[length] {};
			for (int i = 0; i < length; i++)
			{
				m_data[i] = rand();
			}
			std::cout << "Constructor" << std::endl;
			printInfo(length);
		}
	}	

    //Удаление контейнера
	~IntegerArray()
	{
		delete[] m_data;
	}

	//Получить длину контейнера
	int getLength() const;

	//Скопировать контейнер
	IntegerArray* copyContain();

	//Получить элемент контейнера по индексу
	int getItem(int index);

	//Вставить новый элемент в конец контейнера
	void addItem(int value);

	//Вставляем новый элемент в определеное место
	void insertItem(int value, int index);

	//Поиск индекса элелемента по его значению(возвращает первый попавшийся, если не находит, возвращает -1)
	int findItem(int itemValue);

    //Удаление элемента с контейнера
	void deleteItem(int index);

	//Изменить размер контейнера
	void changeSize(int newLength);

	//Отчищаем контейнер
	void eraseCont();
	
	//Перегружаем оператор []
	int& operator[](int index)
	{
		return m_data[index];
	}
};

