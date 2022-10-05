#include <iostream>
#include <iomanip>
#include <time.h>
#include <chrono>

#include "ClassesAlgorithms.h"
#include "Binary_insertion_sort.h"
#include "Shell_Sort.h"
#include "Bubble_Sort.h"
#include "Sheker_Sort.h"
#include "Quick_sort_recursion.h"
#include "Quick_sort_iteration.h"
#include "Simple_selection_sort.h"
#include "Сounting_sort.h"
#include "Natural_merge_sort.h"

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    const int size = 5;
    int Arrey_size[size] = { 10, 20, 30, 40, 50 };
    
    
    Binary_insertion_sort Binary_insertion; //+
    Shell_Sort shell; //+
    Bubble_Sort bubble; //+
    Sheker_Sort sheker; //+
    Quick_sort_recursion rec; //+
    Quick_sort_iteration iter; //+
    Simple_selection_sort simple; //+
    Сounting_sort count; 
    Natural_merge_sort merge;

    std::cout << std::setw(33) << " ";
    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(26) << std::right << "N=" << Arrey_size[i];
    }
    std::cout << std::endl;
    std::cout << std::setw(48) << " ";
    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(28) << std::left << "Сравненя Пересылки Время";
    }
    std::cout << std::endl;

    Show_result(Binary_insertion, Arrey_size, size, "Сортировка бинарными вставками:");
    Show_result(shell, Arrey_size, size, "Сортировка Шелла:");
    Show_result(bubble, Arrey_size, size, "Пузырьковая сортировка:");
    Show_result(sheker, Arrey_size, size, "Шейкер-сортировка:");
    Show_result(rec, Arrey_size, size, "Быстрая сортировка (рекурсивный вариант):");
    Show_result(iter, Arrey_size, size, "Быстрая сортировка (итерационный вариант):");
    Show_result(simple, Arrey_size, size, "Простая сортировка выбором:");
    Show_result(count, Arrey_size, size, "Сортировка распределяющим подсчетом:");
    Show_result(merge, Arrey_size, size, "Сортировка естественным двухпутевым слиянием:");

    return 0;
}

