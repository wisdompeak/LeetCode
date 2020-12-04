class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map<int,int>left;
        unordered_map<int,int>seq;
        for (auto x: nums)
            left[x]++;

        for (auto x: nums)
        {
            if (left[x]==0) continue;
            if (seq[x-1]>0)
            {                
                left[x]--;
                seq[x-1]-=1;
                seq[x]+=1;                
            }
            else
            {
                if (left[x+1]==0 || left[x+2]==0)
                    return false;
                left[x]--;
                left[x+1]--;
                left[x+2]--;
                seq[x+2]+=1;
            }
            
        }
        return true;        
    }
};
