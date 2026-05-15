class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // 1. Init
        unordered_set<char> uset;
        int max_size = 0;
        int left = 0;   // 左边界
        int right = 0;

        // 2. Loop
        while (right < s.size()){

            while (uset.find(s[right]) != uset.end()){  // 已经存在
                uset.erase(s[left]);
                left++;
            }
            
            // 不存在就加进去
            uset.insert(s[right]);
            max_size = max(max_size, right-left+1);

            right++;
        }

        // 3. return
        return max_size;
    }
};
