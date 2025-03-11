#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
    cout << endl
         << "Your Vector is : ";
    int size = v.size();
    for (int i = 0; i < size; i++)
    {

        // cout << v[i] << " ";

        // Vector AT
        cout << v.at(i) << " ";
    }
}

void printVectorUsingIt(vector<int> v)
{
    cout << endl
         << "Your Vector Using Iterator is : ";
    for (auto it : v)
    {

        cout << it << " ";

        // Vector AT
        // cout << v.at(it) << " ";
    }
}

void printVectorOfChar(vector<char> v)
{
    cout << endl
         << "Your Vector is : ";
    int size = v.size();
    for (int i = 0; i < size; i++)
    {

        // cout << v[i] << " ";

        // Vector AT
        cout << v.at(i) << " ";
    }
}

int main()
{
    // INITIALIZE the vector
    vector<int> v; // default with no data and 0 size.
    // vector<int> v1(3, 1); // init the vector of dtype int and name v1 with size 3 and initial values as 1.
    // vector<int> v3 = {1, 2, 3, 4, 5}; // declaring vector with specific values.
    // vector<int> v4{1, 2, 3, 4, 5}; // declaring vector with specific values.
    // printVector(v4);

    // COPY the vector
    // vector<int> v5(v4);
    // printVector(v5);

    // PUSH the Element
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    // printVector(v);
    printVectorUsingIt(v);

    // CLEAR the vector
    // v.clear();
    // printVector(v);

    // POP the Element
    // v.pop_back();
    // printVector(v);

    // INSERT value in vector by user
    // cout << "Enter the size of vector:";
    // int size;
    // cin >> size;
    // for (int i = 0; i < size; i++)
    // {
    //     int num;
    //     cin >> num;
    //     v.push_back(num);
    // }
    // printVector(v);
    // cout << endl
    //      << "Again Enter the vector values:";

    // for (int i = 0; i < size; i++)
    // {
    //     int num;
    //     cin >> num;
    //     v.push_back(num);
    // }
    // printVector(v);

    // INIT a char vector
    // vector<char> vc1;
    // vc1.push_back('a');
    // vc1.push_back('b');
    // vc1.push_back('c');
    // vc1.push_back('d');
    // printVectorOfChar(vc1);
    // cout << endl;

    // To print first and end element of vector.
    // cout << "First ele :" << vc1[0] << endl;
    // OR
    // cout << "Front ele :" << vc1.front() << endl;

    // cout << "Last ele :" << vc1[vc1.size() - 1] << endl;
    // OR
    // cout << "Back ele :" << vc1.back() << endl;
}