class Solution {
    typedef pair<int,int> PII;
    unordered_set<string> rets;
    vector<int> dirs;
    int m, n;
    int freq[26];

    bool frequencyCheck(string& word) {
        vector<int> freq(26, 0);

        for(auto ch: word) {
            ++freq[ch-'a'];
        }

        for(int i = 0; i < 26; ++i) {
            if(this->freq[i] < freq[i]) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int x, int y, string& word, vector<vector<char>>& board, int idx, vector<vector<int>>& visited) {
        if(board[x][y] != word[idx]) return false;
        if(idx == word.size() - 1 && word[idx] == board[x][y]) {
            rets.insert(word);
            return true;
        }

        for(int i = 0; i < 4; ++i) {
            int nx = x + dirs[i];
            int ny = y + dirs[i+1];

            if(nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
            visited[x][y] = 1;
            if(dfs(nx, ny, word, board, idx+1, visited)) {
                visited[x][y] = 0;
                return true;
            }
            visited[x][y] = 0;
        }

        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        unordered_map<char, vector<PII>> char2pos;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        dirs =  {-1, 0, 1, 0, -1};

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                char2pos[board[i][j]].push_back({i, j});
            }
        }

        for(auto& row: board) {
            for(char ch: row) {
                ++freq[ch-'a'];
            }
        } 

        for(auto word: words) {
            // word frequency check
            if(!frequencyCheck(word)) continue;
            
            for(auto [x, y]: char2pos[word[0]]) {
                visited[x][y] = 1;
                dfs(x, y, word, board, 0, visited);
                visited[x][y] = 0;
            }
        }
        return {rets.begin(), rets.end()};
    }
};
