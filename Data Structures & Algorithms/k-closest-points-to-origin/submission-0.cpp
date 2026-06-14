
struct CompareDistance{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b){
        return a.second < b.second; // 这到底什么玩意 为啥这么写就能是大顶堆 还有这个重载的运算符到底是啥
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // 1. Init
        priority_queue<pair<int, int>, vector<pair<int,int>>, CompareDistance> max_heap; // <序号，距离>
        int max_size = k;
        vector<vector<int>> answers;

        for (int i = 0; i < points.size(); ++i){

            // 获得x, y, index

            int index = i;

            int x = points[i][0];
            int y = points[i][1];

            int distance = (x * x + y * y);

            max_heap.push({index, distance});

            if (max_heap.size() > max_size){
                max_heap.pop();
            }
        }

        while (max_heap.size() != 0){
            int index = max_heap.top().first;
            max_heap.pop();

            answers.push_back(points[index]);
        }

        return answers;


    }
};
