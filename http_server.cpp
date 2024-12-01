#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cmath>
#include "cpp-httplib/httplib.h"

double calculate(double x) {
    return sin(x);
}

int main() {
    httplib::Server svr;

    svr.Get("/calculate", [](const httplib::Request &req, httplib::Response &res) {
        const int array_size = 100000;
        const int sorting_cycles = 100;

        std::vector<double> values(array_size);
        for (int i = 0; i < array_size; ++i) {
            values[i] = calculate(i * 0.01);
        }

        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < sorting_cycles; ++i) {
            std::sort(values.begin(), values.end());
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

        res.set_content("Calculation completed in " + std::to_string(elapsed) + " seconds", "text/plain");
    });
	std::cout << "HTTP server is running on http://localhost:8080" << std::endl;
	svr.listen("0.0.0.0", 8080);

	return 0;
}

