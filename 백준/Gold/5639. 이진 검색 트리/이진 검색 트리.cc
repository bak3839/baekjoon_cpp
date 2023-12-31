#include <iostream>
#include <vector>

using namespace std;

typedef struct Node{
    int n;
    Node* left;
    Node* right;
}Node;

Node* makeNode(int n) {
    Node* node = new Node;
    node->n = n;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(Node* &node, int n) {
    if (node == NULL) {
        node = makeNode(n);
        return;
    }

    if (node->n > n && node->left == NULL) {
        node->left = makeNode(n);
        return;
    }

    else if (node->n > n && node->left != NULL) insert(node->left, n);

    if (node->n < n && node->right == NULL) {
        node->right = makeNode(n);
        return;
    }

    else if (node->n < n && node->right != NULL) insert(node->right, n);
}

void PostOrder(Node* node) {
    if (node == NULL) return;

    PostOrder(node->left);
    PostOrder(node->right);
    cout << node->n << "\n";
}

void Solution() {
    Node* root = NULL;
    int num;

    while (cin >> num) {
        if (num == cin.eof()) break;

        insert(root, num);
    }

    PostOrder(root);
}

void Solve() {
    Solution();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Solve();
    return 0;
}
