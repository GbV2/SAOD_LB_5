#include "Shell_Sort.h"

Shell_Sort::Shell_Sort() : Base_sort() {}
Shell_Sort::Shell_Sort(int s) :Base_sort(s) {}
Shell_Sort::~Shell_Sort() {}
void Shell_Sort::Sort_table()
{
    int step = size / 2;

    int j;

    while (step > 0)
    {
        for (int i = 0; i < size - step; i++)
        {
            j = i;
            while (j >= 0 && vector_table[j] > vector_table[j + step])
            {
                average_cmp++;
                std::swap(vector_table[j], vector_table[j + step]);
                j--;
                average_swap++;

            }
            average_cmp++;
        }
        step = step / 2;
    }

}