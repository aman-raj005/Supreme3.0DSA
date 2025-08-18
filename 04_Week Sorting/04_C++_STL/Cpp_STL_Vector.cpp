#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // VECTOR:

    // // creation:
    // vector<int> marks;

    // // creation with size 10
    // vector<int> miles(10);

    // // creation with size 15 and initials 0
    // vector<int> distances(15, 5);

    // // v.begin()
    // cout << "v.start() : " << *(distances.begin()) << endl
    //      << endl;

    // // v.end()
    // cout << "v.end : " << *(distances.end()) << endl
    //      << endl;

    // // v.push_back()
    // distances.push_back(10);
    // distances.push_back(20);
    // distances.push_back(30);
    // distances.push_back(40);

    // // v.size()
    // cout << "Size of vector is " << distances.size() << endl
    //      << endl;
    // ;

    // // v.pop_back()
    // distances.pop_back();
    // cout << "Size of vector is " << distances.size() << endl
    //      << endl;
    // ;

    // // v.front()
    // cout << "Front : " << distances.front() << endl
    //      << endl;

    // // v.back()
    // cout << "Back : " << distances.back() << endl
    //      << endl;

    // // v.empty()
    // cout
    //     << "v.empty() : ";
    // if (distances.empty())
    //     cout
    //         << "Vector is Empty" << endl
    //         << endl;
    // else
    //     cout << "Vector is not Empty" << endl
    //          << endl;

    // // Access using v[i]
    // cout << "v[i] : " << distances[15] << endl
    //      << endl;

    // // v.at(i)
    // cout << "v.at() : " << distances.at(15) << endl
    //      << endl;

    // // v.capacity()
    // vector<int> v;
    // cout << "Capacity : " << v.capacity() << endl;
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // cout << "Here Size is " << v.size() << " but Capacity is " << v.capacity() << endl
    //      << endl;

    // // v.reserve(value) => It reserves the capacity of vector.

    // vector<int> v1;
    // cout << "Capacity: " << v1.capacity() << endl;
    // v1.reserve(5);
    // cout << "After Reserve, Now Capacity: " << v1.capacity() << endl
    //      << endl;

    // // v.max_size()
    // cout << "v.max_size() : " << v1.max_size() << endl
    //      << endl;

    // // v.clear()
    // cout << "Size : " << v.size() << endl;
    // cout << "v.clear() : ";
    // v.clear();
    // cout << "Now size : " << v.size() << endl
    //      << endl;

    // // v.insert(pos, value)
    // v.insert(v.begin(), 50);
    // cout << "v.begin() : " << v[0] << endl
    //      << endl;

    // // v.erase(pos) or v.erase(pos1, pos2)
    // v.push_back(60);
    // v.push_back(70);
    // v.push_back(80);
    // cout << "Size of vector is " << v.size() << endl;
    // v.erase(v.begin(), v.end());
    // cout << "Now size of vector is " << v.size() << endl
    //      << endl;

    // // v.swap(v1)
    // vector<int> first;
    // vector<int> second;

    // first.push_back(1);
    // first.push_back(2);
    // first.push_back(3);
    // second.push_back(4);
    // second.push_back(5);
    // second.push_back(6);

    // first.swap(second);

    // for (int i = 0; i < first.size(); i++)
    // {
    //     cout << "Vector first element at " << i << " is " << first[i] << endl;
    // }

    // for (int i = 0; i < first.size(); i++)
    // {
    //     cout << "Vector second element at " << i << " is " << second[i] << endl;
    // }
    // cout << endl;

    // For Each Loop
    // vector<int> first;

    // first.push_back(1);
    // first.push_back(2);
    // first.push_back(3);

    // for (int i : first)
    // {
    //     cout << i << " ";
    // }

    // Iterator:

    // creation:
    // vector<int>::iterator it;

    // initialize and traverse:
    // vector<int> vec;
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);

    // vector<int>::iterator it2 = vec.begin();
    // while (it2 != vec.end())
    // {
    //     cout << *it2 << " ";
    //     it2++;
    // }

    // OR

    // vector<int>::iterator it3;
    // for (it3 = vec.begin(); it3 != vec.end(); it3++)
    // {
    //     cout << *it3 << " ";
    // }

    // 2D Vector

    vector<vector<int>> arr(4, vector<int>(4, 0));

    // rowcount:
    cout << "Total rows  : " << arr.size() << endl;

    // columncount
    cout << "Total columns : " << arr[0].size() << endl
         << endl;

    // create 2D vector with different size of columns on eachrow (Jagged Array):
    vector<vector<int>> arr2(4);
    arr2[0] = vector<int>(4);
    arr2[1] = vector<int>(2);
    arr2[2] = vector<int>(5);
    arr2[3] = vector<int>(3);

    // Jagged Array rowcount
    cout << "Total rows  : " << arr2.size() << endl;

    // Jagged Array columncount
    cout << "Total columns  : " << endl;
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << "No. of columns in row " << i + 1 << " is " << arr2[i].size() << endl;
    }
    cout << endl;

    return 0;
}