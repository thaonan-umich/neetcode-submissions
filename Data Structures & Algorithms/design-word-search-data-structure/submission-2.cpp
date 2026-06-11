struct TrieNode{
    unordered_map<char, TrieNode*> children_map;
    bool isEnd;

    TrieNode(){
        isEnd = false;
    }
};

class WordDictionary {

private:
    TrieNode* root;

    void clear(TrieNode* node){
        if (node == nullptr)
            return;
        
        for (auto& pair: node->children_map){
            clear(pair.second);
        }

        delete node;
    }

    // 没.就正常搜，没.就开始分支递归搜索
    bool dfs(string& word, int index, TrieNode* node){
        if (index == word.length())
            return node->isEnd;

        char c = word[index];

        if (c == '.'){
            // 遇到 '.', 所有能走的路全部搜一遍

            for (auto& pair: node->children_map){
                if (dfs(word, index + 1, pair.second))
                    return true;
            }

            // 所有分支都试过了都不行
            return false;
        }
        else{
            // 正儿八经的TrieTree匹配
            if (node->children_map.count(c) == 0){
                return false;
            }

            // 有的话进下一个节点继续搜
            return dfs(word, index+1, node->children_map[c]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    ~WordDictionary(){
        clear(root);
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word){
            if (curr->children_map.count(c) == 0){
                curr->children_map[c] = new TrieNode();
            }

            curr = curr->children_map[c];
        } 

        curr->isEnd = true;
    }
    
    bool search(string word) {
        // 不管什么情况，同一从根节点，第一个字符用dfs来找
        return dfs(word, 0, root);
    }

};
