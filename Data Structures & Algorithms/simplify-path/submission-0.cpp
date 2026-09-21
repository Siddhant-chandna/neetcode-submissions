class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        stringstream ss(path);
        string token;
        vector<std::string> directories;
        while (getline(ss, token, '/')) {
            if (!token.empty()) { 
                directories.push_back(token);
            }
        }
        for(auto x:directories){
            if(x=="" || x==".") continue;
            if(x==".."){
                if(!s.empty()) s.pop();
            } else{
                s.push(x);
            }
        }
        if(s.empty()) return "/";
        string ans="";
        stack<string> s2;
        while(!s.empty()){
            s2.push(s.top());
            s.pop();
        }
        while(!s2.empty()){
            ans+="/";
            ans+=s2.top();
            s2.pop();
        }
        return ans;
    }
};