//https://www.renfei.org/blog/bipartite-matching.html
// 顶点、边的编号均从 0 开始
// 邻接表储存

struct Edge
{
    int from;
    int to;
    int weight;

    Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};

vector<int> G[__maxNodes]; /* G[i] 存储顶点 i 出发的边的编号 */
vector<Edge> edges;
typedef vector<int>::iterator iterator_t;
int num_nodes;
int num_left;
int num_right;
int num_edges;
int matching[__maxNodes]; /* 存储求解结果 */
int check[__maxNodes];
queue<int> Q;
int prev[__maxNodes];

int Hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    memset(check, -1, sizeof(check));
    for (int i=0; i<num_left; ++i) {
        if (matching[i] == -1) {
            while (!Q.empty()) Q.pop();
            Q.push(i);
            prev[i] = -1; // 设 i 为路径起点
            bool flag = false; // 尚未找到增广路
            while (!Q.empty() && !flag) {
                int u = Q.front();
                for (iterator_t ix = G[u].begin(); ix != G[u].end() && !flag; ++ix) {
                    int v = edges[*ix].to;
                    if (check[v] != i) {
                        check[v] = i;
                        Q.push(matching[v]);
                        if (matching[v] >= 0) { // 此点为匹配点
                            prev[matching[v]] = u;
                        } else { // 找到未匹配点，交替路变为增广路
                            flag = true;
                            int d=u, e=v;
                            while (d != -1) {
                                int t = matching[d];
                                matching[d] = e;
                                matching[e] = d;
                                d = prev[d];
                                e = t;
                            }
                        }
                    }
                }
                Q.pop();
            }
            if (matching[i] != -1) ++ans;
        }
    }
    return ans;
}
