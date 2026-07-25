class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(auto x:nums){
            s.insert(x);
        }
        int count=1;
        int prev=INT_MIN;
        int ans=0;
        for(auto x:s){
            if(prev+1!=x){
                count=1;
            }
            else{
                count++;
            }
            prev=x;
            ans=max(ans, count);
        }
        return ans;
    }
};
