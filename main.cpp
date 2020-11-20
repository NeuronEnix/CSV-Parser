#include "CSV_Decoder.hpp"

int main() {

    std::vector< std::string > ele;
    CSV_Decoder::decodeToVectorOfString( "1,2,3", ele );
    for( auto s: ele )
        std::cout << s << "  ";
    return 0;
}