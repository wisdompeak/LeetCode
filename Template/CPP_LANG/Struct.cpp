struct State {
    int mask, stage;
    double dist;
    bool operator<(State const& o) const {
        return dist > o.dist;
    }
};

// The top element is the one with smallest dist.
priority_queue<State>pq;
