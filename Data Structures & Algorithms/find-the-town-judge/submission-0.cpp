class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, unordered_set<int>> adj;
        for(auto x:trust){
            adj[x[0]].insert(x[1]);
        }
        int judge=-1;
        for(int i=1;i<=n;i++){
            if(adj.find(i)==adj.end()){
                if(judge==-1) judge=i;
                else return -1;
            }
        }
        for(int i=1;i<=n;i++){
            if(i==judge) continue;
            else{
                if(adj[i].find(judge)==adj[i].end()) return -1;
            }
        }
        return judge;
    }
};