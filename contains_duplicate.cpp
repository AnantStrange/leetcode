#include <cstdio>
#include <vector>
#include <set>
#include <unordered_set>

class Solution2 {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return true;
            seen.insert(num);
        }
        return false;
    }
};

class Solution {
  public:
    bool containsDuplicate(std::vector<int> &nums) {
        std::set<int> set;
        for (int num : nums) {
            if (set.find(num) != set.end()) {
                return true;
            }
            set.insert(num);
        }
        return false;
    }
};


int main(){
    Solution sol;
    std::vector<int> test_vec = {1, 2, 3, 4};
    printf("%d",sol.containsDuplicate(test_vec));
}
