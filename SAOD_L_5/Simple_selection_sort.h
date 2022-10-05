#pragma once
#include "ClassesAlgorithms.h"

class Simple_selection_sort : public Base_sort
{
public:
    Simple_selection_sort();
    Simple_selection_sort(int s);
    ~Simple_selection_sort();

    void Sort_table();
    template<typename T> friend void Ñalculation_average_value(T& t);
    template<typename T> friend void Show_result(T& t, int* Arrey_size, const int, std::string name);
};
