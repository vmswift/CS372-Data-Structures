//Throttle Class Header
//throttle.h
//CS372 Fall 2014
//By John Knowles jknowle2@my.athens.edu
//Date 8/25/2014
//
//This is a clone of the file in the textbook
//I combined the cpp and header file into the header
#include <cassert>
#include <iostream>

using namespace std;

    class throttle
    {
    public:
        // CONSTRUCTORS
        throttle( );
        throttle(int size);
        // MODIFICATION MEMBER FUNCTIONS
        void shut_off( ) { position = 0; }
        void shift(int amount);
        // CONSTANT MEMBER FUNCTIONS
        double flow( ) const { return position / double(top_position); } 
        bool is_on( ) const { return (position > 0); }
    private:
        int top_position;
        int position;
    };

	throttle::throttle( )
    {   // A simple on-off throttle
        top_position = 1;
        position = 0;
    }
    
    throttle::throttle(int size)
    // Library facilities used: cassert
    {
        assert(size > 0);
        top_position = size;
        position = 0;
    }
    
    void throttle::shift(int amount)
    {
	position += amount;

	if (position < 0)
	    position = 0;
	else if (position > top_position)
	    position = top_position;
    }



