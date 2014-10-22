#include <parser.hpp>

#include <iostream>
#include <vector>

int main( int argc, char** argv )
{
    double vx[3] = {8,8,8};

    std::cout << "\nbefore parsing commandline \n vx = \n";
    for ( int index = 0; index != 3; ++ index )
        std::cout << vx[index] << "\n";

    auto triggered_vector = [&vx](double* x){ std::copy( x, x+3, vx ); };
    auto silent_vector = [&vx](){ std::fill( vx, vx+3, -1.0 ); };
    auto p3 = make_option<double,3>( "-vx", ',', triggered_vector, silent_vector );

    auto p = parse( argc, argv, p3 );

    std::cout << "\nafter parsing commandline \n vx = \n";
    for ( int index = 0; index != 3; ++ index )
        std::cout << vx[index] << "\n";

    return 0;
}

