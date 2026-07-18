class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(auto x:s){
            m[x]++;
        }
        for(auto y:t){
            m[y]--;
        }
        for(auto x:m){
            if(x.second!=0) return false;
        }
        return true;
    }
};
