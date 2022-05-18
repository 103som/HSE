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

struct Vector {
    std::string name;
    std::vector<int> coords;

    Vector() {}

    Vector(std::string name, std::vector<int> coords) : name(name), coords(coords) {}

    double operator*(const Vector& rhs) const {
        // if (coords.size() != rhs.coords.size())
            // throw std::exception("Векторы несоотносятся по размерностям.");

        double ans = 0;
        for (size_t i = 0; i < coords.size(); ++i)
            ans += static_cast<double>(coords[i]) * static_cast<double>(rhs.coords[i]);

        return ans;
    }

    static Vector GetCurVector(int dimensions) {
        std::string name;
        std::cin >> name;

        std::vector<int> coords(dimensions);
        for (int i = 0; i < dimensions; ++i)
            std::cin >> coords[i];

        return Vector(name, coords);
    }
};



int main() {
    int m, n;
    std::cin >> m >> n;

    std::vector<Vector> allVectors(m);

    for (int i = 0; i < m; ++i)
        allVectors[i] = Vector::GetCurVector(n);

    std::vector<double> compareVectors(m);
    for (int i = 1; i < m; ++i)
        compareVectors[i] = allVectors[i] * allVectors[0];

    double mxx = compareVectors[1];
    for (int i = 1; i < m; ++i)
        mxx = std::max(mxx, compareVectors[i]);

    for (int i = 1; i < m; ++i) {
        if (compareVectors[i] == mxx)
            std::cout << allVectors[i].name << "\n";
    }
}
