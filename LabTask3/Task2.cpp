#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;

    Node(string data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void addAtTail(const string& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = newNode;
    }

    void deleteFromFront() {
        if (!head) {
            cout << "The catalog is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void searchByTitle(const string& title) {
        Node* current = head;
        while (current) {
            if (current->data == title) {
                cout << "Found book: " << current->data << endl;
                return;
            }
            current = current->next;
        }
        cout << "Book not found." << endl;
    }

    void searchByPosition(int position) {
        Node* current = head;
        int count = 1;
        while (current) {
            if (count == position) {
                cout << "Book at position " << position << ": " << current->data << endl;
                return;
            }
            current = current->next;
            count++;
        }
        cout << "Position out of range." << endl;
    }

    void display() {
        if (!head) {
            cout << "The catalog is empty." << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "None" << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList catalog;

    catalog.addAtTail("Data Structures");
    catalog.addAtTail("Operating Systems");
    catalog.addAtTail("Computer Networks");
    catalog.addAtTail("Database Systems");

    catalog.display();

    catalog.searchByTitle("Operating Systems");

    catalog.searchByPosition(3);

    catalog.deleteFromFront();
    catalog.display();

    return 0;
}
