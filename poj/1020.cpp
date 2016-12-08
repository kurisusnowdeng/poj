#include <iostream>

using namespace std;

int s;
int n;
int w[20];
int x[20];
int y[20];

bool dfs(int dep) {
	if (dep == n)
		return true;
	for (int i = 0; i < s; i++) {
		if (i + w[dep] > s)
			break;
		for (int j = 0; j < s; j++) {
			if (j + w[dep] > s)
				continue;
			bool empty = true;
			for (int k = 0; k < dep; k++) {
				if (!(x[k] >= i + w[dep] || y[k] >= j + w[dep] ||
					i >= x[k] + w[k] || j >= y[k] + w[k])) {
					empty = false;
					break;
				}
			}
			if (empty) {
				x[dep] = i;
				y[dep] = j;
				if (dfs(dep + 1))
					return true;
			}
		}
	}
	return false;
}

bool solve() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += w[i] * w[i];
	}
	if (s * s != sum) {
		return false;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (w[i] < w[j]) {
				int temp = w[i];
				w[i] = w[j];
				w[j] = temp;
			}
		}
	}
	memset(x, 0xff, sizeof(x));
	memset(y, 0xff, sizeof(y));
	return dfs(0);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(w, 0, sizeof(w));
		cin >> s >> n;
		for (int j = 0; j < n; j++) {
			cin >> w[j];
		}
		if (solve()) {
			printf("KHOOOOB!\n");
		}
		else {
			printf("HUTUTU!\n");
		}
	}
	return 0;
}