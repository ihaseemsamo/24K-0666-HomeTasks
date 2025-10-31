#include <iostream>
using namespace std;

class Node {
private:
    int productID;
    int quantity;
    Node* left;
    Node* right;

public:
    Node(int id, int qty) {
        productID = id;
        quantity = qty;
        left = NULL;
        right = NULL;
    }

    int getID() { return productID; }
    int getQuantity() { return quantity; }
    void setQuantity(int qty) { quantity = qty; }

    Node* getLeft() { return left; }
    Node* getRight() { return right; }
    void setLeft(Node* node) { left = node; }
    void setRight(Node* node) { right = node; }

    friend class BinarySearchTree;
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertNode(Node* node, int id, int qty) {
        if (node == NULL) {
            return new Node(id, qty);
        }
        if (id < node->productID) {
            node->left = insertNode(node->left, id, qty);
        } else if (id > node->productID) {
            node->right = insertNode(node->right, id, qty);
        } else {
            node->quantity = qty; // update if already exists
        }
        return node;
    }

    Node* searchNode(Node* node, int id) {
        if (node == NULL || node->productID == id) {
            return node;
        }
        if (id < node->productID) return searchNode(node->left, id);
        return searchNode(node->right, id);
    }

    Node* findMaxNode(Node* node) {
        if (node == NULL) return NULL;
        while (node->right != NULL) {
            node = node->right;
        }
        return node;
    }

    void display(Node* node) {
        if (node == NULL) return;
        display(node->left);
        cout << "Product ID: " << node->productID << ", Quantity: " << node->quantity << endl;
        display(node->right);
    }

public:
    BinarySearchTree() {
        root = NULL;
    }

    void insert(int id, int qty) {
        root = insertNode(root, id, qty);
    }

    Node* search(int id) {
        return searchNode(root, id);
    }

    Node* findMax() {
        return findMaxNode(root);
    }

    void displayTree() {
        if (root == NULL) {
            cout << "No products available.\n";
            return;
        }
        display(root);
    }

    bool isEmpty() {
        return root == NULL;
    }
};

class ProductManagementSystem {
private:
    BinarySearchTree bst;

public:
    void run() {
        int choice, productID, quantity;
        do {
            cout << "\n Product Management System \n";
            cout << "1. Add/Update Product\n";
            cout << "2. Search for a Product\n";
            cout << "3. Find Product with Highest ID\n";
            cout << "4. Display All Products\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter product ID: ";
                    cin >> productID;
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    bst.insert(productID, quantity);
                    cout << "Product added or updated successfully.\n";
                    break;

                case 2:
                    cout << "Enter product ID to search: ";
                    cin >> productID;
                    {
                        Node* product = bst.search(productID);
                        if (product == NULL)
                            cout << "Product not found.\n";
                        else
                            cout << "Product ID: " << product->getID() 
                                 << ", Quantity: " << product->getQuantity() << endl;
                    }
                    break;

                case 3:
                    {
                        Node* maxProduct = bst.findMax();
                        if (maxProduct == NULL)
                            cout << "No products available.\n";
                        else
                            cout << "Product with highest ID -> Product ID: " 
                                 << maxProduct->getID() << ", Quantity: " 
                                 << maxProduct->getQuantity() << endl;
                    }
                    break;

                case 4:
                    bst.displayTree();
                    break;

                case 5:
                    cout << "Exiting...\n";
                    break;

                default:
                    cout << "Invalid choice.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    ProductManagementSystem system;
    system.run();
    return 0;
}
