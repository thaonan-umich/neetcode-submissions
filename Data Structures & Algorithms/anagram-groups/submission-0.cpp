class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // 1. Init
        map<map<char, int>, vector<string>> umap;

        // 2. Loop
        int word_pointer = 0;
        while (word_pointer < strs.size()){

            // 2.1 get the word
            string word = strs[word_pointer];

            // 2.2 contruct chars map of this word
            map<char, int> chars_map_of_word;
            int char_pointer = 0;

            while (char_pointer < word.size()){
                auto it = chars_map_of_word.find(word[char_pointer]);
                if (it != chars_map_of_word.end())
                    it->second++;
                else{
                    chars_map_of_word.insert({word[char_pointer], 1});
                }

                char_pointer++;
            }

            // 2.3 check umap;
            auto it = umap.find(chars_map_of_word);

            if (it != umap.end()){
                it->second.push_back(word);
            }
            else{
                vector<string> insert_list = {word};
                umap.insert({chars_map_of_word, insert_list});
            }

            word_pointer++;
        }


        // 3. iter through map
        vector<vector<string>> results;
        for (const auto& [key, val] : umap){
            results.push_back(val);
        }
        
        return results;
        
    }
};
