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
    std::string str1, str2;
    std::cin >> str1;

    std::set<char> st;
    for (size_t i = 0; i < str1.size(); ++i)
        st.insert(str1[i]);

    while (std::cin >> str2) {
        std::set<char> ans;
        for (size_t i = 0; i < str2.size(); ++i) {
            if (st.find(str2[i]) != st.end())
                ans.insert(str2[i]);
        }

        st = ans;
        str1 = str2;
    }

    for (char symb : st)
        std::cout << symb;
}
