class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int x=digits[digits.size()-1]+1;
        carry=x/10;
        digits[digits.size()-1]=x%10;
        for(int i=digits.size()-2;i>=0;i--){
            int x=digits[i];
            x+=carry;
            carry=x/10;
            digits[i]=x%10;
        }
        vector<int> ans(digits.size()+1);
        if(carry>0) {
            for(int i=digits.size()-1;i>=0;i--){
                ans[i+1]=digits[i];
            }
            ans[0]=carry;
        }
        return carry>0?ans:digits;
    }
};
