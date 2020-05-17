const int MAXN = 100;
const double pi = acos(-1);
class Solution {
    struct point
    {
        double x, y;
    };    
    struct interval
    {
        double arg;
        bool flag;
        bool operator<(const interval &T) const
        {
            return arg < T.arg;
        }
    };
    
    interval event[4 * MAXN];
    
    double dis(vector<int> a, vector<int> b)
    {
        return sqrt((a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]));
    }
    
public:
    int numPoints(vector<vector<int>>& points, int R)
    {
        int n = points.size();
        int num, res, ans;
        
        double r = R+0.01;
        double dist, a1, a2, delta, cta;
        ans = -1;

        for(int i = 0; i < n; i++)
        {
            num = 0;
            for(int j = 0; j < n; j++)
            {
                if(i == j) continue;
                dist = dis(points[i], points[j]);
                if(dist <= 2.0 * r)
                {
                    cta = atan2(points[j][1] - points[i][1], points[j][0] - points[i][0]);
                    if(cta < 0) cta += 2 * pi;
                    delta = acos(dist / 2.0 / r);
                    a1 = cta - delta, a2 = cta + delta;
                    if(a1 < 0)
                    {
                        event[num].arg = a1 + 2 * pi, event[num++].flag = true;
                        event[num].arg = a2 + 2 * pi, event[num++].flag = false;
                    }
                    else
                    {
                        event[num].arg = a1, event[num++].flag = true;
                        event[num].arg = a2, event[num++].flag = false;
                        event[num].arg = a1 + 2 * pi, event[num++].flag = true;
                        event[num].arg = a2 + 2 * pi, event[num++].flag = false;
                    }
                }
            }
            if(num < ans) continue;
            sort(event, event + num);
            res = 0;
            for(int j = 0; j < num; j++)
            {
                if(event[j].flag) res++;
                else res--;
                if(ans < res) ans = res;
            }
        }
        if(ans != -1) return(ans + 1);
        else return 1;
    }
};
