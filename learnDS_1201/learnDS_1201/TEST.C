#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void fun(int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			++count;
		}
	}
	for (int k = 0; k < 2 * N; k++) {
		++count;
	}
	int M = 10;
	while (M--) {
		++count;
	}
	printf("%d\n", count);
}
void fun1(int N) {
	int count = 0;
	for (int k = 0; k < 2 * N; k++) {
		++count;
	}
	int M = 10;
	while (M--) {
		++count;
	}
	printf("%d\n", count);
}

void fun2(int N, int M) {
	int count = 0;
	for (int k = 0; k < M; ++k) {
		++count;
	}
	for (int k = 0; k < N; k++) {
		++count;
	}
	printf("%d\n", count);
}

void fun4(int N) {
	int count = 0;
	for (int k = 0; k < 100; k++) {
		++count;
	}
	printf("%d\n", count);
}

//strchr函数功能为在一个串str中查找给定字符character的第一个匹配之处
const char* strchr(const char* str, int character);
void Swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
//冒泡排序 --从小到大
void BubbleSort(int* a, int n) {
	assert(a);//异常处理
	for (int end = n; end > 0; --end) {
		int exchange = 0;
		for (int i = 1; i < end; ++i) {
			if (a[i - 1] > a[i]) {
				//两个数据进行比较，前面一个数据大于后一个数据
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		//如果遍历整个数组，发现没有数据进行交换，即每个元素均小于等于后一个元素
		//则无须在进行排序，直接结束循环即可
		if (exchange == 0)
			break;
	}
}

//二分查找法
int BinarySearch(int* a, int  n, int x) {
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		int mid = ((end - begin) >> 1) + begin; //计算end与begin的中间值，右移1位相当于除以2
		if (a[mid] < x) {
			begin = mid - 1;
		}
		else if (a[mid] > x) {
			end = mid;
		}
		else {
			return mid;
		}
	}
	return -1;
}

//求阶乘
long long Factorial(int N) {
	return N < 2 ? N : Factorial(N - 1) * N;
}

//斐波那契函数
long long Fibonacci1(int N) {
	return N < 2 ? N : Fibonacci1(N - 1) + Fibonacci1(N - 2);
}

//斐波那契函数
long long* Fibonacci(int n) {
	if (n == 0) {
		return NULL;
	}
	long long* fibArray = (long long*)malloc((n + 1) * sizeof(long long));
	fibArray[0] = 0;
	fibArray[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
}

int main() {

}