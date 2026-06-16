#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class FreqMap{
    std::unordered_map<char, int> freq_map;
    public:
    void add(char ch){
        auto ch_iter = freq_map.find(ch);
        if(ch_iter != freq_map.end()){
            ch_iter->second++;
        }
        else{
            freq_map.insert({ch, 1});
        }
    }
    void remove(char ch){
        auto rem_char = freq_map.find(ch);
        if(rem_char != freq_map.end()){
            if(rem_char->second > 1){
                rem_char->second--;
            }
            else{
                freq_map.erase(rem_char);
            }
        }
    }
    bool isEmpty(){
        return freq_map.empty();
    }
    void print(){
        if(freq_map.empty()){
            printf("freq_map is empty !");
        }
        printf("[ ");
        for(auto key_pair : freq_map){
            printf("%c => %d, ", key_pair.first, key_pair.second);
        }
        printf("]\n");
    }
    bool operator==(const FreqMap& b) const {
        if(freq_map.size() != b.freq_map.size()){
            return false;
        }
        for(const auto& [key_a, val_a] : freq_map){
            auto pair_b = b.freq_map.find(key_a);
            if( pair_b == b.freq_map.end() || val_a != pair_b->second ){
                return false;
            }
        }
        return true;
    }
};
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

vector<vector<string>> createAnagram(vector<string>::iterator ptr1, vector<string>::iterator ptr2,
        int count){
    vector<vector<string>> to_return;
    if (count==1) {
        to_return = {{*ptr1}};
        return to_return;
    }
    FreqMap *freq_map_arr = new FreqMap[count];
    int i = 0;
    vector<string>::iterator ptr1_tmp = ptr1;
    while(ptr1_tmp != ptr2){
        // printf("creating freq_map for :%s\n",ptr1_tmp->c_str());
        for(char ch : *ptr1_tmp){
            freq_map_arr[i].add(ch);
        }
        // freq_map_arr[i].print();
        ptr1_tmp++;
        i++;
    }


    bool *matched = new bool[count]();  // Value-initialized to false
    for(int i=0;i<count;i++){
        if(matched[i]){
            continue;
        }
        vector<string> curr_tuple;
        curr_tuple.push_back(*(ptr1 + i));  

        for(int j=i+1;j<count;j++){
            if(matched[j]){
                continue;
            }
            if(freq_map_arr[i] == freq_map_arr[j]){
                curr_tuple.push_back(*(ptr1+j));
                matched[j] = true;
            }
        }
        to_return.push_back(curr_tuple);
    }

    return to_return;
}

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string> &strs){
            vector<vector<string>> ans;
            sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
                    return a.length() < b.length();
                    });
            // printVecStr(strs);
            auto ptr1 = strs.begin();
            auto ptr2 = ptr1;
            int curr_len = ptr1->length();
            int count = 0;
            bool exit = false;

            while(true){
                if(ptr2->length() == curr_len){
                    ptr2++;
                    count++;
                    if(ptr2 != strs.end()){
                        continue;
                    }
                    exit = true;
                }
                vector<vector<string>> anagram_tuples = createAnagram(ptr1, ptr2, count);
                for(vector<string> anagram_tuple : anagram_tuples ){
                    ans.push_back(anagram_tuple);
                }
                if(exit){
                    break;
                }
                else if(ptr2 == strs.end()-1){
                    ans.push_back({*ptr2});
                    return ans;
                }
                ptr1 = ptr2;
                curr_len = ptr1->length();
                count = 0;
            }
            return ans;
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
