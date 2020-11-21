#pragma once
#include<string>

#include "CSV_Data.hpp"
#include "CSV_Header.hpp"

class CSV_Parser : public CSV_Header, public CSV_Data  {

private:

public:

    // Constructors
    CSV_Parser() {}


    // Methods
    CSV_Parser* readFromFile( std::string );   

};

// Public Methods
CSV_Parser* CSV_Parser::readFromFile( std::string fileName ) {
    std::ifstream fin( fileName );
    
    CSV_Header::setHeader( fin );
    CSV_Data::setData( fin );

    return this;
}
