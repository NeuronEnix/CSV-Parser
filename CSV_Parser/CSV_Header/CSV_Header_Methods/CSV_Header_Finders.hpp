#pragma once
#include "../CSV_Header.hpp"

std::string CSV_Header::headerAt( int pos ) {
    const int min = 0, max = this->header.size();
    if( pos >= min and pos < max ) return this->header[ pos ];
    throw std::out_of_range( "CSV_Header::headerAt( " + std::to_string( pos ) + " ): Available range: min:0, max:" + std::to_string( max ) );
}

int CSV_Header::headerPos( const std::string& headerName ) {
    auto foundHeaderIterator = this->headerMap.find( headerName );
    if ( foundHeaderIterator == this->headerMap.end() )
        return -1;
    return foundHeaderIterator->second;    
}