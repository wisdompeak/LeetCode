class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        string text = s;
        string str;
        unordered_map<char,int>Map;
        for (auto ch: text)
            Map[ch]++;
        unordered_set<char>Set; //visited
        
        for (auto ch: text)
        {
            if (Set.find(ch)!=Set.end())
            {
                Map[ch]--;
            }
            else
            {
                while (str.size()>0  && str.back()>ch && Map[str.back()]>0)
                {
                    Set.erase(str.back());
                    str.pop_back();
                }
                str.push_back(ch);
                Map[ch]--;
                Set.insert(ch);
            }
        }
        
        return str;
    }
};
