#pragma once
#include<fstream>
#include<unordered_map>
#include<string>

#include "CSV_Decoder.hpp"

class CSV_Header {

private:
    std::unordered_map< std::string, size_t > header;
    std::vector< std::string > headerVector;


protected:

    // Methods
    CSV_Header* readHeaderFromFile( std::ifstream& fin );
    CSV_Header* writeHeaderToFile( std::ofstream& fout );


public:

    // Constructors
    CSV_Header(){}

    // Public Methods
    std::unordered_map< std::string, size_t >& getHeader();
    std::vector< std::string >& getHeaderVector();
    size_t getHeaderPos( const std::string& headerName );

    
};

// Protected Methods

CSV_Header* CSV_Header::readHeaderFromFile( std::ifstream& fin ) {
    
    this->header.clear();
    this->headerVector.clear();

    std::string line;

    getline( fin, line );
    CSV_Decoder::decodeToVectorOfString( line, this->headerVector );
    
    // insert vector of string to std::unordered_map as < headerName, headerName's Index > so that we can find pos of header easily
    for ( size_t i = 0; i < this->headerVector.size(); i++ ) 
        this->header[ this->headerVector[ i ] ] = i;
                
    return this;
}

CSV_Header* CSV_Header::writeHeaderToFile( std::ofstream& fout ) {
    
    for( const auto& eachHeader: this->headerVector )
        fout << eachHeader << ',';
    fout << std::endl;
                
    return this;
}


// Public Methods

std::unordered_map< std::string, size_t >& CSV_Header::getHeader() {    return this->header;    }
std::vector< std::string >& CSV_Header::getHeaderVector() {    return this->headerVector;    }

size_t CSV_Header::getHeaderPos( const std::string& headerName ) {    return this->header.at( headerName ); }
  