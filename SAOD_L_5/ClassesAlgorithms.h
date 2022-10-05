#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <vector>
#define MAXSTACK 2048

struct Table
{
    unsigned int value;
    int serial_number;
    int index;
    Table* previous;
    Table* next;
};

class Base_sort
{
protected:
    int size;
    std::vector<int> vector_table;
    unsigned int average_swap;
    int average_cmp;
    long double average_time;

public:
    Base_sort();
    Base_sort(int);
    virtual ~Base_sort() = 0;

    void Zeroing_Class();
    void Creat_table();
    void Delete_table();
    void Out_average_value();

    void Show_table();
};

template<typename T>
void Show_result(T& t, int* Arrey_size, const int size_arrey, std::string name)
{
    std::cout << std::setw(51) << std::left << name;
    for (int i = 0; i < size_arrey; i++)
    {
        t = T(Arrey_size[i]);
        Ñalculation_average_value(t);
        t.Out_average_value();
        //
        t.Zeroing_Class();
        std::cout << "  ";
    }
    std::cout << std::endl;
}

template<typename T>
void Ñalculation_average_value(T& t)
{
    for (int i = 0; i < 1000; i++)
    {
        t.Creat_table();
        auto begin = std::chrono::steady_clock::now();
        t.Sort_table();
        auto end = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        t.average_time += elapsed_ms.count();
        t.Delete_table();
    }
    t.average_swap /= 1000;
    t.average_cmp /= 1000;
    t.average_time /= 1000;
}

