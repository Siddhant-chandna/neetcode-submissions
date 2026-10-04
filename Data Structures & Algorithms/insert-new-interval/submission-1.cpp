class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({newInterval[0], newInterval[1]});
        if(intervals.size()==1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> curr=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(curr[1]>=intervals[i][0]){
                curr[1]=max(intervals[i][1], curr[1]);
            } else{
                ans.push_back(curr);
                curr=intervals[i];
            }
        }
        ans.push_back(curr);

        return ans;
    }
};
