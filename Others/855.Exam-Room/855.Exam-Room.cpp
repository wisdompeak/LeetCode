class ExamRoom {
    int N;
    vector<int>L;
public:
    ExamRoom(int N) 
    {
        this->N = N;        
    }
    
    int seat() 
    {
        if (L.size()==0)
        {
            L.push_back(0);
            return 0;
        }
        
        int maxGap = -1;
        int pos;
        
        if (L[0]!=0)
        {
            pos = 0;
            maxGap = L[0]-1;
        }
        for (int i=0; i<L.size()-1; i++)
        {
            if (L[i+1]!=L[i]+1 && (L[i+1]-L[i]-2)/2 > maxGap)
            {
                maxGap = (L[i+1]-L[i]-2)/2 ;
                pos = L[i]+maxGap+1;
            }
        }
        if (L.back()!=N-1 && N-1-L.back()-1>maxGap)
        {
            maxGap = N-1-L.back()-1;
            pos = N-1;
        }
        
        L.insert(lower_bound(L.begin(),L.end(),pos), pos);

        return pos;
    }
    
    void leave(int p) 
    {
        L.erase(lower_bound(L.begin(),L.end(),p));
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
