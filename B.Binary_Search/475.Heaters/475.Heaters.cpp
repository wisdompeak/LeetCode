class Solution {
public:
    static bool cmp1(int a, int b)
    {
        return (a<b);
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        if (houses.size()==0) return 0;
        if (heaters.size()==0) return INT_MAX;
        
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int result = INT_MIN;
        
        for (int i=0; i<houses.size(); i++)
        {
            int pos = houses[i];
            auto it1 = lower_bound(heaters.begin(),heaters.end(),pos,cmp1);
            auto it2 = it1-1;
            int temp;
            
            if (it1 == heaters.end())
                temp = houses[i]-heaters.back();
            else if (it1 == heaters.begin())
                temp = heaters.front()-houses[i];
            else
                temp = min (abs(houses[i]-*it1),abs(houses[i]-*it2));
                
            //if (i==1) cout<<abs(houses[i]-*it2)<<endl;
            
            result = max(result,temp);
            
        }
        
        return result;

    }
};
