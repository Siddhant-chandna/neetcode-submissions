class Solution {
public:
    class DSU{
        public:
            vector<int> parent, sz;
            DSU(int n){
                parent.resize(n);
                sz.assign(n,0);
                for(int i=0;i<n;i++){
                    parent[i]=i;
                }
            }
            int find(int x, vector<int> &parent){
                if(parent[x]==x) return x;
                return parent[x]=find(parent[x], parent);
            }
            bool unionBySize(int u, int v){
                int parU=find(u, parent);
                int parV=find(v, parent);
                if(parU==parV) return false;
                if(sz[parU]<sz[parV]){
                    swap(parU,parV);
                }
                parent[parV]=parU;
                sz[parU]+=sz[parV];
                return true;
            }
    };
    int kruskalAlgo(int n, vector<vector<int>> &edges, int skipEdge, int forcedEdge){
        DSU dsu(n);
        int count=0;
        int sum=0;

        if(forcedEdge!=-1){
            for (auto& e : edges) {
                if (e[3] == forcedEdge) {
                    dsu.unionBySize(e[0], e[1]);
                    sum += e[2];
                    count++;
                    break;
                }
            }
        }

        for(auto x:edges){
            int u=x[0];
            int v=x[1];
            int w=x[2];
            int i=x[3];

            if(skipEdge==i || forcedEdge==i) continue;

            if(dsu.unionBySize(u,v)){
                sum+=w;
                count++;
                if(count==n-1) break;
            }
        }
        if(count!=n-1) return INT_MAX;
        return sum;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const auto &a, const auto& b){
            return a[2]<b[2];
        });

        int original=kruskalAlgo(n, edges, -1, -1);
        vector<int> critical;
        vector<int> pseudoCritical;
        for(int i=0;i<edges.size();i++){
            int without=kruskalAlgo(n, edges, i, -1);
            if(without>original) critical.push_back(i);
            else{
                int with=kruskalAlgo(n, edges, -1, i);
                if(with==original) pseudoCritical.push_back(i);
            }
        }
        return {critical, pseudoCritical};
    }
};