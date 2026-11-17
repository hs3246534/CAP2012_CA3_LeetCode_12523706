#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);
        
        // 1. Count the frequency of each number
        for (int num : nums) {
            count[num]++;
        }
        
        // 2. Compute prefix sums so count[i] stores how many numbers are <= i
        for (int i = 1; i <= 100; i++) {
            count[i] += count[i - 1];
        }
        
        // 3. Build the result array
        vector<int> result;
        result.reserve(nums.size());
        
        for (int num : nums) {
            if (num == 0) {
                result.push_back(0);
            } else {
                result.push_back(count[num - 1]);
            }
        }
        
        return result;
    }
};
