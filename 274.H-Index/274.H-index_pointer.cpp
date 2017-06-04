class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        if (citations.size()==0) return 0;
        
        sort(citations.begin(),citations.end());
        
        int sum=0;
        int i=citations.size()-1;
        
        while (i>=0)
        {
            sum++;
            
            if (citations[i]==sum)
                return sum;
            else if (citations[i]>sum)
                i--;
            else
            {
                return max(citations[i],sum-1);
            }
            
        }
        
        return sum;
        
    }
};
