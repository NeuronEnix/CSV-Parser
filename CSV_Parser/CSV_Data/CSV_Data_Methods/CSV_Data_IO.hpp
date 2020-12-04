#pragma once
#include<iostream>
#include "../CSV_Data.hpp"
#include "../../CSV_Decoder.hpp"

CSV_Data* CSV_Data::readFromFile( std::ifstream& fin ) {
    
    this->data.clear();
    std::string line;

    std::vector< std::string > eachRowData;

    for( int index = 0; getline( fin, line ); ++index ) {
        eachRowData.clear();
        CSV_Decoder::decodeToVectorOfString( line, eachRowData );
        this->data.push_back( eachRowData );     
    }
    
    // Setting virtualColPos as [0,1,2,3,..., n ] 
    this->virtualColPos.resize( this->data[0].size() );
    for (size_t i = 0; i < this->data.size(); i++)
        this->virtualColPos[ i ] = i;    

}

CSV_Data* CSV_Data::writeToFile( std::ofstream& fout ) {
    for( const auto& eachLine : this->data ) {
        for( const int& ind: this->virtualColPos ) 
            fout << eachLine[ ind ] << ",";
        fout << std::endl;
    }
                
    return this;
}