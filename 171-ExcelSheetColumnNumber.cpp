#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <cmath>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            res += (s[s.size()-1-i] - 'A' + 1)*pow(26,i);
        }
        return res;
    }
};
int main() {
    Solution s;
    cout << s.titleToNumber("ZY");
}