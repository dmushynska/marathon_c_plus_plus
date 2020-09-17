#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <string>

void print(std::multimap<std::string, std::string> &map, std::string &s) {
    std::string one;
    int counter = 0;
    // std::ofstream sout(s);

    for (auto &it : map) {
        if (one == it.first) {
            counter++;
        } else if (one != it.first) {
            one = it.first;
            counter = 1;
            // sout << it.first << ":\n";
            std::cout << it.first << ":\n";
        } else {
            counter++;
        }
        // sout << " " << counter << ": " << it.second << std::endl;
        std::cout << " " << counter << ": " << it.second << std::endl;
    }
}

int main(int argc, char **argv) {
    int counter = 1;
    std::multimap<std::string, std::string> map;
    std::ifstream stream(argv[1]);
    std::regex r("\\s*\"([^\"]+)\"\\s*:\\s*\"([^\"]+)\"\\s*");

    if (stream.fail())
        std::cerr << "error\n";
    for (std::string line; std::getline(stream, line); counter++) {
        std::cmatch result;
        if (line.empty())
            continue;
        if (std::regex_match(line.c_str(), result, r))
            map.insert(std::make_pair(result.str(1), result.str(2)));
        else {
            std::cerr << "Line " << counter << " is invalud\n";
            return 1;
        }
    }

    std::string s(argv[1]);
    print(map, s);
}