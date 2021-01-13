#include<fstream>

#include "CSV_Header/CSV_Header.hpp"
#include "CSV_Data/CSV_Data.hpp"

class BracketHelper {
private:
    CSV_Header *header;
    CSV_Data *data;
    size_t rowPos;
public:
    BracketHelper( CSV_Header *header, CSV_Data *data ):
    header(header),    data(data) 
    {}
    void setRowPos( const size_t rowPos ) { this->rowPos = rowPos; } 
    std::string& operator [] ( const int& colPos ) {
        return this->data->at( this->rowPos, colPos );
    }

    std::string& operator [] ( const std::string& colHeader ) {
        return this->data->at( this->rowPos, this->header->pos( colHeader ) );
    }
    
};

class CSV_Parser {

private:
    CSV_Header *header;
    CSV_Data *data;
    BracketHelper bracketHelper;

public:
    /* Constructors */
    CSV_Parser() : header( new CSV_Header() ), data( new CSV_Data() ), bracketHelper( header, data ) {}

    /* Public Methods */

    // IO Operation
    CSV_Parser* readFromFile( const std::string& fileName );
    CSV_Parser* writeToFile ( const std::string& fileName );

    // Retrievers
    BracketHelper& operator [] ( const size_t rowPos );

    // Finders
    std::string headerAt( const int pos );
    int headerPos( const std::string& headerName );

    // Modifiers
    bool swapCol( const int firstHeaderPos, const int secondHeaderPos );  
    bool swapCol( const std::string& firstHeaderName, const std::string& secondHeaderName );

    bool swapRow( const int firstRowPos, const int secondRowPos );  

    bool moveCol( const std::string& headerName, const int newPos );
    bool renameHeader( const std::string& curHeaderName, const std::string& newHeaderName );

    bool sync();

    // Erasers
    bool eraseCol( const std::string& headerName );
    bool eraseCol( const int colPos );
    bool eraseRow( const int rowPos );

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
BracketHelper& CSV_Parser::operator [] ( const size_t rowPos ) {
    this->bracketHelper.setRowPos( rowPos );
    return this->bracketHelper;
}

// Finders

std::string CSV_Parser::headerAt( const int pos ) { return this->header->at( pos ); }

int CSV_Parser::headerPos( const std::string& headerName ) { return this->header->pos( headerName ); }


// Modifiers

bool CSV_Parser::swapCol( const int firstHeaderPos, const int secondHeaderPos ) {
    return this->header->swap( firstHeaderPos, secondHeaderPos ) and this->data->swapCol( firstHeaderPos, secondHeaderPos );
}

bool CSV_Parser::swapCol( const std::string& firstHeaderName, const std::string& secondHeaderName ){
    int firstHeaderPos = this->header->pos( firstHeaderName );
    int secondHeaderPos = this->header->pos( secondHeaderName );
    return this->swapCol( firstHeaderPos, secondHeaderPos );
}

bool CSV_Parser::swapRow( const int firstRowPos, const int secondRowPos ) {
    return this->data->swapRow( firstRowPos, secondRowPos );
}

bool CSV_Parser::moveCol( const std::string& headerName, const int newPos ) {
    const int headerPos = this->header->pos( headerName );
    return this->header->moveTo( headerName, newPos ) and this->data->moveTo( headerPos, newPos );
}

bool CSV_Parser::renameHeader( const std::string& curHeaderName, const std::string& newHeaderName ) {
    return this->header->rename( curHeaderName, newHeaderName );
}


// Erasers
bool CSV_Parser::eraseCol( const std::string& headerName ) {
    return this->eraseCol( this->header->pos( headerName ) );
}
bool CSV_Parser::eraseCol( const int colPos ) {
    return this->header->erase( colPos ) and this->data->eraseCol( colPos );
}
bool CSV_Parser::eraseRow( const int rowPos ) {
    return this->data->eraseRow( rowPos );
}
