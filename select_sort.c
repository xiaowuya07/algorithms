#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM 1000

//Sort public function implementation
//generate_randm
bool generate_randm(int *arr, int num) {
	srand((unsigned)time(NULL));

	for (int i = 0; i < num; ++i) {
		arr[i] = rand() % NUM;
	}
	return true;
}

//less:Determine if a is less than b
bool less(int a, int b) {
	return (a < b);
}

//exch:Swap the elements at the A and B positions in the ARR array
void exch(int *arr, int a, int b) {
	int c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
}

//show:Print the array elements
void print_arr(int *arr, int num) {
	for (int i = 0; i < num; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//is_sorted:Determine whether the array is ordered
bool is_sorted(int *arr, int num) {
	for (int i = 0; i < num - 1; ++i) {
		if (less(arr[i + 1], arr[i])) {
			return false;
		}
	}
	return true;
}

//SORT FUNCTION
bool select_sort(int *arr, int num) {
	int max = arr[0];
	for (int i = 0; i < num; ++i) {
		for (int j = i + 1; j < num; ++j) {
			if (less(arr[j], arr[i]))
				exch(arr, j, i);
		}
	}
	return true;
}

int main(int argc, char * argv[]) {
	int arr[NUM];
	generate_randm(arr, NUM);

	if (select_sort(arr, NUM)) {
		print_arr(arr, NUM);
		printf("\nsort success\n");
	}
	else {
		printf("\nsort fail\n");
	}

}