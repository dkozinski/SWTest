#include <iostream>
#include <bitset>
#include <string>
#include <climits>

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

#include <string>
#include <sstream>

const std::string whiteSpaces( " \f\n\r\t\v" );


void trimRight( std::string& str,
      const std::string& trimChars = whiteSpaces )
{
   std::string::size_type pos = str.find_last_not_of( trimChars );
   str.erase( pos + 1 );    
}


void trimLeft( std::string& str,
      const std::string& trimChars = whiteSpaces )
{
   std::string::size_type pos = str.find_first_not_of( trimChars );
   str.erase( 0, pos );
}


void trim( std::string& str, const std::string& trimChars = whiteSpaces )
{
   trimRight( str, trimChars );
   trimLeft( str, trimChars );
}

int main(int argc, char **argv) {
    std::cout << "Hello, world!" << std::endl;
    
    std::bitset<8> bs1;
    bs1 = 7;
    
    std::cout<<bs1<<std::endl;
    
        // empty constructor
    std::bitset<8> b1; // [0,0,0,0,0,0,0,0]
 
    // unsigned long long constructor
    std::bitset<8> b2(42);          // [0,0,1,0,1,0,1,0]
    std::bitset<70> bl(ULLONG_MAX); // [0,0,0,0,0,0,1,1,1,...,1,1,1]
    std::bitset<8> bs(0xfff0);      // [1,1,1,1,0,0,0,0]
 
    // string constructor
    std::string bit_string = "110010";
    std::bitset<8> b3(bit_string);       // [0,0,1,1,0,0,1,0]
    std::bitset<8> b4(bit_string, 2);    // [0,0,0,0,0,0,1,0]
    std::bitset<8> b5(bit_string, 2, 3); // [0,0,0,0,0,0,0,1]
 
    // string constructor using custom zero/one digits
    std::string alpha_bit_string = "aBaaBBaB";
    std::bitset<8> b6(alpha_bit_string, 0, alpha_bit_string.size(),
                      'a', 'B');         // [0,1,0,0,1,1,0,1]
  
    std::cout << b1 << '\n' << b2 << '\n' << bl << '\n' << bs << '\n'
              << b3 << '\n' << b4 << '\n' << b5 << '\n' << b6 << '\n';

    std::string mystring =
    bs1.to_string<char,std::string::traits_type,std::string::allocator_type>();

    std::cout << "mystring: " << mystring << '\n';
    
    std::string c = "0";
    trimLeft(mystring,"0");
    std::cout << "mystring: " << mystring << '\n';
    
    std::bitset<4> mybits;     // mybits: 0000
    mybits.set();              // mybits: 1111

    std::string mystring2 =
        mybits.to_string<char,std::string::traits_type,std::string::allocator_type>();

    ulong val = mybits.to_ulong(); 
    std::cout << "mystring: " << mystring2 << '\n';
    std::cout << "VAL: " << val << '\n';
    
    std::stringstream res;
    res << std::hex << std::uppercase <<val;
    std::cout << "HEX: " << res.str() << '\n';
   
    return 0;
}
