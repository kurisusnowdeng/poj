#include <iostream>
#include <math.h>

using namespace std;

int main() {
	double vs, r, c;
	int n;
	cin >> vs >> r >> c >> n;
	for (int i = 0; i < n; i++) {
		double w;
		cin >> w;
		double vr;
		vr = sqrt(1 / (c*c*r*r*w*w + 1)) * vs * c * r * w;
		printf("%.3f\n", vr);
	}
	return 0;
}