#include <iostream>
#include <stdlib.h>

using namespace std;

int w;
int in_val[2000];
int in_idx[2000];
int out_val[10000];
int out_idx[10000];

const int dx[9] = { -1,-1,-1, 0, 0, 0, 1, 1, 1 };
const int dy[9] = { -1, 0, 1,-1, 0, 1,-1, 0, 1 };

int len;
int in_cnt;
int out_cnt;

int _find(int low, int high, int x) {
	if (low == high) {
		return in_val[low];
	}
	int mid = (low + high) / 2;
	if (x >= in_idx[mid] && x < in_idx[mid + 1])
		return in_val[mid];
	int res = 0;
	if (in_idx[mid + 1] <= x)
		res = _find(mid + 1, high, x);
	if (in_idx[mid] > x)
		res = _find(low, mid - 1, x);
	return res;
}

inline void _swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void _sort(int low, int high) {
	int pivot = out_idx[(low + high) / 2];
	int i = low;
	int j = high;
	while (i <= j) {
		while (out_idx[i] < pivot) ++i;
		while (out_idx[j] > pivot) --j;
		if (i <= j) {
			_swap(out_val[i], out_val[j]);
			_swap(out_idx[i], out_idx[j]);
			++i;
			--j;
		}
	}
	if (low < j) _sort(low, j);
	if (i < high) _sort(i, high);
}

inline void solve(int idx) {
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
					int x = abs(_find(0, in_cnt - 1, idx_1) - _find(0, in_cnt - 1, idx_2));
					if (x > max)
						max = x;
				}
			}
			out_val[out_cnt] = max;
			out_idx[out_cnt] = idx_1;
			out_cnt++;
		}
	}
}

int main() {
	cin >> w;
	while (w > 0) {
		int a, b;
		memset(in_val, 0, sizeof(in_val));
		memset(in_idx, 0, sizeof(in_idx));
		len = 0;
		in_cnt = 0;
		
		cin >> a >> b;
		while (!(a == 0 && b == 0)) {
			in_val[in_cnt] = a;
			in_idx[in_cnt] = len;
			len += b;
			in_cnt++;

			cin >> a >> b;
		}
		in_val[in_cnt] = 0;
		in_idx[in_cnt] = len;

		out_cnt = 0;
		for (int i = 0; i < in_cnt; i++) {
			solve(in_idx[i]);
		}
		solve(len - w);
		solve(len - 1);

		_sort(0, out_cnt - 1);

		cout << w << endl;
		int idx = 0;
		int val = out_val[0];
		for (int i = 1; i < out_cnt; i++) {
			if (out_val[i] != val) {
				printf("%d %d\n", val, out_idx[i] - idx);
				val = out_val[i];
				idx = out_idx[i];
			}
		}

		printf("%d %d\n%d %d\n", val, len - idx, 0, 0);

		cin >> w;
	}

	cout << 0 << endl;

	return 0;
}