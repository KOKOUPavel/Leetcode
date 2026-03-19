#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string word(n + m - 1, '?');

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i+j] == '?' || word[i+j] == str2[j]) {
                        word[i+j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool equal = true;
                for (int j = 0; j < m; j++) {
                    if (word[i+j] == '?' || word[i+j] != str2[j]) {
                        equal = false;
                        break;
                    }
                }
                if (equal) {
                    for (int j = 0; j < m; j++) {
                        if (word[i+j] == '?') {
                            word[i+j] = 'a';
                            if (word[i+j] == str2[j]) word[i+j] = 'b';
                            break;
                        }
                    }
                    bool stillEqual = true;
                    
                    for (int j = 0; j < m; j++) {
                        if (word[i+j] != str2[j]) {
                            stillEqual = false;
                            break;
                        }
                    }
                    if (stillEqual) return "";
                }
            }
        }

        for (char &c : word) if (c == '?') c = 'a';

        return word;
    }
};
