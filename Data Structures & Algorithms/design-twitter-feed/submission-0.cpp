class Twitter {
public:
    unordered_map<int,unordered_set<int>> followers;
    vector<pair<int,int>> post;
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        post.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        for(int i=post.size()-1;i>=0 && feed.size()<10;i--){
            int authorId=post[i].first;
            int tweetId=post[i].second;
            if(authorId==userId || followers[userId].count(authorId)){
                feed.push_back(tweetId);
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followers[followerId].insert(followeeId);
        }     
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
