#ifndef BUBBLE_SORT
//Bubble Sort
//Co tham khao: https://www.geeksforgeeks.org/bubble-sort/
void bubbleSort(int a[], int n)
{
    int temp;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = false;
            }
        }
        if (flag == true)
        {
            break;
        }
    }
}
#endif // !BUBBLE_SORT

