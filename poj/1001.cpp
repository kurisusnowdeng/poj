#include <iostream>
#include <math.h>
#include <string>

using namespace std;

const int MaxLen = 200;

typedef struct Num {
	int val[MaxLen];
	int dot;
	int len;
};

Num ToReal(const string s) {
	Num res;
	memset(&res, 0, sizeof(res));
	int k = s.length();
	for (int i = s.length(); i > 0; i--) {
		if (s[i - 1] == '.') {
			res.dot = s.length() - i;
		}
		else {
			res.val[res.len] = s[i - 1] - 48;
			res.len++;
		}
	}
	
	while (res.val[res.len - 1] == 0) {
		res.len--;
	}
	return res;
}

Num multi(Num a, const Num r) {
	Num res;
	memset(&res, 0, sizeof(res));
	res.len = a.len + r.len - 1;
	res.dot = a.dot + r.dot;
	for (int i = 0; i < a.len; i++) {
		for (int j = 0; j < r.len; j++) {
			res.val[i + j] = res.val[i + j] + a.val[i] * r.val[j];
		}
	}
	for (int i = 0; i < res.len; i++) {
		res.val[i + 1] = res.val[i + 1] + res.val[i] / 10;
		res.val[i] = res.val[i] % 10;
	}
	while (res.val[res.len] > 0) {
		res.val[res.len + 1] = res.val[res.len + 1] + res.val[res.len] / 10;
		res.val[res.len] = res.val[res.len] % 10;
		res.len++;
	}
	return res;
}

int print(const Num res) {
	int k = res.len;
	if (res.dot > res.len) k = res.dot;
	int j = 0;
	while (j < res.dot && res.val[j] == 0) {
		j++;
	}
	for (int i = k; i > j; i--) {
		if (i == res.dot) {
			cout << '.';
		}
		cout << res.val[i - 1];
	}
	cout << endl;
	return 0;
}

int main() {
	Num ans, r;
	string s;
	int n;
	char c;
	while (cin >> s >> n) {
		memset(&ans, 0, sizeof(ans));
		r = ToReal(s);
		ans.val[0] = 1; ans.len = 1; ans.dot = 0;
		for (int i = 0; i < n; i++) {
			ans = multi(ans, r);
		}
		print(ans);
	}
	return 0;
}

