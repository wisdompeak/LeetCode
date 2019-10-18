class Solution {
public:
    int minSwapsCouples(vector<int>& row) 
    {        
        if (row.size()==0) return 0;
        
        int N = row.size();
        unordered_map<int,int>Pos;
        unordered_map<int,int>coupleID;
        
        for (int i=0; i<N; i++)
        {
            Pos[row[i]] = i;
            coupleID[i] = i/2;
        }
            
        int count = 0;
        
        for (int k=0; k<N; k+=2)
        {           
            if (coupleID[row[k]]==coupleID[row[k+1]])
                continue;

            int flag=0;       
            
            int holder = row[k];
            int partner = coupleID[holder]*2==holder? holder+1:holder-1;
            int curPos = k+1;
            
            while (flag==0)
            {                
                swap(row[Pos[partner]],row[curPos]);                
                count++;
                
                holder = row[Pos[partner]];
                int holder_pos = Pos[partner];
                
                curPos = (holder_pos%2==0) ? holder_pos+1:holder_pos-1;
                partner = coupleID[holder]*2==holder? holder+1:holder-1;
                                
                flag = row[curPos]==partner;
            }
            
        }
        
        return count;
    }
};
