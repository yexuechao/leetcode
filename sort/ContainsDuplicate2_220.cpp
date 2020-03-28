#include<set>
#include<vector>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.empty()) {
            return false;
        }
        set<int> store;
        for (size_t i = 0; i < nums.size(); i++) {
            set<int>::iterator big_itr = store.lower_bound(nums[i]);
            if (big_itr != store.end()) {
                int64_t big = *big_itr;
                if (big - nums[i] <= t) {
                    return true;
                }
            }
            set<int>::iterator small_itr = store.lower_bound(nums[i]);
            if (small_itr != store.begin()) {
                small_itr--;
                int64_t small = *small_itr;
                if (nums[i] - small <= t) {
                    return true;
                }
            }
            store.insert(nums[i]);
            if (store.size() > k) {
                store.erase(store.find(nums[i - k]));
            }
        }
        return false;
    }
};