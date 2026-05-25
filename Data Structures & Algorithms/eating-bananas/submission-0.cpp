class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        // 1. Get the max element value
        int max_pile = *max_element(piles.begin(), piles.end());


        // 2. Start Binary Search
        int left = 1;
        int right = max_pile;
        int ans = max_pile;

        while (left <= right){  // 找完所有不用剪枝的
            int mid = (right + left) / 2;   //这哪里会溢出

            if (calculate_need_hours(mid, piles) <= h){
                ans = mid;  // 可行，先记录
                right = mid - 1;    // 剪枝直接找更小
            }
            else{
                left = mid + 1;     // 剪枝直接找更大
            }
        }

        return ans;
    }

    int calculate_need_hours(int k, const vector<int>& piles){
        // 2.1 loop to calculate time
        int need_hours = 0;

        for (int pile : piles){
            need_hours  += (pile + k - 1) / k;  // 到底为啥向上取整可以这么写 完全不懂
        }

        return need_hours;
    }
};
