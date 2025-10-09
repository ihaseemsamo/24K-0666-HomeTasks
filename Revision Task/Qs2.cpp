// Shell Sort is preferred over Bubble Sort as it reduces comparisons by using larger gaps first,
// making it faster for larger and unsorted data set
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
    int luggage[] = {32, 25, 40, 12, 18, 50, 28};
    int n = 7;

    cout << "Original Weights: ";
    for (int i=0; i<n; i++) cout << luggage[i] << " ";
    cout << endl;

    shellSort(luggage, n);

    cout << "Sorted Weights: ";
    for (int i=0; i<n; i++) cout << luggage[i] << " ";
    cout << endl;

    cout << "\nShell Sort vs Bubble Sort:\n";
    cout << "- Bubble Sort does many adjacent swaps (O(n^2)).\n";
    cout << "- Shell Sort reduces gap each pass (O(n log n)).\n";
    cout << "- Airport prefers Shell Sort for quick luggage ordering.\n";
    cout << "- If luggage nearly sorted, Shell Sort becomes even faster (almost linear).\n";
}
