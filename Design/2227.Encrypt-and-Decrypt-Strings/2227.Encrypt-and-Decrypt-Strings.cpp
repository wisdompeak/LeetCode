class Encrypter {
    unordered_map<char, string>Map1;
    unordered_map<string, int>count;
    
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) 
    {
        
        for (int i=0; i<keys.size(); i++)
        {
            Map1[keys[i]] = values[i];
        }
                
        for (auto s: dictionary)
        {
            string t = encrypt(s);
            if (t!="") 
                count[t]++;
        }
    }
    
    string encrypt(string word1) 
    {
        string ret;
        for (char ch: word1)
        {
            if (Map1.find(ch)==Map1.end())
                return "";
            ret += Map1[ch];
        }
            
        return ret;        
    }
    
    int decrypt(string word2) 
    {
        if (count.find(word2)==count.end())
            return 0;
        else
            return count[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
