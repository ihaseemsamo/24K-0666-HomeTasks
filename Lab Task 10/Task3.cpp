#include <iostream>
using namespace std;

class Task {
public:
    string name;
    int priority;
    Task() {}
    Task(string n, int p) { name = n; priority = p; }
};

class MaxHeap {
public:
    Task* heap;
    int capacity;
    int size;

    MaxHeap(int c) {
        capacity = c;
        size = 0;
        heap = new Task[c];
    }

    void swap(Task &a, Task &b) {
        Task t = a;
        a = b;
        b = t;
    }

    void insert(Task t) {
        if (size == capacity) return;
        heap[size] = t;
        int i = size;
        size++;

        while (i != 0 && heap[i].priority > heap[(i - 1) / 2].priority) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapify(int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left].priority > heap[largest].priority)
            largest = left;
        if (right < size && heap[right].priority > heap[largest].priority)
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    Task extractMax() {
        if (size <= 0) return Task("", -1);
        Task root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(0);
        return root;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << heap[i].name << "(" << heap[i].priority << ") ";
        cout << endl;
    }
};

int main() {
    MaxHeap h(10);

    h.insert(Task("A", 5));
    h.insert(Task("B", 3));
    h.insert(Task("C", 8));

    cout << "Heap after inserting A, B, C: ";
    h.display();

    Task removed = h.extractMax();
    cout << "Removed highest priority task: " << removed.name << "(" << removed.priority << ")" << endl;

    cout << "Heap after removal: ";
    h.display();

    h.insert(Task("D", 6));
    cout << "Heap after inserting D: ";
    h.display();

    return 0;
}
