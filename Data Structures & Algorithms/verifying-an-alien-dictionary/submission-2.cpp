class Solution {
public:
    bool valid(string &w1, string &w2, unordered_map<char,int> m){
        int i=0;
        while(i<w1.size() && i<w2.size()){
            if(m[w1[i]]==m[w2[i]]){
                i++;
                continue;
            }
            else if(m[w1[i]]<m[w2[i]]) return true;
            else return false;
        }
        if(w1.size()>w2.size()) return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        for(int i=1;i<=order.size();i++){
            m[order[i-1]]=i;
        }
        for(int i=1;i<words.size();i++){
            if(!valid(words[i-1], words[i], m)) return false;
        }
        return true;
    }
};