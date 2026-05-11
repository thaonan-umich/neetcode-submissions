class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        // 1. Allocate
        int l = 0;
        int r = heights.size() - 1;
        int max_water = 0;
        int curr_water = 0;

        // 2. Loop
        while (l < r){

            curr_water = (r-l) * min(heights[l], heights[r]);

            if (curr_water > max_water){
                max_water = curr_water;
            }

            if(heights[l] > heights[r]){
                r--;
            }
            else if(heights[l] < heights[r]){
                l++;
            }
            else{   // (heights[l] == heights[r])
                r--;
                l++;
            }
        }

        return max_water;
    }
};
