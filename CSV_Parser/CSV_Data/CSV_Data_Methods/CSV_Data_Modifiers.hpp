#pragma once
#include "../CSV_Data.hpp"

bool CSV_Data::swap( const int firstPos, const int secondPos ) {
    if( !this->isValidPos( firstPos ) or !this->isValidPos( secondPos ) ) return false;
    std::swap( this->virtualColPos[ firstPos ], this->virtualColPos[ secondPos ] );
    return true;
}

bool CSV_Data::moveTo( const int curPos, const int newPos ) {
    int _curPos = curPos;

    if( !this->isValidPos( _curPos ) or !this->isValidPos( newPos ) ) return false;
    
    if( _curPos < newPos ) // 0,1,2,..., curPos,..., newPos  ( move right )    
        while( _curPos != newPos ) this->swap( _curPos, ++_curPos );

    else // 0,1,2,..., newPos,..., curPos  ( move left )    
        while( _curPos != newPos ) this->swap( _curPos, --_curPos );
        
    return true;
}