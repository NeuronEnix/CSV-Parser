#include<bits/stdc++.h>

#include "CSV_Decoder.hpp"

class CSV_Parser {

private:

    std::unordered_map< std::string , int > header;
    std::vector< std::vector< std::string > > data;

    CSV_Parser* setData  ( std::ifstream& );
    CSV_Parser* setHeader( std::ifstream& );


public:

    // Constructors
    CSV_Parser() {}


    // Methods
    CSV_Parser* readFromFile( std::string );   

};

// Private Methods
CSV_Parser* CSV_Parser::setData( std::ifstream& fin ) {

    this->data.clear();
    std::string line;

    std::vector< std::string > eachRowData;

    while( getline( fin, line ) ) {
        eachRowData.clear();
        CSV_Decoder::decodeToVectorOfString( line, eachRowData );
        this->data.push_back( eachRowData );
    }
    
}


CSV_Parser* CSV_Parser::setHeader( std::ifstream& fin ) {

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
CSV_Parser* CSV_Parser::readFromFile( std::string fileName ) {
    std::ifstream fin( fileName );
    std::string line;    
    
    this->setHeader( fin );
    this->setData( fin );

    return this;
}

