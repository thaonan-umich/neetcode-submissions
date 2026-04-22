class Solution {
public:
    bool isAnagram(string s, string t) {
        
        // 1. len validation
        if (size(s) != size(t))
            return false;

        // 2. Maps construct
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        int pointer = 0;
        while (pointer != size(s)){

            if (s_map.find(s[pointer]) == s_map.end())
                s_map.insert({s[pointer], 1});
            else
                s_map[s[pointer]] += 1;

            if (t_map.find(t[pointer]) == t_map.end())
                t_map.insert({t[pointer], 1});
            else
                t_map[t[pointer]] += 1;

            pointer++;
        }

        // 3. Compare the map
        if (s_map == t_map)
            return true;
        else
            return false;
    } 
};
