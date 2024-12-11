#include <iostream>
#include <algorithm>
using namespace std;

int main () {
	// Step #1. Input
	long long N;
	cin >> N;

	// Step # 2. Ask for an answer
	// Note that in C ++, a / b becomes the "quotient of a / b (rounded down to the nearest whole number)" given that there are integer types a and b.
	// (1LL << i) means 2 to the i-th power
	long long Answer = (1LL << 45);
	for (int i = 0; i <= 45; i++) {
		long long a = N / (1LL << i);
		long long b = i;
		long long c = N - a * (1LL << i);
		Answer = min(Answer, a + b + c);
	}

	// Step #3. Contribute
	cout << Answer << endl;
	return 0;
}
