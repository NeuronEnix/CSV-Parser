#pragma once
#include "../CSV_Header.hpp"

/* Swappers */

bool CSV_Header::swap( const std::string& firstHeaderName, const std::string& secondHeaderName ) {

    // u_map< headerName, headerPos > headerMap

    auto firstHeaderIt = this->headerMap.find( firstHeaderName );
    auto secondHeaderIt = this->headerMap.find( secondHeaderName );

    if( firstHeaderIt == this->headerMap.end() or secondHeaderIt == this->headerMap.end() )
        return false;

    if( firstHeaderIt == secondHeaderIt ) return true;

    std::swap( this->header[ firstHeaderIt->second ], this->header[ secondHeaderIt->second ] );
    std::swap( firstHeaderIt->second, secondHeaderIt->second );

    return true;

}

bool CSV_Header::swap( const int firstPos, const int secondPos ) {
    if( !this->isValied( firstPos ) or !this->isValied( secondPos ) ) return false;
    this->swap( this->header[ firstPos ], this->header[ secondPos ] ); // Swapping by headerNames 
    return true;
}


/* Movers */

bool CSV_Header::moveTo( const std::string& headerName, const int newPos ) {
    if( !this->isValied( newPos ) or !this->isValied( headerName ) ) return false;

    int curPos = this->headerMap[ headerName ];

    if( curPos < newPos ) // 0,1,2,..., curPos,..., newPos  ( move right )    
        while( curPos != newPos ) this->swap( curPos, ++curPos );

    else // 0,1,2,..., newPos,..., curPos  ( move left )    
        while( curPos != newPos ) this->swap( curPos, --curPos );
    
    return true;
}

bool CSV_Header::rename( const std::string& curHeaderName, const std::string& newHeaderName ) {
    if( !this->isValied( curHeaderName ) or !this->isValied( newHeaderName ) )
        return false;

    int curHeaderPos = this->headerMap[ curHeaderName ];

    this->header[ curHeaderPos ] = newHeaderName; 
    this->headerMap[ newHeaderName ] = curHeaderPos; // assign curHeader pos to newHeader
    this->headerMap.erase( curHeaderName );   // Erase curHeaderName 

    return true;    
}

bool CSV_Header::erase( const std::string& headerName ) {
    if( !this->isValied( headerName ) ) return false;

    int headerPos = this->headerMap[ headerName ];
    
    this->header.erase( this->header.begin() + headerPos );
    this->headerMap.erase( headerName );

    return true;
}

bool CSV_Header::erase( const int headerPos ) {
    return this->erase( this->header[ headerPos ] );
}

