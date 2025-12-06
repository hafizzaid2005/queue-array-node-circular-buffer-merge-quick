#include "sorts.h"
#include <iostream>
#include <cstdlib>

using std::cout;

void merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int* arr, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSortCallerFunction(int* arr, const int arrSize)
{
    mergeSort(arr, 0, arrSize - 1);
}

int choosePivot(int left, int right, int pos)
{
    if(pos == 0) return right;
    if(pos == 1) return (left + right) / 2;
    if(pos == 2) return left;
    return left + (rand() % (right - left + 1));
}

int partitionArray(int* arr, int left, int right, int pivotIndex)
{
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[right]);

    int store = left;

    for(int i = left; i < right; i++)
    {
        if(arr[i] < pivotValue)
        {
            std::swap(arr[i], arr[store]);
            store++;
        }
    }

    std::swap(arr[store], arr[right]);
    return store;
}

void quickSort(int* arr, int left, int right, int pos)
{
    if(left < right)
    {
        int pivotIndex = choosePivot(left, right, pos);
        int newIndex = partitionArray(arr, left, right, pivotIndex);
        quickSort(arr, left, newIndex - 1, pos);
        quickSort(arr, newIndex + 1, right, pos);
    }
}

void quickSortCallerFunction(int* arr, const int arrSize, const int pivotPosition)
{
    quickSort(arr, 0, arrSize - 1, pivotPosition);
}
