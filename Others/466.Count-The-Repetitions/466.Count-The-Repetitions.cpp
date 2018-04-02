class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) 
    {
        int L1=s1.size();
        int L2=s2.size();
        auto PairPos=vector<vector<int>>(L2,vector<int>(L1,-1));
        auto PairCount=vector<vector<int>>(L2,vector<int>(L1,-1));
        
        int y = 0;        
        int x;
        int count=0;
        for (int i=0; i<L1*n1; i++)
        {
            x = i%L1;
            y = y%L2;
            if (s1[x]==s2[y])
            {
                if (y==L2-1) count++;
                
                if (PairPos[y][x]!=-1 && i+(i-PairPos[y][x])<L1*n1)
                {                    
                    i+=i-PairPos[y][x];
                    count+=count-PairCount[y][x];
                }                
                
                PairPos[y][x]=i;
                PairCount[y][x]=count;
                y++;                
            }                
        }
        return count/n2;
    }
};
