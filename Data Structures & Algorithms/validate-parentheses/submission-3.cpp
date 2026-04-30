class Solution {
public:
    bool isValid(string s) {
        
        // 1. init
        stack<char> ustack;

        for (char c : s){
            
            if (!ustack.empty()){
                char c_top = ustack.top();

                if ((c_top == (c - 1)) || (c_top == '[' && c == ']') || (c_top == '{' && c == '}'))
                    ustack.pop();
                else
                    ustack.push(c);
            }
            else
                ustack.push(c);

        }

        if (ustack.size() == 0)
            return true;
        else
            return false;
    }
};
