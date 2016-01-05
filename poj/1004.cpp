#include <iostream>

using namespace std;

int main() {
	double total = 0;
	for (int i = 0; i < 12; i++) {
		double x;
		cin >> x;
		total += x;
	}
	printf("$%.2f\n", total / 12);
	return 0;
}