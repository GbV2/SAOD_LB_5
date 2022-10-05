#pragma once
#include "ClassesAlgorithms.h"

class Sheker_Sort : public Base_sort
{
public:
    Sheker_Sort();
    Sheker_Sort(int s);
    ~Sheker_Sort();

    void Sort_table();
    template<typename T> friend void Ñalculation_average_value(T& t);
    template<typename T> friend void Show_result(T& t, int* Arrey_size, const int, std::string name);
};