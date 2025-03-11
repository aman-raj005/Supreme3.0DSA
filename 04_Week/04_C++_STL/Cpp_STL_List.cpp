#include <iostream>
#include <list>
using namespace std;

int main()
{

    // creation
    list<int> myList;

    // insertion
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    myList.push_front(6);
    myList.push_front(4);
    myList.push_front(2);

    // removal
    myList.pop_back();
    myList.pop_front();

    // size
    cout << "Size of list : " << myList.size() << endl
         << endl;

    // clear
    myList.clear();
    cout
        << "Size of list : " << myList.size() << endl
        << endl;

    // is empty
    if (myList.empty())
    {
        cout << "List is empty!" << endl
             << endl;
    }
    else
    {

        cout << "List is not empty!" << endl
             << endl;
    }

    // front
    myList.push_back(2);
    myList.push_front(1);
    cout << "Front: " << myList.front() << endl
         << endl;

    // back
    cout << "Back: " << myList.back() << endl
         << endl;

    // traverse'
    list<int>::iterator it = myList.begin();
    cout << "The list : ";
    while (it != myList.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl
         << endl;

    // remove
    myList.push_back(1);
    // now my list is 1=>2=>1
    myList.remove(1);
    cout << "The list after using remove() : ";
    list<int>::iterator it2 = myList.begin();
    while (it2 != myList.end())
    {
        cout << *it2 << " ";
        it2++;
    }
    cout << endl
         << endl;

    // swap
    list<int> first;
    list<int> second;

    first.push_back(10);
    first.push_back(20);
    second.push_back(1);
    second.push_back(2);

    cout << "The list before : ";
    list<int>::iterator it3 = first.begin();
    while (it3 != first.end())
    {
        cout << *it3 << " ";
        it3++;
    }
    cout << endl
         << endl;

    first.swap(second);

    cout << "The list after : ";
    list<int>::iterator it4 = first.begin();
    while (it4 != first.end())
    {
        cout << *it4 << " ";
        it4++;
    }
    cout << endl
         << endl;

    // insert (insert(iterator,value))
    // first : 1=>2
    first.insert(first.begin(), 0);
    cout << "The list after using insert : ";
    list<int>::iterator it5 = first.begin();
    while (it5 != first.end())
    {
        cout << *it5 << " ";
        it5++;
    }
    cout << endl
         << endl;

    // erase (erase(start_address, end_address))
    first.erase(first.begin(), first.end());
    cout << "The list after using erase : ";
    list<int>::iterator it6 = first.begin();
    while (it6 != first.end())
    {
        cout << *it6 << " ";
        it6++;
    }
    cout << endl
         << endl;
    return 0;
}