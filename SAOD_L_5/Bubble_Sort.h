#pragma once
#include "ClassesAlgorithms.h"

class Bubble_Sort : public Base_sort
{
public:
    Bubble_Sort();
    Bubble_Sort(int s);
    ~Bubble_Sort();

    void Sort_table();

    template<typename T> friend void Ñalculation_average_value(T& t);
    template<typename T> friend void Show_result(T& t, int* Arrey_size, const int, std::string name);
};