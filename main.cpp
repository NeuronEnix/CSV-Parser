#include<iostream>
#include "CSV_Parser/CSV_Parser.hpp"

using namespace std;
int main() {

    CSV_Parser parser = CSV_Parser();
    parser.readFromFile( "file.csv" );

    // Headers : [ "H0", "H1", "H2", "H3" ]

    /* Finders */
    parser.headerAt( 2 ); // returns: "H2"
    parser.headerPos( "H3" ); // returns: 3

    /* Retrievers */
    cout << parser[0][0] << endl; // returns data at row:0, col:0

    parser[0][1] = "New Data";
    parser[1]["H4"] = "Another New Data";

    // Headers : [ "H0", "H1", "H2", "H3" ]

    /* Modifiers */
    parser.swapRow( 1, 5 ); // Data of given two row will be swapped 

    parser.swapCol( "H0", "H1" ); // Headers : [ "H1", "H0", "H2", "H3" ]
    parser.swapCol( 0, 1 ); // Headers : [ "H0", "H1", "H2", "H3" ]

    parser.moveCol( "H0", 2 ); // Headers : [ "H2", "H1", "H0", "H3" ]

    cout << "Position of Header0: " << parser.headerPos( "Header0" ); // output: 0
    cout << "\nHeader at 1: " << parser.headerAt( 1 ); // output: Header1 

    parser.appendCol( "Header3" ); // Adds only header name and the data will have empty string
    parser.appendCol( "Header4", {"1", "2", "3", } ); // Adds headerName , and 2nd argument will be added as data 

    parser.moveCol( "Header3", 0 );

    parser.writeToFile( "new file.csv" );
        
    return 0;
}
