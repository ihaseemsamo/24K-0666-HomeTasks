#include <iostream>
using namespace std;

class MinHeap {
public:
    int* heap;
    int capacity;
    int size;

    MinHeap(int c) {
        capacity = c;
        size = 0;
        heap = new int[c];
    }

    void swap(int &a, int &b) {
        int t = a;
        a = b;
        b = t;
    }

    void insert(int key) {
        if (size == capacity) return;
        heap[size] = key;
        int i = size;
        size++;

        while (i != 0 && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h(10);
    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);

    cout << "Heap before insertion: ";
    h.display();

    h.insert(2);

    cout << "Heap after inserting 2: ";
    h.display();

    return 0;
}
