class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        // 1. Init
        int n = size(nums);
        unordered_map<int, bool> umap;
        int pointer = 0;

        // 2. Loop
        while (pointer != n){
            auto item = umap.find(nums[pointer]);

            if (item == umap.end())
                umap.insert({nums[pointer], true});
            else
                return true;    // 3. return true
            
            pointer++;
        }

        return false;           // 4. return false

    }
};