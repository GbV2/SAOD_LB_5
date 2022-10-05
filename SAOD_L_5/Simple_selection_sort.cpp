#include "Simple_selection_sort.h"

Simple_selection_sort::Simple_selection_sort() :Base_sort() {}
Simple_selection_sort::Simple_selection_sort(int s) :Base_sort(s) {}
Simple_selection_sort::~Simple_selection_sort() {}
void Simple_selection_sort::Sort_table()
{
    int min;
    for (int i = 0; i < size; i++)
    {
        min = i;
        // min - индекс минимального элемента 
        for (int j = i + 1; j < size; j++)
        {
            min = (vector_table[j] < vector_table[min]) ? j : min;
            average_cmp++;
        }
        if (i != min)
        {
            std::swap(vector_table[i], vector_table[min]);
            average_swap++;
        }
    }
}