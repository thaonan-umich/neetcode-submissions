class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // 1. init
        unordered_map<int, int> umap;
        int pointer = 0;
        int n = nums.size();

        // 2. loop
        while (pointer < n){
            auto it = umap.find(nums[pointer]);

            if (it != umap.end()){
                it->second++;
            }
            else{
                umap.insert({nums[pointer], 1});
            }

            pointer++;
        }

        // 3. sort by key
        vector<pair<int, int>> vec(umap.begin(), umap.end());

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        // 4. return by slicing
        vector<int> answer;
        int answer_pointer = 0;

        while (answer_pointer < k){
            answer.push_back(vec[answer_pointer].first);
            answer_pointer++;
        }

        return answer;

    }
};
