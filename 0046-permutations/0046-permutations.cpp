class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums, vector<int>processed={}, int pointer = 0) {
      if(pointer == nums.size()){
        return vector<vector<int>>{processed};
      }
      vector<vector<int>>local_solution;
      for(int i = 0; i <= processed.size(); i++){
        vector<int>processed_copy(processed);
        processed_copy.insert(processed_copy.begin() + i, nums[pointer]);
        vector<vector<int>>result=permute(nums, processed_copy, pointer+1);
        local_solution.insert(local_solution.end(), result.begin(), result.end());
      }
      return local_solution;
    }
};