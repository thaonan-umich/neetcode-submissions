class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // 1. Init
        int left = 0;
        int right = nums.size() - 1;

        // 2. Loop
        while (left <= right){
            int mid = (left + right) / 2;

            if (nums[mid] == target){
                return mid;
            }

            // 2.1 先找到有序区间
            if (nums[mid] < nums[left]){    // -> 右边是有序区间
                if (target >= nums[mid] && target <= nums[right]){
                    // 剪左边 搜右边
                    left = mid + 1;
                }
                else{   // 不在有序区间，剪右边搜左边
                    right = mid - 1;
                }
                
            }
            else{   // nums[mid] > nums[left] -> 左边是有序区间
                if (target >= nums[left] && target <= nums[mid]){
                    // 搜左边 剪右边
                    right = mid - 1;
                }
                else{   // 不在有序区间，剪右边搜左边
                    left = mid + 1;
                }
            }
        }

        return -1;

    }
};
