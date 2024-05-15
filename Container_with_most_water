class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo=0,hi=height.size()-1;
        int mxarea=0;
        while(hi!=lo){
            mxarea=max(mxarea,min(height[hi],height[lo])*(hi-lo));
            if(height[hi]>height[lo]){
                lo++;
            }else hi--;
        }
        return mxarea;
    }
};
