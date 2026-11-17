#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> st;
        
        // 1. Find the next greater element for every number in nums2
        for (int num : nums2) {
            while (!st.empty() && num > st.top()) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        
        // 2. Build the result for nums1 using O(1) map lookups
        vector<int> ans;
        ans.reserve(nums1.size());
        
        for (int num : nums1) {
            if (next_greater.count(num)) {
                ans.push_back(next_greater[num]);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};
