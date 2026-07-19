class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(auto x:asteroids){
            bool destroyed=false;
            while(!s.empty() && s.top()>0 && x<0){
                if(s.top()<abs(x)){
                    s.pop();
                } else if(s.top()==abs(x)){
                    s.pop();
                    destroyed=true;
                    break;
                } else {
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed) s.push(x);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};