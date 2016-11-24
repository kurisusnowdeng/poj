#include <iostream>

using namespace std;

int map[200][200];
int n;

int main() {
	memset(map, 0, sizeof(map));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			map[i][j] += map[i - 1][j];
		}
	}
	int f[200][200];
	memset(f, 0, sizeof(f));
	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < i; k++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = map[i][j] - map[k][j];
				if (f[i][j - 1] > 0) {
					f[i][j] += f[i][j - 1];
				}
				if (f[i][j] > max) {
					max = f[i][j];
				}
			}
		}
	}
	cout << max;
	return 0;
}