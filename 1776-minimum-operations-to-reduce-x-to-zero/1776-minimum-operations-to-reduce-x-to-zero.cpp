class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int i=0;
        int j=0;
        int n=nums.size();
        int k=n-1;
        int sumi=0;
        int walk=0;
        int finle=INT_MIN;
        if(nums[i]>x && nums[k]>x ){
            return -1;
        }
        for(int i=0;i<n;i++){
            sumi+=nums[i];
        }
        if(sumi<x){
            return -1;
        }
        int res=sumi-x;
        while(j<n){
            walk += nums[j];
           
            if(walk>res ){
               while(walk>res && i<=j)
                    walk-=nums[i++];
               
             // j++; 
            }
            if(walk==res){
                finle=max(finle,j-i+1);
             
            }
            j++;
        }
        return n-finle;
    }
};