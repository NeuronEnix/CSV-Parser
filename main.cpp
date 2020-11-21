#include<iostream>
#include "CSV_Parser/CSV_Parser.hpp"

int main() {

    CSV_Parser parser = CSV_Parser();
    parser.readFromFile( "file.csv" );

    std::cout << "Position of Header1: " << parser.headerPos( "Header1" );
    std::cout << "Header at 10: " << parser.headerAt( 1 );

    parser.writeToFile( "new file.csv" );
        
    return 0;
}
