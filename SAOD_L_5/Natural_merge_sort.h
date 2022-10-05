#pragma once
#include "ClassesAlgorithms.h"

class Natural_merge_sort : public Base_sort
{
public:
    Natural_merge_sort();
    Natural_merge_sort(int s);
    ~Natural_merge_sort();

    void Sort_table();
    friend void merge(Natural_merge_sort& merge, int const left, int const mid, int const right);
    friend void mergeSort(Natural_merge_sort& merge, int const begin, int const end);

    template<typename T> friend void Ñalculation_average_value(T& t);
    template<typename T> friend void Show_result(T& t, int* Arrey_size, const int, std::string name);
    
};

void merge(Natural_merge_sort& merge, int const left, int const mid, int const right);
void mergeSort(Natural_merge_sort& merge, int const begin, int const end);