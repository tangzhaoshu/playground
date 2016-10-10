
#include<iostream>
using namespace std;

class A {
public :
    int a;
    A():a(1) {}
    void f() {
        cout <<"a"<<endl;
    }

    void f(int i) {
        cout <<"ai"<<endl;
    }
};

class B: public A {
public:
    int b;
    B():b(2) {}
    void f(char i) {
        cout <<"bi"<<endl;
    }
};

class C: public B {
public:
    int c;
    C():c(3) {}
    void f() {
        cout <<"c"<<endl;
    }

    void f(int i) {
        cout <<"ci"<<endl;
    }
};

#define DEBUG(X) cout<<#X<<" = "<<X<<endl;;
#define TRACE(X) {cout<<#X<<endl; X;}

int main() {
    C* c = new C();
    A* p = c;
    void * vp;
    int* ip = (int*)(vp = p);

    TRACE((*p).f());
    TRACE((*p).f(1));
    TRACE(((A)(*p)).f());
    TRACE(((A)(*p)).f(2));

    DEBUG(sizeof(*p))
    DEBUG(sizeof(*c));
}


