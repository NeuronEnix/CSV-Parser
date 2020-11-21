#pragma once
#include<fstream>
#include<unordered_map>
#include<string>

#include "CSV_Decoder.hpp"

class CSV_Header {

private:
    std::unordered_map< std::string, size_t > header;


protected:

    // Methods
    CSV_Header* setHeader( std::ifstream& fin );


public:

    // Constructors
    CSV_Header(){}

    // Public Methods
    std::unordered_map< std::string, size_t >& getHeader();
    size_t getHeaderPos( const std::string& headerName );

    
};

// Protected Methods

CSV_Header* CSV_Header::setHeader( std::ifstream& fin ) {
    
    this->header.clear();

    std::string line;
    std::vector< std::string > headerName;

    getline( fin, line );
    CSV_Decoder::decodeToVectorOfString( line, headerName );
    
    // insert vector of string to std::map as < headerName, headerName's Index > so that we can find pos of header easily
    for ( size_t i = 0; i < headerName.size(); i++ )
        this->header[ headerName[ i ] ] = i;
            
    return this;
}


// Public Methods

std::unordered_map< std::string, size_t >& CSV_Header::getHeader() {    return this->header;    }

size_t CSV_Header::getHeaderPos( const std::string& headerName ) {    return this->header.at( headerName ); }



  