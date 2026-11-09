class Solution {
public:
    bool checkCycle(int i, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj, stack<int> &st){
        vis[i]=1;
        pathVis[i]=1;
        for(auto x:adj[i]){
            if(!vis[x]){
                if(checkCycle(x, vis, pathVis, adj, st)) return true;
            } else if(pathVis[x]) return true;
        }
        st.push(i);
        pathVis[i]=0;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(checkCycle(i, vis, pathVis, adj, st)) return {};
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
