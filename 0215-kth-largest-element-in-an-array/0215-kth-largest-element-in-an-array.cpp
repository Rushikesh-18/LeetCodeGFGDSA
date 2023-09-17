class Solution {
    int partition(vector<int>& nums, int l,int r){
        int P=l;
        l=l+1;
        while(l<=r){
            if(nums[l]<nums[P] && nums[r]>nums[P]){
                swap(nums[l],nums[r]);
            }
            if(nums[l]>=nums[P]){
                l++;
            }
            if(nums[r]<=nums[P]){
                r--;
            }
        }
        swap(nums[r],nums[P]);
        return r;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l=0;
        int n=nums.size();
        int r=n-1;
        int pivt_indx=0;
        while(true){
            pivt_indx=partition(nums,l,r);
            if(pivt_indx==k-1){
                return nums[pivt_indx];
            }
            else if(pivt_indx >k-1){
                r=pivt_indx-1;
            }
            else{
                l=pivt_indx+1;
            }
        }
        return nums[pivt_indx];

    }
};