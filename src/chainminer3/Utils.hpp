#pragma once
#include <string>
#include <vector>

namespace chainminer3::utils {


inline std::string
s_replace(std::string strSrc, const std::string& oldStr, const std::string& newStr, size_t count = -1) {
    std::string strRet  = strSrc;
    size_t      pos     = 0;
    int         l_count = 0;
    if (-1 == count) count = strRet.size();
    while ((pos = strRet.find(oldStr, pos)) != std::string::npos) {
        strRet.replace(pos, oldStr.size(), newStr);
        if (++l_count >= count) break;
        pos += newStr.size();
    }
    return strRet;
}

template <typename T>
inline bool v_contains(std::vector<T>& v, const T f) {
    for (auto it = v.begin(); it != v.end(); it++) {
        if (*it == f) return true;
    }
    return false;
}

template <typename T>
inline int v_remove(std::vector<T>& v, const T f) {
    int  count = 0;
    auto it    = v.begin();
    while (it != v.end()) {
        if (*it == f) {
            it = v.erase(it);
        } else {
            it++;
        }
    }
    return false;
}


} // namespace chainminer3::utils
