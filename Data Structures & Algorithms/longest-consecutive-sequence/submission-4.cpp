class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // O(n)
        unordered_set<int> uset(nums.begin(), nums.end());
        int max_size = 0;

        // O(n)
        for (int element : uset){
            if (uset.find(element - 1) == uset.end()){
                int curr_size = 1;
                int curr_element = element;

                while (uset.find(curr_element + 1) != uset.end()){
                    curr_element++;
                    curr_size++;
                }

                if (curr_size > max_size)
                    max_size = curr_size;
                }
        }

        return max_size;
         
    }
};
