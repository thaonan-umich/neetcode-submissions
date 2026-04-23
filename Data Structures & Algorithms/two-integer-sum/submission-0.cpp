class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // 1. map init
        unordered_map<int, int> umap;

        // 2. loop
        int pointer = 0;
        int n = size(nums);

        while (pointer < n){

            auto it = umap.find(target - nums[pointer]);
            if (it != umap.end()){
                vector<int> answer = {it->second, pointer}; // return 
                return answer;
            }
            else{
                umap.insert({nums[pointer], pointer});
            }

            pointer++;      // 别忘了这个转移循环条件
        }
    }
};
