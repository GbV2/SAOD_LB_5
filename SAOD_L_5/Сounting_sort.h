#pragma once
#include "ClassesAlgorithms.h"

class Ñounting_sort : public Base_sort
{
public:
    Ñounting_sort();
    Ñounting_sort(int s);
    ~Ñounting_sort();

    void Sort_table();
    template<typename T> friend void Ñalculation_average_value(T& t);
    template<typename T> friend void Show_result(T& t, int* Arrey_size, const int, std::string name);
};