#include "CSV_Parser/CSV_Parser.hpp"
#include "a.hpp"

int main() {

    CSV_Parser parser = CSV_Parser();
    parser.readFromFile( "file.csv" );

    deb_m( parser.getHeader() );
    deb_vv( parser.getData() );
        
    return 0;
}