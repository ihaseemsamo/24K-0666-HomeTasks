#include <iostream>
#include <string>
using namespace std;

class TourNode {
public:
    string packageName;
    TourNode* left;
    TourNode* right;

    TourNode(string name) {
        packageName = name;
        left = NULL;
        right = NULL;
    }
};

class TourTree {
private:
    TourNode* root;

    TourNode* findPackage(TourNode* node, string name) {
        if (node == NULL)
            return NULL;
        if (node->packageName == name)
            return node;
        TourNode* found = findPackage(node->left, name);
        if (found != NULL)
            return found;
        return findPackage(node->right, name);
    }

    void printTree(TourNode* node, int level) {
        if (node == NULL)
            return;
        for (int i = 0; i < level; i++)
            cout << "   ";
        cout << "- " << node->packageName << endl;
        printTree(node->left, level + 1);
        printTree(node->right, level + 1);
    }

public:
    TourTree() {
        root = NULL;
    }

    void createRoot(string name) {
        if (root == NULL) {
            root = new TourNode(name);
            cout << "Root package '" << name << "' created successfully.\n";
        } else {
            cout << "Root already exists!\n";
        }
    }

    void addPackage(string parentName, string childName, bool isLeft) {
        if (root == NULL) {
            cout << "Tree is empty! Please create the root package first.\n";
            return;
        }
        TourNode* parent = findPackage(root, parentName);
        if (parent == NULL) {
            cout << "Parent package not found!\n";
            return;
        }
        if (isLeft) {
            if (parent->left == NULL)
                parent->left = new TourNode(childName);
            else {
                cout << "Left child already exists for " << parentName << "!\n";
                return;
            }
        } else {
            if (parent->right == NULL)
                parent->right = new TourNode(childName);
            else {
                cout << "Right child already exists for " << parentName << "!\n";
                return;
            }
        }
        cout << "Package '" << childName << "' added successfully under '" 
             << parentName << "'.\n";
    }

    void displayTree() {
        if (root == NULL) {
            cout << "No tour packages available!\n";
            return;
        }
        cout << "\nTour Packages Hierarchy:\n";
        printTree(root, 0);
    }
};

class TourSystem {
private:
    TourTree tourTree;

public:
    void run() {
        int choice;
        string parent, child;
        bool isLeft;

        do {
            cout << "\nTour Package Management System\n";
            cout << "1. Create Root Package\n";
            cout << "2. Add Sub-Package\n";
            cout << "3. Display Package Hierarchy\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Enter root package name: ";
                cin.ignore();
                getline(cin, parent);
                tourTree.createRoot(parent);
                break;
            case 2:
                cout << "Enter parent package name: ";
                cin.ignore();
                getline(cin, parent);
                cout << "Enter new sub-package name: ";
                getline(cin, child);
                cout << "Add as Left child? (1 for Yes, 0 for No): ";
                cin >> isLeft;
                tourTree.addPackage(parent, child, isLeft);
                break;
            case 3:
                tourTree.displayTree();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    TourSystem system;
    system.run();
    return 0;
}
