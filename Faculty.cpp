#include "Faculty.h"

Faculty::Faculty():iPerson()
{

}

Faculty::~Faculty()
{

}

Faculty::Faculty(string n, string d, unsigned int i)
{
  name = n;
  department = d;
  id = i;
}
