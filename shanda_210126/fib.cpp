#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	int n;
	cout << "���������е��±꣺";
	cin >> n;
	//�������ֵΪ0��1����ֱ�����쳲��������
	if (n == 0 || n == 1) {
		cout << n << endl;
		return 0;
	}
	int fn1 = 0;
	int fn2 = 1;
	int idx = 2;   //������ʾĿǰ��쳲��������е�����
	int fn;
	while (idx <= n) {
		fn = fn1 + fn2;
		fn1 = fn2;
		fn2 = fn;
		idx++;
	}
	cout <<"�±��Ӧ��쳲�������Ϊ��"<< fn << endl;
	return 0;
}