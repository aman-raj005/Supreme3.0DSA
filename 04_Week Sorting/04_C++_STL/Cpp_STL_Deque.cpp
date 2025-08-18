#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // creation
    deque<int> dq;

    // insertion
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    // dq => 10,20,30

    dq.push_front(7);
    dq.push_front(5);
    dq.push_front(3);
    // dq => 3,5,7,10,20,30

    // removal
    dq.pop_back();
    // dq => 3,5,7,10,20
    dq.pop_front();
    // dq => 5,7,10,20

    // size
    cout << "Size : " << dq.size() << endl
         << endl;

    // front
    cout << "Front : " << dq.front() << endl
         << endl;

    // back
    cout << "Back : " << dq.back() << endl
         << endl;

    // empty
    if (dq.empty())
    {
        cout << "Deque is empty!" << endl
             << endl;
    }
    else
    {
        cout << "Deque is not empty!" << endl
             << endl;
    }

    // iterator
    deque<int>::iterator it = dq.begin();
    cout << "Deque : ";
    while (it != dq.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl
         << endl;

    // dq[i] and dq.at(i)
    // dq => 5,7,10,20
    cout << "Value at 1 index : " << dq[1] << endl
         << endl;
    cout << "Value at 1 index using at : " << dq.at(1) << endl
         << endl;

    // Now insert(pos, value), erase(pos1, pos2), clear(), swap() are same as used in vector.

    // erase
    dq.erase(dq.begin(), dq.end());
    cout << "Size of dq after erase : " << dq.size() << endl
         << endl;

    // insert
    dq.insert(dq.begin(), 1);
    cout << "Value at 0 index after insert(): " << dq[0] << endl
         << endl;

    // clear
    cout << "Deque Size : " << dq.size() << endl
         << endl;
    dq.clear();
    cout << "Now Deque Size : " << dq.size() << endl;
 
    return 0;
}