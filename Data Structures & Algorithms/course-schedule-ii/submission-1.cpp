class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> answer;
        int index = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            index++;
            answer.push_back(node);

            for (int next : adj[node]) {
                if (--indegree[next] == 0)
                    q.push(next);
            }
        }

        if (index != numCourses) {
            return {};
        }

        return answer;
    }
};
