#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;
// ✔ 顺序无关/置换不变性 -> 考虑排序？
// ❌ 排序后考虑使用头尾双指针，此时题目转化为在剩余的集合中找到一个值，使其和前者的和相加最接近target -> 逆向思维，将题目变为 target - 前者的和，然后在剩余的数组中二分查找。
// ⚠️ 修正：对于 3Sum 问题，不能直接在整个数组上只用一对双指针。必须是 Loop + 双指针。即：固定一个，剩下的范围用双指针。
// 💡 提示：在这个问题里，双指针其实是优于二分查找的。固定 i 和 j，对 k 进行二分查找，复杂度是 $O(N^2 \log N)$。固定 i，对 j, k 进行双指针扫描，复杂度是 $O(N^2)$。显然双指针更快。
// ✔ 不动点：双指针始终朝着让 candidate 更接近 target 的方向前进。
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 1. 排序：这是使用双指针的前提
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        // 初始化结果，取前三个数的和作为初始值，避免 INT_MIN/MAX 溢出问题
        int closest_sum = nums[0] + nums[1] + nums[2];
        
        // 2. 固定第一个数 nums[i]
        for (int i = 0; i < n - 2; ++i) {
            // 优化：如果当前数字和上一个数字相同，可以跳过（去重），但在 Closest 题中不是必须的，
            // 且为了逻辑简单可以省略，加上能微小提升效率。
            if (i > 0 && nums[i] == nums[i-1]) continue;

            int L = i + 1;
            int R = n - 1;
            
            // 3. 双指针寻找另外两个数
            while (L < R) {
                int current_sum = nums[i] + nums[L] + nums[R];
                
                // 更新最接近的结果
                if (abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }
                
                // 移动指针逻辑
                if (current_sum == target) {
                    return target; // 距离为0，肯定是最接近的
                } else if (current_sum < target) {
                    L++; // 和太小，左指针右移变大
                    // 优化：跳过重复元素
                    // while (L < R && nums[L] == nums[L-1]) L++; 
                } else {
                    R--; // 和太大，右指针左移变小
                    // 优化：跳过重复元素
                    // while (L < R && nums[R] == nums[R+1]) R--;
                }
            }
        }
        
        return closest_sum;
    }
};
