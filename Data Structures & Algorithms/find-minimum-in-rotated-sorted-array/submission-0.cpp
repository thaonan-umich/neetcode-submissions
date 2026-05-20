class Solution {
public:
    int findMin(vector<int> &nums) {

        // 1. Init
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        // 2. Loop
        while (left < right){
            mid = (left + right) / 2;

            if (nums[mid] < nums[right]){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }

        return nums[left];
        
    }
};
