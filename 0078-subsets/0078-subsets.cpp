class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums, int start = 0, vector<int> processed = {}) {
      
      cout << start << " ";
      if(nums.size() == start){
        vector<vector<int>>vec1;
        vec1.push_back(processed);
        return vec1;
      }
      vector<int>added(processed);
      added.push_back(nums[start]);
      vector<vector<int>>vec2 = subsets( nums, start+1, processed );
      vector<vector<int>>vec1 = subsets( nums, start+1, added);
      vec1.insert( vec1.end(), vec2.begin(), vec2.end() );
      return vec1;
    }
};