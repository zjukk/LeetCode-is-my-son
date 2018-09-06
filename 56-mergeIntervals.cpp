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
int main() {
	int n;
	cin >> n;
    cin.ignore();
	string str;
	vector<Interval> v;
	vector<Interval> ans;
	vector<int> help;
	for (int i = 0; i < n; i++) {
		getline(cin, str);
		str += ';';
		int cur = 0;
		int pre = 0;
		for (int cur = 0; cur < str.size(); cur++) {
			if (str[cur] == ',' || str[cur] == ';') {
				string s(str, pre, cur);
				help.push_back(atoi(s.c_str()));
				pre = cur + 1;
			}
		}	
	}
    for (int i = 0; i < help.size(); i++) {
			if (i % 2 == 1) continue;
			v.push_back(Interval(help[i], help[i + 1]));
		}

	ans = merge(v);
	for (int i = 0; i < ans.size(); i++) {
        if(i == ans.size() - 1) cout << ans[i].start << "," << ans[i].end;
		else cout << ans[i].start << "," << ans[i].end << ";";
	}
}