
struct TrieNode{
    unordered_map<char, TrieNode*> children_map;
    bool isEnd;

    TrieNode(){
        isEnd = false;
    }
};

class PrefixTree {

private:
    TrieNode* root;

    void clear(TrieNode* node){
        if (node == nullptr)
            return;
        
        // 递归遍历哈希表，释放所有子节点
        for (auto& pair : node->children_map){
            clear(pair.second);
        }

        delete node;
    }

public:
    PrefixTree() {
        root = new TrieNode();
    }

    ~PrefixTree(){
        clear(root);     // clear todo
    }

    void insert(string word) {
        TrieNode* curr = root;

        for (char c : word){
            if (curr->children_map.count(c) == 0){  // 这个字符不在子代表中
                curr->children_map[c] = new TrieNode();
            }

            // 顺着这个字符对应的节点往下走
            curr = curr->children_map[c];
        }

        // 这个路径构造结束，盖个end章
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for (char c : word){
            if (curr->children_map.count(c) == 0){
                return false;
            }
            else{
                curr = curr->children_map[c];
            }
        }

        if (curr->isEnd == true){
            return true;    // 必须存了这个完整的单词才算，不然只算半成品
        }
        else{
            return false;
        }

    }
    
    bool startsWith(string prefix) {
        
        TrieNode* curr = root;

        for (char c : prefix){
            if (curr->children_map.count(c) == 0){
                return false;
            }
            else{
                curr = curr->children_map[c];
            }
        }

        return true;
    }
};
