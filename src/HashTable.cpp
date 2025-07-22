#include "HashTable.hpp"

void HashTable::insert(const std::string& key, const std::string& value) {
    table[key] = value;
}

std::string HashTable::get(const std::string& key) {
    if (table.find(key) != table.end()) {
        return table[key];
    }
    return "Key not found";
}
