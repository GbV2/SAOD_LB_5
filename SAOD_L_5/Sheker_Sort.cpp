#include "Sheker_Sort.h"

Sheker_Sort::Sheker_Sort() : Base_sort() {}
Sheker_Sort::Sheker_Sort(int s) : Base_sort(s) {}
Sheker_Sort::~Sheker_Sort() {}
void Sheker_Sort::Sort_table()
{
    int left = 0, right = size - 1; // левая и правая границы сортируемой области массива
    int flag = 1;  // флаг наличия перемещений

    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)  //двигаемся слева направо
        {
            if (vector_table[i] > vector_table[i + 1]) // если следующий элемент меньше текущего,
            {             // меняем их местами
                std::swap(vector_table[i], vector_table[i + 1]);
                average_swap++;
                flag = 1;      // перемещения в этом цикле были
            }
            average_cmp++;
        }
        right--; // сдвигаем правую границу на предыдущий элемент
        for (int i = right; i > left; i--)  //двигаемся справа налево
        {
            if (vector_table[i - 1] > vector_table[i]) // если предыдущий элемент больше текущего,
            {            // меняем их местами
                std::swap(vector_table[i], vector_table[i - 1]);
                average_swap++;
                flag = 1;    // перемещения в этом цикле были
            }
            average_cmp++;
        }
        left++; // сдвигаем левую границу на следующий элемент
    }
}