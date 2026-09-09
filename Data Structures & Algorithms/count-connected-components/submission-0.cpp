class Solution {
public:
    void dfs(int i, vector<int> &vis, vector<vector<int>> adj){
        vis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]) dfs(x, vis, adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                count++;
            }
        }
        return count;
    }
};
