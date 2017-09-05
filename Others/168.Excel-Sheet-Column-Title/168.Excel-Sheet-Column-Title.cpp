class Solution {
public:
    string convertToTitle(int n) 
    {
        string result;               
                
        while (n>0)
        {            
            n--;
            result=char('A'+(n%26))+result;
            n=n/26;
        }
        return result;
    }
};
