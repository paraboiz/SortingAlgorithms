#ifndef RADIX_SORT
#include <algorithm>
#include <iostream>
using namespace std;

// Ham dung de lay chu so o hang thu digit
int getDigit(int num, int digit)
{
	// digit = 1 -> hang don vi, 
	// digit = 2 -> hang chuc,...
	return (num / int(pow(10, digit - 1))) % 10;
}

// Ham sap xep theo tung hang thu digit (don vi, chuc, tram,...)
void sortByDigit(int arr[], int n, int digit)
{
	int i, digit_int, count[10] = { 0 };

	// Buoc 2.1:
	// Luu so luong cac phan tu co chu so o hang digit bang 0 den 9
	for (i = 0; i < n; i++)
		count[getDigit(arr[i], digit)]++;

	// Buoc 2.2: 
	// Luu vi tri ket thuc cua cac phan tu co chu so o hang digit bang 0 den 9
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Buoc 2.3:
	int* result = new int[n];

	// Buoc 2.4: 
	for (i = n - 1; i >= 0; i--)
	{
		// Buoc 2.4.1: 
		digit_int = getDigit(arr[i], digit);

		// Buoc 2.4.2: 
		result[count[digit_int] - 1] = arr[i];

		// Buoc 2.4.3: 
		count[digit_int]--;
	}

	// Buoc 2.5: 
	// Gan mang result cho mang arr
	for (i = 0; i < n; i++)
		arr[i] = result[i];

	delete[] result;
}

// Radix Sort
void radixSort(int arr[], int n)
{
	// Tim phan tu lon nhat mang
	int largest_element = *max_element(arr, arr + n);

	// Buoc 2: 
	for (int digit = 1; largest_element >= pow(10, digit - 1); digit++)
		sortByDigit(arr, n, digit);
}

#endif // !RADIX_SORT

