class Excel {
    vector<vector<int>>Table;
    unordered_map<string,vector<string>>Map;
    
public:
    Excel(int H, char W) 
    {
        Table = vector<vector<int>>(H+1,vector<int>(W-'A'+1,0));
    }
    
    void set(int r, char c, int v) 
    {
        if (Map.find(to_string(r)+c)!=Map.end())
            Map.erase(to_string(r)+c);
        Table[r][c-'A']=v;
    }
    
    int get(int r, char c) 
    {
        if (Map.find(to_string(r)+c)==Map.end())
            return Table[r][c-'A'];
        else
        {
            Table[r][c-'A'] = sum(r,c,Map[to_string(r)+c]);
            return Table[r][c-'A'];
        }
            
    }
    
    int sum(int r, char c, vector<string> strs) 
    {
        Map[to_string(r)+c]=strs;
        int sum=0;
        for (int i=0; i<strs.size(); i++)
        {
            int row1,row2;
            char col1,col2;
            bool flag = read(strs[i],row1,row2,col1,col2);
                        
            if (flag==0)
                sum+=get(row1,col1);
            else
            {   for (int j=row1; j<=row2; j++)
                 for (char k=col1; k<=col2; k++)
                 {
                     sum+=get(j,k);                     
                 }
            }            
        }
        Table[r][c-'A']=sum;
        return sum;
    }
    
    bool read(string str, int& row1, int& row2, char& col1, char& col2)
    {
        bool flag=false;
        int i=0;
        
        while (i<str.size() && str[i]!=':') i++;
        flag = (i!=str.size());
        
        if (flag==0)
        {
            col1=str[0];
            row1=stoi(str.substr(1));
        }
        else
        {
            string str1=str.substr(0,i);
            string str2=str.substr(i+1);
            col1=str1[0];
            row1=stoi(str1.substr(1));
            col2=str2[0];
            row2=stoi(str2.substr(1));
        }        
        return flag;        
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
