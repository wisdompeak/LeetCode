class Solution {
public:
    int reachNumber(int target)     
    {
        target=abs(target);
        int sum=0;
        int i=0;
        while (!(target<=sum && (target%2==sum%2)))
        {
            i++;
            sum+=i;            
        }
        
        return i;
    }
};
