#include<fstream>
#include<string>
#include<vector>

#include "CSV_Decoder.hpp"

class CSV_Data {

private:
    std::vector< std::vector< std::string > > data;


protected:

    // Methods
    CSV_Data* setData( std::ifstream& fin );


public:

    // Constructors
    CSV_Data(){}

    std::vector< std::vector< std::string > >& getData();
    
};

// Protected Methods

CSV_Data* CSV_Data::setData( std::ifstream& fin ) {

    this->data.clear();
    std::string line;

    std::vector< std::string > eachRowData;

    while( getline( fin, line ) ) {
        eachRowData.clear();
        CSV_Decoder::decodeToVectorOfString( line, eachRowData );
        this->data.push_back( eachRowData );
    }
    
}


// Public Methods

std::vector< std::vector< std::string > >& CSV_Data::getData() {
    return this->data;
}
    