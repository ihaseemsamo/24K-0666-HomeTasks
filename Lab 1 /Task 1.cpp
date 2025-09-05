#include <iostream>
using namespace std;

class ResearchPaper
{
public:
    string *authors;
    int no_of_authors;

    ResearchPaper() : no_of_authors(0), authors{nullptr} {};

    ResearchPaper(int n) : no_of_authors(n)
    {
        authors = new string[n];
        input();
    }

    ResearchPaper(const ResearchPaper &other)
    {
        no_of_authors = other.no_of_authors;
        authors = new string[no_of_authors];
        for (int i = 0; i < no_of_authors; i++)
        {
            authors[i] = other.authors[i];
        }
    }

    ~ResearchPaper()
    {
        delete[] authors;
    }

    ResearchPaper &operator=(const ResearchPaper &other)
    {
        no_of_authors = other.no_of_authors;
        authors = new string[no_of_authors];
        for (int i = 0; i < no_of_authors; i++)
        {
            authors[i] = other.authors[i];
        }
        return *this;
    }

    void input()
    {
        for (int i = 0; i < no_of_authors; i++)
        {
            cout << "Enter the name of author " << i + 1 << ":";
            cin >> authors[i];
        }
    }

    void display()
    {
        cout << "Names of authors:" << endl;
        for (int i = 0; i < no_of_authors; i++)
        {
            cout << authors[i] << endl;
        }
    }
};

int main()
{
    ResearchPaper p1(3);
    cout << "Research paper 1" << endl;
    p1.display();

    ResearchPaper p2(p1);
    cout << "Research paper 2" << endl;
    p2.display();

    ResearchPaper p3 = p1;
    cout << "Research paper 3" << endl;
    p3.display();

    p1.authors[0] = "abc";
    p2.authors[1] = "def";
    p3.authors[2] = "xyz";
    cout << "Research paper 1" << endl;
    p1.display();

    cout << "Research paper 2" << endl;
    p2.display();

    cout << "Research paper 3" << endl;
    p3.display();

    return 0;
 
}
