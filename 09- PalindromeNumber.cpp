class Solution {
public:
    bool isPalindrome(int x) {
        int y = x;
        if (x == 0) 
            return true;
        if (x < 0) 
            return false;
        int rev = 0;
        int pop = 0;
        while (x != 0) {
            pop = x % 10;
            x /= 10;
            rev = rev*10 + pop;
        }
        if (rev == y) 
            return true;
            else 
                return false;
    }
};