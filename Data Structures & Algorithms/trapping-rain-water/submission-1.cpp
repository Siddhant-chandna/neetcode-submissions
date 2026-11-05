class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size(),0);
        vector<int> right(height.size(),0);
        left[0]=height[0];
        for(int i=1;i<height.size();i++){
            left[i]=max(height[i], left[i-1]);
        }
        right[height.size()-1]=height[height.size()-1];
        for(int i=height.size()-2;i>=0;i--){
            right[i]=max(height[i], right[i+1]);
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            int water=min(left[i],right[i])-height[i];
            if(water>0){
                ans+=water;
            }
        }
        return ans;
    }
};
