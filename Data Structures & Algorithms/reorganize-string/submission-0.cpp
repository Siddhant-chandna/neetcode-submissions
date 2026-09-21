class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> m;
        for(auto x:s){
            m[x]++;
        }
        priority_queue<pair<int,char>> q;
        for(auto x:m){
            q.push({x.second, x.first});
        }
        string ans="";
        while(q.size()>=2){
            auto a=q.top();
            q.pop();
            auto b=q.top();
            q.pop();
            ans+=a.second;
            ans+=b.second;
            if(--a.first>0) q.push({a.first, a.second});
            if(--b.first>0) q.push({b.first, b.second});
        }
        if(!q.empty()){
           auto a=q.top();
           if(a.first>1) return "";
           ans+=a.second; 
        }
        return ans;
    }
};