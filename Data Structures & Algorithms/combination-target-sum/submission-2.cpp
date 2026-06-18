/*

                     [ 开始: sum=0, path=[] ]
                     /          |         \     \
                选 2 /        选 5 |        选 6 \   \ 选 9
                   /            |           \     \
        [sum=2, path=[2]]   [sum=5, path=[5]]  ...  [sum=9, path=[9]] 🎉 (命中!)
          /      |     \         |
      选 2/    选 5|   ...     选 5| (不能选2了!)
         /       |               |
 [sum=4, [2,2]] [sum=7, [2,5]] [sum=10, [5,5]] ❌ (>9, 回溯)
     /     \         |
 选 2/   选 5\     选 5\
   /         \         \
[sum=6,     [sum=9,   [sum=12, [2,5,5]] ❌ (>9, 回溯)
[2,2,2]]   [2,2,5]] 🎉 
  /          (命中!)
选 2/ 
  /
[sum=8, [2,2,2,2]]
  /       \
选 2\     选 5\
[sum=10]❌ [sum=13]❌
(>9回溯)   (>9回溯)
*/


class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum_now = 0;

    void dfs(vector<int>&nums, int start, int target){
        
        // 每到下一层，先把到这一层之前的路径加入结果中（还不包括这个节点）
        if (sum_now == target){
            res.push_back(path);
            return;
        }
        
        if (sum_now > target)
            return;         // 可以剪枝？

        // 如果还没大于等于，构建下一层所有选择, 从start开始，保证不选当前位置之前的元素
        for (int i = start; i < nums.size(); ++i){

            // 进入其中一个选择
            path.push_back(nums[i]);
            sum_now += nums[i];

            // 继续往下选
            dfs(nums, i, target);   // 传入i而不是 i+1， 允许下一层继续选择当前的[i]

            // 回溯
            path.pop_back();
            sum_now -= nums[i];

        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums, 0, target);
        return res;
    }
};
