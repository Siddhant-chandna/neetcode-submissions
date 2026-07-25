class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum=0;
        m[sum]++;
        int count=0;
        for(auto x:nums){
            sum+=x;
            if(m.find(sum-k)!=m.end()){
                count+=m[sum-k];
            }
            m[sum]++;
        }
        return count;
    }
};