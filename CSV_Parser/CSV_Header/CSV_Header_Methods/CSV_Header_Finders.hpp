#pragma once
#include "../CSV_Header.hpp"

std::string CSV_Header::at( int pos ) {
    if( !this->isValied( pos ) )
        throw std::out_of_range( "CSV_Header::at( " + std::to_string( pos ) + " ): Available range: min:0, max:" + std::to_string( this->header.size() - 1 ) );

    return this->header[ pos ];
    
}

int CSV_Header::pos( const std::string& headerName ) {
    if( this->isValied( headerName ) )
        return this->headerMap[ headerName ];    
    return -1;
}