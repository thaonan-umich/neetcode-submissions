# 1. 子集 / 组合型

特征:
  - 从数组里选元素
  - 每个元素最多用一次
  - 问有哪些组合

题:
  - subsets
  - subsets II
  - Combination Sum
  - Comination Sum II

模板:
  - for + startIndex

特殊手法：
  1. 跳过下一层和前一次对下一层选择的相同元素
  2. StartIndex = 0 允许每元素被重复选择多次

# 2. 排列型

特征：
  - 顺序重要
  - 所有元素可能在任意位置

题:
  - Permutations

模板:
  - visited数组
  - for循环，i=0开始

# 3. 决策型

特征
  - 当前位置有限决策

题:
  - Generate Parentheses

模板:

```C++
if (choiceA)
  加入
  dfs()
  回溯

 if (choiceB)
  加入
  dfs()
  回溯

```
