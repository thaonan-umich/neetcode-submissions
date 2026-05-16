class Solution {
public:
    int characterReplacement(string s, int k) {
        // 0. Init
        unordered_set<char> uset;
        int max_len = 0;

        // 1. 先获取set
        for (char c : s){
            uset.insert(c);
        }

        // 2. 对uset里面每一个字符进行如下循环
        for (char c : uset){

            int left = 0;
            int right = 0;
            int budget = k;


            while (true) {
                // 决定是否要退出

                while (right < s.size()) {
                    // right右移动循环
                    if (s[right] != c)
                        budget -= 1;

                    if (budget == -1){
                        break;
                    }

                    right += 1;
                }

                // 更新最长
                if ((right - left) > max_len)
                    max_len = (right-left);

                if (right == s.size())
                    break;

                while (true){   // left右移动循环

                    if (s[left] != c){
                        left += 1;
                        budget += 1;
                        if (budget == 0)
                            break;
                    }
                    else {
                        left += 1;
                    }
                }

                budget = 0;
                right += 1;

                if (right == s.size())
                    break;
            }
        }
        return max_len;
    }
};
