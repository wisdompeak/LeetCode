class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) 
    {
        int n = sensor1.size();
        int i = 0;
        for (i=0; i<n; i++)
        {
            if (sensor1[i]!=sensor2[i])
                break;
        }
        if (i>=n-1) return -1;
                        
        int flag = 1;
        for (int j=i; j<n-1; j++)
        {
            if (sensor1[j]!=sensor2[j+1])
            {
                flag = 0;
                break;
            }
        }
        if (flag==1) return 1;
        else return 2;        
    }
};
