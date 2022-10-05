#pragma once
#include "ClassesAlgorithms.h"

class Shell_Sort : public Base_sort
{
public:
    Shell_Sort();
    Shell_Sort(int s);
    ~Shell_Sort();

    void Sort_table();

    template<typename T> friend void Ñalculation_average_value(T& t);
    template<typename T> friend void Show_result(T& t, int* Arrey_size, const int, std::string name);
};
