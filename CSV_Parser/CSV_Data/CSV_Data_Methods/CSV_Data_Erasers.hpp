#pragma once
#include "../CSV_Data.hpp"

bool CSV_Data::eraseCol( const int colPos ) {
    if( !this->isValidColPos( colPos ) ) return false;

    this->virtualColPos.erase( this->virtualColPos.begin() + colPos );

    return true;
}

bool CSV_Data::eraseRow( const int rowPos ) {
    if( !this->isValidRowPos( rowPos) ) return false;
    
    this->data.erase( this->data.begin() + rowPos );
    return true;
}