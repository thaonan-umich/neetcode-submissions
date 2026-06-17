class Twitter {

private:
    // 内置数据结构
    // 需求1: 怎么保存所有的历史推特和谁发的它们的信息？
    // choice 1. hash_table: int->vector (user_id -> user_post_ids) 但是好像不能做最近十条查找 放弃
    // choice 2. max_heap: pair<int, pair<int, int>>, pair<addTime, pair<userId, tweetID>>
        // 可以做最近十条查找，同时保存tweets的用户归属
        // 不对啊 最近十条直接用stack不就行了？先进先出，那开choice3了
    // choice 3. stack：pair<userId, tweetID>
    stack<pair<int, int>> tweets_stack;

    // 需求2：怎么保存用户跟踪了谁？
    // choice 1. 哈希表+哈希集合: unordered_map<userId, set<userId>>
    unordered_map<int, unordered_set<int>> follow_table;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets_stack.push({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> follow_set = follow_table[userId];
        follow_set.insert(userId);  // 把自己加入到集合中

        // 复制一份队列
        stack<pair<int, int>> cp_tweets_stack = tweets_stack;

        // 准备返回向量
        vector<int> feeds;

        // 开始弹出
        int count = 0;
        while (count < 10 && cp_tweets_stack.size() != 0){
            pair<int, int> tweet = cp_tweets_stack.top();
            cp_tweets_stack.pop();

            int tweet_userId = tweet.first;
            int tweetId = tweet.second;

            if (follow_set.find(tweet_userId) != follow_set.end()){
                feeds.push_back(tweetId);
                count += 1; // 只有关注的人且加入了feedca
            }

        }

        return feeds;
    }
    
    void follow(int followerId, int followeeId) {
        follow_table[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_table[followerId].erase(followeeId);
    }
};
