class Solution {
private:
    unordered_map<string, string> short2long, long2short;
    string dict;
    
public:
    Solution()
    {
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        short2long.clear();
        long2short.clear();
        srand(time(NULL));
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        if (long2short.find(longUrl)!=long2short.end())
            return "http://tinyurl.com/"+long2short[longUrl];
        
        string s;
        for (int i=0; i<6; i++)
            s+= dict[rand()%62];
        
        long2short[longUrl]=s;
        short2long[s]=longUrl;
        
        return "http://tinyurl.com/"+s;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        string randStr = shortUrl.substr(shortUrl.find_last_of("/") + 1);
        string longUrl;
        
        if (short2long.find(randStr)!=short2long.end())
            longUrl = short2long[randStr];
        else
            longUrl = shortUrl;
        
        return longUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
