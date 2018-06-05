/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>

template < typename T > class Singleton
{
public:
  static T & getInstance ()
  {
    static T instance;		// this is an atomic operation
    return instance;
  }

protected:
  Singleton () = default;
  Singleton (const Singleton &) = delete;
  Singleton & operator= (const Singleton &) = delete;
  virtual ~ Singleton () = default;
};

// This class can only be accessed using the getInstance method from base class
// The Singleton class is made friend for this class to access to constructor
class mySingleton:public Singleton < mySingleton >
{
public:
  short getCount ()
  {
    return ++_count;
  }
private:
    friend class Singleton;
  short _count;
mySingleton ():_count (0)
  {
  }
  mySingleton (const mySingleton &) = delete;
  mySingleton & operator= (const mySingleton &) = delete;
  virtual ~ mySingleton () = default;
};

// This singleton class can be access using the getInstance method
// from the base class as well as by instantiating the class directly
class myDualSingleton:public Singleton < myDualSingleton >
{
public:
  myDualSingleton ():_count (0)
  {
  }
  short getCount ()
  {
    return ++_count;
  }
private:
  short _count;
};

int main ()
{
  for (short i = 0; i < 5; i++)
    {
      mySingleton & s = mySingleton::getInstance ();
      std::cout << "mySingleton" << "\t" << s.getCount () << std::endl;

      myDualSingleton & ds = myDualSingleton::getInstance ();
      std::cout << "myDualSingleton getInstance" << "\t" << ds.getCount () << std::endl;

      myDualSingleton ds2;
      std::cout << "myDualSingleton" << "\t" << ds2.getCount () << std::endl;
    }

  return 0;
}
