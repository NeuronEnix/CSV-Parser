#pragma once
#include<fstream>
#include<unordered_map>
#include<string>

#include "CSV_Decoder.hpp"

class CSV_Header {

private:
    std::vector< std::string > header;
    std::unordered_map< std::string, size_t > headerMap;

protected:
    /* Protected Methods */
    CSV_Header* readFromFile( std::ifstream& fin  );
    CSV_Header* writeToFile ( std::ofstream& fout );

public:
    /* Constructors */
    CSV_Header(){}

    /* Public Methods */

    // Retrieval
    std::vector< std::string >& getHeader();
    std::unordered_map< std::string, size_t >& getHeaderMap();
    
    // Find
    std::string headerAt( size_t pos );
    size_t headerPos( const std::string& headerName );
    
}; // class CSV_Parser


/* Protected Methods */

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


/* Public Methods */

// Retrieval
std::vector< std::string >& CSV_Header::getHeader() { return this->header; }

std::unordered_map< std::string, size_t >& CSV_Header::getHeaderMap() { return this->headerMap; }

// Find
std::string CSV_Header::headerAt( size_t pos ) {
    const size_t min = 0, max = this->header.size();
    if( pos >= min and pos < max ) return this->header[ pos ];
    throw std::out_of_range( "CSV_Header::headerAt( " + std::to_string( pos ) + " ): Available range: min:0, max:" + std::to_string( max ) );
}

size_t CSV_Header::headerPos( const std::string& headerName ) {
    auto foundHeaderIterator = this->headerMap.find( headerName );
    if ( foundHeaderIterator == this->headerMap.end() )
        throw std::out_of_range( "CSV_Header::headerPos( \"" + headerName + "\" ) : No such header name found" );
    return foundHeaderIterator->second;    
}
