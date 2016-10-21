#include <iostream>
#include <stdlib.h>

using namespace std;

int _find(const int val[], const int idx[], int n, int x) {

	return 0;
}

void _sort(int val[], int idx[], int low, int high) {

}

int main() {
	int w;
	int in_val[2000];
	int in_idx[2000];
	int out_val[10000];
	int out_idx[10000];

	int dx[9] = { -1,-1,-1, 0, 0, 0, 1, 1, 1 };
	int dy[9] = { -1, 0, 1,-1, 0, 1,-1, 0, 1 };

	cin >> w;
	while (w > 0) {
		cout << w << endl;

		int a, b;
		memset(in_val, 0, sizeof(in_val));
		memset(in_idx, 0, sizeof(in_idx));
		int len = 0;
		int cnt = 0;
		
		cin >> a >> b;
		while (!(a == 0 && b == 0)) {
			in_val[cnt] = a;
			in_idx[cnt] = len;
			len += b;
			cnt++;

			cin >> a >> b;
		}

		int tot = 0;
		for (int i = 0; i < cnt; i++) {
			int idx = in_idx[i];
			int row = idx / w;
			int col = idx % w;
			for (int k = 0; k < 9; k++) {
				if (row + dx[k] >= 0 && row + dx[k] < len / w
					&& col + dy[k] >= 0 && col + dy[k] < w) {
					int idx_1 = (row + dx[k]) * w + col + dy[k];
					int max = 0;
					for (int j = 0; j < 9; j++) {
						if (row + dx[k] + dx[j] >= 0 && row + dx[k] + dx[j] < len / w
							&& col + dy[k] + dy[j] >= 0 && col + dy[k] + dy[j] < w) {
							int idx_2 = (row + dx[k] + dx[j]) * w + col + dy[k] + dy[j];
							int x = abs(_find(in_val, in_idx, cnt, idx_1) - _find(in_val, in_idx, cnt, idx_2));
							if (x > max)
								max = x;
						}
					}
					out_val[tot] = max;
					out_val[tot] = idx_1;
					tot++;
				}
			}
		}
		_sort(out_val, out_idx, 0, tot - 1);


		printf("%d %d\n", 0, 0);
		cin >> w;
	}

	cout << 0 << endl;
	return 0;
}