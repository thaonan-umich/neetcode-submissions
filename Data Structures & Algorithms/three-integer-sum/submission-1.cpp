class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& ordered_nums) {
        
        sort(ordered_nums.begin(), ordered_nums.end());
        vector<vector<int>> balanced_triplets;

        for (int anchor = 0; anchor < ordered_nums.size(); anchor++) {

            // anchor already positive -> impossible to balance to zero
            if (ordered_nums[anchor] > 0) break;

            // skip repeated anchor
            if (anchor > 0 &&
                ordered_nums[anchor] == ordered_nums[anchor - 1])
                continue;

            int left_probe = anchor + 1;
            int right_probe = ordered_nums.size() - 1;

            while (left_probe < right_probe) {

                int balance =
                    ordered_nums[anchor] +
                    ordered_nums[left_probe] +
                    ordered_nums[right_probe];

                if (balance > 0) {
                    right_probe--;
                }
                else if (balance < 0) {
                    left_probe++;
                }
                else {
                    balanced_triplets.push_back({
                        ordered_nums[anchor],
                        ordered_nums[left_probe],
                        ordered_nums[right_probe]
                    });

                    left_probe++;
                    right_probe--;

                    while (left_probe < right_probe &&
                           ordered_nums[left_probe] ==
                           ordered_nums[left_probe - 1]) {
                        left_probe++;
                    }
                }
            }
        }

        return balanced_triplets;
    }
};