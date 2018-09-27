class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int sum = 0;
        for (int i=0; i<gas.size(); i++)
            sum+= gas[i]-cost[i];
        if (sum<0) return -1;
        
        sum = 0;
        int result=0;
        for (int i=0; i<gas.size(); i++)
        {
            sum+= gas[i]-cost[i];
            if (sum<0)
            {
                sum = 0;
                result = i+1;
            }                
        }
        return result;
    }
};
