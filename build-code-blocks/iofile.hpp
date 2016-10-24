/////////////////////////////////////////////////////////////////////////////////////////
#ifndef IOFILE_HPP
#define IOFILE_HPP
/////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.hpp"
#include "reader.hpp"
#include "book.hpp"
#include <fstream>
#include <stdexcept>
/////////////////////////////////////////////////////////////////////////////////////////
class IOfile
{
    //-----------------------------------------------------------------------------------
public:
    //-----------------------------------------------------------------------------------
    IOfile() = delete;
    ~IOfile() = delete;
    //-----------------------------------------------------------------------------------
    static void load_readers( std::vector< Reader >& readers, const string& name_file )
    {
        std::ifstream f_in( name_file );

        if( !f_in.is_open() )
        {
            throw std::runtime_error( "Can't open file: " + name_file );
        }

        string reader;
        while( std::getline( f_in, reader ) )
        {
            readers.emplace_back( Reader{ reader } );
        }
    }
    //-----------------------------------------------------------------------------------
    static void load_books( set< Book >& books, const string& name_file )
    {
        std::ifstream f_in( name_file );

        if( !f_in.is_open() )
        {
            throw std::runtime_error( "Can't open file: " + name_file );
        }

        string name;
        string author;
        while( !f_in.eof() )
        {
            std::getline( f_in, name );

            if( f_in.eof() )
            {
                throw std::runtime_error( "File eof after, than read all books" );
            }

            std::getline( f_in, author );

            books.emplace( Book{ name, author } );
        }
    }
    //-----------------------------------------------------------------------------------
};
/////////////////////////////////////////////////////////////////////////////////////////
#endif // IOFILE_HPP
/////////////////////////////////////////////////////////////////////////////////////////
