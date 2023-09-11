class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
      vector<int> res;
      std::vector<int>::iterator it;
      for(vector<int> &i:nums){
          for(int j=i[0];j<=i[1];j++){
            it =std::find(res.begin(),res.end(), j);
            if (it == res.end())
            {
                res.push_back(j);
            }
         }
      }  
      return res.size();
    }
};