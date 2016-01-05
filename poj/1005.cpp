#include <iostream>

using namespace std;

#define PI 3.14159265358979323846

int main() {
	// (pi * R ^ 2 / 2) / 50
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		double r2;
		r2 = x * x + y * y;
		int ans;
		ans = (int)(PI*r2 / 100) + 1;
		printf("Property %d: This property will begin eroding in year %d.\n", i+1, ans);
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}