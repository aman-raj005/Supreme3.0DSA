#include<iostream>
using namespace std;
int main(){
    int a =5;
    cout<<a<<endl;
    int b = a;
    // int c = &a; ->gives error
    int* ptr=&a;
    cout<<&a<<endl;
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;
    cout<<sizeof(ptr)<<endl;
    
             int a = 5;
             cout << a << endl;         // prints: 5
             int b = a;                 // copies value, not address
             // int c = &a;             // ? Error: You can’t assign an address to int
             int* ptr = &a;             // ptr stores address of a
            
             int* p = &a;
             int* q = p;                // q points to same location as p
             cout << "a:" << a << endl;           // 5
             cout << "&a:" << &a << endl;         // address of a
             // cout << "*a:" << *a << endl;      // ? Error: a is not a pointer
             cout << "p:" << p << endl;           // address of a
             cout << "&p:" << &p << endl;         // address of p (pointer)
             cout << "*p:" << *p << endl;         // value at p (5)
             cout << "q:" << q << endl;           // same as p
             cout << "&q:" << &q << endl;         // address of q
             cout << "*q:" << *q << endl;         // same as *p (5)

    
    char ch='a';
    char*cptr=&ch;
    cout<<sizeof(cptr)<<endl;
    long l=1040;
    long*lptr=&l;
    cout<<sizeof(lptr)<<endl;




    int*p=&a;
    // copying pointers
    int*q=p;
    cout<<"a:"<<a<<endl;
    cout<<"&a:"<<&a<<endl;
    // cout<<"*a:"<<*a<<endl; ->gives error
    cout<<"p:"<<p<<endl;
    cout<<"&p:"<<&p<<endl;
    cout<<"*p:"<<*p<<endl;
    cout<<"q:"<<q<<endl;
    cout<<"&q:"<<&q<<endl;
    cout<<"*q:"<<*q<<endl;





    // pointer with arrays
    int arr[]={10,20,30,40};
    int *atr = arr;
    // arr=arr+1;
                   int arr[] = {10, 20, 30, 40};
                   int* atr = arr;            // points to first element
                   // arr = arr + 1;          // ? Error: arr is const pointer in this context


    // char arrays
    char c[100]="loveBabbar";
    cout<<"base address:" <<&c<<endl;
    char*ctr=c;
    cout<<ctr<<endl;
    cout<<"c:"<<c<<endl;
    cout<<"&c:"<<&c<<endl;
    cout<<"c[0]:"<<c[0]<<endl;
    cout<<"&ctr:"<<&ctr<<endl;
    cout<<"*c:"<<*c<<endl;
    cout<<"*(ctr+3):"<<*(ctr+3)<<endl;
    // remember this: it doesnt give 104, it prints lovebabbar
    cout<<"ctr:"<<ctr<<endl;
    cout<<"ctr+3:"<<ctr+3<<endl;

             char c[100] = "loveBabbar" ;
             char* ctr = c ;
             cout << "base address:" << &c << endl;      // address of array
             cout << ctr << endl;                        // prints: loveBabbar
             cout << "c:" << c << endl;                  // also prints: loveBabbar
             cout << "&c:" << &c << endl;                // address of whole array
             cout << "c[0]:" << c[0] << endl;            // l
             cout << "&ctr:" << &ctr << endl;            // address of the pointer ctr
             cout << "*c:" << *c << endl;                // l
             
cout << "*(ctr+3):" << *(ctr+3) << endl;    // e
cout << "ctr:" << ctr << endl;              // loveBabbar
cout << "ctr+3:" << ctr+3 << endl;          // prints from 4th char: eBabbar




    char d='a';
    char *dtr=&d;
    cout<<dtr<<endl;

    char race[100]="racecar";
    char*rtpr=&race[0];
    cout<<"race: "<<race<<endl;
    cout<<"&race: "<<&race<<endl;
    cout<<"*(race+3): "<<*(race+3)<<endl;
    cout<<"rtpr: "<<rtpr<<endl;
    cout<<"&rtpr: "<<&rtpr<<endl;
    cout<<"*(rtpr+3): "<<*(rtpr+3)<<endl;
    cout<<"rtpr+2: "<<rtpr+2<<endl;
    cout<<"*rtpr: "<<*rtpr<<endl;
    cout<<"rtpr+4: "<<rtpr+4<<endl;
                        
                        cout << "race: " << race << endl;           // racecar
                        cout << "&race: " << &race << endl;         // address of array
                        cout << "*(race+3): " << *(race+3) << endl; // e
                        cout << "rtpr: " << rtpr << endl;           // racecar
                        cout << "&rtpr: " << &rtpr << endl;         // address of pointer
                        cout << "*(rtpr+3): " << *(rtpr+3) << endl; // e
                        cout << "rtpr+2: " << rtpr+2 << endl;       // prints: cecar
                        cout << "*rtpr: " << *rtpr << endl;         // r
                        cout << "rtpr+4: " << rtpr+4 << endl;       // prints: car

    
    return 0;
}



