class Solution {
public:
    int getParent(int &x, vector<int> &parent){
        if(x==parent[x]) return x;
        return parent[x]=getParent(parent[x], parent);
    }
    bool unionAll(int u, int v, vector<int> &parent, vector<int> &rank){
        int par_u=getParent(u, parent);
        int par_v=getParent(v, parent);
        if(par_u==par_v) return false;
        if(rank[par_u]<rank[par_v]){
            parent[par_u]=par_v;
        } else if(rank[par_v]<rank[par_u]){
            parent[par_v]=par_u;
        } else{
            parent[par_u]=par_v;
            rank[par_v]++;
        }
        return true;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> rank(n,-1);
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            if(unionAll(u,v, parent, rank)){
                n--;
            }
        }
        return n;
    }
};
