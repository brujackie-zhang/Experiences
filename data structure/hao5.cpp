#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int str[10];
	memset(str, 8, sizeof(str));
	for (int i = 0; i < 10; i ++) {
	// for (int i = 0; i < strlen(str); i ++) {
		cout << str[i] << " ";
	}
	cout << endl;
	return 0;
}