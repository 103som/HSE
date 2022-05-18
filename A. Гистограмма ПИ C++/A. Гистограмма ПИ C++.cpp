#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <istream>
#include <fstream>

void GetData(std::map<char, int>& mp) {
    std::ifstream fin("input.txt");
    std::string str;
    std::set<char> st;
    while (fin >> str) {
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == ' ' || str[i] == '\n')
                continue;

            size_t prevSize = st.size();
            st.insert(str[i]);

            if (st.size() == prevSize)
                ++mp[str[i]];
            else
                mp.insert(std::make_pair(str[i], 1));
        }
    }

    fin.close();
}

int FindMax(std::map<char, int>& mp) {
    int mxx = -5;
    for (auto el : mp)
        mxx = std::max(mxx, el.second);

    return mxx;
}

int main() {
    std::ofstream fout("output.txt");
    std::map<char, int> mp;
    GetData(mp);

    int mxxSize = FindMax(mp);
    for (int i = 0, curSize = mxxSize; i < mxxSize; ++i, --curSize) {
        for (auto cur : mp) {
            if (cur.second - curSize >= 0)
                fout << '#';
            else
                fout << ' ';
        }

        fout << "\n";
    }


    for (auto cur : mp) {
        fout << cur.first;
    }

    fout.close();
}
