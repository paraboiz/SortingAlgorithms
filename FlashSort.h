#ifndef FLASH_SORT
#include <iostream>

void swap_f(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void flashSort(int a[], int n) {

	if (n <= 1) return;

	int m = int(0.43 * n);

	int *l = new int[m];
	for (int i = 0; i < m; i++) {
		l[i] = 0;
	}

	//tìm min, max
	int max_idx = 0;
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > a[max_idx]){
			max_idx = i;
		}
		if (a[i] < min) {
			min = a[i];
		}
	}

	if (a[max_idx] == min) return;

	//dem so phan tu trong  bucket
	const double c1 = 1.0 * (m - 1.0) / (1.0 * a[max_idx] - 1.0 * min);

	for (int i = 0; i < n; i++) {
		int k = int(c1*(a[i]*1.0 - min*1.0));
		++l[k];
	}

	//tinh index cuoi cung cho tung bucket
	for (int i = 1; i < m; i++) {
		l[i] = l[i] + l[i - 1];
	}

	//hoan vi
	swap_f(a[0], a[max_idx]);
	max_idx = 0;

	int move = 0;
	int j = 0;
	int k = m - 1;


	while (move < n-1) {
		//int k = int((m - 1) * (a[j] - min) / (a[max_idx] - min));
		while (j > l[k]-1) {
			j++;
			k = int(c1*(a[j]*1.0-min*1.0));
		}
		int flash = a[j];
		while (j != l[k]) {
			k = int(c1* (flash*1.0 - min*1.0));
			--l[k];
			swap_f(a[l[k]],flash);
			move++;
		}
	}

	//intertion sort
	for (int i = 1; i < n; i++) {
		int temp = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j--];
		}

		a[j + 1] = temp;
	}


}


#endif // !FLASH_SORT
//tham khao buoc hoan vi o https://codelearn.io/sharing/flash-sort-thuat-toan-sap-xep-than-thanh
