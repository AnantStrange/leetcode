#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

void printVecVecStr(const std::vector<std::vector<std::string>>& ans) {
    for (size_t i = 0; i < ans.size(); i++) {
        std::cout << "Group " << i + 1 << ": [ ";
        for (size_t j = 0; j < ans[i].size(); j++) {
            std::cout << "\"" << ans[i][j] << "\"";
            if (j < ans[i].size() - 1) std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }
}

void printVecStr(vector<string>strs){
    std::cout << "[ ";
    for (size_t i = 0; i < strs.size(); i++) {
        printf("%s, ",strs[i].c_str());
    }
    std::cout << "]" << std::endl;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& p : groups) {
            result.push_back(p.second);
        }
        return result;
    }
};


int main(){
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<string> strs2 = {"eat","tea","tan","ate","nat","bat","ac","bd","aac","bbd","aacc","bbdd","acc","bdd"};
    vector<vector<string>> ans = sol.groupAnagrams(strs);
    printVecVecStr(ans);
    printf("\n");
    vector<vector<string>> ans2 = sol.groupAnagrams(strs2);
    printVecVecStr(ans2);
}
