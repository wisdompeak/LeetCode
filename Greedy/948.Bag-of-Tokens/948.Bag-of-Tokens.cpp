class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) 
    {
        sort(tokens.begin(),tokens.end());
        int i = 0;
        int j = tokens.size()-1;
        int points = 0;
        int result = 0;
        
        while (i<=j)
        {
            if (P>=tokens[i])
            {
                P-=tokens[i];
                i++;
                points++;
                result = max(result,points);
            }
            else if (points>0)
            {
                points--;
                P+=tokens[j];
                j--;
            }
            else
                break;
        }
        
        return result;
    }
};
