#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	int f[210][30][810];
	int q[20000][3];
	int p[300], d[300];
	int res[30];
	int n, m;
	cin >> n >> m;
	int t = 0;
	int len = 20000;
	int zero = 400;
	while (n && m) {
		memset(f, 0xff, sizeof(f));
		memset(q, 0, sizeof(q));
		memset(p, 0, sizeof(p));
		memset(d, 0, sizeof(d));
		memset(res, 0, sizeof(res));
		for (int i = 1; i <= n; i++) {
			cin >> p[i] >> d[i];
		}
		int head = 0;
		int tail = 1;
		q[1][0] = 0;
		q[1][1] = 0;
		q[1][2] = zero;
		f[0][0][zero] = 0;
		while (head != tail) {
			head = (head + 1) % len;
			int i = q[head][0];
			int j = q[head][1];
			int k = q[head][2];
			if (i + 1 <= n) {
				if (f[i + 1][j][k] < 0 || f[i][j][k] > f[i + 1][j][k]) {
					if (f[i + 1][j][k] < 0) {
						tail = (tail + 1) % len;
						q[tail][0] = i + 1;
						q[tail][1] = j;
						q[tail][2] = k;
					}
					f[i + 1][j][k] = f[i][j][k];
				}
				if (j + 1 <= m && (f[i + 1][j + 1][k + p[i + 1] - d[i + 1]] < 0 ||
					f[i + 1][j + 1][k + p[i + 1] - d[i + 1]] < f[i][j][k] + p[i + 1] + d[i + 1])) {
					if (f[i + 1][j + 1][k + p[i + 1] - d[i + 1]] < 0) {
						tail = (tail + 1) % len;
						q[tail][0] = i + 1;
						q[tail][1] = j + 1;
						q[tail][2] = k + p[i + 1] - d[i + 1];
					}
					f[i + 1][j + 1][k + p[i + 1] - d[i + 1]] = f[i][j][k] + p[i + 1] + d[i + 1];
				}
			}
		}
		int ans = 0;
		while (f[n][m][zero + ans] < 0 && f[n][m][zero - ans] < 0) {
			ans++;
		}
		if (f[n][m][zero - ans] > f[n][m][zero + ans]) {
			ans = -ans;
		}
		int j = m;
		int k = zero + ans;
		for (int i = n; i > 0; i--) {
			if (f[i][j][k] != f[i - 1][j][k]) {
				res[j] = i;
				j--;
				k -= p[i] - d[i];
			}
		}
		int sump = 0;
		int sumd = 0;
		for (int i = 1; i <= m; i++) {
			sump += p[res[i]];
			sumd += d[res[i]];
		}
		printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n", ++t, sump, sumd);
		for (int i = 1; i <= m; i++) {
			printf(" %d", res[i]);
		}
		printf("\n");

		cin >> n >> m;
	}
	return 0;
}