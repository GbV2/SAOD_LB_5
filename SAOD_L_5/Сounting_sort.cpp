#include "�ounting_sort.h"

�ounting_sort::�ounting_sort() : Base_sort() {}
�ounting_sort::�ounting_sort(int s) : Base_sort(s) {}
�ounting_sort::~�ounting_sort() {}
void �ounting_sort::Sort_table()
{
    unsigned int min, max;
    max = min = vector_table[0];
    for (size_t i = 1; i < vector_table.size(); i++) {
        if (vector_table[i] < min) {
            min = vector_table[i];
            average_cmp++;
        }
        if (vector_table[i] > max) {
            max = vector_table[i];
            average_cmp++;
        }
    }
    std::vector<unsigned int> counts(max - min + 1, 0);
    for (size_t i = 0; i < vector_table.size(); i++) {
        counts[vector_table[i] - min]++;
    }
    size_t index = 0;
    // ��������� �� ���� ���������
    // count[i] - ���������� ������� ��� ����������� �� ��� ���� �����
    for (size_t i = 0; i < counts.size(); i++) {
        for (size_t j = 0; j < counts[i]; j++) {
            if (vector_table[index] != i + min)
                average_swap++;
            vector_table[index++] = i + min;
        }
    }
}