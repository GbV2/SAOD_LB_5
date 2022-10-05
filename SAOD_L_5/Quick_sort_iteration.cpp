#include "Quick_sort_iteration.h"

Quick_sort_iteration::Quick_sort_iteration() :Base_sort() {}
Quick_sort_iteration::Quick_sort_iteration(int s) : Base_sort(s) {}
Quick_sort_iteration::~Quick_sort_iteration() {}
void Quick_sort_iteration::Sort_table()
{
    long i, j; // указатели, участвующие в разделении
    long lb, ub; // границы сортируемого в цикле фрагмента

    long lbstack[MAXSTACK], ubstack[MAXSTACK]; // стек запросов
    // каждый запрос задаетс€ парой значений,
    // а именно: левой(lbstack) и правой(ubstack)
    // границами промежутка
    long stackpos = 1; // текуща€ позици€ стека
    long ppos; // середина массива
    int pivot; // опорный элемент

    lbstack[1] = 0;
    ubstack[1] = size - 1;

    do {
        // ¬з€ть границы lb и ub текущего массива из стека.
        lb = lbstack[stackpos];
        ub = ubstack[stackpos];
        stackpos--;

        do {
            // Ўаг 1. –азделение по элементу pivot
            ppos = (lb + ub) >> 1;
            i = lb; j = ub; pivot = vector_table[ppos];
            do {
                while (vector_table[i] < pivot)
                {
                    i++;
                    average_cmp++;
                    if (vector_table[i] > pivot)
                        average_cmp++;
                }

                while (pivot < vector_table[j])
                {
                    j--;
                    average_cmp++;
                    if (pivot > vector_table[j])
                        average_cmp++;
                }
                if (i <= j) {
                    //temp = a[i]; a[i] = a[j]; a[j] = temp;
                    std::swap(vector_table[i], vector_table[j]);
                    average_swap++;
                    i++; j--;
                }
            } while (i <= j);

            // —ейчас указатель i указывает на начало правого подмассива,
            // j - на конец левого (см. иллюстрацию выше), lb ? j ? i ? ub.
            // ¬озможен случай, когда указатель i или j выходит за границу массива

            // Ўаги 2, 3. ќтправл€ем большую часть в стек и двигаем lb,ub
            if (i < ppos) { // права€ часть больше
                if (i < ub) { // если в ней больше 1 элемента - нужно
                    stackpos++; // сортировать, запрос в стек
                    lbstack[stackpos] = i;
                    ubstack[stackpos] = ub;
                }
                ub = j; // следующа€ итераци€ разделени€
                // будет работать с левой частью
            }
            else { // лева€ часть больше
                if (j > lb) {
                    stackpos++;
                    lbstack[stackpos] = lb;
                    ubstack[stackpos] = j;
                }
                lb = i;
            }
        } while (lb < ub); // пока в меньшей части более 1 элемента
    } while (stackpos != 0); // пока есть запросы в стеке

}