#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        // auto it = find(s.rbegin(), s.rend(),' ');
        // return it - s.rbegin();
        // if (it != s.rend()) return it - s.rbegin();
        // else return 0;
        auto itOfSpace = s.begin();
        auto itOfStr = s.begin();
        for (auto it = s.end() - 1; it >= s.begin(); --it) {
            if (*it == ' ') {
                itOfSpace = it;
            }
            else {
                itOfStr = it;
                break;
            }
        }

        for (auto it = itOfStr; it >= s.begin(); --it) {
            if (*it == ' ')
            return itOfStr - it;
        }
        return itOfStr - s.begin() + 1;
    }
};
int main() {
    Solution s;
    cout << s.lengthOfLastWord("World ");
}