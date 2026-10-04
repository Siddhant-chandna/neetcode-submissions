class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int n=intervals.size();
        vector<int> curr=intervals[0];
        int ans=1;
        for(int i=1;i<intervals.size();i++){
            if(curr[1]<=intervals[i][0]){
                ans++;
                curr=intervals[i];
            }
        }
        return n-ans;
    }
};
