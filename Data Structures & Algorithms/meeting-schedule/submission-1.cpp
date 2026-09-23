/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n==0 || n==1) return true;
        vector<pair<int,int>> v;
        for(auto x:intervals){
            v.push_back({x.start, x.end});
        }
        sort(v.begin(), v.end());
        for(int i=1;i<n;i++){
            if(v[i-1].second>v[i].first) return false;
        }
        return true;
    }
};
