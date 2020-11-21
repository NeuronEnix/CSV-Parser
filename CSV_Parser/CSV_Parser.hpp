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
    
    CSV_Header::readHeaderFromFile( fin );
    CSV_Data::readDataFromFile( fin );

    return this;
}

CSV_Parser* CSV_Parser::writeToFile ( const std::string& fileName ) {

    std::ofstream fout( fileName );

    CSV_Header::writeHeaderToFile( fout );
    CSV_Data::writeDataToFile( fout );

    return this;        
}
