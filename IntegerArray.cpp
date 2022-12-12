#include "IntegerArray.h"

int IntegerArray::getLength() const //�������� ����� ����������
{ 
	return m_length; 
}

IntegerArray* IntegerArray::copyContain() //����������� ���������
{
	IntegerArray *copyArray = new IntegerArray(m_length);
	for (int i = 0; i < copyArray->m_length; i++)
	{
		copyArray->m_data[i] = m_data[i];
	}
	return copyArray;
}

int IntegerArray::getItem(int index) //�������� �������� �������� �� �������
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

void IntegerArray::setItem(int index, int value) //�������� ������� ���������� �� �������
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

void IntegerArray::insertStartItem(int value) //�������� ����� ������� � ������ ����������
{
	//������� �������� ���������
	int* data = new int[m_length + 1];

	//�������� � �������� ��������� ��� �������� ����������
	for (int index = 1; index < m_length; ++index)
	{
		data[index] = m_data[index];
	}

	data[0] = value; //��������� �  ������ ��������� ��������� ����� ��������

	//�������� ���������
	delete[] m_data;

	m_data = data; //����������� ���������� ����� ������ � ��������� ���������
	++m_length; //������������� ����� ����� ����������
}

void IntegerArray::insertEndItem(int value) //�������� ����� ������� � ����� ����������
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

void IntegerArray::insertItem(int index, int value) //��������� ����� ������� � ����������� �����
{
	if (index < 0 || index > m_length)
	{
		throw BadRange();
	}

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

void IntegerArray::removeItem(int indexDelItem) //�������� �������� � ����������
{
	if (indexDelItem < 0 || indexDelItem > m_length)
	{
		throw BadRange();
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
	}
}

void IntegerArray::eraseCont() //�������� ���������
{
	delete[] m_data;

	m_data = nullptr;
	m_length = 0;
}

void IntegerArray::changeSize(int newLength) //�������� ������ ����������
{
	if (newLength <= 0)
	{
		throw BadLength();
	}
	else
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
			if (newLength > m_length) { elementsToCopy = m_length; }
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
	}
}

