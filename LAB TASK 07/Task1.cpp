#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int time;
};

void merge(Runner arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Runner leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i].time <= rightArr[j].time) {
            arr[k] = leftArr[i];
            i = i + 1;
        } else {
            arr[k] = rightArr[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j = j + 1;
        k = k + 1;
    }
}

void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    const int n = 10;
    Runner runners[n];

    cout << "Enter names and finish times (in seconds):\n";
    for (int i = 0; i < n; i++) {
        cout << "Runner " << i + 1 << " name: ";
        cin >> runners[i].name;
        cout << "Finish time (in seconds): ";
        cin >> runners[i].time;
    }

    mergeSort(runners, 0, n - 1);

    for (int i = 0; i < 5 && i < n; i++) {
        cout << (i + 1) << "\t" << runners[i].name << "\t\t" << runners[i].time << endl;
    }

    return 0;
}
