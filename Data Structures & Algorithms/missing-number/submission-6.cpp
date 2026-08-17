// 这用啥位操作啊 感觉杀鸡用牛刀

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        
        int target = 0;

        for (int num : nums){
            if (num != target){
                return target;
            }

            ++target;
        }

        // 如果都到这了还没return 那说明差最后一个
        return target;

    }
};
