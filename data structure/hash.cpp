#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n = 11;
	int a[256] = {0};
	string str= "hello world";
	for (int i = 0; i < n; i ++) {
		a[str[i]] ++;
		if (a[str[i]] > 1) {
			cout << str[i] << endl;
			break;
		}
	}
	return 0;
}