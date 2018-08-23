class ExamRoom {
    vector<int>L;
    int N;
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
        int maxGap = 0;
        int pos;
        for (int i=1; i<L.size(); i++)
        {
            if ((L[i]-L[i-1])/2>maxGap)
            {
                maxGap = (L[i]-L[i-1])/2;
                pos = (L[i]+L[i-1])/2;
            }
        }        
        if (N-1-L.back()>maxGap)
        {
            maxGap = N-1-L.back();
            pos = N-1;
        }
        if (L[0]>=maxGap)
        {
            maxGap = L[0]-1;
            pos = 0;
        }
        L.insert(lower_bound(L.begin(),L.end(),pos),pos);
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
