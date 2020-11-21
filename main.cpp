#include<iostream>
#include "CSV_Parser/CSV_Parser.hpp"

int main() {

    CSV_Parser parser = CSV_Parser();
    parser.readFromFile( "file.csv" );

    std::cout << "Position of Header1: " << parser.getHeaderPos( "Header1" );
        
    return 0;
}