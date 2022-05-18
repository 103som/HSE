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

std::deque<std::string> GetData() {
    int n;
    std::cin >> n;

    std::deque<std::string> allStudents;
    for (int i = 0; i < n; ++i) {
        std::string studentsSurname, position;
        std::cin >> studentsSurname >> position;

        if (position == "bottom")
            allStudents.push_back(studentsSurname);
        else
            allStudents.push_front(studentsSurname);
    }

    return allStudents;
}

void answerRequests(const std::deque<std::string>& allStudentsInfo) {
    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        int ind;
        std::cin >> ind;
        std::cout << allStudentsInfo[ind - 1] << "\n";
    }
}

int main() {
    answerRequests(GetData());
}
