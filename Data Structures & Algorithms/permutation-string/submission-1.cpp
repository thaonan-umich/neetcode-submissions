class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        // 1. Init
        unordered_map<char, int> maps1;
        int s1_size = s1.size();

        for (char c : s1){
            auto it = maps1.find(c);
            if (it == maps1.end()){
                maps1.insert({c, 1});
            }
            else{
                it->second++;
            }
        }
        
        // 2. Loop
        
        int left = 0;
        unordered_map<char, int> window_map;


        while(left + s1_size - 1 <= s2.size() - 1){

            window_map.clear();

            for (int step = 0; step < s1_size; ++step){
                auto it = window_map.find(s2[left + step]);
                if (it == window_map.end()){
                    window_map.insert({s2[left+step], 1});
                }
                else{
                    it->second++;
                }
            }

            if (window_map == maps1){
                return true;
            }


            left++;
        }

        return false;
    }
};
