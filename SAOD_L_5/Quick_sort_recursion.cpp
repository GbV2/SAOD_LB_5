#include "Quick_sort_recursion.h"

Quick_sort_recursion::Quick_sort_recursion() :Base_sort() {}
Quick_sort_recursion::Quick_sort_recursion(int s) : Base_sort(s) {}
Quick_sort_recursion::~Quick_sort_recursion() {}
void Quick_sort_recursion::Sort_table()
{
    int* mas = new int[size]; 
    int cmp = 0, swap = 0;
    // копия основного списка 
    for (int i = 0; i < size; i++)
    {
        mas[i] = vector_table[i];
    }

    // функция рекурсивной сортировки 
    qsortRecursive(mas, size, cmp, swap);

    average_cmp += cmp;
    average_swap += swap;
    for (int i = 0; i < size; i++)
    {
        vector_table[i] = mas[i];
    }
    delete[]mas;
}

void qsortRecursive(int* mas, int size, int& cmp, int& swap)
{
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (mas[i] < mid) {
            i++;
            cmp++;
            if (mas[i] > mid)
                cmp++;
        }

        //В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) {
            j--;
            cmp++;
            if (mas[j] < mid)
                cmp++;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
            swap++;
            i++;
            j--;
        }
    } while (i <= j);

    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левая часть"
        qsortRecursive(mas, j + 1, cmp, swap);
    }
    if (i < size) {
        //"Првая часть"
        qsortRecursive(&mas[i], size - i, cmp, swap);
    }
}