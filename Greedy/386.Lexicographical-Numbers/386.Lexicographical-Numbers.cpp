class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        vector<int>rets = {1};
        int i=1;
        
        while (rets.size()<n)
        {
            if (i*10<=n)
            {
                i=i*10;
            }
            else 
            {
                while (i+1>n || (i%10==9))                
                    i = i/10;                    
                i+=1;
            }         
            
            rets.push_back(i);
         }
        
        return rets;
    }
};
