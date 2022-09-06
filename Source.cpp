#include <iostream>
using namespace std;

void print(int arr[], int n) {
	cout << "array : ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

#include "BubbleSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "ShakerSort.h"
#include "FlashSort.h"
#include "CountingSort.h"

void main() {
	int arr[] = { 50,77,1,40,11,3,81,100,23,15 };
	int n = sizeof(arr) / sizeof(arr[0]);

	print(arr, n);

	flashSort(arr,n);

	print(arr, n);
}