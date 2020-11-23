#pragma once
#include "../CSV_Header.hpp"
#include "../../CSV_Decoder.hpp"

CSV_Header* CSV_Header::readFromFile( std::ifstream& fin ) {
    
    this->header.clear();
    this->headerMap.clear();

    std::string line;

    getline( fin, line );
    CSV_Decoder::decodeToVectorOfString( line, this->header );
    
    // insert vector of string to std::u_map as < headerName, headerName's Pos > so that we can find pos of header quickly
    for ( size_t i = 0; i < this->header.size(); i++ ) 
        this->headerMap[ this->header[ i ] ] = i;
                
    return this;
}

CSV_Header* CSV_Header::writeToFile( std::ofstream& fout ) {
    
    for( const auto& eachHeader: this->header )
        fout << eachHeader << ',';
    fout << std::endl;
                
    return this;
}