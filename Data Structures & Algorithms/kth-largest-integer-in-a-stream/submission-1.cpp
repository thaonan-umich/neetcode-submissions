class KthLargest {

private:
    int max_size;
    priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    KthLargest(int k, vector<int>& nums) : max_size(k), min_heap(nums.begin(), nums.end()){
        while(min_heap.size() > max_size){
            min_heap.pop();
        }
    }
    
    int add(int val) {

        min_heap.push(val);

        while(min_heap.size() > max_size){
            min_heap.pop();
        }

        return min_heap.top();
    }
};
