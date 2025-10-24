#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    int price;
    string description;
    string availability;
};

int partition(Product arr[], int low, int high) {
    int pivot = arr[high].price;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            Product temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    Product temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int n = 3;
    Product products[n];

    cout << "Enter details of 3 products:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << " name: ";
        cin >> products[i].name;
        cout << "Price: ";
        cin >> products[i].price;
        cout << "Description: ";
        cin >> products[i].description;
        cout << "Availability (In stock / Out of stock): ";
        cin.ignore();
        getline(cin, products[i].availability);
    }

    quickSort(products, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << products[i].name << "\t\t" 
             << products[i].price << "\t" 
             << products[i].availability << "\t\t" 
             << products[i].description << endl;
    }

    return 0;
}
