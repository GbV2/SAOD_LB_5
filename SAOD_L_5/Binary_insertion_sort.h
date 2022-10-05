#pragma once
#include "ClassesAlgorithms.h"

class Binary_insertion_sort : public Base_sort
{
public:
    Binary_insertion_sort();
    Binary_insertion_sort(int s);
    ~Binary_insertion_sort();

    void Sort_table();

    template<typename T> friend void Ñalculation_average_value(T& t);
    template<typename T> friend void Show_result(T& t, int* Arrey_size, const int, std::string name);
};