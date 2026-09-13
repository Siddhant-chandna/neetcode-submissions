class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0}; 
        vector<int> adj[n];
        vector<int> inDegree(n,0);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            inDegree[x[0]]++;
            inDegree[x[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==1) q.push(i);
        } 
        int remaining=n;
        while(remaining>2){
            int size=q.size();
            remaining-=size;
            for(int i=0;i<size;i++){
                int leaf=q.front();
                q.pop();
                for(auto x:adj[leaf]){
                    inDegree[x]--;
                    if(inDegree[x]==1) q.push(x);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};