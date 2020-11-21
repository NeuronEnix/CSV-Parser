#include "CSV_Parser.hpp"

int main() {

    CSV_Parser parser = CSV_Parser();
    parser.readFromFile( "file.csv" );
        
    return 0;
}