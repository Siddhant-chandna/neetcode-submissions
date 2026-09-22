class Solution {
public:
    double myPow(double x, int n) {
        int i=1;
        double ans=1.0;
        if(n<0){
            n=-n;
            x=1/x;
        }
        double currentProduct = x;
        while(n>0){
            if (n%2==1) {
                ans*=currentProduct;
            }
            currentProduct*=currentProduct;
            n/=2;
        }
        return ans;
    }
};
