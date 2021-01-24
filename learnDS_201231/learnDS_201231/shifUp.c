#include<stdio.h>
#include<stdlib.h>

typedef int HPDataType;

void shifUp(HPDataType* arr, int n, int cur) {
	int parent = (cur - 1) / 2;
	while (parent >= 0) {
		if (arr[cur] < arr[parent]) {
			Swap(arr, cur, parent);
			cur = parent;
			parent = (cur - 1) / 2;
		}
		else
			break;
	}
}