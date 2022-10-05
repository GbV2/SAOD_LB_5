#pragma once
#include "ClassesAlgorithms.h"

class �ounting_sort : public Base_sort
{
public:
    �ounting_sort();
    �ounting_sort(int s);
    ~�ounting_sort();

    void Sort_table();
    template<typename T> friend void �alculation_average_value(T& t);
    template<typename T> friend void Show_result(T& t, int* Arrey_size, const int, std::string name);
};