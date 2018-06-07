/******************************************************************************
	Ekvira Academy
Author: Aniket Pingley
CRTP object traker
 *******************************************************************************/
#include <stdio.h>
#include <iostream>

template < typename T > class instanceCounter
{
		public:
				instanceCounter ()
				{
						++_created;
						++_alive;
				}

				unsigned long getCountCreated ()
				{
						return _created;
				}

				unsigned long getCountAlive ()
				{
						return _alive;
				}

				virtual ~ instanceCounter ()
				{
						--_alive;
				}

		private:
				static unsigned long _created;
				static unsigned long _alive;
};

template <typename T> unsigned long instanceCounter<T>::_alive (0);
template <typename T> unsigned long instanceCounter<T>::_created (0);

//
//
//
class myInstanceA:public instanceCounter < myInstanceA >{ 
		public:
				myInstanceA ():_type ("myInstanceA")
		{
		}

				const std::string& getType ()
				{
						return _type;
				}

		private:
				std::string _type;
};

//
//
//
class myInstanceB: public instanceCounter <myInstanceB>{
		public:
				myInstanceB ():_type ("myInstanceB")
		{
		}

				const std::string& getType ()
				{
						return _type;
				}

		private:
				std::string _type;
};


int main ()
{
		{
				myInstanceA a1;
				std::cout << a1.getType() << "\t" << a1.getCountCreated() << "\t" << a1.getCountAlive() << std::endl;
				myInstanceA a2;
				std::cout << a2.getType() << "\t" << a2.getCountCreated() << "\t" << a2.getCountAlive() << std::endl;
				myInstanceA a3;
				std::cout << a3.getType() << "\t" << a3.getCountCreated() << "\t" << a3.getCountAlive() << std::endl;
				myInstanceB b1;
				std::cout << b1.getType() << "\t" << b1.getCountCreated() << "\t" << b1.getCountAlive() << std::endl;
				myInstanceB b2;
				std::cout << b1.getType() << "\t" << b1.getCountCreated() << "\t" << b1.getCountAlive() << std::endl;
		}

		{
				myInstanceA a1;
				std::cout << a1.getType() << "\t" << a1.getCountCreated() << "\t" << a1.getCountAlive() << std::endl;
				myInstanceA a2;
				std::cout << a2.getType() << "\t" << a2.getCountCreated() << "\t" << a2.getCountAlive() << std::endl;
				myInstanceA a3;
				std::cout << a3.getType() << "\t" << a3.getCountCreated() << "\t" << a3.getCountAlive() << std::endl;
				myInstanceB b1;
				std::cout << b1.getType() << "\t" << b1.getCountCreated() << "\t" << b1.getCountAlive() << std::endl;
				myInstanceB b2;
				std::cout << b1.getType() << "\t" << b1.getCountCreated() << "\t" << b1.getCountAlive() << std::endl;
		}


		return 0;
}
