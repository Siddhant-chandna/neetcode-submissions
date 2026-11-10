class Solution {
public:
    bool cycle(int i, vector<vector<char>> &adj, vector<int> &vis, vector<int> &pathVis, string &ans){
        vis[i]=1;
        pathVis[i]=1;
        for(auto x:adj[i]){
            int y=x-'a';
            if(!vis[y]){
                if(cycle(y, adj, vis, pathVis, ans)) return true;
            } else if(pathVis[y]) return true;
        }
        ans+=(i+'a');
        pathVis[i]=0;
        return false;
    }
    string foreignDictionary(vector<string>& words) {
        vector<vector<char>> adj(26);
        for(int i=1;i<words.size();i++){
            string a=words[i-1];
            string b=words[i];
            int len=min(a.size(), b.size());
            bool found=false;
            for(int j=0;j<len;j++){
                if(a[j]!=b[j]){
                    adj[b[j]-'a'].push_back(a[j]);
                    found=true;
                    break;
                }
            }
            if(!found && a.size()>b.size()) return "";
        }
        vector<bool> present(26, false);
        for(auto x:words){
            for(auto y:x){
                present[y-'a']=true;
            }
        }
        vector<int> vis(26, 0);
        vector<int> pathVis(26,0);
        string ans="";
        for(int i=0;i<26;i++){
            if(present[i] && !vis[i]){
                if(cycle(i, adj, vis, pathVis, ans)) return "";
            }
        }
        return ans;
    }
};
