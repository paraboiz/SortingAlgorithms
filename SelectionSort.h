#ifndef SelectionSort
void swap(int& int1, int& int2)
{
	int temp = int1;
	int1 = int2;
	int2 = temp;
}

void selectionSort(int a[], int n)
{
	int min_index;

	// Buoc 1:
	for (int i = 0; i < n - 1; i++)
	{
		// Buoc 1.1:
		min_index = i;

		// Tim vi tri min_index 
		// sao cho a[min_index] la phan tu nho nhat mang 
		// tu vi tri i den n - 1
		for (int j = i + 1; j < n; j++)
		{
			if (a[min_index] > a[j])
			{
				// Buoc 1.1.1:
				min_index = j;
			}
		}
		// Buoc 1.2
		swap(a[min_index], a[i]);
	}
}
//
#endif // !SelectionSort

