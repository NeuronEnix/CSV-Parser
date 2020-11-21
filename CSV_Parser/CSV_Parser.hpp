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

}; // class CSV_Parser


/* Public Methods */

CSV_Parser* CSV_Parser::readFromFile( const std::string& fileName ) {
    std::ifstream fin( fileName );
    
    CSV_Header::readFromFile( fin );
    CSV_Data::readFromFile( fin );

    return this;
}

CSV_Parser* CSV_Parser::writeToFile ( const std::string& fileName ) {

    std::ofstream fout( fileName );

    CSV_Header::writeToFile( fout );
    CSV_Data::writeToFile( fout );

    return this;        
}
