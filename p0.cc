#include <parser.hpp>

#include <iostream>

int main( int argc, char** argv )
{
    auto triggered_void = [](){ std::cout << "option -r triggered.\n"; };
    auto silent_void = [](){ std::cout << "option -r silent.\n"; };
    auto p0 = make_option<void>( "-r", triggered_void, silent_void );

    parse( argc, argv, p0 );

    return 0;
}

