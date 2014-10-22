#include <parser.hpp>

#include <iostream>
#include <vector>
#include <memory>

int main( int argc, char** argv )
{
    int i = 0;
    auto triggered_int = [&i](int i_){ i = i_; };
    auto silent_int = [&i](){ i = -1; };
    auto p1 = make_option<int>( "--index", triggered_int, silent_int );
    
    std::cout << "before parse, i = " << i << "\n";
    auto p = parse( argc, argv, p1 );
    std::cout << "after parse, i = " << i << "\n";

    return 0;
}
