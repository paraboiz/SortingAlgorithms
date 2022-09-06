#ifndef INSERTION_SORT
void insertionSort(int arr[], int n) {
    int i, j, key;

    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Di chuyển các phần tử có giá trị lớn hơn giá trị
        key về sau một vị trí so với vị trí ban đầu
        của nó */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}
#endif // !INSERTION_SORT

