#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;
        for (int i = 0; i < s.length(); i++) {
            mapS[s[i]]++;
            mapT[t[i]]++;
        }
        for (int j = 0; j < mapS.size(); j++) {
            if (mapS[j] != mapT[j]) {
                return false;
            }
        }
        return true;
    }
};