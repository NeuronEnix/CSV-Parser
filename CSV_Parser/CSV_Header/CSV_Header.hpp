#pragma once

#include<fstream>
#include<unordered_map>
#include<string>

#include "../CSV_Decoder.hpp"

class CSV_Header {

private:
    std::vector< std::string > header;
    
    // < headerName, headerPos > 
    std::unordered_map< std::string, int > headerMap;

    inline bool isValied( const int pos ) const { return 0 <= pos and pos < this->header.size(); }
    inline bool isValied( const std::string& headerName ) const { return this->headerMap.find( headerName ) != this->headerMap.end(); }

public:
    /* Constructors */
    CSV_Header(){}

    /* Public Methods */

    // IO Operation
    CSV_Header* readFromFile( std::ifstream& fin  );
    CSV_Header* writeToFile ( std::ofstream& fout );

    // Retrivers
    std::vector< std::string >& getHeader();
    
    // Finders
    std::string at( int pos );
    int pos( const std::string& headerName );

    // Modifiers
    
    bool swap( const std::string& firstHeaderName, const std::string& secondHeaderName );
    bool swap( const int firstPos, const int secondPos );    

    bool moveTo( const std::string& headerName, const int newPos );

    bool rename( const std::string& curHeaderName, const std::string& newHeaderName );
    
    // Erasers
    
    bool erase( const std::string& headerName );
    bool erase( const int headerPos );
    



}; // class CSV_Parser


#include "CSV_Header_Methods/CSV_Header_Erasers.hpp"
#include "CSV_Header_Methods/CSV_Header_Finders.hpp"
#include "CSV_Header_Methods/CSV_Header_IO.hpp"
#include "CSV_Header_Methods/CSV_Header_Modifiers.hpp"
#include "CSV_Header_Methods/CSV_Header_Retrievers.hpp"
