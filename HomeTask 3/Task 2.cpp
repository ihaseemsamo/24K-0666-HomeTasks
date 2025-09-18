#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int price;
    Node* next;
};

class ShoppingCart {
    Node* head;
public:
    ShoppingCart() { head = NULL; }

    void addItemTail(string name, int price) {
        Node* n = new Node{name, price, NULL};
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void deleteFront() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void searchByName(string key) {
        Node* temp = head;
        while (temp) {
            if (temp->name == key) {
                cout << key << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << key << " not found" << endl;
    }

    void searchByPosition(int pos) {
        Node* temp = head;
        int index = 1;
        while (temp) {
            if (index == pos) {
                cout << "Position " << pos << ": " << temp->name << " - $" << temp->price << endl;
                return;
            }
            index++;
            temp = temp->next;
        }
        cout << "No item at position " << pos << endl;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->name << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ShoppingCart cart;
    cart.addItemTail("Laptop", 1000);
    cart.addItemTail("Phone", 700);
    cart.addItemTail("Tablet", 400);
    cart.addItemTail("Headphones", 150);

    cart.display();
    cout << "Deleting first item..." << endl;
    cart.deleteFront();
    cart.display();

    cart.searchByName("Phone");
    cart.searchByPosition(2);

    return 0;
}
