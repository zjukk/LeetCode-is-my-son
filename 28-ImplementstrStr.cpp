#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int len1 = haystack.size();
    int len2 = needle.size();
    int i;
    int j;
    int k;
    for (i = 0; i < haystack.size(); i++) {
        if(len1-i < len2) return -1;
        j = 0;
        k = i;
        while(haystack[k] == needle[j] && j < len2) {
            ++k;
            ++j;
            cout << "a" << i << j;
        }
        if(j == len2) return i;
    }
    return -1;
}

int main() {
  string haystack = "Hello";
  string needle = "ll";
  cout << strStr(haystack, needle);
}