#pragma once
#include "../CSV_Data.hpp"
#include "../../CSV_Decoder.hpp"

CSV_Data* CSV_Data::readFromFile( std::ifstream& fin ) {
    
    this->data.clear();
    std::string line;

    std::vector< std::string > eachRowData;

    while( getline( fin, line ) ) {
        eachRowData.clear();
        CSV_Decoder::decodeToVectorOfString( line, eachRowData );
        this->data.push_back( eachRowData );
    }
}

CSV_Data* CSV_Data::writeToFile( std::ofstream& fout ) {
    
    for( const auto& eachLine : this->data ){
        for( const auto& eachEle : eachLine )
            fout << eachEle << ',';
        fout << std::endl;
    }
                
    return this;
}