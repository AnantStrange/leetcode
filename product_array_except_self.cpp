#include <cstdio>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums){
        vector<int> to_return(nums.size());
        int sum = 1;
        int zero_counter = 0;

        to_return[0] = 1;
        to_return[nums.size()-1] = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] == 0){
                if(++zero_counter>1){
                    return vector<int>(nums.size(), 0);
                }
            }
            sum *= nums[i-1];
            to_return[i] = sum;
        }

        sum = 1;
        for(int i=nums.size()-2;i>-1;i--){
            sum *= nums[i+1];
            to_return[i] *= sum;
        }
        return to_return;
    }
};

void printVecInt( vector<int>vec){
    printf("[ ");
    for(int elem : vec){
        printf("%d, ", elem);
    }
    printf("]\n");
}

int main(){
    Solution sol;
    vector<int> vec1 = {1,2,3,4};
    auto ans1 = sol.productExceptSelf(vec1);
    printVecInt(ans1);

    vector<int> vec2 = {-1,1,0,-3,3};
    auto ans2 = sol.productExceptSelf(vec2);
    printVecInt(ans2);
}
