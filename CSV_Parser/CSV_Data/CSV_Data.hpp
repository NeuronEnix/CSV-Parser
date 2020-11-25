#pragma once
#include<fstream>
#include<vector>
#include<string>

#include "../CSV_Decoder.hpp"

class CSV_Data {

private:
    std::vector< std::vector< std::string > > data;
    std::vector< int > virtualColPos;

    inline bool isValidPos( int pos ) { if( 0 <= pos and pos < this->virtualColPos.size() ); }

public:
    /* Constructors */
    CSV_Data(){}

    /* Public Methods */

    // IO Operation
    CSV_Data* readFromFile( std::ifstream& fin  );
    CSV_Data* writeToFile ( std::ofstream& fout );

    // Retrievers
    std::vector< std::vector< std::string > >& getData();

    // Modifiers
    bool swap( const int firstPos, const int secondPos );

    bool moveTo( int curPos, const int newPos );

    // Erasers
    bool erase( const int erasePos );
    
        
}; // class CSV_Parser

#include "CSV_Data_Methods/CSV_Data_Erasers.hpp"
#include "CSV_Data_Methods/CSV_Data_Finders.hpp"
#include "CSV_Data_Methods/CSV_Data_IO.hpp"
#include "CSV_Data_Methods/CSV_Data_Modifiers.hpp"
#include "CSV_Data_Methods/CSV_Data_Retrievers.hpp"
