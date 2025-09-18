#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string customer;
    string ride;
    Node* next;
};

class TicketSystem {
    Node* tail;
public:
    TicketSystem() { tail = NULL; }

    void issueEnd(int id, string customer, string ride) {
        Node* n = new Node{id, customer, ride, NULL};
        if (!tail) {
            tail = n;
            tail->next = tail;
        } else {
            n->next = tail->next;
            tail->next = n;
            tail = n;
        }
    }

    void issueFront(int id, string customer, string ride) {
        Node* n = new Node{id, customer, ride, NULL};
        if (!tail) {
            tail = n;
            tail->next = tail;
        } else {
            n->next = tail->next;
            tail->next = n;
        }
    }

    void cancelByID(int id) {
        if (!tail) return;
        Node* curr = tail->next;
        Node* prev = tail;
        do {
            if (curr->id == id) {
                if (curr == tail && curr == tail->next) {
                    delete curr;
                    tail = NULL;
                    return;
                }
                prev->next = curr->next;
                if (curr == tail) tail = prev;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
    }

    void cancelFront() {
        if (!tail) return;
        Node* front = tail->next;
        if (tail == front) {
            delete front;
            tail = NULL;
        } else {
            tail->next = front->next;
            delete front;
        }
    }

    void searchByID(int id) {
        if (!tail) { cout << "No tickets" << endl; return; }
        Node* temp = tail->next;
        do {
            if (temp->id == id) {
                cout << "ID: " << temp->id << ", " << temp->customer << ", Ride: " << temp->ride << endl;
                return;
            }
            temp = temp->next;
        } while (temp != tail->next);
        cout << "Ticket with ID " << id << " not found" << endl;
    }

    void displayAll() {
        if (!tail) { cout << "No tickets" << endl; return; }
        Node* temp = tail->next;
        do {
            cout << "ID: " << temp->id << ", " << temp->customer << ", Ride: " << temp->ride << endl;
            temp = temp->next;
        } while (temp != tail->next);
    }

    int countTickets() {
        if (!tail) return 0;
        int count = 0;
        Node* temp = tail->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != tail->next);
        return count;
    }

    void nextAfterID(int id) {
        if (!tail) { cout << "No tickets" << endl; return; }
        Node* temp = tail->next;
        do {
            if (temp->id == id) {
                Node* nextNode = temp->next;
                cout << "Next Ticket -> ID: " << nextNode->id << ", " << nextNode->customer << ", Ride: " << nextNode->ride << endl;
                return;
            }
            temp = temp->next;
        } while (temp != tail->next);
        cout << "Ticket with ID " << id << " not found" << endl;
    }
};

int main() {
    TicketSystem ts;
    ts.issueEnd(1, "Alice", "Roller Coaster");
    ts.issueEnd(2, "Bob", "Ferris Wheel");
    ts.issueEnd(3, "Charlie", "Bumper Cars");
    ts.issueFront(4, "Diana", "Haunted House");

    cout << "All Tickets:" << endl;
    ts.displayAll();

    cout << "\nSearching Ticket ID 2:" << endl;
    ts.searchByID(2);

    cout << "\nNext after Ticket 2:" << endl;
    ts.nextAfterID(2);

    cout << "\nCancel Front Ticket:" << endl;
    ts.cancelFront();
    ts.displayAll();

    cout << "\nCancel Ticket ID 3:" << endl;
    ts.cancelByID(3);
    ts.displayAll();

    cout << "\nTotal Tickets: " << ts.countTickets() << endl;

    return 0;
}
