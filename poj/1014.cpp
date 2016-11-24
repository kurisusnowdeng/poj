#include <iostream>

using namespace std;

int main() {
	int n[10];
	int w[200];
	bool f[300000];
	int a = 0;
	for (int i = 1; i <= 6; i++) {
		cin >> n[i];
		a = a | n[i];
	}
	int k = 1;
	while (a) {
		printf("Collection #%d:\n", k++);
		memset(w, 0, sizeof(w));
		int total = 0;
		int m = 0;
		for (int i = 1; i <= 6; i++) {
			int x = 1;
			total += n[i] * i;
			while (x <= n[i]) {
				w[m++] = x * i;
				n[i] -= x;
				x = x << 1;
			}
			if (n[i] > 0) {
				w[m++] = n[i] * i;
			}
		}
		if (total % 2 > 0) {
			printf("Can't be divided.\n\n");
		}
		else {
			total = total / 2;
			memset(f, 0, sizeof(f));
			f[0] = true;
			for (int i = 0; i < m; i++) {
				for (int j = total; j >= w[i]; j--) {
					f[j] = f[j] | f[j - w[i]];
				}
			}
			if (f[total]) {
				printf("Can be divided.\n\n");
			}
			else {
				printf("Can't be divided.\n\n");
			}
		}
		a = 0;
		for (int i = 1; i <= 6; i++) {
			cin >> n[i];
			a = a | n[i];
		}
	}

	return 0;
}