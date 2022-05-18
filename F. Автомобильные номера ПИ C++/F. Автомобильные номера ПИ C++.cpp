#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <istream>
#include <fstream>
#include <unordered_set>

int main() {
    int m;
    std::cin >> m;

    std::vector<std::unordered_set<char>> st(m);
    for (int i = 0; i < m; ++i) {
        std::string str;
        std::cin >> str;

        for (auto symb : str)
            st[i].insert(symb);
    }

    std::vector<std::pair<std::string, int>> mp;
    int mxx = -1;

    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;

        int cnt = 0;
        for (size_t j = 0; j < st.size(); ++j) {
            bool check = false;
            for (auto symb : st[j]) {
                if (std::find(str.begin(), str.end(), symb) == str.end()) {
                    check = true;
                    break;
                }
            }

            if (!check)
                ++cnt;
        }

        mxx = std::max(mxx, cnt);
        mp.push_back(std::make_pair(str, cnt));
    }

    for (auto number : mp)
        if (number.second == mxx)
            std::cout << number.first << "\n";
}
