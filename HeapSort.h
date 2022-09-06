#ifndef HeapSort
void swap_h(int& int1, int& int2)
{
	int temp = int1;
	int1 = int2;
	int2 = temp;
}

void heapRebuild(int pos, int*& a, int n)
{
	int j, k = pos;
	int v = a[k];
	bool isHeap = false;
	while (!isHeap && 2 * k + 1 < n)
	{
		j = 2 * k + 1;
		if (j < n - 1)
		{
			if (a[j] < a[j + 1])
			{
				j++;
			}
		}
		if (a[k] >= a[j])
		{
			isHeap = true;
		}
		else
		{
			swap_h(a[k], a[j]);
			k = j;
		}
	}

}

void heapConstruction(int*& a, int n)
{
	int index = (n - 1) / 2;
	while (index >= 0)
	{
		heapRebuild(index, a, n);
		index--;
	}
}

void heapSort(int a[], int n)
{
	heapConstruction(a, n);
	int r = n - 1;
	while (r > 0)
	{
		swap_h(a[0], a[r]);
		heapRebuild(0, a, r);
		r--;
	}

}
#endif // !HeapSort
