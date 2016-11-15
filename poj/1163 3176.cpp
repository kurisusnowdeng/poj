#include <iostream>

using namespace std;

int main() {
	int n;
	int a[400][400];
	int f[400][400];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
			f[i][j] = a[i][j];
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			if (f[i + 1][j] > f[i + 1][j + 1]) {
				f[i][j] += f[i + 1][j];
			}
			else {
				f[i][j] += f[i + 1][j + 1];
			}
		}
	}
	cout << f[1][1] << endl;
	return 0;
}
