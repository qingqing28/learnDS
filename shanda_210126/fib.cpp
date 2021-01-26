#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int n;
	cout << "请输入数列的下标：";
	cin >> n;
	//如果输入值为0或1可以直接输出斐波那契结果
	if (n == 0 || n == 1) {
		cout << n << endl;
		return 0;
	}
	int fn1 = 0;
	int fn2 = 1;
	int idx = 2;   //用来表示目前发斐波那契数列的项数
	int fn;
	while (idx <= n) {
		fn = fn1 + fn2;
		fn1 = fn2;
		fn2 = fn;
		idx++;
	}
	cout <<"下标对应的斐波那契数为："<< fn << endl;
	return 0;
}