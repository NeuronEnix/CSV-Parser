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
    std::string headerAt( int pos );
    int headerPos( const std::string& headerName );

    // Modifiers
    bool swapHeader( const std::string& firstHeaderName, const std::string& secondHeaderName );
    bool swapHeader( const int firstPos, const int secondPos );    

}; // class CSV_Parser


#include "CSV_Header_Methods/CSV_Header_Deleters.hpp"
#include "CSV_Header_Methods/CSV_Header_Finders.hpp"
#include "CSV_Header_Methods/CSV_Header_IO.hpp"
#include "CSV_Header_Methods/CSV_Header_Modifiers.hpp"
#include "CSV_Header_Methods/CSV_Header_Retrievers.hpp"
