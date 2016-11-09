#include <iostream>

using namespace std;

int res[15];

int execute(int k) {
	int m = k + 1;
	while (true) {
		int rest = k + k;
		int p = (m - 1) % rest;
		while (p >= k) {
			rest--;
			if (rest == k) {
				break;
			}
			p = (p + m - 1) % rest;
		}
		if (rest == k) {
			return m;
		}
		m++;
	}
}

int main() {
	memset(res, 0, sizeof(res));
	for (int i = 1; i < 14; i++) {
		res[i] = execute(i);
	}
	int k;
	scanf("%d", &k);
	while (k > 0) {
		printf("%d\n", res[k]);
		scanf("%d", &k);
	}
	return 0;
}