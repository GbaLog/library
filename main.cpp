/////////////////////////////////////////////////////////////////////////////////////////
#include "library.hpp"
/////////////////////////////////////////////////////////////////////////////////////////
void print_books( const Library& lib )
{
    std::cout << "Library: " << std::endl;
    for( const auto& it : lib.get_books() )
    {
        std::cout
            << '\t'
            << it.get_name()
            << "/"
            << it.get_author()
            << std::endl;
    }
    std::cout << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////////
void print_readers( const Library& lib )
{
    std::cout << "Readers:" << std::endl;
    for( const auto& it : lib.get_readers() )
    {
        std::cout
            << '\t'
            << it.get_name()
            << std::endl;
    }
    std::cout << std::endl;
}
/////////////////////////////////////////////////////////////////////////////////////////
void print_what_readers_have( const Library& lib )
{
    for( const auto& it : lib.get_readers() )
    {
        std::cout
            << it.get_name()
            << " have"
            << std::endl;
        for( const auto& it2 : it.get_books() )
        {
            std::cout
                << '\t'
                << it2.get_name()
                << "/"
                << it2.get_author()
                << "\n\n";
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    Library lib{ "books.txt", "readers.txt" };

    print_books( lib );
    print_readers( lib );

    lib.request( "Steve McConnell", e_give, "Code complete" );

    print_books( lib );
    print_what_readers_have( lib );

    lib.request( "Steve McConnell", e_take, "Code complete" );

    print_what_readers_have( lib );
    print_books( lib );
}
/////////////////////////////////////////////////////////////////////////////////////////
