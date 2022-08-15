class Solution {
  vector<vector<int>> subFunc(vector<int>& nums, int current = 0, vector<int>processed={}){
    if(nums.size() == current){
      vector<vector<int>> vec1;
      vec1.push_back(processed);
      return vec1;
    }
    vector<vector<int>>avoided;
    if(processed.size() == 0 || processed.back() != nums[current]){
      avoided = subFunc(nums, current+1, processed);
    }
    vector<int>added(processed);
    added.push_back(nums[current]);
    vector<vector<int>>included = subFunc(nums, current+1, added);
    avoided.insert(avoided.end(), included.begin(), included.end());
    return avoided;
  }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      return subFunc(nums);
    }
};
  