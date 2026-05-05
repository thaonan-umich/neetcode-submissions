class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        // 1. init
        vector<pair<int,int>> combined;

        for (int i = 0; i < position.size(); ++i){
            combined.push_back({position[i], speed[i]});
        }

        sort(combined.begin(), combined.end(), [](const auto& a, const auto& b){
            return a.first > b.first;   // 这个看不懂在干啥，但是貌似就是降序排序
        });

        // debug
        for (pair<int, int> element : combined){
            cout << element.first << " ";
        }
        cout << endl;
        for (pair<int, int> element : combined){
            cout << element.second << " ";
        }
        cout << endl;

        // 2. calculate time
        vector<float> times(combined.size(), 0);
        for (int i = 0; i < combined.size(); ++i){
            float time = (float(target - combined[i].first) / float(combined[i].second));
            cout << time << endl;
            
            times[i] = time;
        }

        // debug
        for (float time : times){
            cout << time << " ";
        }

        // 3. 好像不用单调栈？
        float max_time = 0;
        int fleet = 0;
        for (int i = 0; i < times.size(); ++i){
            if (times[i] > max_time){
                max_time = times[i];
                fleet += 1;
            }
        }


        return fleet;
    }
};
