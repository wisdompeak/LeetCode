class CombinationIterator {
    string cur;
    string end;
    bool firstCall;
    string characters;
    int combinationLength;
    
public:
    CombinationIterator(string characters, int combinationLength) 
    {
        cur = characters.substr(0,combinationLength);
        end = characters.substr(characters.size()-combinationLength);
        firstCall = 1;
        this->characters = characters;
        this->combinationLength = combinationLength;        
    }
    
    string next() 
    {
        if (firstCall)
        {
            firstCall = 0;
            return cur;
        }
        
        int i = cur.size()-1;
        while (i>=0 && cur[i]==characters[i+characters.size()-combinationLength])
            i--;
        int j = 0;
        while (cur[i]!=characters[j])
            j++;
        for (int k=i; k<cur.size(); k++)
            cur[k] = characters[j+1 + k-i];  // cur[i] = characters[j+1]
        
        return cur;
    }
    
    bool hasNext() 
    {
        return firstCall==1 || cur!=end;
    }
};
