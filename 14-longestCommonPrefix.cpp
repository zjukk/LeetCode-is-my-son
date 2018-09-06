#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
//Sol1:horizontal scanning
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
            string prefix = strs[0];
            int len = prefix.size();
        for (int i = 1; i < strs.size(); i++) {
            while(prefix.substr(0,len) != strs[i].substr(0,len)){//利用substr横向对比两个string的prefix，把多维的比较降为二维，不断更新prefix进行迭代
                len--;
            }
            prefix = prefix.substr(0,len);
            if (prefix == "")
            return "";
        }
        return prefix;
    }
    //sol2:vertical scanning 纵向循环比较
    string longestCommonPrefix2(vector<string>& strs) {
        if (strs.size() == 0) 
        return "";
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                //if (i == strs[j].size() || strs[j][i] != c)
                if (strs[j][i] == '\0' || strs[j][i] != c)//对应列上字符不相等或者已经没有字符了
                return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
    //sol3:recursion version, Divide and conquer
    
    string prefix(string& str1, string& str2) {
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]){
                return str1.substr(0,i);
            }
        }
        return str1;
    }
    string process(vector<string>& strs, int L, int R) {
        if (L == R) {
            return strs[L];
        }
        int mid = (L + R) / 2;
        string leftPrefix = process(strs, L, mid);
        string rightPrefix = process(strs, mid + 1, R);
        return prefix(leftPrefix,rightPrefix); 
    }
    string longestCommonPrefix3(vector<string>& strs) {
        if (strs.size() == 0)
        return "";
        return process(strs, 0, strs.size() - 1);
    }
int main() {
    vector<string> v = {"abc","abe","abd"};
    string str = longestCommonPrefix3(v);
    cout << str;
}