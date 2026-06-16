#include <string>
#include <unordered_map>

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
    bool operator==(const FreqMap& b){
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

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        FreqMap freq_map_s;
        FreqMap freq_map_t;

        for(char ch : s) {
            freq_map_s.add(ch);
        }
        freq_map_s.print();
        for(char ch : t) {
            freq_map_t.add(ch);
        }
        freq_map_t.print();

        return freq_map_s == freq_map_t;
    };
};

int main(){
    Solution sol;
    std::string str_a = "";
    std::string str_b = "";
    printf("%d\n", sol.isAnagram(str_a, str_b));
}
