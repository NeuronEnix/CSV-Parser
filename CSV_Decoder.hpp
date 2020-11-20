#include<bits/stdc++.h>

namespace CSV_Decoder
{
    void decodeToVectorOfString( const std::string& line, std::vector< std::string >& elements  ) {
        
        bool enclosedWithDoubleQuotes = false; 

        size_t newElePos = 0;

        for( int i = 0; i<line.size(); ++i ) {
            
            if( line[i] == ',' ) {
                elements.push_back( line.substr( newElePos, i-newElePos ) );
                newElePos = i+1;
            }
                
        }        
        
        // If last element is still remaining then add it to "elements"
        if( newElePos != line.size() ) elements.push_back( line.substr( newElePos ) ) ;

    }
} // namespace CSV_Decoder
