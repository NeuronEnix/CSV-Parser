#pragma once
#include "../CSV_Data.hpp"

std::vector< std::vector< std::string > >& CSV_Data::getData() { 
    return this->data;
}