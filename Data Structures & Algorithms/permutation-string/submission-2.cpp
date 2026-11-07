class Solution {
public:
    bool find(string s2,string s1){
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1==s2;
    }
    bool checkInclusion(string s1, string s2) {
        int n=s1.size(), m=s2.size();
        if(n>m) return false;
        for(int i=0;i<m-n+1;i++){
            if(find(s2.substr(i, n), s1)) return true;
        }
        return false;
    }
};
