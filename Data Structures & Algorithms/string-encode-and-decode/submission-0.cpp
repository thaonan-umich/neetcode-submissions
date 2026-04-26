class Solution {
public:

    string encode(vector<string>& strs) {
        // Encoder

        // 1. Init
        string result;
        int string_pointer = 0;
        int n = strs.size();

        // 2. Loop
        while (string_pointer < n){
            string str = strs[string_pointer];
            int chars_num = str.size();

            result += to_string(chars_num);
            result += '#';

            result += str;
            string_pointer++;
        }

        return result;
    }

    vector<string> decode(string s) {
        // Decoder

        // 1. Init
        vector<string> results_vec;
        int char_pointer = 0;
        int n = s.size();

        // 2. Loop
        while (char_pointer < n){
            
            // 2.1 scheduling
            string num_str;
            while (s[char_pointer] != '#'){
                num_str += s[char_pointer];
                char_pointer++;
            }

            int num_chars = stoi(num_str);
            char_pointer++; // step over #

            // 2.2 eating
            int eat_count = 0;
            string str;
            while (eat_count != num_chars){
                str += s[char_pointer];
                eat_count++;
                char_pointer++;
            }

            results_vec.push_back(str);

        }

        // 3. return 
        return results_vec;
    }
};
