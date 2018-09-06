#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main() {
    int son = 1;
    int dad = 7;
    cin >> son >> dad;
    int n = 30;
    vector<int> v;
    string s;
    while (--n) {
        son *= 10;
        s.push_back((char)(son / dad + '0'));
        son = son % dad;
        if (!son) break;
    }
    if (son == 0) {
        cout << s << endl;
    } else {
        cout << "infinity: " << s << endl;
    }
}