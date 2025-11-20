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

    void heapify(int i) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    int extractMin() {
        if (size <= 0) return -1;
        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
        return root;
    }

    void display() {
        for (int i = 0; i < size; i++) cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h(10);

    h.insert(100);
    h.insert(50);
    h.insert(75);
    h.insert(60);

    cout << "Heap after inserting initial orders: ";
    h.display();

    h.insert(55);
    cout << "Heap after inserting 55: ";
    h.display();

    int executed = h.extractMin();
    cout << "Executed order with lowest price: " << executed << endl;

    cout << "Heap after executing order: ";
    h.display();

    return 0;
}
