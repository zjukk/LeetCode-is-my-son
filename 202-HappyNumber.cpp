#include <iostream>
#include <cmath>
#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if (n <= 0) return false;
        set<int> rec;
        rec.insert(n);
        while (n != 1) {
            int happy = 0;
            while (n != 0) {
                happy += pow(n%10, 2);
                n /= 10;
            }
            n = happy;
            if (rec.count(n)) return false;
            rec.insert(n);
        }
        return true;
    }
};
int main() {
    Solution s;
    cout << s.isHappy(2);
}