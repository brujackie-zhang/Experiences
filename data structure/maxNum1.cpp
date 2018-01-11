#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
	while (1) {
		int *a = new int[1000000];
		int digit = 1;
		int temp, i, j, carry, n;
		cout << "Please input n:" << endl;
		cin >> n;
		a[0] = 1;
		for (i = 2; i <= n; i ++) {
			for (j = 1, carry = 0; j <= digit; j ++) {
				temp = a[j - 1] * i + carry;
				a[j - 1] = temp % 10;
				carry = temp / 10;
			}
			while (carry) {
				a[++ digit - 1] = carry % 10;
				carry = carry / 10;
			}
		}
		cout << "n!= ";
		for (i = digit; i >= 1; i --) {
			cout << a[i - 1];
		}
		cout << endl;
		a[digit] = {0}; 
	}
	return 0;
}