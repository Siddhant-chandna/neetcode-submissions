class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(auto x:operations){
            if(x=="+"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.push(a);
                s.push(a+b);
            } else if(x=="D") {
                s.push(s.top()*2);
            } else if(x=="C") {
                s.pop();
            } else {
                s.push(stoi(x));
            }
        } 
        int ans=0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};