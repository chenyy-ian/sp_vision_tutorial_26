#include <fmt/core.h>
#include <fmt/chrono.h>  // 时间格式化支持
#include <vector>
#include <string>
#include <chrono>
#include <system_error>

int main() {
    // 1. 基本 print
    fmt::print("Hello, {}!\n", "World");

    // 2. 使用 format 构造字符串
    std::string s = fmt::format("The answer is {}.", 42);
    fmt::print("{}\n", s);

    // 3. 参数顺序
    fmt::print("{0}, {1}, {2}\n", 'a', 'b', 'c');   // a, b, c
    fmt::print("{2}, {1}, {0}\n", 'a', 'b', 'c');   // c, b, a

    // 4. 对齐和宽度
    fmt::print("left   : |{:<10}|\n", "text");
    fmt::print("right  : |{:>10}|\n", "text");
    fmt::print("center : |{:^10}|\n", "text");
    fmt::print("fill   : |{:*^10}|\n", "text");

    // 5. 不同进制
    fmt::print("int: {0:d}; hex: {0:x}; oct: {0:o}; bin: {0:b}\n", 42);
    fmt::print("int: {0:d}; hex: {0:#x}; oct: {0:#o}; bin: {0:#b}\n", 42);

    // 6. 容器打印 (v8 不支持，需要升级到 v9+ 或手动打印)
    // fmt::print("Vector: {}\n", std::vector{1, 2, 3}); // v8 会报错
    std::vector<int> vec{1, 2, 3};
    fmt::print("Vector: [");
    for (size_t i = 0; i < vec.size(); ++i) {
        fmt::print("{}", vec[i]);
        if (i != vec.size() - 1) fmt::print(", ");
    }
    fmt::print("]\n");

    // 7. 时间格式化
    std::tm t{};
    t.tm_year = 2010 - 1900;  // 年份从 1900 开始
    t.tm_mon  = 7;            // 8 月 (0-based)
    t.tm_mday = 4;
    t.tm_hour = 12;
    t.tm_min  = 15;
    t.tm_sec  = 58;
    fmt::print("Time: {:%Y-%m-%d %H:%M:%S}\n", t);

    // 8. error_code 格式化
    auto ec = std::make_error_code(std::errc::no_such_file_or_directory);
    fmt::print("Error: {}\n", ec.message());  // 使用 message() 而不是 {:s}

    return 0;
}
