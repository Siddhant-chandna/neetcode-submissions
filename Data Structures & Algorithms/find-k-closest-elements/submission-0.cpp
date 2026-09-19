class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i=0;i<arr.size();i++){
            q.push({abs(x-arr[i]), i});
        }
        vector<int> idx;
        vector<int> ans;
        while(k--){
            auto x=q.top();
            q.pop();
            idx.push_back(x.second);
        }
        sort(idx.begin(), idx.end());
        for(auto x:idx){
            ans.push_back(arr[x]);
        }
        return ans;
    }
};