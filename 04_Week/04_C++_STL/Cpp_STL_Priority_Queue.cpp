#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // min-heap => minimum value => highest priority:
    // creation
    priority_queue<int, vector<int>, greater<int>> pq1;

    // insertion
    pq1.push(10);
    pq1.push(30);
    pq1.push(20);
    // pq =>
    // 10
    // 20
    // 30

    // removal
    pq1.pop();
    // pq =>
    // 20
    // 30

    // top => it has highest priority
    cout << "Top element (min-heap): " << pq1.top() << endl
         << endl;

    // size
    cout << "Size (min-heap) : " << pq1.size() << endl
         << endl;

    // ************************************* //

    // creation
    priority_queue<int> pq;

    // max-heap => maximum value => highest priority

    // insertion
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(60);
    // pq =>
    // 60
    // 30
    // 20
    // 10

    // removal
    pq.pop();
    // pq =>
    // 30
    // 20
    // 10

    // top => it has highest priority
    cout << "Top element : " << pq.top() << endl
         << endl;

    // size
    cout << "Size : " << pq.size() << endl
         << endl;

    // empty
    if (pq.empty())
    {
        cout << "Priority Queue is Empty!" << endl
             << endl;
    }
    else
    {
        cout << "Priority Queue is not Empty!" << endl
             << endl;
    }

    // swap() is same as others.

    return 0;
}