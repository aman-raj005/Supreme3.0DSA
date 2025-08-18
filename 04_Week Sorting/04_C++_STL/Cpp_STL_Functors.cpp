// #include <iostream>
// using namespace std;

// class functorOne
// {
// public:
//     bool operator()(int a, int b)
//     {
//         return a > b;
//     }
// };

// int main()
// {

//     functorOne cmp;

//     if (cmp(20, 10))
//     {
//         cout << "Here, 20 is greater than 10" << endl
//              << endl;
//     }
//     else
//     {
//         cout << "20 is less than 10" << endl
//              << endl;
//         ;
//     }

//     return 0;
// }

// #include <iostream>
// using namespace std;

// // class
// class Student
// {
// public:
//     int marks;
//     string name;
//     Student()
//     {
//     }
//     Student(int m, string n)
//     {
//         this->marks = m;
//         this->name = n;
//     }
// };

// // functor
// class StudentComparator
// {
// public:
//     bool operator()(Student a, Student b)
//     {
//         return a.marks < b.marks;
//     }
// };

// int main()
// {

//     Student s1;
//     Student s2;

//     s1.marks = 90;
//     s1.name = "Ravi";

//     s2.marks = 95;
//     s2.name = "Kishan";

//     StudentComparator cmp;

//     if (cmp(s1, s2))
//     {
//         cout << "Marks of Ravi is less than Kishan" << endl
//              << endl;
//     }
//     else
//     {
//         cout << "Marks of Kishan is less than Ravi" << endl
//              << endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class comparator
// {
// public:
//     bool operator()(int a, int b)
//     {
//         return a > b;
//     }
// };

// int main()
// {

//     vector<int> arr;

//     arr.push_back(30);
//     arr.push_back(10);
//     arr.push_back(20);

//     sort(arr.begin(), arr.end(), comparator());
//     cout << "Sorting in descending order: ";
//     for (int a : arr)
//     {
//         cout << a << " ";
//     }
//     cout << endl
//          << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// class Student
// {
// public:
//     int marks;
//     string name;
//     Student()
//     {
//     }
//     Student(int m, string n)
//     {
//         this->marks = m;
//         this->name = n;
//     }
// };

// class comparator
// {
// public:
//     bool operator()(Student a, Student b)
//     {
//         if (a.marks == b.marks)
//         {
//             return a.name < b.name;
//         }
//         return a.marks > b.marks;
//     }
// };

// int main()
// {
//     vector<Student> arr;
//     arr.push_back(Student(80, "Ravi"));
//     arr.push_back(Student(85, "Kishan"));
//     arr.push_back(Student(90, "Pankaj"));

//     sort(arr.begin(), arr.end(), comparator());

//     for (Student it : arr)
//     {
//         cout << "Marks : " << it.marks << " and Name : " << it.name << endl;
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Student
{
public:
    int marks;
    string name;
    Student()
    {
    }
    Student(int m, string n)
    {
        this->marks = m;
        this->name = n;
    }
};

class comparator
{
public:
    bool operator()(Student a, Student b)
    {
        return a.marks < b.marks;
    }
};

int main()
{

    // priority_queue<int, vector<int>, less<int>> pq; => A priority queue named pq which perform operations on int dtype , use container as vector<int> and comparator as less<int>(create max-heap).

    priority_queue<Student, vector<Student>, comparator> pq;

    pq.push(Student(80, "Ravi"));
    pq.push(Student(60, "Kishan"));
    pq.push(Student(95, "Gopal"));
    pq.push(Student(70, "Shekhar"));

    cout << "Top Student Marks is " << pq.top().marks << " and their Name is " << pq.top().name << endl;
    pq.pop();
    cout << "Top Student Marks is " << pq.top().marks << " and their Name is " << pq.top().name << endl;
    pq.pop();
    cout << "Top Student Marks is " << pq.top().marks << " and their Name is " << pq.top().name << endl;
    pq.pop();
    cout << "Top Student Marks is " << pq.top().marks << " and their Name is " << pq.top().name << endl
         << endl
         << endl;

    return 0;
}