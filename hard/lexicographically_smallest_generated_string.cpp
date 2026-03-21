class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int L = n + m - 1;

        string word(L, '?');
        vector<bool> locked(L, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        locked[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }
        for (int i = 0; i < L; i++) {
            if (word[i] == '?') {
                word[i] = 'a';
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {

                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool ok = false;

                    for (int j = m - 1; j >= 0; j--) {

                        if (locked[i + j]) continue;

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c == str2[j]) continue;

                            char old = word[i + j];
                            word[i + j] = c;

                            bool mincheu = true;
                            for (int k = 0; k < m; k++) {
                                if (word[i + k] != str2[k]) {
                                    mincheu = false;
                                    break;
                                }
                            }

                            if (!mincheu) {
                                ok = true;
                                break;
                            }

                            word[i + j] = old;
                        }

                        if (ok) break;
                    }

                    if (!ok) return "";
                }
            }
        }

        return word;
    }
};
