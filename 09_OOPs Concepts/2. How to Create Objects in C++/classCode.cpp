                              //           code by mee

#include<iostream>
using namespace std ;

// object creation
class student {
 public:
  //constructor
  student(string name,int age,int regno){
    cout<<"this is construcotor"<<endl;
    this->age=age;
    this->name=name;
    this->regno=regno;
  }
  //attribute
  string name;
  int regno;
  int age;

    //copy object
  student(const student &srcobj){
    cout<<"this is copy object"<<endl;
    this->age=srcobj.age;
    this->name=srcobj.name;
    this->regno=srcobj.regno;
  }

  //behaviour
  void work(){
    cout<<"working"<<endl;
  }
  void read(){
    cout<<"reading "<<endl;
  }
   //dconstructor
  ~student(){
    cout<<"this is dconstrucotor"<<endl;
    this->age=age;
    this->name=name;
    this->regno=regno;
  }
};

int main(){
        student aman("aman",233001,19);
        //copy object
        student raj=aman;
        cout<<aman.name<<endl;
        cout<<"next one "<<raj.regno<<endl;
        //dynamic allocation
        student *A=new student("rohit",34,44);
        delete A;
    
  return 0;
}


                                 // code by lakchya 
#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
    //Attributes
    int id;
    int age;
    string name;
    int nos;
    int *gpa;
    // constructor-> ctor: default ctor
    Student(){
        cout<<"Student Default constructor called"<<endl;
    }

    // Parameterised ctor
    Student(int id, int age, string name, int nos,float gpa){
        cout<<"Student Parameterised constructor called"<<endl;
        this->id=id;
        this->age=age;
        this->name=name;
        this->nos=nos;
        this->gpa= new int(gpa);
    }

    // copy ctor
    Student(const Student &srcobj){     //srcobj=>A
        cout<<"Student copy constructor called"<<endl;
        this->id=srcobj.id;
        this->age=srcobj.age;
        this->name=srcobj.name;
        this->nos=srcobj.nos;
    }

    //Behaviors/Methods/Functions
    void study(){
        cout << this->name << "Studying" << endl;
    }
    void sleep(){
        cout << this->name << "Sleeping" << endl;
    }
    void bunk(){
        cout << this->name << "Bunking" << endl;
    }

    //dtor
    ~Student(){
        cout<<"Student Default destructor called"<<endl;
        delete this->gpa;
    }

};

int main(){
    // Using Default Constructor
    // Student A;
    // A.id=1;
    // A.age=15;
    // A.name="Raano";
    // A.nos=6;
    // A.study();

    // Student B;
    // B.id=2;
    // B.age=15;
    // B.name="Rahul";
    // B.nos=5;
    // B.bunk();

    // Student A(1,15,"Raano",6);    //Stack
    // Student B(2,13,"Rahul",4);
    // Student C(3,11,"Reena",6);
    // Student D(4,17,"raman",5);

    // cout<<A.name<<" "<<A.age<<endl;
    // A.bunk();
    // B.sleep();

    // // copy ctor
    // // Student E = A;
    // Student E(A);
    // cout<<E.name<<" "<<A.name<<endl;

    // dynamic memory allocation, or student pointer
    Student *A = new Student(1,14,"Saumya",7,9.45);
    cout<< A->name <<endl;
    cout<< A->age <<endl;
    A->study();
    delete A;
    return 0;
}
