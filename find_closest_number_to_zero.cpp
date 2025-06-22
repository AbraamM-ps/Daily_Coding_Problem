class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int min = nums[0];
        for (int i = 0; i < nums.size(); i++){
            if (std::abs(min) > std::abs(nums[i])){
                min = nums[i];
            }
            if (std::abs(min) == std::abs(nums[i])){
                min = std::max(nums[i], min);
            }
        }
        return min; 

        // Space Complexity O(1)
        // Time Complexity O(n)
    }
};
