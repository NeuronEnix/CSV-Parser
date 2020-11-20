#include<bits/stdc++.h>

class CSV_Parser {

private:

    std::unordered_map< std::string , int > header;
    std::vector< std::vector< std::string > > data;

    void setData  ( std::ifstream& );
    void setHeader( std::ifstream& );


public:

    // Constructors
    CSV_Parser() {}


    // Methods
    CSV_Parser& readFromFile( std::string );   

};

CSV_Parser& CSV_Parser::readFromFile( std::string fileName ) {
    std::ifstream fin( fileName );
    std::string line;

    this->header.clear();
    this->data.clear();
    
    return *this;
}

