#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <set>

using namespace std;
using namespace std::placeholders;

class compo {
public:
    compo() { cout << "cmp's ctor" << endl;}
    ~compo() { cout << "cmp's dctor" << endl;}
};
class A {
public:
    A() { cout << "A's ctor" << endl; }
    ~A() { cout << "A's dctor" << endl;}
    compo cmp;
};
class B : public A {
public:
    B() { cout << "B's ctor" << endl; }
    ~B() { cout << "B's dctor" << endl;}
};
int main() {
    B b;
    // compo c;
}
