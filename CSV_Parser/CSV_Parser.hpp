#include<fstream>

#include "CSV_Header/CSV_Header.hpp"
#include "CSV_Data/CSV_Data.hpp"

class CSV_Parser {

private:
    CSV_Header *header;
    CSV_Data *data;

public:
    /* Constructors */
    CSV_Parser() : header( new CSV_Header() ), data( new CSV_Data() ) {}

    /* Public Methods */

    // IO Operation
    CSV_Parser* readFromFile( const std::string& fileName );
    CSV_Parser* writeToFile ( const std::string& fileName );

    // Retrievers
    std::vector< std::string >& getHeader();
    std::vector< std::vector< std::string > >& getData();

    // Finders
    std::string headerAt( const int pos );
    int headerPos( const std::string& headerName );

    // Modifiers
    bool swapHeader( const string& firstHeader, const string& secondHeader );
    bool swapHeader( const int firstHeader, const int secondHeader );  

}; // class CSV_Parser


// IO Operation

CSV_Parser* CSV_Parser::readFromFile( const std::string& fileName ) {
    std::ifstream fin( fileName );
    
    this->header->readFromFile( fin );
    this->data->readFromFile( fin );

    return this;
}

CSV_Parser* CSV_Parser::writeToFile ( const std::string& fileName ) {

    std::ofstream fout( fileName );

    this->header->writeToFile( fout );
    this->data->writeToFile( fout );
    
    return this;        
}


// Retrievers

std::vector< std::string >& CSV_Parser::getHeader() { return this->header->getHeader(); }

std::vector< std::vector< std::string > >& CSV_Parser::getData() { return this->data->getData(); } 


// Finders

std::string CSV_Parser::headerAt( const int pos ) { return this->header->at( pos ); }

int CSV_Parser::headerPos( const std::string& headerName ) { return this->header->pos( headerName ); }


// Modifiers