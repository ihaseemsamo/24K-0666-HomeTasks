#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    int price;
    Node* prev;
    Node* next;
};

class ShoppingCart {
    Node* head;
    Node* tail;
public:
    ShoppingCart() { head = tail = NULL; }

    void insertEnd(int id, string name, int price) {
        Node* n = new Node{id, name, price, tail, NULL};
        if (!head) head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
    }

    void insertFront(int id, string name, int price) {
        Node* n = new Node{id, name, price, NULL, head};
        if (!head) head = tail = n;
        else {
            head->prev = n;
            head = n;
        }
    }

    void removeFront() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) head = tail = NULL;
        else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void removeEnd() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) head = tail = NULL;
        else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete temp;
    }

    void searchByID(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "ID: " << temp->id << ", " << temp->name << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found" << endl;
    }

    void updatePrice(int id, int newPrice) {
        Node* temp = head;
        while (temp) {
            if (temp->id == id) {
                temp->price = newPrice;
                return;
            }
            temp = temp->next;
        }
    }

    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", " << temp->name << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        Node* temp = tail;
        while (temp) {
            cout << "ID: " << temp->id << ", " << temp->name << " - $" << temp->price << endl;
            temp = temp->prev;
        }
    }

    int countItems() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void mostExpensiveItem() {
        if (!head) { cout << "Cart is empty" << endl; return; }
        Node* temp = head;
        Node* maxItem = head;
        while (temp) {
            if (temp->price > maxItem->price) maxItem = temp;
            temp = temp->next;
        }
        cout << "Most Expensive -> ID: " << maxItem->id << ", " << maxItem->name << " - $" << maxItem->price << endl;
    }
};

int main() {
    ShoppingCart cart;
    cart.insertEnd(1, "Laptop", 1000);
    cart.insertEnd(2, "Phone", 700);
    cart.insertEnd(3, "Tablet", 400);
    cart.insertFront(4, "Smartwatch", 200);

    cout << "Cart Forward:" << endl;
    cart.displayForward();

    cout << "\nCart Backward:" << endl;
    cart.displayBackward();

    cout << "\nSearching ID 2:" << endl;
    cart.searchByID(2);

    cart.updatePrice(3, 450);
    cout << "\nAfter updating Tablet price:" << endl;
    cart.displayForward();

    cart.removeFront();
    cart.removeEnd();
    cout << "\nAfter removals:" << endl;
    cart.displayForward();

    cout << "\nTotal Items: " << cart.countItems() << endl;
    cart.mostExpensiveItem();

    return 0;
}
