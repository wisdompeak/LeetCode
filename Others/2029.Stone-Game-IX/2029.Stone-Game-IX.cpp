class Solution {
public:
    bool stoneGameIX(vector<int>& stones) 
    {        
        vector<int>count(3);
        for (int x: stones)        
            count[x%3]+=1;                    

        auto temp = count;        
        if (temp[1]>0)
        {
            temp[1]-=1;
            if (!win(temp, 1, 1))
                return true;
        }

        temp = count;
        if (temp[2]>0)
        {
            temp[2]-=1;
            if (!win(temp, 2, 1))
                return true;
        }

        return false;        
    }

    bool win(vector<int>&count, int sum, int turn)
    {
        if (count[0]+count[1]+count[2]==0)
        {
            if (turn == 1)
                return true;
            else
                return false;
        }

        if (count[0]>0)
        {
            count[0]-=1;
            return 1-win(count, sum, 1-turn);
        }

        if (sum%3==1)
        {
            if (count[1]>0)
            {
                count[1]--;
                return 1-win(count, sum+1, 1-turn);
            }
            else
                return false;            
        }
        else
        {
            if (count[2]>0)
            {
                count[2]--;
                return 1 - win(count, sum+2, 1-turn);
            }
            else
                return false;            
        }
    }
};
