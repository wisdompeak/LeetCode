using LL = long long;
class Solution {
    int n;
public:
    long long maxScore(vector<int>& points, int m) 
    {
        n = points.size();
        LL left = 0, right = 1e15;
        while (left < right)
        {
            LL mid = right - (right-left)/2;                       
            if (checkOK(points, m, mid))
                left = mid;
            else
                right = mid-1;
        }
        return left;        
    }
    
     bool checkOK(vector<int>& points, LL M, LL P)
     {
         LL count = 1;
         LL cur = points[0];
         
         for (int i=0; i<n; i++)
         {
             if (i==n-1)
             {
                 if (cur>=P) return true;
                 LL d = (P-cur-1) / points[i] + 1;
                 return count+d*2 <= M;
             }
             
             if (cur>=P)
             {
                 count++;
                 if (count > M) return false;
                 cur = points[i+1];                 
             }
             else
             {
                 LL d = (P-cur-1) / points[i] + 1;
                 if (i==n-2 && count+d*2<=M && points[i+1]*d>=P)
                     return true;
                 
                 count += 2*d+1;                 
                 if (count > M) return false;                                  
                 cur = points[i+1] * (d+1);
             }
         }
         
         return true;
     }
};
