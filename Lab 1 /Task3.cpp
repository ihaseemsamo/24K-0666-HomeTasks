#include <iostream>
using namespace std;

class Exam
{
public:
    int *marks;
    int no_of_marks;

    Exam() : no_of_marks(0), marks(nullptr) {};
    Exam(int n) : no_of_marks(n)
    {
        marks = new int[n];
        input();
    }

    void input()
    {
        for (int i = 0; i < no_of_marks; i++)
        {
            cout << "Enter marks " << i + 1 << ":";
            cin >> marks[i];
        }
    }

    void display()
    {
        for (int i = 0; i < no_of_marks; i++)
        {
            cout << "Marks " << i << ": " << marks[i] << endl;
        }
    }
};

int main()
{
    Exam e1(3);
    Exam e2(e1);

    cout << "Exam 1"<< endl;
    e1.display();
    cout << "Exam 2"<< endl;
    e2.display();

    e2.marks[0] = 40;

    cout << "Exam 1" << endl;
    e1.display();
    cout << "Exam 2"<< endl;
    e2.display();

    return 0;
}
