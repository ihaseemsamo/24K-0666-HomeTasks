// Shell Sort is used instead of Insertion Sort because it compares elements far apart first,
// reducing total swaps and improving efficien
#include <iostream>
using namespace std;

void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap)
                arr[j] = arr[j-gap];
            arr[j] = temp;
        }
        cout << "After gap " << gap << ": ";
        for (int k=0; k<n; k++) cout << arr[k] << " ";
        cout << endl;
    }
}

int main() {
    int books[] = {205, 102, 310, 450, 120, 90};
    int n = 6;
    cout << "Original IDs: ";
    for(int i=0;i<n;i++) cout << books[i] << " ";
    cout << endl;

    shellSort(books, n);

    cout << "Sorted IDs: ";
    for(int i=0;i<n;i++) cout << books[i] << " ";
}
