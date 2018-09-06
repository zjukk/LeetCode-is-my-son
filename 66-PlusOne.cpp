#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int shang = 1;
        int yu = 0;
        for (int i = n-1; i >= 0; --i) {
            yu = (digits[i] + shang) % 10;
            shang = (digits[i] + shang) / 10;
            digits[i] = yu;
        }
        if (shang == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};
int main() {
    Solution s;
    vector<int> digits = {9,9,9};
    s.plusOne(digits);
    for (auto i : digits) 
        cout << i;
}