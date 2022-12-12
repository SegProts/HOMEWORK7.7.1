#pragma once
#include <iostream>
#include <exception>

class IntegerArray
{
private:
    int m_length; //длина контейнера
    int* m_data{}; //начало контейнера
public:

	class BadRange : public std::exception 	//Исключение выхода индекса за диапазон
	{
	public:
		virtual const char* what() const noexcept override
		{
			return "ERROR: Индекс вышел за диапазон значений";
		}
	};

	class BadLength : public std::exception //Исключение выхода длины контейнера за диапазон
	{
	public:
		virtual const char* what() const noexcept override
		{
			return "ERROR: Направильно указана длина контейнера";
		}
	};
    
    IntegerArray() = default;
    
	IntegerArray(int length) : m_length(length) //Конструктор(создание контейнера)
	{
		if (length <= 0)
		{
			throw BadLength();
		}
		else 
		{
			m_data = new int[length] {};
		}
	}	

	void printItems() //Распечатать содержимое контейнера
	{
		std::cout << std::endl << "Адрес контейнера(" << m_data << ")" << std::endl;
		for (int i = 0; i < this->m_length; i++)
		{
			std::cout << "m_data[" << i << "] = " << this->m_data[i] << std::endl;
		}
		std::cout << std::endl;
	}

	~IntegerArray() //Удаление контейнера
	{
		delete[] m_data;
	}

	int getLength() const; //Получить длину контейнера

	IntegerArray* copyContain();	//Скопировать контейнер

	int getItem(int index);	//Получить элемент контейнера по индексу

	void setItem(int index, int value);	//Изменить элемент контейнера по индексу

	void insertStartItem(int value); //Вставить новый элемент в конец контейнера

	void insertEndItem(int value); //Вставить новый элемент в конец контейнера

	void insertItem(int index, int value); //Вставляем новый элемент в определеное место

	int findItem(int itemValue); //Поиск индекса элелемента по его значению(возвращает первый попавшийся, если не находит, возвращает -1)

	void removeItem(int index); //Удаление элемента с контейнера

	void changeSize(int newLength); 

	void eraseCont();//Отчищаем контейнер

	int& operator[](int index) //Перегружаем оператор []
	{
		if (index >= 0 && index < m_length)
		{
			throw BadRange();
		}
		else
		{
			return m_data[index];
		}
	}
};

