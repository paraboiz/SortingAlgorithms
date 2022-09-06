#ifndef COUNTING_SORT
#define COUNTING_SORT

//https://www.mygreatlearning.com/blog/counting-sort/
int _count_arr[1000000];

void countingSort(int arr[], int n) {
	if (n <= 0) return;

	//khởi tạo lại giá trị cho mảng toàn cục để tránh trường hợp kết quả sai khi gọi hàm nhiều lần, dùng mảng cục bộ sẽ bị tràn bộ nhớ ?!?
	std::fill_n(_count_arr, 1000000, 0);

	int* output = new int[n];
	int max = arr[0];

	for (int i = 0; i < n; i++) {
		_count_arr[arr[i]]++;
		if (max < arr[i]) max = arr[i];
	}

	for (int i = 1; i <= max; i++) {
		_count_arr[i] += _count_arr[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		output[_count_arr[arr[i]] - 1] = arr[i];
		_count_arr[arr[i]]--;
	}

	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}

#endif // !COUNTING_SORT

