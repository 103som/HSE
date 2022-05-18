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
#include <deque>
#include <queue>

int main() {
    int sportsmenCount;
    std::cin >> sportsmenCount;

    std::vector<int> helpContainer(300001, -1);
    std::vector<int> checkSportsmanInLine(300001, false);

    int firstSportsman = -1;
    for (int i = 0; i < sportsmenCount; ++i) {
        int fromSportsman, toSportsman;
        std::cin >> fromSportsman >> toSportsman;

        if (firstSportsman == -1) {
            firstSportsman = fromSportsman;
            checkSportsmanInLine[fromSportsman] = true;

            continue;
        }

        if (!checkSportsmanInLine[toSportsman]) {
            helpContainer[fromSportsman] = firstSportsman;
            firstSportsman = fromSportsman;
            checkSportsmanInLine[fromSportsman] = true;

            continue;
        }

        if (fromSportsman == toSportsman)
            continue;


        checkSportsmanInLine[fromSportsman] = true;

        if (toSportsman == -1) {
            helpContainer[toSportsman] = fromSportsman;

            continue;
        }

        int buff = helpContainer[toSportsman];
        helpContainer[toSportsman] = fromSportsman;
        helpContainer[fromSportsman] = buff;
    }

    for (int i = firstSportsman; i != -1; i = helpContainer[i])
        if (checkSportsmanInLine[i])
            std::cout << i << "\n";
}
