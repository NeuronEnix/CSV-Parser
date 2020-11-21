#pragma once
#include<string>

#include "CSV_Data.hpp"
#include "CSV_Header.hpp"

class CSV_Parser : public CSV_Header, public CSV_Data  {

public:

    // Constructors
    CSV_Parser() {}


    // Methods
    CSV_Parser* readFromFile( const std::string& fileName );
    CSV_Parser* writeToFile ( const std::string& fileName );

};

// Public Methods
CSV_Parser* CSV_Parser::readFromFile( const std::string& fileName ) {
    std::ifstream fin( fileName );
    
    CSV_Header::setHeader( fin );
    CSV_Data::setData( fin );

    return this;
}

CSV_Parser* CSV_Parser::writeToFile ( const std::string& fileName ) {
    std::ofstream fout( fileName );

    // Write Headers
    for( const auto& eachHeader: this->getHeader() )
        fout << eachHeader.first << ',';
    
    fout << std::endl; 

    // Write Data
    for( const auto& eachLine : this->getData() ){
        for( const auto& eachEle : eachLine )
            fout << eachEle << ',';
        fout << std::endl;
    }
        
}
