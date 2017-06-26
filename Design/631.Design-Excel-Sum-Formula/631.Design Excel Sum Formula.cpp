class Excel {
    vector<vector<int>>table;
    unordered_map<string,vector<string>>Map;
public:
    Excel(int H, char W) 
    {
        table=vector<vector<int>>(H+1,vector<int>(W-'A',0));
    }
    
    void set(int r, char c, int v) 
    {
        table[r][c-'A']=v;
        if (Map.find(to_string(r)+c)!=Map.end())
            Map.erase(to_string(r)+c);
    }
    
    int get(int r, char c) 
    {
        //cout<<"get"<<r<<c<<endl;
        
        if (Map.find(to_string(r)+c)!=Map.end())
            sum(r,c,Map[to_string(r)+c]);
        return table[r][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) 
    {
        cout<<"sum"<<r<<c<<endl;
        
        Map[to_string(r)+c]=strs;
        
        int sum=0;
        
        for (int i=0; i<strs.size(); i++)
        {
            string str=strs[i];
            int flag=0;
            for (int j=0; j<str.size(); j++)
            {
                if (str[j]==':')
                {
                    flag=1;
                    break;
                }
            }
            
            if (flag==0)
            {
                int row;
                char col;
                
                read(str,row,col);
                sum+=get(row,col);
                
                if (r==3 && c=='C') cout<<sum<<endl;
            }
            else
            {
                int j=0;
                while (str[j]!=':') j++;
                string str1=str.substr(0,j);
                string str2=str.substr(j+1);
                
                int row1, row2;
                char col1, col2;
                read(str1,row1,col1);
                read(str2,row2,col2);
                
                
                for (int a=row1; a<=row2; a++)
                 for (int b=col1; b<=col2; b++)
                    sum+=get(a,b);
                 
            }
        }
        
        table[r][c-'A']=sum;
        return sum;
    }
    
    void read(string str, int &row, char &col)
    {
        col=str[0];
        row=stoi(str.substr(1));
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel obj = new Excel(H, W);
 * obj.set(r,c,v);
 * int param_2 = obj.get(r,c);
 * int param_3 = obj.sum(r,c,strs);
 */
