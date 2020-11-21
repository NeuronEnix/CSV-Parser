#pragma once
#include<fstream>
#include<vector>
#include<string>

#include "CSV_Decoder.hpp"

class CSV_Data {

private:
    std::vector< std::vector< std::string > > data;

protected:
    /* Protected Methods */
    CSV_Data* readFromFile( std::ifstream& fin  );
    CSV_Data* writeToFile ( std::ofstream& fout );

public:
    /* Constructors */
    CSV_Data(){}

    /* Public Methods */

    // Retrieval
    std::vector< std::vector< std::string > >& getData();
        
}; // class CSV_Parser


/* Protected Methods */

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


/* Public Methods */

// Retrieval
std::vector< std::vector< std::string > >& CSV_Data::getData() { return this->data; }
