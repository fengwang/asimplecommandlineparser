#include <parser.hpp>

#include <iostream>
#include <vector>

int main( int argc, char** argv )
{
    auto triggered_void = [](){ std::cout << "option -r triggered.\n"; };
    auto silent_void = [](){ std::cout << "option -r silent.\n"; };
    auto p0 = make_option<void>( "-r", triggered_void, silent_void );

    int i;
    auto triggered_int = [&i](int i_){ i = i_; };
    auto silent_int = [&i](){ i = -1; };
    auto p1 = make_option<int>( "--index", triggered_int, silent_int );

    double vx[3] = {8,8,8};

    auto triggered_vector = [&vx](double* x){ std::copy( x, x+3, vx ); };
    auto silent_vector = [&vx](){ std::fill( vx, vx+3, -1.0 ); };
    auto p2 = make_option<double,3>( "-vx", ',', triggered_vector, silent_vector );

    auto p = parse( argc, argv, p0, p1, p2 );

    std::cout << "\nafter parsing commandline \n";
    for ( int index = 0; index != argc; ++ index )
        std::cout << argv[index] << "\n";
    std::cout << "\n";

    std::cout << "i = " << i << "\n";
    std::cout << "vx = \n";
    for ( unsigned r = 0; r != 3; ++r )
        std::cout << vx[r] << "\n";
    std::cout << "\n";

    return 0;
}

