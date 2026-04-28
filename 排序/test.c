#define _CRT_SECURE_NO_WARNINGS
#include"sort.h"
#include"Stack.h"
int main(){
	int arr[10] = { 1,5,6,4,8,3,2,7,9,10 };
	//int arr[3] = { 6,9,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//InsertSort(arr, n);
	//ShellSort(arr, n);
	//SelectSort(arr, n);
	//HeapSort(arr, n);
	//QuickSort(arr, 0, n - 1);
	//QuickSortNonR(arr, 0, n - 1);
	PartSort4(arr, 0, n - 1);
	return 0;
}