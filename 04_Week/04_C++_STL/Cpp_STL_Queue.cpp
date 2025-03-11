#include <iostream>
#include <queue>
using namespace std;

int main()
{

     // creation
     queue<int> q;

     // insertion
     q.push(10);
     q.push(20);
     q.push(30);
     // 10,20,30

     // removal
     q.pop();
     // 20,30

     // size
     cout << "The Queue size is " << q.size() << endl
          << endl;

     // empty
     if (q.empty())
     {
          cout << "Queue is Empty!" << endl
               << endl;
     }
     else
     {
          cout << "Queue is not Empty!" << endl
               << endl;
     }

     // front
     cout << "Front : " << q.front() << endl
          << endl;

     // back
     cout << "Back : " << q.back() << endl
          << endl;

     // swap
     queue<int> first;
     queue<int> second;

     first.push(1);
     first.push(2);

     second.push(10);
     second.push(20);

     cout << "Queue 1 before swap : " << first.front() << " " << first.back() << endl
          << endl;

     first.swap(second);

     cout << "Queue 1 after swap : " << first.front() << " " << first.back() << endl
          << endl;

     // printing
     cout << "Queue : ";
     while (!first.empty())
     {
          cout << first.front() << " ";
          first.pop();
     }
     cout << endl;

     return 0;
}