class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // 1. Init
        int rowNumber = matrix.size();
        int colNumber = matrix[0].size();
        
        int flat_size = rowNumber * colNumber;


        // 2. Loop Search

        int left_pointer = 0;
        int right_pointer = flat_size - 1;

        int mid_pointer;
        int mid_num;
        int mid_row_index;
        int mid_col_index;

        while (left_pointer <= right_pointer){
            mid_pointer = (left_pointer + right_pointer) / 2;

            mid_row_index = mid_pointer / colNumber;
            mid_col_index = mid_pointer % colNumber;

            mid_num = matrix[mid_row_index][mid_col_index];

            if (mid_num == target)
                return true;
            else{
                if (mid_num < target)
                    left_pointer = mid_pointer + 1;
                else    // mid_num > target
                    right_pointer = mid_pointer - 1;
            }
            
        }

        return false;
    }
};
