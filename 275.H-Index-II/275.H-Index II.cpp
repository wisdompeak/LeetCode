class Solution {
public:
    int hIndex(vector<int>& citations) 
    {
        if (citations.size()==0) return 0;
        
        int left=0;
        int right=citations.size()-1;
        int mid;
        int N=citations.size()-1;
        
        while (left<right)
        {
            mid = left+(right-left)/2;
            if (citations[mid]==N-mid+1)
                return citations[mid];
            else if (citations[mid]>N-mid+1)
                right = mid;
            else if (citations[mid]<N-mid+1)
                left = mid+1;
        }
        
        cout<<left<<endl;
        
        if (citations[left] >= N-left+1)
            return N-left+1;
        if (citations[left] < N-left+1)
            return citations[left];
           
    }
};
