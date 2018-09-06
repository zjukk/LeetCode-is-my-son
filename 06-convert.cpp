    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <vector>

    using namespace std;
    //my version:
    string convert(string s, int numRows) {
        if (numRows == 1)
        return s;
        int n = numRows;
        string res;
        for (int i = 0; i < n; i++) {
            int j = i;
            bool flag = true;
                if(j == 0 || j == n-1){//第一行和最后一行
                    res += s[j];
                    j += 2*n-2;
                    while(j < s.size()){
                        res += s[j];
                        j += 2*n-2;
                    }
                } else {//中间行
                bool flag = true;
                    res += s[j];//加入首列元素
                    int row = j;//保存行号
                    j = j + 2*n - 2*row -2;
                    while(j < s.size()){
                        if(flag) {
                            res += s[j];
                            flag = !flag;
                            j += 2*row;
                        }else {
                            res += s[j];
                            flag = !flag;
                            j += 2*n - 2*row - 2;
                        }
                    }
                }
        }
        return res;
    }
    //sol2:
    string convert3(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }

    //smart sol:
    //We can use \text{min}( \text{numRows}, \text{len}(s))min(numRows,len(s)) lists 
    //to represent the non-empty rows of the Zig-Zag Pattern.
    //Iterate through ss from left to right, appending each character to the appropriate row. 
    //The appropriate row can be tracked using two variables: the current row and the current direction.
    //The current direction changes only when we moved up to the topmost row or moved down to the bottommost row.
    string convert2(string s, int numRows) {
        vector<string> rows(min(numRows, (int)s.size()));
        bool goingDown = false;
        int curRow = 0;
        for (char c : s){
            rows[curRow] += c;
            if(curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }
        string res;
        for (string& str : rows){
            res += str;
        }
        return res;
    }
    int main() {
        string str = "PAYPALISHIRING";
        string str2 = "PAY";
        cout << convert(str,4) << endl;
        cout << convert2(str,4);
        return 0;
    }