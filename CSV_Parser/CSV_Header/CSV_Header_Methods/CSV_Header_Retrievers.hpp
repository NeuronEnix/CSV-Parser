#pragma once
#include "../CSV_Header.hpp"

std::vector< std::string >& CSV_Header::getHeader() {
    return this->header;
}
