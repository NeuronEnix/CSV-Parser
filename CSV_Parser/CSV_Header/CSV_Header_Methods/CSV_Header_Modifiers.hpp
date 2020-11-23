#pragma once
#include "../CSV_Header.hpp"

bool CSV_Header::swapHeader( const std::string& firstHeaderName, const std::string& secondHeaderName ) {

    // u_map< headerName, headerPos > headerMap

    auto firstHeaderIt = this->headerMap.find( firstHeaderName );
    auto secondHeaderIt = this->headerMap.find( secondHeaderName );

    if( firstHeaderIt == this->headerMap.end() or secondHeaderIt == this->headerMap.end() )
        return false;

    if( firstHeaderIt == secondHeaderIt ) return true;

    std::swap( this->header[ firstHeaderIt->second ], this->header[ secondHeaderIt->second ] );
    std::swap( firstHeaderIt->second, secondHeaderIt->second );

}

bool CSV_Header::swapHeader( const int firstPos, const int secondPos ) {
    this->swapHeader( this->header[ firstPos ], this->header[ secondPos ] );
}
