class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_map<char,int> m;
        int i=0,j=1;
        m[s[0]]++;
        int ans=1;
        while(i<j && j<s.size()){
            while(i<j && m.find(s[j])!=m.end()){
                m.erase(s[i]);
                i++;
            } 
            m[s[j]]++;
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
