class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // 1. Init
        int right_pointer = nums.size() - 1;
        int left_pointer = 0;

        int mid_pointer;
        int mid_num;

        // 2. Loop
        while (left_pointer <= right_pointer){
            mid_pointer = (left_pointer + right_pointer) / 2;
            mid_num = nums[mid_pointer];

            if (mid_num == target){
                return mid_pointer;
            }

            if (mid_num < target){
                left_pointer = mid_pointer + 1;
            }
            if (mid_num > target){
                right_pointer = mid_pointer - 1;
            }

        }

        return -1;

    }
};
