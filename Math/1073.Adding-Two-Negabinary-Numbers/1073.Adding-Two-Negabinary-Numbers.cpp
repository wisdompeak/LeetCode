class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) 
    {
        reverse(arr1.begin(),arr1.end());
        reverse(arr2.begin(),arr2.end());
        int len = max(arr1.size(), arr2.size());
        int carry = 0;
        vector<int>ret;
        for (int i=0; i<len+2; i++)
        {
            int a = i>=arr1.size()? 0:arr1[i];
            int b = i>=arr2.size()? 0:arr2[i];            
            int sum = a+b+carry;
            int r = sum%(-2);
            carry = sum/(-2);
            if (r<0)
            {
                carry+=1;
                r+=2;
            }
            ret.push_back(r);
        }        
        while (ret.size()>0 && ret.back()==0) ret.pop_back();        
        reverse(ret.begin(),ret.end());
        if (ret.size()==0) return {0};
        else return ret;
    }
};
