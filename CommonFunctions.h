#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>


class CommonFunctions {
public:
    CommonFunctions() = delete; // optional: prevent instantiation



   static int GenerateNextID(const std::string& FileName) {
        std::ifstream inFile(FileName);
        std::string line;
        int lastID = 0;

        if (!inFile.is_open()) {
            std::cout << " Failed to open file: " << FileName << "\n";
            return 1;
        }

        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string idStr;
            std::getline(ss, idStr, ','); // assumes ID is first
            try {
                lastID = std::stoi(idStr);
            }
            catch (...) {
                continue;
            }
        }

        return lastID + 1;
    }

   static void AddDataLineToFile(const std::string& FileName, const std::string& stDataLine) {
        std::ofstream MyFile(FileName, std::ios::out | std::ios::app);
        if (MyFile.is_open()) {
            MyFile << stDataLine << std::endl;
            MyFile.close();
        }
    }

   static std::vector<std::string> SplitString(const std::string& S1, const std::string& Delim) {
        std::vector<std::string> vString;
        std::string s = S1;
        size_t pos = 0;

        while ((pos = s.find(Delim)) != std::string::npos) {
            std::string token = s.substr(0, pos);
            if (!token.empty()) vString.push_back(token);
            s.erase(0, pos + Delim.length());
        }

        if (!s.empty()) vString.push_back(s);
        return vString;
    }
   static bool IsNumber(const std::string& str) {
       if (str.empty()) return false;

       for (char ch : str) {
           if (!std::isdigit(ch)) return false;
       }

       return true;
   }


};

