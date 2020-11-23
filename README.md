# CSV-Parser
CSV Parser Using C++

```C++
#include<iostream>
#include "CSV_Parser/CSV_Parser.hpp"

using namespace std;
int main() {

    CSV_Parser parser = CSV_Parser();
    parser.readFromFile( "file.csv" );
    
    vector< string > parsedHeader = parser.getHeader();
    vector< vector< string > > parsedData = parser.getData();

    cout << "Position of Header0: " << parser.headerPos( "Header0" ); // output: 0
    cout << "\nHeader at 1: " << parser.headerAt( 1 ); // output: Header1 

    parser.writeToFile( "new file.csv" );
        
    return 0;
}
```
