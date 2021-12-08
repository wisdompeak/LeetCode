class Robot {
    int width, height;
    int d,x,y;
    vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    int total;
public:
    Robot(int width, int height) 
    {
        this->width = width;
        this->height = height;
        d=0, x=0, y=0;
        total = width*2+(height-2)*2;
    }
    
    void move(int num) 
    {
        int flag = 0;
        
        while (num > 0)
        {
            int remain;
            if (d==0) remain = width-1-x;
            else if (d==1) remain = height-1-y;
            else if (d==2) remain = x;
            else remain = y;

            if (remain >= num)
            {
                x += dir[d].first * num;
                y += dir[d].second * num;
                num  = 0;
            }
            else
            {
                x += dir[d].first * remain;
                y += dir[d].second * remain;
                d = (d+1)%4;
                num -= remain;      
                
                num %= total;                 
                if (num == 0 && atCorner(x,y))
                {
                    d = (d-1+4)%4;
                }                
            }
        }
    }
    
    bool atCorner(int x, int y)
    {
        if (x==0 && y==0) return true;
        if (x==0 && y==height-1) return true;
        if (x==width-1 && y==0) return true;
        if (x==width-1 && y==height-1) return true;
        return false;
    }
    
    vector<int> getPos() 
    {
        return {x,y};
    }
    
    string getDir() 
    {
        if (d==0) return "East";
        else if (d==1) return "North";
        else if (d==2) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
