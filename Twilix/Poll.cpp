#include "Poll.h"

const Poll::Type Poll::Closed(0);

Poll::Poll(const Type &_type) :
	type(_type)
{

}


Poll::~Poll()
{
}
