class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_map<char,int> m;
        int i=0;
        int ans=0;
        for(int j=0;j<s.size();j++){
            if(m.find(s[j])!=m.end()){
                i=max(i, m[s[j]]+1);
            }
            m[s[j]]=j;
            ans=max(ans, j-i+1);
        }
        return ans;
    }
};
