#pragma once
#include "../CSV_Data.hpp"

bool CSV_Data::swapCol( const int firstColPos, const int secondColPos ) {
    if( !this->isValidColPos( firstColPos ) or !this->isValidColPos( secondColPos ) ) return false;
    std::swap( this->virtualColPos[ firstColPos ], this->virtualColPos[ secondColPos ] );
    return true;
}

bool CSV_Data::swapRow( const int firstRowPos, const int secondRowPos ) {
    if( !this->isValidRowPos( firstRowPos ) and !this->isValidRowPos( secondRowPos ) ) return false;

    std::swap( this->data[firstRowPos], this->data[secondRowPos] );
}


bool CSV_Data::moveTo( int curPos, const int newPos ) {
    if( !this->isValidColPos( curPos ) or !this->isValidColPos( newPos ) ) return false;
    
    // 0,1,2,..., curPos,..., newPos  ( move right )    
    while( curPos < newPos ) this->swapCol( curPos++, curPos+1 );
    // 0,1,2,..., newPos,..., curPos  ( move left )    
    while( curPos > newPos ) this->swapCol( curPos--, curPos-1 );
        
    return true;
}