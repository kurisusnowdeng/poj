#include <iostream>

using namespace std;

inline int getlen(int x) {
	int ans = 0;
	while (x > 0) {
		ans++;
		x = x / 10;
	}
	return ans;
}

#define max 2147483647

int main() {
	int t;
	cin >> t;
	for (int j = 0; j < t; j++) {
		int n;
		cin >> n;
		int linelen;
		linelen = 0;
		int k = 0;
		while (n > 0) {
			k++;
			linelen = linelen + getlen(k);
			n -= linelen;
		}
		n += linelen;
		int ans = 0;
		for (int i = 1; i <= k; i++) {
			int numlen = getlen(i);
			if (n > numlen) {
				n -= numlen;
			}
			else {
				n = numlen - n + 1;
				int x = i;
				while (n > 0) {
					ans = x % 10;
					x = x / 10;
					n--;
				}
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
