class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        vector<int> ans;
        for(int i=temperatures.size()-1;i>=0;i--){
            while(!s.empty() && s.top().first<=temperatures[i]){
                s.pop();
            }
            if(!s.empty()){
                ans.push_back(s.top().second-i);
            } else{
                ans.push_back(0);
            }
            s.push({temperatures[i],i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
