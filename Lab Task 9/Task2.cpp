#include <iostream>
using namespace std;

class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;
    Node(int k) {
        key = k;
        height = 1;
        left = right = nullptr;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() { root = nullptr; }

    int height(Node* n) {
        if (!n) return 0;
        return n->height;
    }

    int getBalance(Node* n) {
        if (!n) return 0;
        return height(n->left) - height(n->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T = x->right;
        x->right = y;
        y->left = T;
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T = y->left;
        y->left = x;
        x->right = T;
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    Node* insertNode(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key) node->left = insertNode(node->left, key);
        else if (key > node->key) node->right = insertNode(node->right, key);
        else return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void insert(int key) {
        root = insertNode(root, key);
    }

    void inorder(Node* r) {
        if (r) {
            inorder(r->left);
            cout << r->key << " ";
            inorder(r->right);
        }
    }
};

int main() {
    AVLTree t;

    t.insert(50);
    t.insert(30);
    t.insert(70);
    t.insert(20);
    t.insert(40);
    t.insert(60);
    t.insert(80);
    t.insert(55);

    t.root = t.leftRotate(t.root);

    t.inorder(t.root);

    return 0;
}
