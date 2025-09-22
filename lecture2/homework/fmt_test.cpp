#include <fmt/core.h>
#include <fmt/chrono.h>
#include <vector>
#include <string>
#include <chrono>
#include <system_error>

int main() {   
    fmt::print("Hello, {}!\n", "World");

    std::string s = fmt::format("The answer is {}.", 42);
    fmt::print("{}\n", s);

    fmt::print("{0}, {1}, {2}\n", 'a', 'b', 'c');
    fmt::print("{2}, {1}, {0}\n", 'a', 'b', 'c');

    fmt::print("left   : |{:<10}|\n", "text");
    fmt::print("right  : |{:>10}|\n", "text");
    fmt::print("center : |{:^10}|\n", "text");
    fmt::print("fill   : |{:*^10}|\n", "text");

    fmt::print("int: {0:d}; hex: {0:x}; oct: {0:o}; bin: {0:b}\n", 42);
    fmt::print("int: {0:d}; hex: {0:#x}; oct: {0:#o}; bin: {0:#b}\n", 42);

    std::vector<int> vec{1, 2, 3};
    fmt::print("Vector: [");
    for (size_t i = 0; i < vec.size(); ++i) {
        fmt::print("{}", vec[i]);
        if (i != vec.size() - 1) fmt::print(", ");
    }
    fmt::print("]\n");

    std::tm t{};
    t.tm_year = 2010 - 1900;
    t.tm_mon  = 7;
    t.tm_mday = 4;
    t.tm_hour = 12;
    t.tm_min  = 15;
    t.tm_sec  = 58;
    fmt::print("Time: {:%Y-%m-%d %H:%M:%S}\n", t);

    auto ec = std::make_error_code(std::errc::no_such_file_or_directory);
    fmt::print("Error: {}\n", ec.message());

    return 0;
}
