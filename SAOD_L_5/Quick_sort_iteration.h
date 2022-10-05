#pragma once
#include "ClassesAlgorithms.h"

class Quick_sort_iteration : public Base_sort
{
public:
    Quick_sort_iteration();
    Quick_sort_iteration(int s);
    ~Quick_sort_iteration();


    void Sort_table();
    template<typename T> friend void Ñalculation_average_value(T& t);
    template<typename T> friend void Show_result(T& t, int* Arrey_size, const int, std::string name);
};