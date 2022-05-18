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

void FindAllDirectories(const std::string& str, std::set<std::string>& allDirectories) {
    if (str.size() != 0 && str[0] != '/')
        return;

    allDirectories.insert("/");

    std::string::size_type curPos = 1, prevPos = 1;
    while ((curPos = str.find('/', prevPos)) != std::string::npos) {
        allDirectories.insert(str.substr(0, curPos + 1));

        prevPos = curPos + 1;
    }
}

int main() {
    std::set<std::string> allDirectories;

    std::string str;
    while (std::getline(std::cin, str))
        FindAllDirectories(str, allDirectories);


    for (auto directory : allDirectories)
        std::cout << directory << "\n";
}
