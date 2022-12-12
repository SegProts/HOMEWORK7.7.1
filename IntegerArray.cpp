#include "IntegerArray.h"

//�������� ����� ����������
int IntegerArray::getLength() const 
{ 
	return m_length; 
}

//����������� ���������
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

//��������� ����� ������� � ����������� �����
int IntegerArray::getItem(int index)
{
	return m_data[index];
}

//�������� ����� ������� � ����� ����������
void IntegerArray::addItem(int value)
{
	//������� �������� ���������
	int* data = new int[m_length + 1];

	//�������� � �������� ��������� ��� �������� ����������
	for (int index = 0; index < m_length; ++index)
	{
		data[index] = m_data[index];
	}

	data[m_length] = value; //��������� � �������� ��������� ����� ��������

	//�������� ���������
	delete[] m_data;

	m_data = data; //����������� ���������� ����� ������ � ��������� ���������
	++m_length; //������������� ����� ����� ����������
}

//��������� ����� ������� � ����������� �����
void IntegerArray::insertItem(int value, int index)
{
	//������� �������� ���������
	int* data = new int[m_length + 1];

	//�������� � �������� ��������� ��� ��� �� ����������� �������
	for (int before = 0; before < index; ++before)
	{
		data[before] = m_data[before];
	}

	data[index] = value; //��������� � �������� ��������� ����� ��������

	//�������� � �������� ��������� ��� ��� �� ����� �������
	for (int after = index; after < m_length; ++after)
	{
		data[after + 1] = m_data[after];
	}

	//�������� ���������
	delete[] m_data;

	m_data = data; //����������� ���������� ����� ������ � ��������� ���������
	++m_length; //������������� ����� ����� ����������
}

//����� ������� ���������� �� ��� ��������(���������� ������ ����������, ���� �� �������, ���������� -1)
int IntegerArray::findItem(int itemValue)
{
	for (int i = 0; i < m_length; i++)
	{
		if (m_data[i] == itemValue) { return i; };
	}
	return -1;
}

//�������� �������� � ����������
void IntegerArray::deleteItem(int indexDelItem)
{
	//���� ������ ������������� ��� ������� �� ������� ����������
	if ((indexDelItem < 0) || (indexDelItem >= m_length))
	{
		std::cout << "�������: " << indexDelItem << " �� ����������� � ����������" << std::endl;
	}
	else
	{
		//������� �������� ���������
		int* data{ new int[m_length - 1] };

		int odds = 0; //����������� ��� �������� ��������, ������� ��������� �������
		for (int index = 0; index < m_length - 1; ++index)
		{
			if (index == indexDelItem)
			{
				odds++;
			}
			data[index] = m_data[index + odds];
		}

		//�������� ���������
		delete[] m_data;

		m_data = data; //����������� ���������� ����� ������ � ��������� ���������
		m_length--; //��������� ����� ����������
		std::cout << "deleteItem" << std::endl;
		printInfo(m_length);
	}
}

//�������� ���������
void IntegerArray::eraseCont() 
{
	delete[] m_data;

	m_data = nullptr;
	m_length = 0;
}

void IntegerArray::changeSize(int newLength)
{
	//���� ������ ��� ����� ������ �����, �� ���������
	if (newLength == m_length)
	{
		return;
	}

	//���� �� �������� ������ ������� �������, ������ �������� ���
	if (newLength <= 0)
	{
		IntegerArray::eraseCont();
		return;
	}

	//������� �������� ���������
	int* data{ new int[newLength] };

	if (m_length > 0)
	{
		int elementsToCopy;

		//�������� ������� ��������� � ������ ��������� ���������� ��������� � �����
		if (newLength > m_length) { elementsToCopy = m_length;	}
		else { elementsToCopy = newLength; }

		//��������� �������� �� ������� � ��������� � ��������
		for (int index = 0; index < elementsToCopy; ++index)
		{
			data[index] = m_data[index];
		}
	}

	//�������� ���������
	delete[] m_data;

	m_data = data;	//����������� ���������� ����� ������ � ��������� ���������
	m_length = newLength; //������������� ����� ����� ����������

	std::cout << "changeSize" << std::endl;
	printInfo(newLength);
}

