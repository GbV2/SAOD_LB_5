#include "Binary_insertion_sort.h"

Binary_insertion_sort::Binary_insertion_sort() :Base_sort() {}
Binary_insertion_sort::Binary_insertion_sort(int s) :Base_sort(s) {}
Binary_insertion_sort::~Binary_insertion_sort() {}
void Binary_insertion_sort::Sort_table()
{
    int left, right, x;
    int mid;


    for (int i = 1; i < size; i++)
    {
        x = vector_table[i]; // ���������� �������� �������� 
        left = 0;
        right = i;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (x >= vector_table[mid]) // ��������� ������������ ������� � �������� � �������� ������� 
            {
                left = mid + 1; // �������� ����� ������� 
                average_cmp++;
            }
            else
            {
                right = mid;    // �������� ������ ������� 
                average_cmp++;
            }
        }
        // ������� ��������� �����
        for (int j = i; j > right; j--)
        {
            vector_table[j] = vector_table[j - 1];
            average_swap++;
        }
        vector_table[right] = x;
        average_swap++;
    }

}