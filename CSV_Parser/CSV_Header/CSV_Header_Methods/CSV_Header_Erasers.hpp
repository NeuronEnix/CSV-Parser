#pragma once 
#include "../CSV_Header.hpp"

/* Erasers */

bool CSV_Header::erase( const int headerPos ) {
    if( !this->isValied( headerPos ) ) return false;

    this->headerMap.erase( this->header[headerPos] );
    this->header.erase( this->header.begin() + headerPos );
    
    return true;
}

bool CSV_Header::erase( const std::string& headerName ) {
    this->erase( this->pos( headerName ) );
}
