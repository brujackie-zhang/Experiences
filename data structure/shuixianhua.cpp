#include<iostream>
using namespace std;
int main()
{
	int n, m, count;
    while (cin >> n >> m) {
        count = 0;
        for (int i = n; i <= m; i ++) {
              int a = i / 100;
              int b = i % 100 / 10;
              int c = i % 10;
              if (i == a * a *a + b * b * b + c * c *c) {
                   cout << i << " ";
                   count ++;
              }
        }
        if (count == 0) {
                   cout << "no"; 
        }
        cout << endl;
    }
    return 0;
}