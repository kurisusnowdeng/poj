#include <iostream>

using namespace std;

int main() {
	int n;
	char s[5000];
	int f1[5000], f2[5000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	memset(f1, 0, sizeof(f1));
	memset(f2, 0, sizeof(f2));
	for (int i = 1; i < n; i++) {
		f2[i] = 0;
		if (s[i - 1] == s[i]) {
			f2[i - 1] = 0;
		}
		else {
			f2[i - 1] = 1;
		}
		for (int j = i - 2; j >= 0; j--) {
			if (s[j] == s[i]) {
				f2[j] = f1[j + 1];
			}
			else {
				if (f1[j] < f2[j + 1]) {
					f2[j] = f1[j] + 1;
				}
				else {
					f2[j] = f2[j + 1] + 1;
				}
			}
		}
		for (int j = i; j >= 0; j--) {
			f1[j] = f2[j];
		}
	}
	cout << f2[0] << endl;
	return 0;
}