#pragma once
#include <iostream>
#include <exception>

class IntegerArray
{
private:
    int m_length; //����� ����������
    int* m_data{}; //������ ����������
public:

	class BadRange : public std::exception 	//���������� ������ ������� �� ��������
	{
	public:
		virtual const char* what() const noexcept override
		{
			return "ERROR: ������ ����� �� �������� ��������";
		}
	};

	class BadLength : public std::exception //���������� ������ ����� ���������� �� ��������
	{
	public:
		virtual const char* what() const noexcept override
		{
			return "ERROR: ����������� ������� ����� ����������";
		}
	};
    
    IntegerArray() = default;
    
	IntegerArray(int length) : m_length(length) //�����������(�������� ����������)
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

	void printItems() //����������� ���������� ����������
	{
		std::cout << std::endl << "����� ����������(" << m_data << ")" << std::endl;
		for (int i = 0; i < this->m_length; i++)
		{
			std::cout << "m_data[" << i << "] = " << this->m_data[i] << std::endl;
		}
		std::cout << std::endl;
	}

	~IntegerArray() //�������� ����������
	{
		delete[] m_data;
	}

	int getLength() const; //�������� ����� ����������

	IntegerArray* copyContain();	//����������� ���������

	int getItem(int index);	//�������� ������� ���������� �� �������

	void setItem(int index, int value);	//�������� ������� ���������� �� �������

	void insertStartItem(int value); //�������� ����� ������� � ����� ����������

	void insertEndItem(int value); //�������� ����� ������� � ����� ����������

	void insertItem(int index, int value); //��������� ����� ������� � ����������� �����

	int findItem(int itemValue); //����� ������� ���������� �� ��� ��������(���������� ������ ����������, ���� �� �������, ���������� -1)

	void removeItem(int index); //�������� �������� � ����������

	void changeSize(int newLength); 

	void eraseCont();//�������� ���������

	int& operator[](int index) //����������� �������� []
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

