#pragma once
#include "ClassesAlgorithms.h" 

class Quick_sort_recursion : public Base_sort
{
public:
    Quick_sort_recursion();
    Quick_sort_recursion(int s);
    ~Quick_sort_recursion();

    void Sort_table();
    template<typename T> friend void Ñalculation_average_value(T& t);
    template<typename T> friend void Show_result(T& t, int* Arrey_size, const int, std::string name);
};

void qsortRecursive(int* mas, int size, int& cmp, int& swap);