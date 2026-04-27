class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        //  1. Init
        int n = nums.size();

        int product_non_zero = 1;
        int zero_nums = 0;
        int zero_index = -1;

        // 2. Loop1
        int init_pointer = 0;
        while (init_pointer < n){
            if (nums[init_pointer] == 0){
                zero_nums++;
                zero_index = init_pointer;
            }
            else{
                product_non_zero = product_non_zero * nums[init_pointer];
            }
            init_pointer++;
        }

        // 3. 3 Cases
        if (zero_nums == 0){
            vector<int> result_vec(n, product_non_zero); 

            int result_pointer = 0;
            while (result_pointer < n){
                result_vec[result_pointer] /= nums[result_pointer];
                result_pointer++;
            }

            return result_vec;
        }
        else if (zero_nums == 1){
            vector<int> result_vec(n, 0);
            result_vec[zero_index] = product_non_zero;
        
            return result_vec;
        }
        else{
            vector<int> result_vec(n, 0);
            return result_vec;
        }
    }
};
