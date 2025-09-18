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

    void insertFront(string name, int price) {
        Node* n = new Node{name, price, head};
        head = n;
    }

    void insertEnd(string name, int price) {
        Node* n = new Node{name, price, NULL};
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void insertAfter(string key, string name, int price) {
        Node* temp = head;
        while (temp && temp->name != key) temp = temp->next;
        if (temp) {
            Node* n = new Node{name, price, temp->next};
            temp->next = n;
        }
    }

    void search(string key) {
        Node* temp = head;
        while (temp) {
            if (temp->name == key) {
                cout << key << " found with price $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << key << " not found" << endl;
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
    cart.insertEnd("Laptop", 1000);
    cart.insertEnd("Phone", 700);
    cart.insertEnd("Tablet", 400);
    cart.insertEnd("Headphones", 150);

    cart.insertFront("Smartwatch", 200);
    cart.insertEnd("Keyboard", 80);
    cart.insertAfter("Phone", "Monitor", 300);

    cart.search("Tablet");
    cout<<"\n"<<endl;
    cart.display();

    return 0;
}

