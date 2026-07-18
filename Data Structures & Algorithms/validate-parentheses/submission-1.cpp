class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto x:s){
            if(x==')' || x=='}' || x==']'){
                if(!stk.empty() && ((stk.top()=='(' && x==')') || 
                    (stk.top()=='{' && x=='}') || (stk.top()=='[' && x==']'))){
                    stk.pop();
                } else {
                    return false;
                }
            } else{
                stk.push(x);
            }
        }
        return stk.empty();
    }
};
