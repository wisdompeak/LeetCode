class TweetCounts {
    unordered_map<string,multiset<int>>Map;
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) 
    {
        Map[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) 
    {
        vector<int>rets;
                
        int count = 0;
        int delta = 0;
        if (freq=="minute")
            delta = 60;
        else if (freq=="hour")
            delta = 60*60;
        else
            delta = 60*60*24;
        
        auto iter = Map[tweetName].lower_bound(startTime);                
        
        while (startTime <= endTime)
        {            
            if (iter!=Map[tweetName].end() && *iter < startTime+delta && *iter<=endTime)
            {
                count++;
                iter = next(iter,1);
            }
            else
            {
                rets.push_back(count);
                count = 0;
                startTime += delta;
            }
        }
        
        return rets;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
