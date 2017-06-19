class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) 
    {
        sort(heaters.begin(),heaters.end());
        int result=0;
        
        for (int i=0; i<houses.size(); i++)
        {
            int radius;
            
            auto pos= lower_bound(heaters.begin(),heaters.end(),houses[i]);
            
            if (pos==heaters.begin())
                radius = heaters[0]-houses[i];
            else if (pos==heaters.end())
                radius = houses[i]-heaters.back();
            else
                radius = min(*pos-houses[i], houses[i]-*(pos-1));
                
            result = max(result,radius);
        }
        
        return result;
    }
};
