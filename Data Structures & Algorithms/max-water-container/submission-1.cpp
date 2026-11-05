class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j=heights.size()-1;
        int ans=0;
        while(i<j){
            int h=min(heights[i], heights[j]);
            ans=max(ans,h*(j-i));
            if(heights[i]<heights[j]){
                i++;
            } else{
                j--;
            }
        }
        return ans;
    }
};
