#pragma once
#include "../CSV_Data.hpp"

std::string& CSV_Data::at( const size_t rowPos, const size_t colPos ) {
    if( !this->isValidRowPos( rowPos ) or !this->isValidColPos( colPos ) ) 
        throw std::out_of_range( "Out of range" );
    return this->data[ rowPos ][ this->virtualColPos[ colPos ] ];
}
