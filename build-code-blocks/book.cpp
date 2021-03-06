/////////////////////////////////////////////////////////////////////////////////////////
#include "book.hpp"
/////////////////////////////////////////////////////////////////////////////////////////
Book::Book()
    :
    name( "" ),
    author( "" )
{}
/////////////////////////////////////////////////////////////////////////////////////////
Book::Book( string name_book, string name_author )
    :
    name( name_book ),
    author( name_author )
{}
/////////////////////////////////////////////////////////////////////////////////////////
const string& Book::get_name() const
{
    return name;
}
/////////////////////////////////////////////////////////////////////////////////////////
const string& Book::get_author() const
{
    return author;
}
/////////////////////////////////////////////////////////////////////////////////////////
