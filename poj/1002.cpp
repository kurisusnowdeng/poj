#include <iostream>
#include <string>

using namespace std;

typedef struct node {
	node *left, *right, *parent;
	int val, cnt;
};

node *root;
int total;

const int convert[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1 };

int left_rotate(node *x) {
	node *y = x->right;
	if (y != NULL) {
		x->right = y->left;
		if (y->left != NULL) {
			y->left->parent = x;
		}
		y->parent = x->parent;
	}
	if (x->parent == NULL) {
		root = y;
	}
	else if (x->parent->left == x) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	if (y != NULL) {
		y->left = x;
	}
	x->parent = y;
	return 0;
}

int right_rotate(node *x) {
	node *y = x->left;
	if (y != NULL) {
		x->left = y->right;
		if (y->right != NULL) {
			y->right->parent = x;
		}
		y->parent = x->parent;
	}
	if (x->parent == NULL) {
		root = y;
	}
	else if (x->parent->left == x) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	if (y != NULL) {
		y->right = x;
	}
	x->parent = y;
	return 0;
}

int splay(node *x) {
	while (x->parent != NULL) {
		if (x->parent->parent == NULL) {
			if (x->parent->left == x) {
				right_rotate(x->parent);
			}
			else {
				left_rotate(x->parent);
			}
		}
		else if (x->parent->left == x && x->parent->parent->left == x->parent) {
			right_rotate(x->parent->parent);
			right_rotate(x->parent);
		}
		else if (x->parent->right == x && x->parent->parent->right == x->parent) {
			left_rotate(x->parent->parent);
			left_rotate(x->parent);
		}
		else if (x->parent->left == x && x->parent->parent->right == x->parent) {
			right_rotate(x->parent);
			left_rotate(x->parent);
		}
		else if (x->parent->right == x && x->parent->parent->left == x->parent) {
			left_rotate(x->parent);
			right_rotate(x->parent);
		}
	}
	return 0;
}

int insert(int key) {
	node *x = root;
	node *p = NULL;
	while (x != NULL) {
		p = x;
		if (key == x->val) {
			x->cnt++;
			return 0;
		}
		else if (key < x->val) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	x = new node;
	x->left = NULL; x->right = NULL; x->parent = p;
	x->val = key; x->cnt = 1;
	if (p == NULL) { 
		root = x;
	}
	else if (key < p->val) {
		p->left = x;
	}
	else {
		p->right = x;
	}
	splay(x);
	return 0;
}

int getPhoneNum(int a) {
	cout << a / 1000000;
	a = a % 1000000;
	cout << a / 100000;
	a = a % 100000;
	cout << a / 10000;
	a = a % 10000;
	cout << "-";
	cout << a / 1000;
	a = a % 1000;
	cout << a / 100;
	a = a % 100;
	cout << a / 10;
	a = a % 10;
	cout << a;
	return 0;
}

int print(node *x) {
	if (x == NULL) return 0;
	if (x->left != NULL) print(x->left);
	if (x->cnt > 1) {
		getPhoneNum(x->val);
		cout << " " << x->cnt << endl;
		total++;
	}
	if (x->right != NULL) print(x->right);
	return 0;
}

int main() {
	root = NULL;
	int n, key;
	string s;
	bool error;
	cin >> n;
	for (int i = 0; i < n; i++) {
		error = true;
		cin >> s;
		key = 0;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] >= '0' && s[j] <= '9') {
				key = key * 10 + s[j] - 48;
			}
			else if (s[j] >= 'A' && s[j] <= 'Y' && s[j] != 'Q') {
				key = key * 10 + convert[s[j] - 65];
			}
			else if (s[j] == '-' || s[j] == ' ') {
				continue;
			}
			else {
				error = false;
				break;
			}
		}
		if (error) insert(key);
	}
	total = 0;
	print(root);
	if (total == 0) {
		cout << "No duplicates. " << endl;
	}
	return 0;
}