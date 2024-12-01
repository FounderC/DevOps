#include "cpp-httplib/httplib.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <iostream>

class TrigonometricFunctions {
public:
    static std::vector<double> calculateTrigonometricFunctions(int num_elements) {
        std::vector<double> values;
        for (int i = 0; i < num_elements; ++i) {
            values.push_back(std::sin(i * M_PI / 180.0));
        }
        return values;
    }
};

int main() {
    httplib::Server svr;

    svr.Get("/calculate", [](const httplib::Request& req, httplib::Response& res) {
        int num_elements = 1000;
        std::vector<double> values = TrigonometricFunctions::calculateTrigonometricFunctions(num_elements);

        auto start_time = std::chrono::high_resolution_clock::now();
        std::sort(values.begin(), values.end());
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        res.set_content("Calculation time: " + std::to_string(duration.count()) + " ms", "text/plain");
    });

    svr.listen("0.0.0.0", 8080);
    return 0;
}
