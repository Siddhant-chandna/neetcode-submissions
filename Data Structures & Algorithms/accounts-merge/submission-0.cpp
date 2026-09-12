class Solution {
public:
    int findParent(int x, vector<int> &parent) {
        if(x==parent[x]) return x;
        return parent[x]=findParent(parent[x], parent);
    }
    void unionRank(int u, int v, vector<int> &rank, vector<int> &parent){
        int par_u=findParent(u, parent);
        int par_v=findParent(v, parent);
        if(par_u==par_v) return;
        if(rank[par_u]<rank[par_v]) parent[par_u]=par_v;
        else if(rank[par_v]<rank[par_u]) parent[par_v]=par_u;
        else{
            parent[par_u]=par_v;
            rank[par_v]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        vector<int> rank(n+1,0);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        unordered_map<string,int> m;
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])==m.end()){
                    m[accounts[i][j]]=i;
                }
                else{
                    unionRank(m[accounts[i][j]], i, rank, parent);
                }
            }
        }
        vector<string> merged[accounts.size()];
        for(auto x:m){
            int par=findParent(x.second, parent);
            merged[par].push_back(x.first);
        }
        for(auto x: merged){
            sort(x.begin(), x.end());
        }
        vector<vector<string>> ans;
        for(int i=0;i<accounts.size();i++){
            if(merged[i].empty()) continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(string mail:merged[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};