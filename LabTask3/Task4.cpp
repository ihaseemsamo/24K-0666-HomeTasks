#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
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

    void addAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "None" << endl;
    }

    void sortList() {
        if (!head || !head->next) {
            return; 
        }
        Node* current = head;
        Node* index = NULL;
        int temp;
        while (current) {
            index = current->next;
            while (index) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    void concatenate(LinkedList& otherList) {
        if (!head) {
            head = otherList.head;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = otherList.head;
        otherList.head = NULL;
    }

    int findMiddle() {
        if (!head) {
            cout << "The list is empty." << endl;
            return -1; 
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    void removeDuplicates() {
        Node* current = head;
        while (current) {
            Node* prev = current;
            Node* temp = current->next;
            while (temp) {
                if (current->data == temp->data) {
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                } else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            current = current->next;
        }
    }

    static LinkedList mergeSortedLists(LinkedList& list1, LinkedList& list2) {
        Node* p1 = list1.head;
        Node* p2 = list2.head;
        LinkedList mergedList;
        Node* current = NULL;

        while (p1 && p2) {
            Node* newNode = NULL;
            if (p1->data <= p2->data) {
                newNode = new Node(p1->data);
                p1 = p1->next;
            } else {
                newNode = new Node(p2->data);
                p2 = p2->next;
            }

            if (!mergedList.head) {
                mergedList.head = newNode;
                current = mergedList.head;
            } else {
                current->next = newNode;
                current = current->next;
            }
        }

        while (p1) {
            Node* newNode = new Node(p1->data);
            current->next = newNode;
            current = current->next;
            p1 = p1->next;
        }

        while (p2) {
            Node* newNode = new Node(p2->data);
            current->next = newNode;
            current = current->next;
            p2 = p2->next;
        }

        return mergedList;
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
    LinkedList list1;
    LinkedList list2;

    list1.addAtEnd(10);
    list1.addAtEnd(20);
    list1.addAtEnd(30);
    list1.addAtEnd(40);
    cout << "List 1: ";
    list1.display();

    list2.addAtEnd(5);
    list2.addAtEnd(25);
    list2.addAtEnd(35);
    list2.addAtEnd(45);
    cout << "List 2: ";
    list2.display();

    LinkedList mergedList = LinkedList::mergeSortedLists(list1, list2);
    cout << "Merged Sorted List: ";
    mergedList.display();

    list1.addAtEnd(10);
    list1.addAtEnd(15);
    list1.addAtEnd(10);
    cout << "\nList with Duplicates: ";
    list1.display();

    list1.removeDuplicates();
    cout << "List after removing duplicates: ";
    list1.display();

    cout << "Middle element of the list: " << list1.findMiddle() << endl;

    list1.sortList();
    cout << "Sorted List: ";
    list1.display();

    LinkedList list3;
    list3.addAtEnd(50);
    list3.addAtEnd(60);
    list1.concatenate(list3);
    cout << "List after concatenation: ";
    list1.display();

    return 0;
}
