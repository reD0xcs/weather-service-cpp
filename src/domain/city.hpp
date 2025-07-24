#pragma once
#include <string>

struct City {
    std::string name;
};

inline bool operator==(const City& lhs, const City& rhs) {
    return lhs.name == rhs.name;
}
