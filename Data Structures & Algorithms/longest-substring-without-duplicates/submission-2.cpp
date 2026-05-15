class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // 1. Init
        unordered_set<char> uset;
        int max_size = 0;

        // 2. Loop
        int pointer = 0;
        int n = s.size();
        int curr_size = 0;

        while (pointer < n){
            
            auto it = uset.find(s[pointer]);
            
            if (it == uset.end()){
                curr_size += 1;
                uset.insert(s[pointer]);
                if (curr_size > max_size)
                    max_size = curr_size;
            }
            else{
                // back loop
                while (s[pointer - 1] != *it){
                    pointer -= 1;
                }
                curr_size = 1;
                uset.clear();
                uset.insert(s[pointer]);
            }

            pointer++;
        }

        return max_size;

    }
};
