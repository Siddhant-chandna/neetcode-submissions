class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
            sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
                    return a[1] < b[1];
                });
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        int remaining=capacity;
        for(auto x:trips){
            int passengers=x[0];
            int start=x[1];
            int end=x[2];
            while(!q.empty() && q.top().first<=start){
                remaining+=q.top().second;
                q.pop();
            }
            remaining-=passengers;
            if(remaining<0) return false;
            q.push({end, passengers});
        }
        return true;
    }
};