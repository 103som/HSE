#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <istream>
#include <fstream>

int main() {
    std::set<int> st;

    int num;
    while (std::cin >> num) {
        size_t prevSize = st.size();
        st.insert(num);


        if (prevSize == st.size())
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}
