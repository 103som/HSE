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

std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> ans;

    std::string::size_type curPos = 0, prevPos = 0;
    while ((curPos = str.find(delimiter, prevPos)) != std::string::npos) {
        ans.push_back(str.substr(prevPos, (curPos - prevPos)));

        prevPos = curPos + 1;
    }


    ans.push_back(str.substr(prevPos, (str.size() - prevPos)));

    return ans;
}

class DateTime {
private:
    int day = 0;
    int month = 0;
    int year = 0;

    enum months {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    static inline std::map<int, int> daysInMonth;
    void SetDaysInMonth() {
        daysInMonth = { {std::make_pair(months::January, 31)},
        {std::make_pair(months::February, 28 +
            (GetYear() % 400 == 0 ? 1 :
                (GetYear() % 100 == 0 ? 0 :
                    (GetYear() % 4 == 0 ? 1 : 0))))},
        {std::make_pair(months::March, 31)},
        {std::make_pair(months::April, 30)},
        {std::make_pair(months::May, 31)},
        {std::make_pair(months::June, 30)},
        {std::make_pair(months::July, 31)},
        {std::make_pair(months::August, 31)},
        {std::make_pair(months::September, 30)},
        {std::make_pair(months::October, 31)},
        {std::make_pair(months::November, 30)},
        {std::make_pair(months::December, 31)} };
    }

public:
    DateTime() {}

    DateTime(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;

        if (daysInMonth.size() == 0)
            SetDaysInMonth();
    }

    int GetDay() { return day; }
    void SetDay(int day) { this->day = day; }

    int GetMonth() { return day; }
    void SetMonth(int month) { this->month = month; }

    int GetYear() { return year; }
    void SetYear(int year) { this->year = year; }

    DateTime GetNextDay() {
        if (day + 2 <= daysInMonth[month])
            return DateTime(day + 2, month, year);

        if (month != months::December)
            return DateTime(day + 2 - daysInMonth[month], month + 1, year);

        return DateTime(day + 2 - daysInMonth[month], 1, year + 1);
    }

    operator std::string() const {
        return (std::to_string(day) + " " + std::to_string(month) + " " + std::to_string(year));
    }

    bool operator <(const DateTime& rhs) const {
        return (std::tie(year, month, day) < std::tie(rhs.year, rhs.month, rhs.day));
    }

    bool operator >(const DateTime& rhs) const {
        return (std::tie(year, month, day) > std::tie(rhs.year, rhs.month, rhs.day));
    }

    bool operator ==(const DateTime& rhs) const {
        return (std::tie(year, month, day) == std::tie(rhs.year, rhs.month, rhs.day));
    }

    bool operator !=(const DateTime& rhs) const {
        return (std::tie(year, month, day) != std::tie(rhs.year, rhs.month, rhs.day));
    }
};

struct Student {
    std::string name, surname;
    DateTime birthday;
    int score;
    std::vector<std::string> priorityUniversities;

    Student() {}

    Student(std::string name, std::string surname, DateTime birtday,
        int score, std::vector<std::string> priorityUniversities) {
        this->name = name;
        this->surname = surname;
        this->birthday = birtday;
        this->score = score;
        this->priorityUniversities = priorityUniversities;
    }

    bool operator <(const Student& rhs) const {
        return std::tie(surname, name, birthday) <
            std::tie(rhs.surname, rhs.name, rhs.birthday);
    }

    operator std::string() const {
        return (name + " " + surname);
    }
};

bool SortingStudentsByTheirResults(const Student& lhs, const Student& rhs) {
    if (lhs.score != rhs.score)
        return lhs.score > rhs.score;

    if (lhs.birthday != rhs.birthday)
        return lhs.birthday < rhs.birthday;

    return (std::tie(lhs.surname, lhs.name) < std::tie(rhs.surname, rhs.name));
}

int main() {
    int n;
    std::cin >> n;

    std::set<std::string> universitiesSorted;
    std::unordered_map<std::string, int> universities(n);
    std::unordered_map<std::string, std::set<Student>> acceptedStudents(n);

    for (int i = 0; i < n; ++i) {
        std::string university;
        std::cin >> university;

        int maxStudents;
        std::cin >> maxStudents;

        universitiesSorted.insert(university);
        universities.insert(std::make_pair(university, maxStudents));
        acceptedStudents.insert(std::make_pair(university, std::set<Student>()));
    }

    int totalStudentsCount;
    std::cin >> totalStudentsCount;

    std::vector<Student> students(totalStudentsCount);
    for (int i = 0; i < totalStudentsCount; ++i) {
        std::string name, surname;
        int day, month, year, score, cnt;
        std::cin >> name >> surname >> day >> month >> year >> score >> cnt;

        std::vector<std::string> priorityUnivers(cnt);
        for (int j = 0; j < cnt; ++j)
            std::cin >> priorityUnivers[j];

        students[i] = (Student(name, surname, DateTime(day, month, year),
            score, priorityUnivers));
    }

    std::sort(students.begin(), students.end(), SortingStudentsByTheirResults);

    for (Student student : students) {
        for (auto university : student.priorityUniversities) {
            if (universities[university] > 0) {
                acceptedStudents[university].insert(student);
                --universities[university];
                break;
            }
        }
    }

    for (auto studentList : universitiesSorted) {
        std::cout << studentList << "\t";

        for (auto student : acceptedStudents[studentList])
            std::cout << std::string(student) << "\t";

        std::cout << "\n";
    }
}