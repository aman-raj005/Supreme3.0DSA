#include<iostream>
using namespace std;

class abc{
    mutable int x;
    int *y;
    int z;
    public: 
    abc(){
        x = 0;
        y = new int(0);
        z = 0;
    }
    abc(int _x, int _y, int _z = 1){
        x = _x;
        y = new int(_y);
        z = _z;
    }
    int getX() const{           // const : "This function will not change any member variables of the object."// unless mutable
        x = 50; //gives error, but can change it by adding mutable with x -> but not good practice
        return x;
    }
    void setX(int _val){
        x = _val;
    }
    int getY() const{
        // int f = 20;
        // y = &f; -> gives error
        return *y;
    }
    void setY(int _val){
        *y = _val;
    }
    int getZ() const{
        return z;
    }
};

void printABC(const abc&a){ //getX, getY, and getZ must be const       //const :"I promise not to change a inside this function
    cout << a.getX() << " " << a.getY() << " " << a.getZ() << endl;
}

int main(){
    abc a(1,2,3);
    printABC(a);
    return 0;
}
