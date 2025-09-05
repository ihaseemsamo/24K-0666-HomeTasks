#include <iostream>
using namespace std;

class Box
{
public:
    int *volume;

    Box()
    {
        volume = new int(0);
    }

    Box(int v)
    {
        volume = new int(v);
    }

    Box(const Box &other)
    {
        volume = new int(*other.volume);
    }

    ~Box()
    {
        delete volume;
    }

    void display()
    {
        cout << "Volume:" << *volume << endl;
    }
    void changeVolume(int n)
    {
        *volume = n;
    }
};
int main()
{
    Box b1(1);
    Box b2(b1);

    cout << " Box 1 ";
    b1.display();
    cout << " Box 2 ";
    b2.display();

    b2.changeVolume(3);

    cout << " Box 1 ";
    b1.display();
    cout << " Box 2 ";
    b2.display();

    return 0;
}
