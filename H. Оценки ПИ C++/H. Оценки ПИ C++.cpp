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
#include <unordered_map>
#include <list>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<std::string,
        std::pair<unsigned long long, unsigned long long>> studentsCount;
    std::list<unsigned long long> st;
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;

        unsigned long long grade;
        std::cin >> grade;

        if (studentsCount.find(str) == studentsCount.end()) {
            studentsCount.insert(std::make_pair(str, std::make_pair(grade, 1)));
            st.push_back(grade);
        }
        else {
            studentsCount[str].first = studentsCount[str].first + grade;
            ++studentsCount[str].second;
            st.push_back(studentsCount[str].first / studentsCount[str].second);
        }
    }

    for (auto student : st)
        std::cout << student << "\n";
}
