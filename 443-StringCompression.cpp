#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int cnt = 0;
        for (int i = 0; i < chars.size(); ++i) {
            ++cnt;
            if (i == chars.size() - 1 || chars[i+1] != chars[i]) {
                chars[idx++] = chars[i];
                if (cnt > 1) {
                    for (auto c : to_string(cnt)) {
                        chars[idx++] = c;
                    }
                }
                cnt = 0;
            }
        }
        return idx;
    }
};