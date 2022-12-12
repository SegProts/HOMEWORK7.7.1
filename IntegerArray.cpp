#include "IntegerArray.h"

//Получить длину контейнера
int IntegerArray::getLength() const 
{ 
	return m_length; 
}

//Скопировать контейнер
IntegerArray* IntegerArray::copyContain()
{
	std::cout << "copyContain" << std::endl;
	IntegerArray copyArray(m_length);
	for (int i = 0; i < m_length; i++)
	{
		copyArray[i] = 1;
		std::cout << copyArray[i] << std::endl;
	}

	return &copyArray;
}

//Вставляем новый элемент в определеное место
int IntegerArray::getItem(int index)
{
	return m_data[index];
}

//Вставить новый элемент в конец контейнера
void IntegerArray::addItem(int value)
{
	//Создаем буферное хранилище
	int* data = new int[m_length + 1];

	//Копируем в буферное хранилище все значения контейнера
	for (int index = 0; index < m_length; ++index)
	{
		data[index] = m_data[index];
	}

	data[m_length] = value; //Вставляем в буферное хранилище новое значение

	//Отчищяем хранилище
	delete[] m_data;

	m_data = data; //Присваиваем контейнеру новый массив с удаленным элементом
	++m_length; //Устанавливаем новую длину контейнера
}

//Вставляем новый элемент в определеное место
void IntegerArray::insertItem(int value, int index)
{
	//Создаем буферное хранилище
	int* data = new int[m_length + 1];

	//Копируем в буферное хранилище все что до полученного индекса
	for (int before = 0; before < index; ++before)
	{
		data[before] = m_data[before];
	}

	data[index] = value; //Вставляем в буферное хранилище новое значение

	//Копируем в буферное хранилище все что до после индекса
	for (int after = index; after < m_length; ++after)
	{
		data[after + 1] = m_data[after];
	}

	//Отчищяем хранилище
	delete[] m_data;

	m_data = data; //Присваиваем контейнеру новый массив с удаленным элементом
	++m_length; //Устанавливаем новую длину контейнера
}

//Поиск индекса элелемента по его значению(возвращает первый попавшийся, если не находит, возвращает -1)
int IntegerArray::findItem(int itemValue)
{
	for (int i = 0; i < m_length; i++)
	{
		if (m_data[i] == itemValue) { return i; };
	}
	return -1;
}

//Удаление элемента с контейнера
void IntegerArray::deleteItem(int indexDelItem)
{
	//Если индекс отрицательный или выходит за размеры контейнера
	if ((indexDelItem < 0) || (indexDelItem >= m_length))
	{
		std::cout << "Индекса: " << indexDelItem << " не сущевствует в контейнере" << std::endl;
	}
	else
	{
		//Создаем буферное хранилище
		int* data{ new int[m_length - 1] };

		int odds = 0; //коэффициент для пропуска значения, которое собираемя удалить
		for (int index = 0; index < m_length - 1; ++index)
		{
			if (index == indexDelItem)
			{
				odds++;
			}
			data[index] = m_data[index + odds];
		}

		//Отчищаем хранилище
		delete[] m_data;

		m_data = data; //Присваиваем контейнеру новый массив с удаленным элементом
		m_length--; //Уменьшаем длину контейнера
		std::cout << "deleteItem" << std::endl;
		printInfo(m_length);
	}
}

//Отчищаем контейнер
void IntegerArray::eraseCont() 
{
	delete[] m_data;

	m_data = nullptr;
	m_length = 0;
}

void IntegerArray::changeSize(int newLength)
{
	//Если массив уже имеет нужную длину, мы закончили
	if (newLength == m_length)
	{
		return;
	}

	//Если мы изменяем размер пустого массива, просто отчищяем его
	if (newLength <= 0)
	{
		IntegerArray::eraseCont();
		return;
	}

	//Создаем буферное хранилище
	int* data{ new int[newLength] };

	if (m_length > 0)
	{
		int elementsToCopy;

		//Выясняем сколько элементов в старом хранилище необходимо перенести в новое
		if (newLength > m_length) { elementsToCopy = m_length;	}
		else { elementsToCopy = newLength; }

		//Переносим значения из старого в хранилища в буферное
		for (int index = 0; index < elementsToCopy; ++index)
		{
			data[index] = m_data[index];
		}
	}

	//Отчищяем хранилище
	delete[] m_data;

	m_data = data;	//Присваиваем контейнеру новый массив с удаленным элементом
	m_length = newLength; //Устанавливаем новую длину контейнера

	std::cout << "changeSize" << std::endl;
	printInfo(newLength);
}

