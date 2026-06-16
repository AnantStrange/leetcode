#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

void printVecInt( vector<int>vec){
    printf("[ ");
    for(int elem : vec){
        printf("%d, ", elem);
    }
    printf("]\n");
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }
        
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, freq] : freq_map) {
            buckets[freq].push_back(num);
        }
        
        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1,1,1,2,2,3};
    int k1 = 2;
    vector<int> nums2 = {1,2,1,2,1,2,3,1,3,2,3,1,4,4,4,4,4,4};
    int k2 = 2;

    auto ans1 = sol.topKFrequent(nums1, k1);
    printVecInt(ans1);
    auto ans2 = sol.topKFrequent(nums2, k2);
    printVecInt(ans2);

    
}
