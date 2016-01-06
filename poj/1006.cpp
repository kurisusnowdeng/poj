#include <iostream>

using namespace std;

int main() {
	int p, e, i, d;
	cin >> p >> e >> i >> d;
	int cnt = 0;
	while (p >= 0) {
		cnt++;
		int ans = 0;
		for (int j = 1; j <= 21252; j++) {
			int x = (d + j - p) % 23;
			int y = (d + j - e) % 28;
			int z = (d + j - i) % 33;
			if (x == 0 && y == 0 && z == 0) {
				ans = j;
				break;
			}
		}
		printf("Case %d: the next triple peak occurs in %d days.\n", cnt, ans);
		cin >> p >> e >> i >> d;
	}
	return 0;
}