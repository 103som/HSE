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

    std::map<std::string, std::vector<int>> allContestsResults;
    std::unordered_set<std::string> allSurnames;
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;

        for (int j = 0; j < k; ++j) {
            std::string studentSurname;
            std::cin >> studentSurname;

            int score;
            std::cin >> score;

            size_t prevSize = allSurnames.size();
            allSurnames.insert(studentSurname);
            if (prevSize == allSurnames.size()) {
                allContestsResults[studentSurname][i] = score;
            }
            else {
                allContestsResults.insert(std::make_pair(studentSurname, std::vector<int>(n)));
                allContestsResults[studentSurname][i] = score;
            }
        }
    }

    for (auto studentResults : allContestsResults) {
        std::cout << studentResults.first << "\t";

        for (auto result : studentResults.second)
            std::cout << result << "\t";

        std::cout << "\n";
    }
}
