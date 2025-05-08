#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <regex>

class Translator {
public:
    static std::string translate_comment(const std::string& line);

private:
    static std::unordered_map<std::string, std::string> translator;  // Static map

    static std::tuple<std::string, std::string> extract_comment_and_code(const std::string& line);
    static std::string trim_comment(const std::string& comment);
    static std::string trim(const std::string& str);
};

#endif // TRANSLATOR_H
