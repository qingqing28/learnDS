#include<stdio.h>
#include<stdlib.h>
/*Ï£¶ûÅÅĞò
*/
void shellSort(int* arr, int n) {
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1 ;
		//Î´ÅÅĞòÊı×é[gap , n)
		for (int i = gap; i < n; i++) {
			int end = i - gap;
			int data = arr[i];
			while (end >= 0 && arr[end] > data) {
				arr[end + gap] = arr[end];
				end = end - gap;
			}
			arr[end + gap] = data;
		}
	}
}

void testShellSort() {
	int arr[] = { 9 ,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	shellSort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}