class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n=s.size();
        string count="";
        string repeatChar="";
        int r=0;
        while(r<n){
            if(s[r]=='['){
                st.push(repeatChar);
                st.push(count);
                repeatChar="";
                count="";
            } else if(s[r]==']'){
                int num=stoi(st.top());
                st.pop();
                string temp="";
                for(int i=0;i<num;i++){
                    temp+=repeatChar;
                }
                repeatChar=st.top()+temp;
                st.pop();
            } else if(s[r]>='0' && s[r]<='9'){
                count+=s[r];
            } else if(s[r]>='a' && s[r]<='z'){
                repeatChar+=s[r];
            }
            r++;
        }
        return repeatChar;
    }
};