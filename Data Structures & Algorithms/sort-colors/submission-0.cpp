class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0, one=0, two=0;
        for(auto x:nums){
            if(x==0) zero++;
            else if(x==1) one++;
            else two++;
        }
        int i=0;
        while(i<zero){
            nums[i]=0;
            i++;
        }
        while(i<zero+one){
            nums[i]=1;
            i++;
        }
        while(i<zero+one+two){
            nums[i]=2;
            i++;
        }
    }
};