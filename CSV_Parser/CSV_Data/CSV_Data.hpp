#pragma once
#include<fstream>
#include<vector>
#include<string>

#include "../CSV_Decoder.hpp"

class CSV_Data {

private:
    std::vector< std::vector< std::string > > data;
    std::vector< int > virtualColPos;

    inline bool isValidColPos( int pos ) { return 0 <= pos and pos < this->virtualColPos.size(); }
    inline bool isValidRowPos( int pos ) { return 0 <= pos and pos < this->data.size();  }

public:
    /* Constructors */
    CSV_Data(){}

    /* Public Methods */

    // IO Operation
    CSV_Data* readFromFile( std::ifstream& fin  );
    CSV_Data* writeToFile ( std::ofstream& fout );

    // Retrievers
    std::string& at( const size_t rowPos, const size_t colPos );

    // Modifiers
    bool appendCol( const std::vector<std::string>& colData );
    
    bool swapCol( const int firstColPos, const int secondColPos );
    bool swapRow( const int firstRowPos, const int secondRowPos );

    bool moveTo( int curPos, const int newPos );

    // Erasers
    bool eraseCol( const int colPos );
    bool eraseRow( const int rowPos );
    
        
}; // class CSV_Parser

#include "CSV_Data_Methods/CSV_Data_Erasers.hpp"
#include "CSV_Data_Methods/CSV_Data_Finders.hpp"
#include "CSV_Data_Methods/CSV_Data_IO.hpp"
#include "CSV_Data_Methods/CSV_Data_Modifiers.hpp"
#include "CSV_Data_Methods/CSV_Data_Retrievers.hpp"
