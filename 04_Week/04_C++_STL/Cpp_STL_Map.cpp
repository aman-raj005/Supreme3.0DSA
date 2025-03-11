#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    // ordered map:
    // all insertion and operations complexity are O(log n)

    // creation
    map<string, string> table1;

    // insertion
    table1["in"] = "India";
    table1.insert(make_pair("en", "England"));
    pair<string, string> p1;
    p1.first = "br";
    p1.second = "Brazil";
    table1.insert(p1);

    // traverse
    map<string, string>::iterator it1 = table1.begin();
    cout << "The Ordered Map : " << endl;
    while (it1 != table1.end())
    {
        pair<string, string> p1 = *it1;
        cout << "key : " << p1.first << " , " << "value : " << p1.second << endl;
        it1++;
    }
    cout << endl;

    // *************************************** //

    // creation
    unordered_map<string, string> table;

    // insertion
    table["in"] = "India";

    table.insert(make_pair("en", "England"));

    pair<string, string> p;
    p.first = "br";
    p.second = "Brazil";
    table.insert(p);

    // size
    cout << "Size : " << table.size() << endl
         << endl;

    // table[key] and table.at(key)
    cout << "Value at key=>in : " << table["in"] << endl
         << endl;
    cout << "Value at key=>in using at() : " << table.at("in") << endl
         << endl;

    // updation
    table.at("in") = "Bharat";
    cout << "Updated key=>in : " << table.at("in") << endl
         << endl;

    // iterator
    unordered_map<string, string>::iterator it = table.begin();
    cout << "The Map : " << endl;
    while (it != table.end())
    {
        pair<string, string> p = *it;
        cout << "key : " << p.first << " , " << "value : " << p.second << endl;
        it++;
    }
    cout << endl;

    // find
    if (table.find("jp") != table.end())
    {
        cout << "key found!" << endl
             << endl;
    }
    else
    {
        cout << "key not found!" << endl
             << endl;
    }

    // count
    if (table.count("in") == 0)
    {
        cout << "(count) key not found!" << endl
             << endl;
    }
    if (table.count("in") == 1)
    {
        cout << "(count) key found!" << endl
             << endl;
    }

    // clear
    table.clear();
    cout << "Size after clear : " << table.size() << endl
         << endl;

    // empty
    if (table.empty())
    {
        cout << "Map is empty!" << endl
             << endl;
    }
    else
    {
        cout << "Map is not empty!" << endl
             << endl;
    }

    // erase
    table["in"] = "India";
    table["ch"] = "China";
    table["sr"] = "Sri Lanka";
    table.erase(table.begin(), table.end());
    cout << "Size of table after erase : " << table.size() << endl
         << endl;

    return 0;
}