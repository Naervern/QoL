#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> n_text;

std::string fixline(std::string line) {
  //  int i;
    if (line.find("/in ") != std::string::npos && line.find("/e ") == std::string::npos) {
        for (int i = line.find("/in ") + 4; i < line.length(); i++) {
            if (line[i] == ' ') {
                //adds the corrective /e right before the space after the /in sentence;
                line.insert(i, " /e");
                break;
            }
        }
    }
    return line;
}

int main()
{
    std::string filename = "";
    std::cout << "Enter file name to fix. (Default = macros-cache.txt)" << '\n';
    getline(std::cin, filename);
    filename = filename == "" ? "macros-cache.txt" : filename;
    std::fstream text(filename);
    if (text.fail()) {
        std::cout << "\n-- Error --\nFile " << filename << " not found on root directory.\n";
        system("pause");
        return 0;
    }
    for (std::string line; getline(text, line);) {
        line = fixline(line);
        std::cout << line << '\n';
        n_text.push_back(line);
    }
    text.close();
    text.open(filename, std::ios::out | std::ios::trunc);
    for (const auto& i : n_text) text << i << std::endl;
    std::cout << "\n\nChanges saved to " << filename << '\n';
    system("pause");
    return 0;
}
