class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) 
    {
        string s;
        for (auto str:sentence)
        {
            if (str.size()>cols) return 0;
            s+= str+" ";
        }   
        
        int i = 0;
        int len = s.size();
        
        for (int k=0; k<rows; k++)
        {
            i+=cols;
            while (s[i%len]!=' ')
                i--;
            i++;
        }
        return i/len;
    }
};
