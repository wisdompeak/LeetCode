class Solution {
public:
    int maximumSwap(int num) 
    {
        int MAX=0;
        int pos;
        string str=to_string(num);
        
        string str2=str;
        sort(str2.begin(),str2.end());
        reverse(str2.begin(),str2.end());
        
        int j=0;
        while (j<str.size() && str[j]==str2[j])
            j++;
        
        if (j==str.size()) return num;
                
        for (int i=j; i<str.size(); i++)
        {
            if (str[i]-'0'>=MAX)
            {
                MAX=str[i]-'0';
                pos=i;
            }
        }
        
        for (int i=j; i<pos; i++)
        {
            if (str[i]-'0'>=MAX)
                continue;
            swap(str[i],str[pos]);         
            break;
        }
        
        return stoi(str);
        
        
    }
};
