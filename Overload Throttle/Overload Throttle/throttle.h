//Throttle Overload Class Header
//throttle.h
//CS372 Fall 2014
//By John Knowles jknowle2@my.athens.edu
//Date 9/8/2014
//
//This is a partial clone of the file in the textbook
//I combined the cpp and header file into the header
#include <cassert>
#include <iostream>

    class throttle
    {
	public:
        throttle( );
        throttle(int size);
		throttle(int size, int pos);
		throttle(throttle & one);

        void shut_off( ) { position = 0; };
        void shift(int amount);

		bool operator==(throttle& t1); //overload ==
		bool operator!=(throttle& t1); //overload !=

        double flow( ) const { return position / double(top_position); } ;
        bool is_on( ) const { return (position > 0); };
		int getPos();
		int getTop();
		friend  std::ostream& operator<<(std::ostream& outs,throttle& t1); //overload cout
    private:
        int top_position;
        int position;
    };


	throttle::throttle( )
    {   // A simple on-off throttle
        top_position = 6;
        position = 0;
    }

    throttle::throttle(int size)
    // Library facilities used: cassert
    {
        assert(size > 0);
        top_position = size;
        position = 0;
    }

	 throttle::throttle(int size,int pos)
    // Library facilities used: cassert
    {
        assert(size > 0);
        top_position = size;
        position = pos;
    }

	 throttle::throttle(throttle &one)
	 {
		 top_position=one.top_position;
		 position=one.position;
	 }

    void throttle::shift(int amount)
    {
	position += amount;

	if (position < 0)
	    position = 0;
	else if (position > top_position)
	    position = top_position;
    }

	int throttle::getPos()
	{
		return position;
	}

	int throttle::getTop()
	{
		return top_position;
	}

	bool throttle::operator==(throttle& t1)
	{
		if (position==t1.getPos())
			if (top_position==t1.getTop())
				return true;
			else
				return false;
		else
			return false;

	}
 bool throttle::operator!=(throttle& t1)
	{
		if (!(position==t1.getPos()))
			if (!(top_position==t1.getTop()))
				return true;
			else
				return false;
		else
			return false;

	}

std::ostream& operator<<(std::ostream& outs,throttle& t1)
{
	outs << "Top position: " << t1.top_position << " ";
	outs << "Current Position: " << t1.position;
    return outs;
}


