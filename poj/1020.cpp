#include <iostream>

using namespace std;

int s;
int n;
int w[20];
int map[50];

int minrow() {
	int min = 0;
	for (int i = 1; i < s; i++) {
		if (map[i] < map[min])
			min = i;
	}
	return min;
}

bool dfs(int dep) {
	if (dep == n)
		return true;
	int r = minrow();
	for (int i = 10; i > 0; i--) {
		if (w[i] && r + i <= s) {
			bool empty = true;
			for (int j = r; j < r + i; j++) {
				if (map[j] + i > s) {
					empty = false;
					break;
				}
			}
			if (empty) {
				for (int j = r; j < r + i; j++) {
					map[j] += i;
				}
				w[i]--;
				if (dfs(dep + 1))
					return true;
				w[i]++;
				for (int j = r; j < r + i; j++) {
					map[j] -= i;
				}
			}
		}
	}
	return false;
}

bool solve() {
	int sum = 0;
	for (int i = 1; i <= 10; i++) {
		sum += w[i] * i * i;
	}
	if (s * s != sum) {
		return false;
	}
	memset(map, 0, sizeof(map));
	return dfs(0);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(w, 0, sizeof(w));
		cin >> s >> n;
		int x;
		for (int j = 0; j < n; j++) {
			cin >> x;
			w[x]++;
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
