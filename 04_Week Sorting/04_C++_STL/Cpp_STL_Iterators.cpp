// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {

//     vector<int> arr;
//     arr.push_back(10);
//     arr.push_back(20);
//     arr.push_back(30);

//     // create Iterator
//     vector<int>::iterator it = arr.begin();

//     // traversing
//     cout << "The elements in vector arr : ";
//     while (it != arr.end())
//     {
//         cout << *it << " ";
//         it++;
//     }
//     cout << endl
//          << endl;

//     return 0;
// }

// forward Iterator
// #include <iostream>
// #include <forward_list>
// using namespace std;

// int main()
// {
//     // creation
//     forward_list<int> flist;

//     // insertion
//     flist.push_front(10);
//     flist.push_front(20);
//     flist.push_front(30);

//     // traverse
//     forward_list<int>::iterator it = flist.begin();
//     cout << "Forward list is : ";
//     while (it != flist.end())
//     {
//         cout << *it << " ";
//         it++;
//     }

//     // writing in forward list
//     it = flist.begin();
//     while (it != flist.end())
//     {
//         (*it) = (*it) + 10;
//         it++;
//     }
//     cout << endl
//          << endl;
//     it = flist.begin();
//     cout << "After writing in forward list : ";
//     while (it != flist.end())
//     {
//         cout << *it << " ";
//         it++;
//     }
//     cout << endl
//          << endl;

//     // moving backward => not possible to move backward in forward list.
//     // it = flist.end();
//     // while (it != flist.begin())
//     // {
//     //     cout << *it << " ";
//     //     it--;
//     // }
//     // cout << endl
//     //      << endl;

//     return 0;
// }

// bidirectional Iterator
// #include <iostream>
// #include <list>
// using namespace std;

// int main()
// {
//     // creation
//     list<int> biDirlist;

//     // insertion
//     biDirlist.push_front(10);
//     biDirlist.push_front(20);
//     biDirlist.push_front(30);

//     // traverse and printing
//     list<int>::iterator it = biDirlist.begin();
//     cout << "Bidirectional List is : ";
//     while (it != biDirlist.end())
//     {
//         cout << *it << " ";
//         it++;
//     }
//     cout << endl
//          << endl;

//     // Updation in bidirectional list
//     it = biDirlist.begin();
//     while (it != biDirlist.end())
//     {
//         (*it) = (*it) + 5;
//         it++;
//     }
//     it = biDirlist.begin();
//     cout << "After updation in bidirectional list : ";
//     while (it != biDirlist.end())
//     {
//         cout << *it << " ";
//         it++;
//     }
//     cout << endl
//          << endl;

//     // moving backward in bidirectional
//     it = biDirlist.end();
//     cout << "Moving backward in bidirectional list : ";
//     while (it != biDirlist.begin())
//     {
//         it--;
//         cout << *it << " ";
//     }
//     cout << endl
//          << endl;

//     return 0;
// }

// random access Iterator
// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     // creation
//     vector<int> arr = {1, 2, 3, 4, 5};

//     // traverse and printing
//     vector<int>::iterator it = arr.begin();
//     cout << "Vector is : ";
//     while (it != arr.end())
//     {
//         cout << *it << " ";
//         it++;
//     }
//     cout << endl
//          << endl;

//     // Updation and Printing
//     it = arr.begin();
//     while (it != arr.end())
//     {
//         (*it) = (*it) + 10;
//         it++;
//     }
//     it = arr.begin();
//     cout << "After updation vector : ";
//     while (it != arr.end())
//     {
//         cout << *it << " ";
//         it++;
//     }
//     cout << endl
//          << endl;

//     // Moving backward
//     it = arr.end() - 1;
//     cout << "Moving backward : ";
//     while (it != arr.begin() - 1)
//     {
//         cout << *it << " ";
//         it--;
//     }
//     cout << endl
//          << endl;

//     // random access Iterator
//     vector<int>::iterator it1 = arr.begin() + 3;
//     cout << "Vector value at arr.begin()+3 location : ";
//     cout << *it1 << endl
//          << endl;

//     return 0;
// }