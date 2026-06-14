#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;

    Node(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int diameter = 0;

int height(Node* node) {
    if (node == nullptr)
        return -1;

    int L = height(node->left);
    int R = height(node->right);

    diameter = max(diameter, L + R + 2);

    return max(L, R) + 1;
}

int main() {
    int n;

    cout << "Masukkan jumlah node: ";
    cin >> n;

    Node* root = nullptr;

    cout << "Masukkan " << n << " nilai node:\n";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    height(root);

    cout << "Diameter Binary Tree = " << diameter << endl;

    return 0;
}