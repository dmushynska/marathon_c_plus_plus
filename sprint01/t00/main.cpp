#include <array>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 6) {
        std::cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5\n";
        return 1;
    }
    std::array<std::string, 5> arr{argv[1], argv[2], argv[3], argv[4],
                                   argv[5]};
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << ((i != 4) ? " " : "\n");
}