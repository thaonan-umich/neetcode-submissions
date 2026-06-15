class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        // 1. Init
        priority_queue<int> max_heap(nums.begin(), nums.end());

        // 2. Pop
        int index = 0;
        int num_now;

        while (index != k){
            num_now = max_heap.top();
            max_heap.pop();
            index++;
        }

        return num_now;
    }
};
