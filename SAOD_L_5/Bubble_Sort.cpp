#include "Bubble_Sort.h"

Bubble_Sort::Bubble_Sort() : Base_sort() {}
Bubble_Sort::Bubble_Sort(int s) : Base_sort(s) {}
Bubble_Sort::~Bubble_Sort() {}
void Bubble_Sort::Sort_table()
{
    int i, j;
    for (i = 0; i < vector_table.size() - 1; i++)
    {
        // Максимальный i элемент на месте(в конце области сортировки) 
        for (j = 0; j < vector_table.size() - i - 1; j++)
        {
            average_cmp++;
            if (vector_table[j] > vector_table[j + 1])
            {
                average_swap++;
                std::swap(vector_table[j], vector_table[j + 1]);
            }
        }
    }

}