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

std::vector<std::string_view> Split(const std::string_view& str, char delimiter) {
    std::vector<std::string_view> ans;

    std::string::size_type curPos = 0, prevPos = 0;
    while ((curPos = str.find(delimiter, prevPos)) != std::string_view::npos) {
        ans.push_back(str.substr(prevPos, (curPos - prevPos)));

        prevPos = curPos + 1;
    }


    ans.push_back(str.substr(prevPos, (str.size() - prevPos)));

    return ans;
}

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::unordered_set<std::string_view> st;

    std::string str;
    while (std::getline(fin, str)) {
        if (str[0] == '#')
            break;

        auto curStr = Split(str, ' ');

        if (curStr[0] == "+") {
            st.insert(curStr[1]);
        }
        else if (curStr[0] == "-") {
            st.erase(curStr[1]);
        }
        else if (curStr[0] == "?") {
            if (st.find(curStr[1]) != st.end())
                fout << "YES\n";
            else
                fout << "NO\n";
        }
    }


    fin.close();
    fout.close();
}
