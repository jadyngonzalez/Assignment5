//Person interface
#include "iPerson.h"

iPerson::iPerson()
{
  name = "default";
  id = 0;
}

iPerson::~iPerson()
{
  //tbd
}

bool iPerson::operator ==(const iPerson& p)
{
  if(p.id == id)
  {
    return true;
  }

  else
  {
    return false;
  }
}

bool iPerson::operator == (const int p)
{
  if(p == id)
  {
    return true;
  }

  else
  {
    return false;
  }
}

bool iPerson::operator != (const Person& p)
{
  if(p.id != id)
  {
    return true;
  }

  else
  {
    return false;
  }
}

bool iPerson::operator < (const Person& p)
{
  if(p.id > id)
  {
    return true;
  }

  else
  {
    return false;
  }
}
bool iPerson::operator > (const Person& p)
{
  if(p.id < id)
  {
    return true;
  }

  else
  {
    return false;
  }
}
