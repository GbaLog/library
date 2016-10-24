/////////////////////////////////////////////////////////////////////////////////////////
#include "library.hpp"
/////////////////////////////////////////////////////////////////////////////////////////
void print_books( const Library& lib )
{
    std::cout
        << std::endl
        << "Library: "
        << std::endl;
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
        const auto& books = it.get_books();
        if( books.size() == 0 )
        {
            std::cout
                << it.get_name()
                << " haven\'t books"
                << std::endl;
            continue;
        }

        std::cout
            << it.get_name()
            << " have"
            << std::endl;

        for( const auto& it2 : books )
        {
            std::cout
                << '\t'
                << it2.get_name()
                << "/"
                << it2.get_author()
                << std::endl;
        }
    }
    std::cout << std::endl;
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
