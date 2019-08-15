#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
        map<int, char> m{{1,'A'},{2,'B'},{3,'C'},{4,'D'},{5,'E'},{6,'F'},{7,'G'},{8,'H'},{9,'I'},{10,'J'},
                         {11,'K'},{12,'L'},{13,'M'},{14,'N'},{15,'O'},{16,'P'},{17,'Q'},{18,'R'},{19,'S'},
                         {20,'T'},{21,'U'},{22,'V'},{23,'W'},{24,'X'},{25,'Y'},{0,'Z'}};
        string res;

        while (n) {
            if (n == 26) {
                res = "Z" + res;
                return res;
            }
            res = m[n%26] + res;
            if (n%26 == 0) n = n/26 - 1; //52->AZ
            else
                n = n/26;
        }
        return res;
    }
};

//SOL2
class Solution2 {
public:
    string convertToTitle(int n) {
        string res;

        while (n) {
            if (n%26 == 0) {
                res = "Z" + res;
                n -= 26;
            } else {
                char tmp = n%26 - 1 + 'A';
                res = tmp + res;
                n -= n%26;
            }
            n /= 26;
        }
        return res;
    }
};
//sol3 more precise
class Solution3 {
public:
    string convertToTitle(int n) {
        string res;
        while (n) {
            res += --n%26 + 'A';
            n /= 26;
        }
        return string(res.rbegin(), res.rend());
    }
};
//recursion
class Solution4 {
public:
    string convertToTitle(int n) {
        return n == 0 ? "" : convertToTitle(n/26) + (char)(--n % 26 + 'A');
    }
};
int main() {
    Solution4 s;
    cout << s.convertToTitle(52);
}