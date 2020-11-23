#pragma once
#include<fstream>
#include<vector>
#include<string>

#include "../CSV_Decoder.hpp"

class CSV_Data {

private:
    std::vector< std::vector< std::string > > data;

public:
    /* Constructors */
    CSV_Data(){}

    /* Public Methods */

    // IO Operation
    CSV_Data* readFromFile( std::ifstream& fin  );
    CSV_Data* writeToFile ( std::ofstream& fout );

    // Retrievers
    std::vector< std::vector< std::string > >& getData();

        
}; // class CSV_Parser

#include "CSV_Data_Methods/CSV_Data_Deleters.hpp"
#include "CSV_Data_Methods/CSV_Data_Finders.hpp"
#include "CSV_Data_Methods/CSV_Data_IO.hpp"
#include "CSV_Data_Methods/CSV_Data_Modifiers.hpp"
#include "CSV_Data_Methods/CSV_Data_Retrievers.hpp"
