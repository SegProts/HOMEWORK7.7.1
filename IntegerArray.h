#pragma once
class IntegerArray
{
private:
    int m_length{}; //����� ����������
    int* m_data{}; //������ ����������

public:
    
    IntegerArray() = default;

    //�����������(�������� ����������)
    IntegerArray(int length) : m_length{ length } {}

    //�������� ����������
    ~IntegerArray() {}

    //�������� �������� � ����������
    void deleteItem(int index) {}

    //�������� ������� ����������� �� �������
    int getItem(int index) {}

};

