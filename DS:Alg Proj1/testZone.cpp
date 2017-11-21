#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "PSLL.h"
#include "SSLL.h"
#include "SDAL.h"
#include "CDAL.h"
#include "CBL.h"

#include <iostream>

SCENARIO ("General List Testing")
 {
	GIVEN ("Char List") {

    //Replace the List Implementation Type to any of the five
    //and everything will work exactly the same

		cop3530::List<char> * list  = new cop3530::SDAL<char>();

    list->push_back('A');
    list->push_back('B');
    list->push_back('C');
    list->push_back('D');
    list->push_front('Z');
    list->push_front('Y');
    list->push_front('X');
    list->push_front('W');
    list->insert('Q', 0);
    list->insert('&', 5);

    std:: cout << "\n===========================================\n"
      << "Printing the List\nList should be: \n"
      << "[Q,W,X,Y,Z,&,A,B,C,D]" << "\nList actually is:\n";
      list->print(std::cout);
      std:: cout << "\n===========================================\n";


		WHEN ("Removing some elements at 0, last, and middle using list->remove(list->length()-1)for last element")
     {
			char first = list->remove(0);
      char last = list->remove(list->length()-1);
      char mid = list->remove(list->length()/2);
			THEN ("First char should be Q")
      {
				REQUIRE(first == 'Q');
			}
      THEN ("Last char should be D")
      {
        REQUIRE(last == 'D');
      }
      THEN ("Mid char should be &")
      {
        REQUIRE(mid == '&');
      }
		}

		WHEN ("Popping some elements; then checking length again")
    {
      std:: cout << "List currently is \n";
      list->print(std::cout);
      std:: cout << "\n\n";
			char poppyFront = list->pop_front();
      char poppyBack = list->pop_back();
      THEN ("Front char should be W")
      {
        REQUIRE(poppyFront == 'W');
      }
      THEN ("Back char should be C")
      {
        REQUIRE(poppyBack == 'C');
      }
      size_t len = list->length();
      THEN ("Length should be 5 because we have removed thrice and popped twice")
      {
        REQUIRE(len == 5);
      }
		}

    WHEN ("Peeking some elements")
    {
      THEN("Peek front should be X")
      {
        REQUIRE(list->peek_front() == 'X');
      }
      THEN("Peek back should be B")
      {
        REQUIRE(list->peek_back() == 'B');
      }
    }

    std:: cout << "\n===========================================\n"
      << "Printing the List again\nList should be: \n"
      << "[X,Y,Z,A,B]" << "\nList actually is:\n";
      list->print(std::cout);
      std:: cout << "\n===========================================\n";

      WHEN("Checking the contents of the List")
      {
        char * array = list->contents();
  			THEN ("Array items should be [X,Y,Z,A,B]")
        {
  				char checker[5] = {'X', 'Y', 'Z', 'A', 'B'};
  				for(int i = 0; i < 5; i++)
           {
  					REQUIRE(*(array+i) == checker[i]);
  				 }
  			}
      }

      WHEN ("Checking the contains function for 'Z' ")
      {
        bool checking = list->contains('B', [](const char& a, const char& b) {
          					return a == b;
     				   		});
  			THEN ("Bool checking should be true") {
  				REQUIRE (checking);
  			}
      }

      WHEN("Replacing List at 3 with element G and checking Item_at")
      {
        char replaced = list->replace('G', 3);
        THEN("Replaced element should be A")
        {
          REQUIRE(replaced == 'A');
        }
        THEN("Element at 3 should be G")
        {
          REQUIRE(list->item_at(3) == 'G');
        }
      }

      WHEN("Checking the booleans full and empty")
      {
        THEN("Full should be false")
        {
          REQUIRE(!list->is_full());
        }
        THEN("Empty should be false")
        {
          REQUIRE(!list->is_empty());
        }

      }

		WHEN ("Checking if clear works")
     {
			list->clear();
      THEN("Empty should be true")
      {
        REQUIRE(list->is_empty());
      }

			size_t len = list->length();
			THEN ("Length should be 0 after everything is cleared")
      {
				REQUIRE(len == 0);
			}
      delete list;
		 }


  }
}



SCENARIO ("Large List Testing Making sure growth and shrinkage of List works") {
	GIVEN ("Int list") {

		cop3530::List<int> * list = new cop3530::SDAL<int>();


		for(int i = 0; i < 142; i++)
			list->push_back(i);

		WHEN ("Checking Length of the List")
    {
			size_t len = list->length();
			THEN ("Length should be 142") {
				REQUIRE(len == 142);
			}
		}
		WHEN("Removing a middle element of the list, then checking the contents to make sure the hole was patched")
    {
      int x = list->remove(65);
      THEN("Element x should be 65")
      {
        REQUIRE(x == 65);
      }
        int * array = list->contents();
        THEN ("Array items should be [0 - 141], without 65")
        {
          char checker[list->length()];
          int x = 0;
          for (int i = 0; i < list->length(); i++)
          {
            if (x == 65)x++;
            checker[i] =x;
            x++;
          }
          for(int i = 0; i < list->length(); i++)
           {
            REQUIRE(*(array+i) == checker[i]);
           }
        }
      }

		delete list;
	}
}
