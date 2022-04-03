#pragma "once"
#include <chrono>
#include <iostream>
using namespace std;

main() {
    const auto start_time = std::chrono::high_resolution_clock::now();
    // solve();
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;
    cerr << "Time Taken : " << diff.count() << "\n";
}