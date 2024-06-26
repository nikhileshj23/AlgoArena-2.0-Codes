class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[lo]){
                if(target>=nums[lo]&&target<=nums[mid]){
                    hi=mid-1;
                }else lo=mid+1;
            }else{
                if(target>=nums[mid]&&target<=nums[hi]) lo=mid+1;
                else hi=mid-1;
            }
        }
        if(nums[hi]==target) return hi;
        else if(nums[lo]==target) return lo;
        else return -1;
    }
};
