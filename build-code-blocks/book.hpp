/////////////////////////////////////////////////////////////////////////////////////////
#ifndef BOOK_HPP
#define BOOK_HPP
/////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.hpp"
/////////////////////////////////////////////////////////////////////////////////////////
class Book
{
    //-----------------------------------------------------------------------------------
public:
    //-----------------------------------------------------------------------------------
    Book();
    //-----------------------------------------------------------------------------------
    Book( string name_book, string name_author );
    //-----------------------------------------------------------------------------------
    const string& get_name() const;
    //-----------------------------------------------------------------------------------
    const string& get_author() const;
    //-----------------------------------------------------------------------------------
private:
    //-----------------------------------------------------------------------------------
    string name;
    string author;
    //-----------------------------------------------------------------------------------
};
/////////////////////////////////////////////////////////////////////////////////////////
inline bool operator<( const Book& b1, const Book& b2 )
{
    return b1.get_name() < b2.get_name()
        || b1.get_author() < b2.get_author();
}
//---------------------------------------------------------------------------------------
inline bool operator==( const Book& b1, const Book& b2 )
{
    return b1.get_name() == b2.get_name()
        && b1.get_author() == b2.get_author();
}
//---------------------------------------------------------------------------------------
inline bool operator==( const Book& b1, const string& name_book)
{
    return b1.get_name() == name_book;
}
/////////////////////////////////////////////////////////////////////////////////////////
#endif // BOOK_HPP
/////////////////////////////////////////////////////////////////////////////////////////