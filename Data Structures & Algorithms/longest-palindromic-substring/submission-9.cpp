// 这题硬要DP的话是2D-DP
// 还是双指针写比较爽

class Solution {
public:
    string longestPalindrome(string s) {
        
        // 1. Init
        string res = "";
        int max_len = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i){
            
            // odd情况
            int left = i;
            int right = i;

            while(left >= 0 && right <= n){  // 还在区间之内
                if (s[left] == s[right]){
                    // 更新res和max_len
                    if (right-left+1 > max_len){
                        res = s.substr(left, right-left+1);
                        max_len = right-left+1;
                    }
                    left--;
                    right++;
                }
                else{
                    // 如果不匹配，后续也不可能
                    break;
                }
            }

            // even情况
            left = i;
            right = i+1;

            while(left >= 0 && right <= n){  // 还在区间之内
                if (s[left] == s[right]){
                    // 更新res和max_len
                    if (right-left+1 > max_len){
                        res = s.substr(left, right-left+1);
                        max_len = right-left+1;
                    }
                    left--;
                    right++;
                }
                else{
                    // 如果不匹配，后续也不可能
                    break;
                }
            }

        }

        return res;
    }
};
