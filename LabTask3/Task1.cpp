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

    void addAtFront(const string& data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void addAtEnd(const string& data) {
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

    void insertAfter(const string& prevBook, const string& data) {
        Node* current = head;
        while (current) {
            if (current->data == prevBook) {
                Node* newNode = new Node(data);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Book '" << prevBook << "' not found in the list." << endl;
    }

    bool search(const string& bookName) {
        Node* current = head;
        while (current) {
            if (current->data == bookName) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() {
        if (!head) {
            cout << "The list is empty." << endl;
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
    LinkedList library;
    string books[] = {"Data Structures", "Operating Systems", "Computer Networks", "Database Systems"};
    
    for (int i = 0; i < 4; i++) {
        library.addAtEnd(books[i]);
    }

    library.addAtFront("Artificial Intelligence");
    library.addAtEnd("Machine Learning");
    library.insertAfter("Operating Systems", "Cyber Security");

    bool bookExists = library.search("Database Systems");
    cout << "Book 'Database Systems' exists: " << (bookExists ? "Yes" : "No") << endl;

    cout << "Complete List of Books:" << endl;
    library.display();

    return 0;
}

