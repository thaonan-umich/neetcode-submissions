class Solution {
public:
    bool isPalindrome(string s) {
        string pure_s;

        for (char c : s){
            if ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
                pure_s += c;
            }
        }

        int pointer = 0;
        while (pointer < pure_s.length()) {
            if (isupper(pure_s[pointer])) {
                pure_s[pointer] = tolower(pure_s[pointer]);
            }
            pointer++;
        }

        int left_pointer = 0;
        int right_pointer = pure_s.size() - 1;

        while (left_pointer < right_pointer){
            if (pure_s[left_pointer] == pure_s[right_pointer]){
                left_pointer++;
                right_pointer--;
            }
            else{
                break;
            }
        }

        if (left_pointer < right_pointer){
            return false;
        }
        else{
            return true;
        }
    }
};
