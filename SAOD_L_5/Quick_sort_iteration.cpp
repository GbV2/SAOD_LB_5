#include "Quick_sort_iteration.h"

Quick_sort_iteration::Quick_sort_iteration() :Base_sort() {}
Quick_sort_iteration::Quick_sort_iteration(int s) : Base_sort(s) {}
Quick_sort_iteration::~Quick_sort_iteration() {}
void Quick_sort_iteration::Sort_table()
{
    long i, j; // ���������, ����������� � ����������
    long lb, ub; // ������� ������������ � ����� ���������

    long lbstack[MAXSTACK], ubstack[MAXSTACK]; // ���� ��������
    // ������ ������ �������� ����� ��������,
    // � ������: �����(lbstack) � ������(ubstack)
    // ��������� ����������
    long stackpos = 1; // ������� ������� �����
    long ppos; // �������� �������
    int pivot; // ������� �������

    lbstack[1] = 0;
    ubstack[1] = size - 1;

    do {
        // ����� ������� lb � ub �������� ������� �� �����.
        lb = lbstack[stackpos];
        ub = ubstack[stackpos];
        stackpos--;

        do {
            // ��� 1. ���������� �� �������� pivot
            ppos = (lb + ub) >> 1;
            i = lb; j = ub; pivot = vector_table[ppos];
            do {
                while (vector_table[i] < pivot)
                {
                    i++;
                    average_cmp++;
                    if (vector_table[i] > pivot)
                        average_cmp++;
                }

                while (pivot < vector_table[j])
                {
                    j--;
                    average_cmp++;
                    if (pivot > vector_table[j])
                        average_cmp++;
                }
                if (i <= j) {
                    //temp = a[i]; a[i] = a[j]; a[j] = temp;
                    std::swap(vector_table[i], vector_table[j]);
                    average_swap++;
                    i++; j--;
                }
            } while (i <= j);

            // ������ ��������� i ��������� �� ������ ������� ����������,
            // j - �� ����� ������ (��. ����������� ����), lb ? j ? i ? ub.
            // �������� ������, ����� ��������� i ��� j ������� �� ������� �������

            // ���� 2, 3. ���������� ������� ����� � ���� � ������� lb,ub
            if (i < ppos) { // ������ ����� ������
                if (i < ub) { // ���� � ��� ������ 1 �������� - �����
                    stackpos++; // �����������, ������ � ����
                    lbstack[stackpos] = i;
                    ubstack[stackpos] = ub;
                }
                ub = j; // ��������� �������� ����������
                // ����� �������� � ����� ������
            }
            else { // ����� ����� ������
                if (j > lb) {
                    stackpos++;
                    lbstack[stackpos] = lb;
                    ubstack[stackpos] = j;
                }
                lb = i;
            }
        } while (lb < ub); // ���� � ������� ����� ����� 1 ��������
    } while (stackpos != 0); // ���� ���� ������� � �����

}