#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef struct rec {
	vector<int> val;
	int dif;
	int size;
};

vector<int> stamp_val;
static int _size;
vector<rec> result;

void _insert(rec item) {
	if (!result.empty()) {
		rec best = result[0];
		if (item.dif > best.dif ||
			(item.dif == best.dif && item.size < best.size) ||
			(item.dif == best.dif && item.size == best.size &&
				item.val.back() > best.val.back())) {
			result.clear();
			result.push_back(item);
		}
		else if (item.dif == best.dif && item.size == best.size &&
					item.val.back() == best.val.back()) {
			result.push_back(item);
		}
	}
	else {
		result.push_back(item);
	}
}

void dfs(int dep, int k, int total, rec buff) {
	if (dep == 4 || total <= 0) {
		if (total == 0) {
			_insert(buff);
		}
		return;
	}
	rec newbuff = buff;
	for (int i = k; i < _size; i++) {
		if (i < 0) continue;
		newbuff.val.push_back(stamp_val[i]);
		newbuff.size++;
		if (i > k) {
			newbuff.dif++;
		}
		dfs(dep + 1, i, total - stamp_val[i], newbuff);
		newbuff.val.pop_back();
		newbuff.size--;
		if (i > k) {
			newbuff.dif--;
		}
	}
}

void _print(int need) {
	if (result.empty()) {
		printf("%d ---- none\n", need);
	}
	else {
		rec best = result[0];
		printf("%d (%d):", need, best.dif);
		if (result.size() > 1) {
			printf(" tie\n");
		}
		else {
			for (int i = 0; i < best.size; i++) {
				printf(" %d", best.val[i]);
			}
			printf("\n");
		}
	}
}

int main() {
	int x, y;
	while (scanf("%d", &x) != EOF) {
		stamp_val.clear();
		map<int, int> hash;
		hash.clear();
		while (x > 0) {
			if (hash[x] < 4) {
				stamp_val.push_back(x);
				hash[x]++;
			}
			scanf("%d", &x);
		}
		_size = stamp_val.size();
		sort(stamp_val.begin(), stamp_val.end());

		scanf("%d", &y);
		while (y > 0) {
			result.clear();
			rec buff;
			buff.val.clear();
			buff.dif = 0;
			buff.size = 0;
			dfs(0, -1, y, buff);
			_print(y);
			scanf("%d", &y);
		}
	}
	return 0;
}
