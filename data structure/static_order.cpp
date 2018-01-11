#include <iostream>
#define MAXSIZE 10
using namespace std;

void insertElement(int sqlist[], int *len, int i, int x)
{
	int t;
	if (*len = MAXSIZE || i < 1 || i > (*len + 1)) {
		cout << endl << "insert illegal!" << i << endl;
	}
	for (t = *len - 1; t >= i - 1; t--) {
		sqlist[t + 1] = sqlist[t];
	}
	sqlist[i - 1] = x;
	*len = *len + 1; 
}

void delElement(int sqlist[], int *len, int i)
{
	int t;
	if (i < 1 || i > (*len + 1)) {
		cout << "delete illegal!" << i << endl;
	}
	for (t = i; t < *len -1; t ++) {
		sqlist[t - 1] = sqlist[t];
	}
	*len = *len - 1;
}

int main()
{
	int sqlist[MAXSIZE];
	int len, i;
	cout << "please input six integer number:" << endl;
	for (i = 0; i < 6; i ++) {
		cin >> sqlist[i];
	}
	len = 6;
	cout << "before order:" << endl;
	for (i = 0; i < len; i ++) {
		cout << sqlist[i] << " ";
	}
	insertElement(sqlist, &len, 3, 0);
	cout << "after insert order:" << endl;
	for (i = 0; i < len; i ++) {
		cout << sqlist[i] << " ";
	}
	insertElement(sqlist, &len, 11, 11);
	delElement(sqlist, &len, 6);
	cout << "after delete order:" << endl;
	for (i = 0; i < len; i ++) {
		cout << sqlist[i] << " ";
	}
	return 0;
}
