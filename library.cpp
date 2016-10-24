/////////////////////////////////////////////////////////////////////////////////////////
#include "library.hpp"
#include "iofile.hpp"
/////////////////////////////////////////////////////////////////////////////////////////
#define find( cont, expr ) std::find( cont.begin(), cont.end(), expr )
/////////////////////////////////////////////////////////////////////////////////////////
Library::Library( const string& name_file_books, const string& name_file_readers )
{
    IOfile::load_books( BD.get_books_ref(), name_file_books );
    IOfile::load_readers( readers, name_file_readers );
}
/////////////////////////////////////////////////////////////////////////////////////////
void Library::request( const string& name_reader, e_act act, string name_book )
{
    auto reader = find( readers, name_reader );

    if( reader != readers.end() )
    {
        request( *reader, act, name_book );
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
void Library::request( Reader& reader, e_act act, string name_book )
{
    switch( act )
    {
        case e_give:
            {
                if( name_book.size() == 0 )
                {
                    return;
                }
                if( BD.contain( name_book ) && is_registered( reader ) )
                {
                    reader.add_book( BD.get_book( name_book ) );
                }
            }
            break;
        case e_take:
            {
                if( name_book.size() == 0 )
                {
                    return;
                }
                BD.add_book( reader.get_book( name_book ) );
            }
            break;
        default:
            break;
    };
}
/////////////////////////////////////////////////////////////////////////////////////////
void Library::request( const Reader& reader, e_act act )
{
    switch( act )
    {
        case e_register:
            readers.emplace_back( reader );
            break;
        default:
            break;
    };
}
/////////////////////////////////////////////////////////////////////////////////////////
const set< Book >& Library::get_books() const
{
    return BD.get_books_cref();
}
/////////////////////////////////////////////////////////////////////////////////////////
const std::vector< Reader >& Library::get_readers() const
{
    return readers;
}
/////////////////////////////////////////////////////////////////////////////////////////
const Reader& Library::get_reader( const string& name_reader ) const
{
    auto ret = find( readers, name_reader );

    if( ret == readers.end() )
    {
        std::cout
            << "Reader "
            << name_reader
            << " not found!"
            << std::endl;
        return *readers.begin();
    }

    return *ret;
}
/////////////////////////////////////////////////////////////////////////////////////////
void Library::add_book( const string& name_book, const string name_author )
{
    BD.add_book( { name_book, name_author } );
}
/////////////////////////////////////////////////////////////////////////////////////////
void Library::add_book( const Book& book )
{
    BD.add_book( book );
}
/////////////////////////////////////////////////////////////////////////////////////////
void Library::remove_book( const string& name_book )
{
    auto ref = BD.get_books_ref();
    ref.erase( find( ref, name_book ) );
}
/////////////////////////////////////////////////////////////////////////////////////////
bool Library::is_registered( const Reader& reader )
{
    return std::find_if(
                            readers.begin(),
                            readers.end(),
                            [&reader]
                            ( const Reader& rhs )
                            {
                                return rhs == reader;
                            }
                       )
        != readers.end();
}
/////////////////////////////////////////////////////////////////////////////////////////
