#include <queue>

using namespace std;

class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {
        // Queue initializes empty
    }
    
    int ping(int t) {
        q.push(t);
        
        // Remove all timestamps outside the [t - 3000, t] window
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        
        return q.size();
    }
};
