class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> db;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        db[key].push_back({timestamp, value});  // c++ unordered_map 没命中会自己创建
    }
    
    string get(string key, int timestamp) {
        if (db.find(key) == db.end())
            return "";
        
        const auto& pairs_vec = db[key];

        int left = 0;
        int right = pairs_vec.size() - 1;
        string res = "";

        // 开始二分查找

        while (left <= right){
            int mid = (left + right) / 2;

            if (pairs_vec[mid].first > timestamp){
                right = mid - 1;
            }
            else{   // pairs_vec[mid].first <= timestamp
                // 这是一个OK的答案，先存着
                res = pairs_vec[mid].second;

                // 继续去可能更大的右半部分找
                left = mid + 1;
            }
        }

        return res;
    }
};
