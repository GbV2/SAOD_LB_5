#include "ClassesAlgorithms.h"
#define MAXSTACK 2048

Base_sort::Base_sort() :
    size(0), average_cmp(0), average_time(0), average_swap(0) {}
Base_sort::Base_sort(int s):
    size(s), average_cmp(0), average_time(0), average_swap(0) {}
Base_sort::~Base_sort() {}

void Base_sort::Creat_table()
{
    for (int i = 0; i < size; i++)
    {
        vector_table.push_back(rand() % size + 1);
    }
}
void Base_sort::Zeroing_Class()
{
    size = 0;
    Delete_table();
    average_cmp = 0;
    average_swap = 0;
    average_time = 0;
}
void Base_sort::Delete_table()
{
    vector_table.clear();
}
void Base_sort::Out_average_value()
{
    std::cout << std::setw(10) << std::left << average_cmp << std::setw(6) << std::left << average_swap << std::setw(10) << std::left << average_time;
}
void Base_sort::Show_table()
{
    for (auto i = vector_table.begin(); i != vector_table.end(); i++)
    {
        std::cout << *i << "  ";
    }
    std::cout << std::endl;
}
