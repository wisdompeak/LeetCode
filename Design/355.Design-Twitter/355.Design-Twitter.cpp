class Twitter {
    unordered_map<int,set<int>>friends;
    unordered_map<int,vector<pair<int,int>>>tweets;
    int global_id;

public:
    /** Initialize your data structure here. */
    Twitter() 
    {
        global_id = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) 
    {
        follow(userId,userId);
        tweets[userId].push_back({global_id,tweetId});
        global_id++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) 
    {
        set<pair<int,int>>news;
        for (auto i:friends[userId])
        {
            for (int j=tweets[i].size()-1; j>=0; j--)
            {
                if (news.size()<10)
                    news.insert(tweets[i][j]);
                else if (tweets[i][j].first> news.begin()->first)
                {
                    news.erase(news.begin());
                    news.insert(tweets[i][j]);
                }
                else
                    break;
            }
        }
        
        vector<int>results;
        for (auto a:news)
        {
            results.push_back(a.second);
        }
        reverse(results.begin(),results.end());
        return results;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) 
    {
        friends[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) 
    {
        if (followerId!=followeeId)
            friends[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
