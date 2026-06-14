

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // 1. Init
        priority_queue<pair<int, int>> max_heap; // <距离，序号>, 默认大顶堆
        int max_size = k;
        vector<vector<int>> answers;

        for (int i = 0; i < points.size(); ++i){

            // 获得x, y, index

            int index = i;

            int x = points[i][0];
            int y = points[i][1];

            int distance = (x * x + y * y);

            max_heap.push({distance, index});

            if (max_heap.size() > max_size){
                max_heap.pop();
            }
        }

        while (max_heap.size() != 0){
            int index = max_heap.top().second;
            max_heap.pop();

            answers.push_back(points[index]);
        }

        return answers;


    }
};
