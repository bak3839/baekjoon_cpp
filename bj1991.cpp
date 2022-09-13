#include <iostream>
#include <vector>

using namespace std;

pair<int, int> tree[26];

void preorder(char ch) { // 전위
	if (ch == '.') return;
	cout << ch;
	preorder(tree[ch - 'A'].first);
	preorder(tree[ch - 'A'].second);
}

void inorder(char ch) { // 중위
	if (ch == '.') return;
	inorder(tree[ch - 'A'].first);
	cout << ch;
	inorder(tree[ch - 'A'].second);
}

void postorder(char ch) { // 후위
	if (ch == '.') return;
	postorder(tree[ch - 'A'].first);
	postorder(tree[ch - 'A'].second);
	cout << ch;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	char parent, left, right;
	
	cin >> N;
	for (int i = 0; i < N; i++) { // pair<int, int> tree[26];
		cin >> parent >> left >> right;
		tree[parent - 'A'].first = left;
		tree[parent - 'A'].second = right;
	}

	cout << "전위: ";
	preorder('A');
	cout << "\n\n";

	cout << "중위: ";
	inorder('A');
	cout << "\n\n";

	cout << "후위: ";
	postorder('A');
	cout << "\n";
	return 0;
}