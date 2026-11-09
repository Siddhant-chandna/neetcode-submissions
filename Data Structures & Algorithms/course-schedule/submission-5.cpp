class Solution {
public: 
    bool checkCycle(int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis){
        vis[i]=1;
        pathVis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]){
                if(checkCycle(x, adj, vis, pathVis)) return true;
            } else if(pathVis[x]){
                return true;
            }
        }
        pathVis[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(checkCycle(i, adj, vis, pathVis)) return false;
            }
        }
        return true;
    }
};
