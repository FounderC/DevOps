#include <iostream>
#include <chrono>
#include <cassert>
#include "cpp-httplib/httplib.h"

int main() {
    httplib::Client cli("http://localhost:8080");
    auto start = std::chrono::high_resolution_clock::now();
    auto res = cli.Get("/calculate");
    auto end = std::chrono::high_resolution_clock::now();
    assert(res && res->status == 200);
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
    std::cout << "Elapsed time: " << elapsed << " seconds" << std::endl;
    assert(elapsed >= 5 && elapsed <= 20);
    return 0;
}
