class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // 1. Init
        stack<int> mdStack; // monotonic decreasing stack
        unordered_map<int, int> umap;

        // 2. Loop
        for (int num : nums2){
            if (mdStack.empty()){
                mdStack.push(num);
                continue;
            }
            else{
                // not empty
                if (num < mdStack.top())
                    mdStack.push(num);
                else{

                    while(!mdStack.empty() && mdStack.top() < num){
                        int smaller = mdStack.top();
                        umap.insert({smaller, num});
                        mdStack.pop();
                    }

                    mdStack.push(num);

                }

            }
        }

        // 3. return answer
        vector<int> answer(nums1.size(), -1);
        int pointer = 0;
        while (pointer < nums1.size()){
            auto it = umap.find(nums1[pointer]);
            if (it != umap.end()){
                answer[pointer] = it->second;
            }
            pointer++;
        }

        // 4. return
        return answer;
    }

};