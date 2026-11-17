#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = 0;
        
        for (const auto& customer : accounts) {
            int current_wealth = 0;
            for (int money : customer) {
                current_wealth += money;
            }
            max_wealth = max(max_wealth, current_wealth);
        }
        
        return max_wealth;
    }
};
