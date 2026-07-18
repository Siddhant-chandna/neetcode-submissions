class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        transform(s.begin(), s.end(), s.begin(),::tolower);
        for(auto x:s){
            if((x>='a' && x<='z') || (x>='0' && x<='9')){
                str+=x;
            }
        }
        int i=0,j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;j--;
        }
        return true;
    }
};
