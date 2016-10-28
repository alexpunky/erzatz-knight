#define BOOST_TEST_MODULE erzatzTest
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( erzatzTest )
{
    //my_class test_object( "qwerty" );

    BOOST_CHECK( true );
	BOOST_CHECK( 1 == 1 );
	BOOST_CHECK( 0 == 1 );
	BOOST_CHECK( 1 == 1 );
	BOOST_CHECK( 2 == 1 );
}