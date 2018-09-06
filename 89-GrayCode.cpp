#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//G(n) = B(n+1) XOR B(n) 即 G(n) = B(n+1) + B(n) ，n是正在计算的位
/*
        The purpose of this function is to convert an unsigned
        binary number to reflected binary Gray code.
 
        The operator >> is shift right. The operator ^ is exclusive or.
*/
unsigned int binaryToGray(unsigned int num)
{
        return (num >> 1) ^ num;
}
 
/*
        The purpose of this function is to convert a reflected binary
        Gray code number to a binary number.
*/
unsigned int grayToBinary(unsigned int num)
{
    unsigned int mask;
    for (mask = num >> 1; mask != 0; mask = mask >> 1)
    {
        num = num ^ mask;//把最高位和0异或。任何数和0异或都为其本身，任何数和1异或为取反
    }
    return num;
}
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2, n); ++i) {
            res.push_back((i >> 1)^i);
        }
        return res;
    }
};
//镜像性质
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for (int i = 0; i < n; ++i) {
            int size = res.size();
            for (int j = size - 1; j >= 0; --j) {
                res.push_back(res[j] | (1 << i));
            }
        }
        return res;
    }
};

int main() {

}