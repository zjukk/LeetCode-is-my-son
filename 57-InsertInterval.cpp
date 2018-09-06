#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
static bool cmp(const Interval& a, const Interval& b) {
     return a.start < b.start;
 }

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
    vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> ans;
    if (intervals.size() == 0) {
        return ans;
    }
    if (intervals.size() == 1) {
        return intervals;
    }
    sort(intervals.begin(), intervals.end(), cmp);
    int i = 0;
    int start = intervals[0].start;
    int end = intervals[0].end;
    for (int i = 0; i < intervals.size() - 1; i++) {
        if (intervals[i].end < intervals[i+1].start) {
            ans.push_back(intervals[i]);
            start = intervals[i+1].start;
            end = intervals[i+1].end;
        }  else {
            intervals[i+1].start =intervals[i].start;
            intervals[i+1].end = max(intervals[i].end, intervals[i+1].end);
        }
            if (i == intervals.size() - 2) {
            ans.push_back(intervals[i+1]);
        }
    }
    return ans;
}
};

int main() {
    vector<Interval> v;
    v.push_back(Interval(1,3));
    v.push_back(Interval(2,5));
    v.push_back(Interval(6,9));
    vector<Interval> ans = merge(v);
    for (auto i : ans) 
    cout << i.start << i.end;
}