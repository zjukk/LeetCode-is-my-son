#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int jin = 0;
        int n1 = a.size();
        int n2 = b.size();
        if (n1 < n2) return addBinary(b, a);
        if (n1 != n2)
        b.insert(b.begin(), n1-n2, '0');
        string c = a;
        for (int i = 1; i <= n1; ++i) {
            c[n1-i] = ((a[n1-i]-'0') ^ (b[n1-i]-'0') ^ jin) + '0';
            jin = ((a[n1-i]-'0') + (b[n1-i]-'0') + jin) / 2;
        }
        if (jin == 1) c = "1" + c;
        return c;
    }
};
class Solution2 {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int n1 = a.size() - 1;
        int n2 = b.size() - 1;
        string res;
        while (n1 >= 0 || n2 >= 0) {
            int p = n1 >= 0 ? a[n1--] - '0' : 0;
            int q = n2 >= 0 ? b[n2--] - '0' : 0;
            int sum = (p + q + carry) % 2;
            carry = (p + q + carry) / 2;
            res = to_string(sum) + res;
        }
        return carry == 1 ? "1"+res : res;
    }
};
int main() {
    Solution2 s;
    string a("11");
    string b("11");
    cout << s.addBinary(a,b);
}