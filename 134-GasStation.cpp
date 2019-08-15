#include <iostream>
#include <vector>

using namespace std;
//O(n2)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cnt = 0;
        for (int i = 0; i < gas.size(); ++i) {
            if (gas[i] >= cost[i]) {
                int tank = gas[i] - cost[i];
                int j = (i + 1) % gas.size();
                while (tank >= 0 && j != i) {
                    tank += gas[j] - cost[j];
                    ++j;
                    j %= gas.size();
                }
                if (j == i && tank >= 0) {
                        return j;
                    } 
            }
        }
        return -1;
    }
};
//O(n)
class Solution2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, sum = 0, total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            //如果sum < 0,从0到i都不能作为起点，start更新为i+1
            if (sum < 0) {
                sum = 0;
                start = i + 1;
            }
        }
        //如果total < 0, 肯定不能到达
        return total < 0 ? -1 : start;
    }
};
//从后往前(TO DO)
class Solution3 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = gas.size() - 1, mx = -1, total = 0;
        for (int i = gas.size() - 1; i >= 0; --i) {
            total += gas[i] - cost[i];
            //如果sum < 0,从0到i都不能作为起点，start更新为i+1
            if () {
                
            }
        }
        //如果total < 0, 肯定不能到达
        return total < 0 ? -1 : start;
    }
};
int main() {
    Solution2 s;
    vector<int> gas  = {5};
    vector<int> cost = {4};

    // [4,5,2,6,5,3]
    // [3,2,7,3,2,9]
    cout << s.canCompleteCircuit(gas, cost);
}