class Solution {
public:
    int triangularSum(vector<int>& nums) {
      if(nums.size() == 1){
        return nums[0];
      }
      
      for(auto it = nums.begin(); it != nums.end(); it++){
        if(it != nums.end() - 1){
          *it = (*it + *(it + 1))%10;
        }
      }
      vector<int> u;
      u.assign(nums.begin(),nums.end()-1);
      
      return triangularSum(u);
    }
};