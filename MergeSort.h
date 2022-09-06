#ifndef MERGE_SORT
//Merge Sort
//Có tham khảo: https://www.youtube.com/watch?v=4-emXIl9IeU
void merge(int a[], int first, int mid, int last) {
    int n1 = mid - first + 1;
    int n2 = last - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = a[first + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0;
    int k = first;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int first, int last) {
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSort(a, first, mid);
        mergeSort(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}
#endif // !MERGE_SORT

