#include "Sheker_Sort.h"

Sheker_Sort::Sheker_Sort() : Base_sort() {}
Sheker_Sort::Sheker_Sort(int s) : Base_sort(s) {}
Sheker_Sort::~Sheker_Sort() {}
void Sheker_Sort::Sort_table()
{
    int left = 0, right = size - 1; // ����� � ������ ������� ����������� ������� �������
    int flag = 1;  // ���� ������� �����������

    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)  //��������� ����� �������
        {
            if (vector_table[i] > vector_table[i + 1]) // ���� ��������� ������� ������ ��������,
            {             // ������ �� �������
                std::swap(vector_table[i], vector_table[i + 1]);
                average_swap++;
                flag = 1;      // ����������� � ���� ����� ����
            }
            average_cmp++;
        }
        right--; // �������� ������ ������� �� ���������� �������
        for (int i = right; i > left; i--)  //��������� ������ ������
        {
            if (vector_table[i - 1] > vector_table[i]) // ���� ���������� ������� ������ ��������,
            {            // ������ �� �������
                std::swap(vector_table[i], vector_table[i - 1]);
                average_swap++;
                flag = 1;    // ����������� � ���� ����� ����
            }
            average_cmp++;
        }
        left++; // �������� ����� ������� �� ��������� �������
    }
}