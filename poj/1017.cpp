#include <iostream>

using namespace std;

int main() {
	int a, b, c, d, e, f, n;
	cin >> a >> b >> c >> d >> e >> f;
	while (a > 0 || b > 0 || c > 0 || d > 0 || e > 0 || f > 0) {
		n = f + e + d + (c / 4);
		int x = b;
		if (c % 4 > 0) {
			n++;
			x -= 6 - ((c % 4) * 2 - 1);
			if (x < 0) x = 0;
		}
		if (x > 0) x -= d * 5;
		if (x < 0) x = 0;
		if (x > 0) {
			n += x / 9;
			if (x % 9 > 0) n++;
		}
		int y = a;
		y -= n * 36 - f * 36 - e * 25 - d * 16 - c * 9 - b * 4;
		if (y < 0) y = 0;
		if (y > 0) {
			n += y / 36;
			if (y % 36 > 0) n++;
		}
		printf("%d\n", n);
		cin >> a >> b >> c >> d >> e >> f;
	}
	return 0;
}
