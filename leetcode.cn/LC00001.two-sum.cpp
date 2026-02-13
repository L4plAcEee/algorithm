class Solution {
public:
    // hash缓存法
    // 建立从 Target - nums[idx] 到 idx 的映射
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); ++i) {
            um[target - nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (um.find(nums[i]) != um.end() && i != um[nums[i]]) return {i, um[nums[i]]};
        } 
        return {0, 0};
    }
};
