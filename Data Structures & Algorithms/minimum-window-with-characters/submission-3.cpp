class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(auto x:t){
            m[x]++;
        }
        int i=0;
        int count=t.size();
        int minLen=INT_MAX;
        int start=0;
        for(int j=0;i<=j && j<s.size();j++){
            if(m[s[j]]>0){
                count--;
            }
            m[s[j]]--;
            while(count==0){
                if(j-i+1<minLen){
                    minLen=j-i+1;
                    start=i;
                }
                m[s[i]]++;
                if(m[s[i]]>0){
                    count++;
                }
                i++;
            }
        }
        return minLen==INT_MAX?"":s.substr(start, minLen);
    }
};
