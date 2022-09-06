#ifndef TEMP
#include <iostream>
using namespace std;
template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}


void shakerSort(int a[], int n) {
	cout << "\nShaker Sort";

	int count_cmp = 0;

	int left = 0;
	int right = n - 1;
	int key = n - 1;


	while (++count_cmp&& left < right) {
		for (int i = right; ++count_cmp && i > left; i--) {
			if (++count_cmp && a[i] < a[i - 1]) {
				HoanVi(a[i], a[i - 1]);
				key = i;
			}
		}

		left = key;

		for (int i = left; ++count_cmp && i < right; i++) {
			if (++count_cmp && a[i] > a[i + 1]) {
				HoanVi(a[i], a[i + 1]);
				key = i;
			}
		}

		right = key;
	}

	cout << "\ncount_cmp= " << count_cmp;
}


//Shell Sort
//Phan thuat toan em tham khao
//Link https://www.geeksforgeeks.org/shellsort/

void shellSort(int a[], int n) {
	cout << "\nShell Sort";

	int count_cmp = 0;

	int interval, i, j, temp;

	for (interval = n / 2; ++count_cmp && interval > 0; interval /= 2) {
		for (i = interval; ++count_cmp && i < n; i++) {
			temp = a[i];

			for (j = i; (++count_cmp && j >= interval) && (++count_cmp && a[j - interval] > temp); j -= interval) {
				a[j] = a[j - interval];
			}

			a[j] = temp;
		}
	}

	cout << "\ncount_cmp= " << count_cmp;
}

//Insertion Sort
//Thuat toan nay em tham khao
//Link https://nguyenvanhieu.vn/thuat-toan-sap-xep-chen/
void insertionSort(int arr[], int n) {
	cout << "\nInsertion Sort";

	int count_cmp = 0;

	int i, j, key;

	for (i = 1; ++count_cmp && i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Di chuyển các phần tử có giá trị lớn hơn giá trị
		key về sau một vị trí so với vị trí ban đầu
		của nó */
		while ((++count_cmp && j >= 0) && (++count_cmp && arr[j] > key)) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}

	cout << "\ncount_cmp= " << count_cmp;
}


#endif // !TEMP

