#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int id) {
        this->id = id;
        left = nullptr;
        right = nullptr;
    }
};

class EmployeeTree {
private:
    Node* root;

    Node* insert(Node* node, int id) {
        if (node == nullptr)
            return new Node(id);

        if (id < node->id)
            node->left = insert(node->left, id);
        else if (id > node->id)
            node->right = insert(node->right, id);

        return node;
    }

    Node* findLCA(Node* node, int id1, int id2) {
        if (node == nullptr)
            return nullptr;

        if (node->id > id1 && node->id > id2)
            return findLCA(node->left, id1, id2);

        if (node->id < id1 && node->id < id2)
            return findLCA(node->right, id1, id2);

        return node; // This node is the LCA
    }

public:
    EmployeeTree() {
        root = nullptr;
    }

    void insert(int id) {
        root = insert(root, id);
    }

    int findClosestCommonManager(int id1, int id2) {
        Node* lca = findLCA(root, id1, id2);
        return (lca != nullptr) ? lca->id : -1;
    }
};

int main() {
    EmployeeTree tree;
    int n, id;

    cout << "Enter number of employees: ";
    cin >> n;

    cout << "Enter employee IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> id;
        tree.insert(id);
    }

    int id1, id2;
    cout << "Enter two employee IDs to find their closest common manager: ";
    cin >> id1 >> id2;

    int manager = tree.findClosestCommonManager(id1, id2);

    if (manager != -1)
        cout << "Closest common manager (Lowest Common Ancestor): " << manager << endl;
    else
        cout << "No common manager found.\n";

    return 0;
}
