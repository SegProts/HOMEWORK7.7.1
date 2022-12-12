#pragma once
#include <iostream>

class IntegerArray
{
private:
    int m_length; //����� ����������
    int* m_data{}; //������ ����������
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

    //�����������(�������� ����������)
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

    //�������� ����������
	~IntegerArray()
	{
		delete[] m_data;
	}

	//�������� ����� ����������
	int getLength() const;

	//����������� ���������
	IntegerArray* copyContain();

	//�������� ������� ���������� �� �������
	int getItem(int index);

	//�������� ����� ������� � ����� ����������
	void addItem(int value);

	//��������� ����� ������� � ����������� �����
	void insertItem(int value, int index);

	//����� ������� ���������� �� ��� ��������(���������� ������ ����������, ���� �� �������, ���������� -1)
	int findItem(int itemValue);

    //�������� �������� � ����������
	void deleteItem(int index);

	//�������� ������ ����������
	void changeSize(int newLength);

	//�������� ���������
	void eraseCont();
	
	//����������� �������� []
	int& operator[](int index)
	{
		return m_data[index];
	}
};

