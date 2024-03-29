//
// Created by sebastian on 23.06.19.
//

#include "stringUtils.h"

void utils::split(std::vector<std::string> &strs, const std::string &txt,  char ch) noexcept {
    strs.clear();
    size_t pos = txt.find( ch );
    size_t initialPos = 0;

    while( pos != std::string::npos ) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;

        pos = txt.find( ch, initialPos );
    }

    strs.push_back( txt.substr( initialPos, std::min( pos, txt.size() ) - initialPos + 1 ) );
}

// ---- from: https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring ---

// trim from start (in place)
void utils::ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
void utils::rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
void utils::trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
std::string utils::ltrim_copy(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
std::string utils::rtrim_copy(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
std::string utils::trim_copy(std::string s) {
    trim(s);
    return s;
}

[[nodiscard]] std::optional<std::size_t> utils::findNthSubStr(std::size_t n, const std::string& subString, const std::string& string) {
    std::string::size_type i = string.find(subString);
    std::string::size_type adv = subString.length();

    std::size_t j;
    for (j = 1; j < n && i != std::string::npos; ++j)
        i = string.find(subString, i+adv);

    if (j == n)
        return i;
    else
        return std::nullopt;
}