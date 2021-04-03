class Solution {
public:
    bool isMagic(vector<int>& target) 
    {        
        int n = target.size();
        vector<int>temp;
        for (int i=2; i<=n; i+=2)
            temp.push_back(i);
        for (int i=1; i<=n; i+=2)
            temp.push_back(i);
        
        int k = 0;
        for (int i=0; i<target.size(); i++)
        {
            if (target[i]==temp[i])
                k++;
            else
                break;
        }

        if (k==0) return false;

        vector<int>a(temp.begin()+k, temp.end());
        int count = k;

        while (a.size() > 0)
        {
            vector<int>temp;
            for (int i=1; i<a.size(); i+=2)
                temp.push_back(a[i]);
            for (int i=0; i<a.size(); i+=2)
                temp.push_back(a[i]);

            for (int i=0; i<min(k, (int)temp.size()); i++)
            {
                if (temp[i]!=target[count+i])
                    return false;                    
            }
            count += k;
            
            if (k < temp.size())
                a = vector<int>(temp.begin()+k, temp.end());
            else
                a = {};
        }
        return true;
    }
};
