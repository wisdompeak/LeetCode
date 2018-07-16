class RangeModule {
    map<int,int>Map;
public:
    RangeModule() 
    {
        Map.clear();
    }
    
    void addRange(int left, int right) 
    {       
        auto pos1 = Map.lower_bound(left);
        int leftboundary=left;
        if (pos1!=Map.begin() && prev(pos1,1)->second>=left)
            leftboundary = prev(pos1,1)->first;
                            
        auto pos2 = Map.upper_bound(right);
        int rightboundary = right;
        if (pos2!=Map.begin())
            rightboundary = max(right, prev(pos2,1)->second);
        
        Map.erase(pos1,pos2);
        Map[leftboundary]=rightboundary;        
        
        /*
        for (auto a:Map)
            cout<<a.first<<":"<<a.second<<endl;
        cout<<"added"<<endl;
        */
    }
    
    bool queryRange(int left, int right) 
    {
        auto pos = Map.upper_bound(left);
        if (pos==Map.begin())
            return false;
        pos = prev(pos,1);
        return (pos->second>=right);
    }
    
    void removeRange(int left, int right) 
    {
        auto pos1 = Map.lower_bound(left);
        bool flag1=0;
        int temp1;
        if (pos1!=Map.begin() && prev(pos1,1)->second > left)
        {
            temp1 = prev(pos1,1)->first;
            flag1=1;
        }
        
        auto pos2 = Map.lower_bound(right);
        int temp2;
        bool flag2=0;        
        if (pos2!=Map.begin() && prev(pos2,1)->second > right)
        {
            temp2 = prev(pos2,1)->second;
            flag2=1;
        }
        
        Map.erase(pos1,pos2);
        if (flag1) Map[temp1]=left;
        if (flag2) Map[right]=temp2;
        
        /*
        for (auto a:Map)
            cout<<a.first<<":"<<a.second<<endl;
        cout<<"removed"<<endl;    
        */
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
