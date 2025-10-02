#include <iostream>
using namespace std;

int sumDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumDigits(n / 10);
}

int nestedSum(int n) {
    if (n >= 0 && n <= 9)
        return n;
    return nestedSum(sumDigits(n));
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int result = nestedSum(num);
    cout << "Final single-digit result: " << result << endl;
    return 0;
}
