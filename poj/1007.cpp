#include <iostream>
#include <string>

using namespace std;

int getsortedness(const string s, int len) {
	int ans = 0;
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (s[i] > s[j]) {
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	string data[110];
	int val[110];
	int idx[110];
	memset(data, 0, sizeof(data));
	memset(val, 0, sizeof(val));
	memset(idx, 0, sizeof(idx));
	int len;
	int n;
	cin >> len >> n;
	for (int i = 0; i < n; i++) {
		cin >> data[i];
		val[i] = getsortedness(data[i], len);
		idx[i] = i;
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (val[j] > val[j + 1]) {
				int temp = val[j];
				val[j] = val[j + 1];
				val[j + 1] = temp;
				temp = idx[j];
				idx[j] = idx[j + 1];
				idx[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << data[idx[i]] << endl;
	}
	return 0;
}