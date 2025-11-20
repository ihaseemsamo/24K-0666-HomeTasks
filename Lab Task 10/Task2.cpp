#include <iostream>
using namespace std;

class MaxHeap {
public:
    int* heap;
    int capacity;
    int size;

    MaxHeap(int c) {
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

        while (i != 0 && heap[i] > heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapify(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    int extractMax() {
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
    MaxHeap h(10);
    h.insert(15);
    h.insert(20);
    h.insert(5);

    cout << "Heap before adding patient 10: ";
    h.display();

    h.insert(10);
    cout << "Heap after adding patient 10: ";
    h.display();

    int treated = h.extractMax();
    cout << "Treated patient with severity: " << treated << endl;
    cout << "Heap after treating patient: ";
    h.display();

    return 0;
}
