#include <iostream>
#include <string>
using namespace std;

class Node {
private:
    string data;
    Node* left;
    Node* right;

public:
    Node(string val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    string getData() { return data; }
    Node* getLeft() { return left; }
    Node* getRight() { return right; }

    void setLeft(Node* node) { left = node; }
    void setRight(Node* node) { right = node; }

    friend class BinaryTree;
};

class BinaryTree {
private:
    Node* root;

    Node* find(Node* node, string val) {
        if (!node) return NULL;
        if (node->data == val) return node;
        Node* leftRes = find(node->left, val);
        if (leftRes) return leftRes;
        return find(node->right, val);
    }

    int countNodes(Node* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    int countLeaves(Node* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        return countLeaves(node->left) + countLeaves(node->right);
    }

    int height(Node* node) {
        if (!node) return 0;
        int leftH = height(node->left);
        int rightH = height(node->right);
        return 1 + (leftH > rightH ? leftH : rightH);
    }

public:
    BinaryTree() {
        root = NULL;
    }

    void createRoot(string val) {
        if (!root) {
            root = new Node(val);
            cout << "Root created.\n";
        } else {
            cout << "Root already exists.\n";
        }
    }

    void addNode(string parentVal, string childVal, bool isLeft) {
        if (!root) {
            cout << "Create root first.\n";
            return;
        }
        Node* parent = find(root, parentVal);
        if (!parent) {
            cout << "Parent not found.\n";
            return;
        }
        if (isLeft) {
            if (!parent->left) {
                parent->left = new Node(childVal);
                cout << "Left child added successfully.\n";
            } else cout << "Left child already exists.\n";
        } else {
            if (!parent->right) {
                parent->right = new Node(childVal);
                cout << "Right child added successfully.\n";
            } else cout << "Right child already exists.\n";
        }
    }

    void displayProperties() {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }
        cout << "Total nodes: " << countNodes(root) << endl;
        cout << "Leaf nodes: " << countLeaves(root) << endl;
        cout << "Height of tree: " << height(root) << endl;
    }
};

class BinaryTreeApp {
private:
    BinaryTree tree;

public:
    void run() {
        int choice;
        string parent, child;
        bool isLeft;

        do {
            cout << "\nBinary Tree Data Analysis\n";
            cout << "1. Create Root\n";
            cout << "2. Add Node\n";
            cout << "3. Display Properties\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter root data: ";
                    cin.ignore();
                    getline(cin, parent);
                    tree.createRoot(parent);
                    break;
                case 2:
                    cout << "Enter parent data: ";
                    cin.ignore();
                    getline(cin, parent);
                    cout << "Enter child data: ";
                    getline(cin, child);
                    cout << "Add as left child? (1 for yes, 0 for no): ";
                    cin >> isLeft;
                    tree.addNode(parent, child, isLeft);
                    break;
                case 3:
                    tree.displayProperties();
                    break;
                case 4:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    BinaryTreeApp app;
    app.run();
    return 0;
}
