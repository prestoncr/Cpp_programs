//ADT List Testing file
//Preston Programming

#include "PSLL.h"
#include "SSLL.h"
#include "SDAL.h"
#include "CDAL.h"
#include "CBL.h"



#include <iostream>

int main()
{

      //Replace the List Implementation Type to any of the five
      //and everything will work exactly the same

  		cop3530::List<char> * list  = new cop3530::CDAL<char>();

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

  			char first = list->remove(0);

        char last = list->remove(list->length()-1);
        char mid = list->remove(list->length()/2);


  				if (first != 'Q') std:: cout << "TEST FAILED Line 47\n";
          if(last != 'D')std:: cout << "TEST FAILED Line 48\n";
          if(mid != '&')std:: cout << "TEST FAILED Line 49\n";

  			char poppyFront = list->pop_front();

        char poppyBack = list->pop_back();

          if(poppyFront != 'W') std:: cout << "TEST FAILED Line 53\n";

          if(poppyBack != 'C')std:: cout << "TEST FAILED Line 54\n";
         size_t len1 = list->length();
          if(len1 != 5)std:: cout << "TEST FAILED Line 57\n";
          if(list->peek_front() != 'X')std:: cout << "TEST FAILED Line 59\n";
          if(list->peek_back() != 'B')std:: cout << "TEST FAILED Line 60\n";


      std:: cout << "\n===========================================\n"
        << "Printing the List again\nList should be: \n"
        << "[X,Y,Z,A,B]" << "\nList actually is:\n";
        list->print(std::cout);
        std:: cout << "\n===========================================\n";


          char * array = list->contents();

    				char checker1[5] = {'X', 'Y', 'Z', 'A', 'B'};
    				for(int i = 0; i < 5; i++)
             {
    					if(*(array+i) != checker1[i])std:: cout << "TEST FAILED Line 73\n";;
    				 }

          bool checking = list->contains('B', [](const char& a, const char& b) {
            					return a == b;
       				   		});

    				if(!checking)std:: cout << "TEST FAILED Line 83\n";;

          char replaced = list->replace('G', 3);

            if(replaced != 'A')std:: cout << "TEST FAILED Line 87\n";
            if(list->item_at(3) != 'G')std:: cout << "TEST FAILED Line 88\n";


            if(list->is_full())std:: cout << "TEST FAILED Line 91\n";
            if(list->is_empty())std:: cout << "TEST FAILED Line 92\n";

  			list->clear();

          if(!list->is_empty())std:: cout << "TEST FAILED Line 96\n";

  			size_t len2 = list->length();

  				if(len2 != 0)std:: cout << "TEST FAILED Line 99\n";

        delete list;


        std:: cout << "\n\nINT LIST\n\n";
  		cop3530::List<int> * list2 = new cop3530::CDAL<int>();

  		for(int i = 0; i < 142; i++)
  			list2->push_back(i);

  			size_t len3 = list2->length();
  				if(len3 != 142)std:: cout << "TEST FAILED Line 110\n";

        int x = list2->remove(65);

          if(x != 65)
          {
            std:: cout << "TEST FAILED Line 114\n";
            std:: cout << "x is actually : " << x << "\n\n";
          }

          int * array2 = list2->contents();

            int checker2[list2->length()];
            int z = 0;
            for (int i = 0; i < list2->length(); i++)
            {
              if (z == 65)z++;
              checker2[i] =z;
              z++;
            }
            for(int i = 0; i < list2->length(); i++)
             {
              if(*(array2+i) != checker2[i])
              {
                std:: cout << "TEST FAILED Line 128\n";
                std:: cout << "arr is " << *(array2+i);
                std:: cout << "\n\nchecker is " << checker2[i] << std:: endl;
              }
             }



  		delete list2;

      std:: cout <<"All Tests are complete, hopefully they all passed too :) \n\n";

}
