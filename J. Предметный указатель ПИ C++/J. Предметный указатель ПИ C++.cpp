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

    std::map<int, std::set<std::string>> allPages;
    for (int i = 0; i < n; ++i) {
        std::string name;
        int page;
        std::cin >> name >> page;

        if (allPages.contains(page))
            allPages[page].insert(name);
        else
            allPages.insert(std::make_pair(page, std::set<std::string>({ name })));
    }

    for (auto page : allPages) {
        std::cout << page.first << ' ';

        for (auto name : page.second)
            std::cout << name << ' ';

        std::cout << "\n";
    }
}
