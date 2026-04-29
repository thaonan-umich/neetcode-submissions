class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> uset;
        unordered_set<int> starts_set;

        // O(n)
        for (auto it = nums.begin(); it != nums.end(); ++it){
            uset.insert(*it);
        }

        // O(n)
        for (auto it = uset.begin(); it != uset.end(); ++it){
            if (uset.find(*it - 1) == uset.end())       // 不存在
                starts_set.insert(*it);
        }

        int max_size = 0;

        
        // max k * O(n)
        for (auto it = starts_set.begin(); it != starts_set.end(); ++it){
            int curr_size = 1;
            int curr_element = *it;

            while (uset.find(curr_element + 1) != uset.end()){
                curr_element++;
                curr_size++;
            }

            if (curr_size > max_size)
                max_size = curr_size;
        }

        return max_size;

         
    }
};
