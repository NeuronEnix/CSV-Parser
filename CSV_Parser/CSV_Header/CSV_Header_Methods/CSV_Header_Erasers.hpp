#pragma once 
#include "../CSV_Header.hpp"

/* Erasers */

bool CSV_Header::erase( const int headerPos ) {
    return this->erase( this->at( headerPos ) );
}

bool CSV_Header::erase( const std::string& headerName ) {
    if( !this->isValied( headerName ) ) return false;

    // move the header to the end
    this->moveTo( headerName, this->header.size()-1 );

    // erase the last header after moving
    this->header.erase( this->header.end() - 1 );
    this->headerMap.erase( headerName );

    return true;
}
