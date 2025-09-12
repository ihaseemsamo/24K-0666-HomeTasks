#include <iostream>
using namespace std;

class JaggedArray {
private:
    int** array;
    int rows;

public:
    JaggedArray(int r) {
        rows = r;
        array = new int*[rows];
    }

    ~JaggedArray() {
        for (int i = 0; i < rows; i++) {
            delete[] array[i];
        }
        delete[] array;
    }

    void setRow(int row, int numElements) {
        array[row] = new int[numElements];
    }

    void setValues(int row, int numElements, int* values) {
        for (int i = 0; i < numElements; i++) {
            array[row][i] = values[i];
        }
    }

    int sumRow(int row, int numElements) {
        int sum = 0;
        for (int i = 0; i < numElements; i++) {
            sum += array[row][i];
        }
        return sum;
    }

    void printRow(int row, int numElements) {
        for (int i = 0; i < numElements; i++) {
            cout << array[row][i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int numTeams = 3;
    JaggedArray scores(numTeams);

    int team1[] = {10, 20, 30};  
    int team2[] = {15, 25};       
    int team3[] = {40, 50, 60, 70};  

    scores.setRow(0, 3);
    scores.setValues(0, 3, team1);

    scores.setRow(1, 2);
    scores.setValues(1, 2, team2);

    scores.setRow(2, 4);
    scores.setValues(2, 4, team3);

    for (int i = 0; i < numTeams; i++) {
        cout << "Team " << i + 1 << " scores: ";
        scores.printRow(i, (i == 0 ? 3 : (i == 1 ? 2 : 4)));
        cout << "Sum of Team " << i + 1 << " scores: " << scores.sumRow(i, (i == 0 ? 3 : (i == 1 ? 2 : 4))) << endl;
    }

    return 0;
}

