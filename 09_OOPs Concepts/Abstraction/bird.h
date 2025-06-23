// ifnd    : start header file
#if !defined(BIRD_H)
#define BIRD_H
#include<iostream>

// Abstraction means:

//Hiding how something works and only showing what it does.



class Bird{
public:
    // this is interface
    virtual void eat() = 0; //pure virtual function
    virtual void fly() = 0;
    // classes that inherits this class has to implement pure virtual functions
};

class Sparrow : public Bird{
  public:
    void eat(){
        std::cout << "Sparrow is eating\n";
    }
    void fly(){
        std::cout << "Sparrow is flying \n";
    }
};

class Eagle : public Bird{
  public:
    void eat(){
        std::cout << "Eagle is eating\n";
    }
    void fly(){
        std::cout << "Eagle is flying faster\n";
    }
};

class Pigeion : public Bird{
  public:
    void eat(){
        std::cout << "Pigeion is eating\n";
    }
    void fly(){
        std::cout << "Pigeion is flying \n";
    }
};
#endif // BIRD_H

                      // the below things should be used by using #include"bird.h"
   
//int main() {
//    Bird* b1 = new Sparrow();
//    Bird* b2 = new Eagle();
//    Bird* b3 = new Pigeion();
//
//    b1->eat();   // Output: Sparrow is eating
//    b2->fly();   // Output: Eagle is flying faster
//    b3->eat();   // Output: Pigeion is eating
//
//    return 0;
//}


// Easy Real-Life Example:
//Imagine a Bird class as a contract:
//
// "If you want to be called a Bird, you must know how to eat() and fly()."
//
//Then:
//
// Sparrow says: "Sure! I’ll define how I eat and fly."
//
// Eagle: "I'll define it my way."
//
// Pigeon: "I also have my own style."
//
//Each bird hides internal details of how it eats and flies. You just call eat() or fly(), and it works — that’s abstraction.
//

