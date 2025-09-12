#include <iostream>
using namespace std;

struct Node {
    int compartmentNumber;
    Node* next;
    Node* prev;

    Node(int compartmentNumber) {
        this->compartmentNumber = compartmentNumber;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addAtEnd(int compartmentNumber) {
        Node* newNode = new Node(compartmentNumber);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeFromFront() {
        if (!head) {
            cout << "The train is empty." << endl;
            return;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void searchCompartment(int compartmentNumber) {
        Node* current = head;
        while (current) {
            if (current->compartmentNumber == compartmentNumber) {
                cout << "Compartment " << compartmentNumber << " found in the train." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Compartment " << compartmentNumber << " not found in the train." << endl;
    }

    void displayFromFrontToEnd() {
        if (!head) {
            cout << "The train is empty." << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->compartmentNumber << " <-> ";
            current = current->next;
        }
        cout << "None" << endl;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList train;

    train.addAtEnd(101);
    train.addAtEnd(102);
    train.addAtEnd(103);
    train.addAtEnd(104);

    cout << "Train compartments from front to end: ";
    train.displayFromFrontToEnd();

    train.searchCompartment(102);
    train.searchCompartment(105);

    train.removeFromFront();
    cout << "Train compartments after removing the first compartment: ";
    train.displayFromFrontToEnd();

    return 0;
}
