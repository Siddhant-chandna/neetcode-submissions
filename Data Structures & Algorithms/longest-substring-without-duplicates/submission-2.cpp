class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int i=0,j=1;
        unordered_map<char,int> m;
        m[s[i]]++;
        int ans=1;
        while(i<j && j<s.size()){
            m[s[j]]++;
            if(m.find(s[j])!=m.end()){
                while(m[s[j]]>1){
                    m[s[i]]--;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
