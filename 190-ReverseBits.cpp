#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<uint32_t> v;
        while (n) {
            int yu = n%2;
            v.push_back(yu);
            n /= 2;
        }
        int size = 32 - v.size();
        for (int i = 0; i < size; ++i) {
            v.push_back(0);
        }
        uint32_t res = 0;
        for (int i = 0; i < v.size(); ++i) {
            res += pow(2,i)*v[v.size()-i-1];
        }
        return res;
    }
};
// 我们只需要把要翻转的数从右向左一位位的取出来，如果取出来的是1，
// 我们将结果res左移一位并且加上1；如果取出来的是0，
// 我们将结果res左移一位，然后将n右移一位即可
class Solution2 {
public:
    uint32_t reverseBits(uint32_t n) {
        int k = 32;
        uint32_t res = 0;
        while (k--) {
            uint32_t bit = n & 1; 
            res += bit*pow(2,k);
            n >>= 1;
        }
        return res;
    }
};
class Solution3 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 1 == 1) {
                res = (res << 1) + 1;
            } else {
                res <<= 1;
            }
            n >>= 1;
        }
        return res;
    }
};
class Solution4 {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res = (res << 1) + (n >> i & 1);//"+"优先级高于 <<
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    Solution4 s;
    uint32_t n = 43261596;
    cout << s.reverseBits(n);
    return 0;
}
