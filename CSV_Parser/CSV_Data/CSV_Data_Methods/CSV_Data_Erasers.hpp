#pragma once
#include "../CSV_Data.hpp"

bool CSV_Data::eraseCol( const int colPos ) {
    if( !this->isValidColPos( colPos ) ) return false;

    // Move the pos to be erased to the end
    this->moveTo( colPos, this->virtualColPos.size() -1 ); 

    // Make the pos to be erased as -1 in "this->virtualColPos"
    this->virtualColPos[ this->virtualColPos.size() - 1 ] = -1; 

    return false;
}

bool CSV_Data::eraseRow( const int rowPos ) {
    if( !this->isValidRowPos( rowPos) ) return false;
    
    this->data.erase( this->data.begin() + rowPos );
    return true;
}