class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // 初始化一个最大堆
        priority_queue<int, vector<int>> max_heap(stones.begin(), stones.end());

        while (max_heap.size() > 1){
            int big1 = max_heap.top();
            max_heap.pop();
            int big2 = max_heap.top();
            max_heap.pop();

            if (big1 - big2 == 0)
                continue;
            else{
                max_heap.push(big1 - big2);
            }
        }

        if (max_heap.size() == 1){
            return max_heap.top();
        }
        else if (max_heap.size() == 0){
            return 0;
        }

    }
};
