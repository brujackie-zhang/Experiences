#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;

int main()
{
	string str;
	long a[1000000];
	while (cin >> str) {
		long sum = 0;
		int len = str.length();
		int n = len;
		for (int i = 0; i < len; i ++) {
			a[i] = str[i] - 'a';
		}
		for (int j = 0; j < len; j ++) {
			sum += a[j] * pow(26, n - 1);
			n = n - 1;
		}
		cout << sum << endl;
	}
}