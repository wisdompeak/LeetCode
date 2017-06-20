class Solution {
    string dict="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    unordered_map<string,string>Map1;
    unordered_map<string,string>Map2;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        string sr;
        do
        {
            sr="";
            for (int i=0; i<6; i++)
                sr+= dict[rand()%62];
        }while (Map1.find(sr)!=Map1.end());
        Map1[longUrl]=sr;
        Map2[sr]=longUrl;
        return sr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        return Map2[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
