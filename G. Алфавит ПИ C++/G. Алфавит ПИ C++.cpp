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
    std::string str;
    std::cin >> str;

    std::unordered_set<char> st;
    for (auto symb : str)
        st.insert(symb);

    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> str;

        bool flag = false;
        for (auto symb : str)
            if (st.find(symb) == st.end())
                flag = true;

        if (!flag)
            std::cout << str << "\n";
    }
}
