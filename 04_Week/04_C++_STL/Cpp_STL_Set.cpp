#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main()
{

    // creation
    set<int> s;

    // insertion
    s.insert(10);
    s.insert(30);
    s.insert(20);

    // traverse
    set<int>::iterator it = s.begin();
    cout << "Set : " << endl;
    while (it != s.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl
         << endl;

    //  all other methods size(), clear(), empty(), erase(), find(), count() are same.

    // ************************************* //

    // unordered set
    // creation
    unordered_set<int> s1;

    // insertion
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);

    // traverse
    unordered_set<int>::iterator it1 = s1.begin();
    cout << "Unordered Set : " << endl;
    while (it1 != s1.end())
    {
        cout << *it1 << " ";
        it1++;
    }
    cout << endl;

    //  all other methods size(), clear(), empty(), erase(), find(), count() are same.

    return 0;
}