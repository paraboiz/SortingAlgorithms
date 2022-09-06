#ifndef QUICK_SORT
//Quick Sort
//Co tham khao: https://www.geeksforgeeks.org/quick-sort/ 
void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int a[], int first, int last) {
    int i = first - 1;

    //Chon pivot random
    srand(time(NULL));
    int random = first + rand() % (last - first); 
    swap(a[random], a[last]);
    int pivot = a[last];

    for (int j = first; j <= last - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[last]);
    return(i + 1);
}

void quickSort(int a[], int first, int last) {
    if (first < last) {
        int p = partition(a, first, last);
        quickSort(a, first, p - 1);
        quickSort(a, p + 1, last);
    }
}

//quickSort(arr,0, n-1);

#endif // !QUICK_SORT
