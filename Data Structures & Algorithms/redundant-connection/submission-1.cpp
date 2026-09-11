class Solution {
public:
    int findParent(int &x, vector<int> &parent){
        if(x==parent[x]) return x;
        return parent[x]=findParent(parent[x], parent);
    }
    bool unionPar(int u_par, int v_par, vector<int> &rank, vector<int> &parent){
        if(u_par==v_par) return false;
        if(rank[u_par]<rank[v_par]){
            parent[u_par]=v_par;
        } else if(rank[u_par]>rank[v_par]){
            parent[v_par]=u_par;
        } else{
            parent[u_par]=v_par;
            rank[v_par]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> rank(n+1,0);
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            int u_par=findParent(u, parent);
            int v_par=findParent(v, parent);
            if(!unionPar(u_par, v_par, rank, parent)) return {u,v};
        }
        return {};
    }
};
