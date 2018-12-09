class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) 
    {
        sort(tokens.begin(),tokens.end());
        int i = 0;        
        int j = 0;
        int k = tokens.size()-1;
        int score = 0;
        int result = 0;
        
        do
        {
            while (j<=k && P>=tokens[j])
            {
                score+=1;
                P-=tokens[j];                
                j+=1;
            }
            result = max(result,score);
            
            if (i<j)
            {
                score-=1;
                P+=tokens[k];
                i++;
                k--;                
            }  
            
        }while (i<j || (j<=k && P>=tokens[j]));
            
        return result;        
    }
};
