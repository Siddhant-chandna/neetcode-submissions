class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
    // Insertion sort:
        // for(int i=1;i<nums.size();i++){
        //     int key=nums[i];
        //     int j=i-1;
        //     while(j>=0 && nums[j]>key){
        //         nums[j+1]=nums[j];
        //         j--;
        //     }
        //     nums[j+1]=key;
        // }
        // return nums;

    //Selection sort:
        // for(int i=0;i<nums.size()-1;i++){
        //     int min_idx=i;
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[j]<nums[min_idx]){
        //             min_idx=j;
        //         }
        //     }
        //     swap(nums[min_idx], nums[i]);
        // }
        // return nums;

    //Bubble Sort:
        for(int i=0;i<nums.size()-1;i++){
            bool swapped=false;
            for(int j=0;j<nums.size()-i-1;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                    swapped=true;
                }
            }
            if(!swapped) break;
        }
        return nums;
    }
};