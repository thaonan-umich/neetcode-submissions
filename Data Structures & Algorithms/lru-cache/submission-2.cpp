class LRUCache {

private:
    list<int> order;    // STL 双向链表（只存key）
    unordered_map<int, pair<int, list<int>::iterator>> cache;   // 键 ：<值，迭代指针>
    int capacity;


public:
    LRUCache(int capacity) {
        // 末尾最新访问，头部最旧访问
        this->capacity = capacity;
    }
    
    int get(int key) {

        if (cache.find(key) == cache.end())
            return -1;  // 找不到

        // 找到了
        order.erase(cache[key].second);   // list.erase(迭代指针)，O(1)删除

        // 塞到链表最末尾，代表最新被访问
        order.push_back(key);

        // 更新哈希表中得迭代指针
        cache[key].second = --order.end();  // order.end返回的是复制的迭代指针，不是本体

        return cache[key].first;
        
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()){    // 命中，准备调整顺序
            order.erase(cache[key].second);     // 先删掉，准备插到尾部
        }
        else if (cache.size() == capacity){     // 没命中，但是满了，准备删一个
            int old_key = order.front();        // 这是一个key，最老访问的key
            order.pop_front();                  // 把这个key弹出来
            cache.erase(old_key);               // 哈希表用key删除记录
        }

        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
