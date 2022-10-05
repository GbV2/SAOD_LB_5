#include "Quick_sort_recursion.h"

Quick_sort_recursion::Quick_sort_recursion() :Base_sort() {}
Quick_sort_recursion::Quick_sort_recursion(int s) : Base_sort(s) {}
Quick_sort_recursion::~Quick_sort_recursion() {}
void Quick_sort_recursion::Sort_table()
{
    int* mas = new int[size]; 
    int cmp = 0, swap = 0;
    // ����� ��������� ������ 
    for (int i = 0; i < size; i++)
    {
        mas[i] = vector_table[i];
    }

    // ������� ����������� ���������� 
    qsortRecursive(mas, size, cmp, swap);

    average_cmp += cmp;
    average_swap += swap;
    for (int i = 0; i < size; i++)
    {
        vector_table[i] = mas[i];
    }
    delete[]mas;
}

void qsortRecursive(int* mas, int size, int& cmp, int& swap)
{
    //��������� � ������ � � ����� �������
    int i = 0;
    int j = size - 1;

    //����������� ������� �������
    int mid = mas[size / 2];

    //����� ������
    do {
        //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
        //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
        while (mas[i] < mid) {
            i++;
            cmp++;
            if (mas[i] > mid)
                cmp++;
        }

        //� ������ ����� ���������� ��������, ������� ������ ������������
        while (mas[j] > mid) {
            j--;
            cmp++;
            if (mas[j] < mid)
                cmp++;
        }

        //������ �������� �������
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            swap++;
            i++;
            j--;
        }
    } while (i <= j);

    //����������� ������, ���� ��������, ��� �����������
    if (j > 0) {
        //"����� �����"
        qsortRecursive(mas, j + 1, cmp, swap);
    }
    if (i < size) {
        //"����� �����"
        qsortRecursive(&mas[i], size - i, cmp, swap);
    }
}