#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

//借用强大的字符串流stringstream的功能来实现分段和转为整数
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream v1(version1 + ","), v2(version2 + ",");
        int d1, d2;
        char dot;
        while (v1.good() || v2.good()) {
            if (v1.good()) v1 >> d1 >> dot;
            if (v2.good()) v2 >> d2 >> dot;
            if (d1 > d2) return 1;
            if (d1 < d2) return -1;
            d1 = d2 = 0;
        }
        return 0;
    }
};
class Solution2 {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0;
        int num1, num2;
        string d1, d2;
        while (i < n1 || j < n2) {
            while (i < n1 && version1[i] != '.') {
                d1.push_back(version1[i++]);
            }
            num1 = atoi(d1.c_str());//若d1为空，则num1=0
            while (j < n2 && version2[j] != '.') {
                d2.push_back(version2[j++]);
            }
            num2 = atoi(d2.c_str());
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
            d1.clear();
            d2.clear();
            ++i;
            ++j;
        }
        return 0;
    }
};
class Solution3 {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0, num1 = 0, num2 = 0;
        while (i < n1 || j < n2) {
            while (i < n1 && version1[i] != '.') {
                num1 = num1*10 + version1[i] - '0';
                ++i;
            }
            while (j < n2 && version2[j] != '.') {
                num2 = num2*10 + version2[j] - '0';
                ++j;
            }
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
            num1 = num2 = 0;
            ++i;
            ++j;
        }
        return 0;
    }
};
//using strtol
class Solution4 {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        long num1 = 0, num2 = 0;
        char* v1 = (char*)version1.c_str();
        char* v2 = (char*)version2.c_str();
        while (*v1 != '\0' || *v2 != '\0') {
            num1 = strtol(v1, &v1, 10);
            num2 = strtol(v2, &v2, 10);
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
            if (*v1 != '\0') ++v1;
            if (*v2 != '\0') ++v2;
        }
        return 0;
    }
};
int main() {
    Solution4 s;
    cout << s.compareVersion("0","0.1");
}