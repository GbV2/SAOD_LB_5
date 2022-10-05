#include "Natural_merge_sort.h"

Natural_merge_sort::Natural_merge_sort() : Base_sort() {}
Natural_merge_sort::Natural_merge_sort(int s) : Base_sort(s) {}
Natural_merge_sort::~Natural_merge_sort() {}
void Natural_merge_sort::Sort_table()
{
    mergeSort(*this, 0, size - 1);
}

void merge(Natural_merge_sort& mer, int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // �������� ��������� ��������
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // ����������� ������ � ��������� ������� leftArray[] � rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = mer.vector_table[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = mer.vector_table[mid + 1 + j];

    auto indexOfSubArrayOne = 0, //��������� ������ ������� ����������
        indexOfSubArrayTwo = 0; // ��������� ������ ������� ����������
    int indexOfMergedArray = left; // ��������� ������ ������������� �������

    // ����������� ��������� � �������� � ������ [left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        mer.average_cmp++;
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            mer.vector_table[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            mer.average_swap++;
        }
        else {
            mer.vector_table[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            mer.average_swap++;
        }
        indexOfMergedArray++;
    }
    // ����������� ���������� ��������� �����
    while (indexOfSubArrayOne < subArrayOne) {
        mer.average_swap++;
        mer.vector_table[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // ����������� ���������� ��������� ������
    while (indexOfSubArrayTwo < subArrayTwo) {
        mer.average_swap++;
        mer.vector_table[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(Natural_merge_sort& mer, int const begin, int const end)
{
    if (begin >= end)
        return; // ���������� ����������

    auto mid = begin + (end - begin) / 2;
    mergeSort(mer, begin, mid);
    mergeSort(mer, mid + 1, end);
    merge(mer, begin, mid, end);
}