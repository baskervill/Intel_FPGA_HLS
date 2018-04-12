#include <bits/stdc++.h>
using namespace std;
class A{
public:
    A(){
        this->test();
    }
private:
    virtual void test(){
        cout<<"This is A's virtual"<<endl;
    }
};
class B : public A{
public:
    B(){
        this->test();
    }
private:
    void test(){
        cout<<"This is B's virtual"<<endl;
    }
};
int main(){
    B b;
    return 0;
}