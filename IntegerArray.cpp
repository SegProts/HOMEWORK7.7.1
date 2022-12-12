#include "IntegerArray.h"

int IntegerArray::getLength() const //Получить длину контейнера
{ 
	return m_length; 
}

IntegerArray* IntegerArray::copyContain() //Скопировать контейнер
{
	IntegerArray *copyArray = new IntegerArray(m_length);
	for (int i = 0; i < copyArray->m_length; i++)
	{
		copyArray->m_data[i] = m_data[i];
	}
	return copyArray;
}

int IntegerArray::getItem(int index) //Получаем значение элемента по индексу
{
	if (index < 0 || index > m_length)
	{
		throw BadRange();
	}
	else
	{
		return m_data[index];
	}
}

void IntegerArray::setItem(int index, int value) //Изменить элемент контейнера по индексу
{
	if (index < 0 || index > m_length)
	{
		throw BadRange();
	}
	else
	{
		m_data[index] = value;
	}
}

void IntegerArray::insertStartItem(int value) //Вставить новый элемент в начало контейнера
{
	//Создаем буферное хранилище
	int* data = new int[m_length + 1];

	//Копируем в буферное хранилище все значения контейнера
	for (int index = 1; index < m_length; ++index)
	{
		data[index] = m_data[index];
	}

	data[0] = value; //Вставляем в  начало буферного хранилища новое значение

	//Отчищяем хранилище
	delete[] m_data;

	m_data = data; //Присваиваем контейнеру новый массив с удаленным элементом
	++m_length; //Устанавливаем новую длину контейнера
}

void IntegerArray::insertEndItem(int value) //Вставить новый элемент в конец контейнера
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

void IntegerArray::insertItem(int index, int value) //Вставляем новый элемент в определеное место
{
	if (index < 0 || index > m_length)
	{
		throw BadRange();
	}

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

void IntegerArray::removeItem(int indexDelItem) //Удаление элемента с контейнера
{
	if (indexDelItem < 0 || indexDelItem > m_length)
	{
		throw BadRange();
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
	}
}

void IntegerArray::eraseCont() //Отчищаем контейнер
{
	delete[] m_data;

	m_data = nullptr;
	m_length = 0;
}

void IntegerArray::changeSize(int newLength) //Изменить размер контейнера
{
	if (newLength <= 0)
	{
		throw BadLength();
	}
	else
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
			if (newLength > m_length) { elementsToCopy = m_length; }
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
	}
}

