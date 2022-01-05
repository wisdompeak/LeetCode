class Solution {

private:
  using point_t = std::vector<int>;

  static inline uint64_t hash(const point_t &p)
  {
    return p[0] * 1e6 + p[1];
  }

public:
  bool isEscapePossible(vector<vector<int>>& blocked,
                        vector<int>& source,
                        vector<int>& target)
  {
    // blocked points set, uint64_t is selected since it is larger than 1e6*le6
    std::unordered_set<uint64_t> bps;

    for (auto &x: blocked)
      bps.insert(hash(x));

    auto e1 = enclose(source, bps, target);
    auto e2 = enclose(target, bps, source);

    return !e1 && !e2;
  }

private:
  bool enclose(const point_t &s,
               const std::unordered_set<uint64_t> & b,
               const point_t &d)
  {
    int max_points = (1+b.size()-1) * b.size()/2;

    std::deque<point_t> Q;
    Q.push_back(s);

    std::unordered_set<uint64_t> visited;
    visited.insert(hash(s));

    while (!Q.empty() && visited.size() <= max_points)
    {
      int &r = Q.front()[0];
      int &c = Q.front()[1];

      static std::vector<std::pair<int, int>> ds
      {
        {0, 1}, {-1, 0}, {0, -1}, {1, 0}
      };

      for (auto &dir: ds)
      {
        auto rr = r + dir.first;
        auto cc = c + dir.second;

        std::vector<int> p{rr, cc};

        if (rr < 0 || rr >= 1e6                   || // out of bound
            cc < 0 || cc >= 1e6                   || // out of bound
            visited.find(hash(p)) != visited.end()|| // visited
            b.find(hash(p)) != b.end()             ) // blocked
          continue;

        if (p == d) // reached out to destination
          return false;

        Q.push_back(p);
        visited.insert(hash(p));
      }

      Q.pop_front();
    }
    // no points left in queue, indicating this attempt is enclosed
    return Q.empty();
  }
};