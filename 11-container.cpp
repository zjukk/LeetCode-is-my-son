    #include <iostream>
    #include <string>
    #include <algorithm>
    #include <vector>

    using namespace std;
    //Brute Force
    int maxArea(vector<int>& height) {
        int maxA = 0;
        for (int i = 0; i < height.size(); i++){
            for (int j = i + 1; j < height.size(); j++) {
                maxA = max(maxA, (j-i)*min(height[i],height[j]));
            }
        }
        return maxA;
    }
    //sol2:2pointer 
    int maxArea2(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxA = 0;
        while (i < j) {
            maxA = max(maxA,(j-i)*min(height[i], height[j]));
            height[i] > height[j] ? j-- : i++;//两个指针从两端移动，长的不动，短的移动，每次更新maxA。
        }//If we try to move the pointer at the longer line inwards, we won't gain any increase in area, since it is limited by the shorter line.
        return maxA;
    }

    int main() {
        vector<int> height = {1,8,6,2,5,4,8,3,7};
        cout << maxArea2(height);
    }   