#include<iostream>
using namespace std;
class B

{

    public:

        int ib;

        char cb;

    public:

        B():ib(0),cb('B') {}

        virtual void f() { cout << "B::f()" << endl;}

        virtual void Bf() { cout << "B::Bf()" << endl;}

};

class B1 : public B

{

    public:

        int ib1;

        char cb1;

    public:

        B1():ib1(11),cb1('1') {}

        virtual void f() { cout << "B1::f()" << endl;}

        virtual void f1() { cout << "B1::f1()" << endl;}

        virtual void Bf1() { cout << "B1::Bf1()" << endl;}
};

class B2: public B

{

    public:

        int ib2;

        char cb2;

    public:

        B2():ib2(12),cb2('2') {}

        virtual void f() { cout << "B2::f()" << endl;}

        virtual void f2() { cout << "B2::f2()" << endl;}

        virtual void Bf2() { cout << "B2::Bf2()" << endl;}
};

class D : public B1, public B2

{

    public:

        int id;

        char cd;

    public:

        D():id(100),cd('D') {}

        virtual void f() { cout << "D::f()" << endl;}

        virtual void f1() { cout << "D::f1()" << endl;}

        virtual void f2() { cout << "D::f2()" << endl;}

        virtual void Df() { cout << "D::Df()" << endl;}
};

int main()
{
    typedef void(*Func)(void);
    D d;
    int **pd = (int**)&d;
    int i = 0;
    cout << "+++++++++++++++++++B1_vTable+++++++++++++++++" << endl;
    while(i < 6)
    {
        Func f = (Func)(pd[0][i]);
        f();
        i++;
    }
    int s = (int)(pd[1]);
    cout << s << endl;
    int *p = (int *)&d;
    char c = (char)*(p + 2);
    cout << c << endl;
    s = (int)(pd[3]);
    cout << s << endl;
    c = (char)*(p + 4);
    cout << c << endl;
    cout << "===================B2_vTable=================" << endl;
    i = 0;
    while(i < 4)
    {
        Func f = (Func)(pd[5][i]);
        f();
        i++;
    }
    s = (int)(pd[6]);
    cout << s << endl;
    c = (char)*(p + 7);
    cout << c << endl;
    s = (int)(pd[8]);
    cout << s << endl;
    c = (char)*(p + 9);
    cout << c << endl;
    s = (int)(pd[10]);
    cout << s << endl;
    c = (char)*(p + 11);
    cout << c << endl;
    return 0;
}
