#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
	double ans = 0;
	double i = 1;
	int n[600];
	memset(n, 0, sizeof(n));
	while (ans < 5.21) {
		ans = ans + 1 / (i + 1);
		//printf("%d, %.5f, %d\n", (int)i, ans, (int)floor(ans * 100));
		int k = (int)floor(ans * 100);
		if (n[k] == 0) n[k] = (int)i;
		i = i + 1;
	}
	int x = n[521];
	for (int k = 520; k > 0; k--) {
		if (n[k] == 0) {
			n[k] = x; 
		}
		else {
			x = n[k];
		}
	}
	double c;
	int j;
	while (cin >> c) {
		if (c == 0) break;
		j = (int)floor(c * 100);
		cout << n[j] << " card(s)"<< endl;
	}
	return 0;
}
