#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n)
{
	if (n < 2) {
		cout << "number error!\n";
	}
	for (int i = 2; i <= sqrt(n); i ++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n) {
		if (isPrime(n)) {
			cout << n << " is prime!\n";
		} else {
			cout << n << " is not prime!\n";
		}
	}
}