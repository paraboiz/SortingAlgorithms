#ifndef SHAKER_SORT
//Shaker Sort
//Phan thuat toan nay em tham khao 
//Link: https://www.youtube.com/watch?v=FgExRtl66Lc

template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

void shakerSort(int a[], int n) {
	int left = 0;
	int right = n - 1;
	int key = n - 1;

	while (left < right) {
		for (int i = right; i > left; i--) {
			if (a[i] < a[i - 1]) {
				HoanVi(a[i], a[i - 1]);
				key = i;
			}
		}

		left = key;

		for (int i = left; i < right; i++) {
			if (a[i] > a[i + 1]) {
				HoanVi(a[i], a[i + 1]);
				key = i;
			}
		}

		right = key;
	}
}
#endif // !SHAKER_SORT

