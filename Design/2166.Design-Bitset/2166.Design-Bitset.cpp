class Bitset {
    int flips[100000];
    int totalFlip = 0;
    int m;
    int cnt = 0;
public:
    Bitset(int size) {
        m = size;
        for (int i=0; i<m; i++)
            flips[i] = 0;
    }
    
    void fix(int idx) 
    {
        if ((flips[idx]+totalFlip)%2==0)
        {
            flips[idx]+=1;
            cnt++;
        }
    }
    
    void unfix(int idx) {
        if ((flips[idx]+totalFlip)%2==1)
        {
            flips[idx]+=1;
            cnt--;
        }
    }
    
    void flip() {
        totalFlip += 1;
        cnt = m - cnt;
    }
    
    bool all() {
        return cnt == m;
    }
    
    bool one() {
        return cnt >= 1;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        string s;
        for (int i=0; i<m; i++)
        {
            int t = (flips[i]+totalFlip)%2;
            s += t==0?"0":"1";
        }
        return s;
    }
};
