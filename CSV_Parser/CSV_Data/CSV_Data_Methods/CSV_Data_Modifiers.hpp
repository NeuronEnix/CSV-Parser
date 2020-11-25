#pragma once
#include "../CSV_Data.hpp"

bool CSV_Data::swap( const int firstPos, const int secondPos ) {
    if( !this->isValidPos( firstPos ) or !this->isValidPos( secondPos ) ) return false;
    std::swap( this->virtualColPos[ firstPos ], this->virtualColPos[ secondPos ] );
    return true;
}

bool CSV_Data::moveTo( int curPos, const int newPos ) {
    if( !this->isValidPos( curPos ) or !this->isValidPos( newPos ) ) return false;
    
    if( curPos < newPos ) // 0,1,2,..., curPos,..., newPos  ( move right )    
        while( curPos != newPos ) this->swap( curPos, ++curPos );

    else // 0,1,2,..., newPos,..., curPos  ( move left )    
        while( curPos != newPos ) this->swap( curPos, --curPos );
        
    return true;
}