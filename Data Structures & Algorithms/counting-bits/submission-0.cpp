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
