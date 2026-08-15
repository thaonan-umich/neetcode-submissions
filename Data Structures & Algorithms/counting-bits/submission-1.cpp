// 这个是一个典型的得写出来大量例子观察才能找到规律的
// 而且还得竖着对齐写才能更方便找到规律，视角很重要

class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> dp(n+1, 0);
        
        int current_offset = 1;
        int next_offset = 2;

        for (int i = 1; i < n+1; ++i){

            if (i == next_offset){
                current_offset = next_offset;
                next_offset *= 2;
            }
            
            dp[i] = 1 + dp[i - current_offset];
        }

        return dp;
    }
};
