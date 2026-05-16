class Solution {
public:
    int characterReplacement(string s, int k) {
        // 1. Init
        unordered_set<char> uset(s.begin(), s.end());
        int max_len = 0;

        // 2. loop
        for (char target : uset){
            int left = 0;
            int budget = k;

            // 标准滑窗
            for (int right = 0; right < s.size(); ++right){ // 从最小窗口1开始开始滑动算窗口

                // 核心数据结构心智模型：窗口模型

                //  如果进窗的不是目标字符，扣预算
                if (s[right] != target){
                    budget--;
                }

                

                // 如果预算透支，左边界开始右移，直到把预算吐出来
                while (budget < 0){
                    if (s[left] != target){
                        budget++;
                    }
                    left++;
                }

                max_len = max(max_len, right-left+1);

            }

            
        }

        return max_len;
    }
};
