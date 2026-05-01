class MinStack {

private:
    stack<int> main_stack;
    stack<int> sub_stack;
public:
    MinStack() {
    }
    
    void push(int val) {

        main_stack.push(val);
        
        if(sub_stack.empty()){
            sub_stack.push(val);
        }
        else{
            if (val < sub_stack.top()){
                sub_stack.push(val);
            }
            else{
                sub_stack.push(sub_stack.top());
            }
        }

    }
    
    void pop() {
        main_stack.pop();
        sub_stack.pop();
    }
    
    int top() {
        return main_stack.top();
    }
    
    int getMin() {
        return sub_stack.top();
    }
};
