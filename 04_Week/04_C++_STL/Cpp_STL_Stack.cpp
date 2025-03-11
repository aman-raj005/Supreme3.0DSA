#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // creation
    stack<int> st;

    // insertion
    st.push(10);
    st.push(20);
    st.push(30);
    // st =>
    //   30
    //   20
    //   10

    // removal
    st.pop();
    // st =>
    //   20
    //   10

    // size
    cout << "Size : " << st.size() << endl
         << endl;

    // top => to observe/access topmost element in stack
    cout << "Top : " << st.top() << endl
         << endl;

    // empty
    if (st.empty())
    {
        cout << "Stack is empty!" << endl
             << endl;
    }
    else
    {
        cout << "Stack is not empty!" << endl
             << endl;
    }

    // swap
    stack<int> first;
    stack<int> second;

    first.push(1);
    first.push(2);
    second.push(10);
    second.push(20);

    cout << "First stack top before swap: " << first.top() << endl
         << endl;

    first.swap(second);

    cout
        << "First stack top after swap: " << first.top() << endl
        << endl;

    // printing
    cout << "Stack : ";
    while (!first.empty())
    {
        cout << first.top() << " ";
        first.pop();
    }
    cout << endl;

    return 0;
}