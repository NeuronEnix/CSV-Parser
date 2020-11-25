#pragma once
#include "../CSV_Data.hpp"

bool CSV_Data::erase( const int erasePos ) {
    if( !this->isValidPos( erasePos ) ) return false;

    // Move the pos to be erased to the end
    this->moveTo( erasePos, this->virtualColPos.size() -1 ); 

    // Make the pos to be erased as -1 in "this->virtualColPos"
    this->virtualColPos[ this->virtualColPos.size() - 1 ] = -1; 

    return false;
}