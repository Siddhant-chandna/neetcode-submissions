class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> q;
        for(auto x: points){
            double dist=sqrt((x[0]*x[0])+(x[1]*x[1]));
            q.push({dist,{x[0],x[1]}});
        }
        vector<vector<int>> ans;
        while(k--){
            auto x=q.top();
            q.pop();
            int a=x.second.first;
            int b=x.second.second;
            ans.push_back({a,b});
        }
        return ans;
    }
};
