class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = nums.size()-1;
        int maxes_found=0;
        if(nums.size()==2){
            return nums[nums.size()-1];
        }
        
        else if(nums.size()>2){
            
            while(maxes_found<2 && i>0){
                if(nums[i]==nums[i-1]){
                    i--;
                }else if(nums[i]!=nums[i-1]){
                    i--;
                    maxes_found++;
                }
            }
            
        }
        // if(maxes_found==1){
        //     return nums[nums.size()-1];
        // }
        return maxes_found>1 ? nums[i]:nums[nums.size()-1];
    }
};