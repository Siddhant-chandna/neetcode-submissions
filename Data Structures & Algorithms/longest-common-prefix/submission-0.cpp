class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string x=strs[0];
        int n=x.size();
        for(int i=1;i<strs.size();i++){
            while(x.substr(0,n)!=strs[i].substr(0,n)){
                n--;
            }
        }
        return x.substr(0,n);
    }
};