class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size();
        int pointer = 0;

        while (pointer < n){
            int curr_num = abs(nums[pointer]);

            int jum_num = nums[curr_num];

            if (jum_num > 0){
                nums[curr_num] = -1 * nums[curr_num];
            }
            else{
                return curr_num;
            }
            
            pointer++;

        }

    }
};
