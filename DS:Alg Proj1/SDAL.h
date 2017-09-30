//Implementing ADT List with a Simple Dynamic Array-Based List
//Preston Programming
//======================================================

#ifndef _SDAL_H_
#define _SDAL_H_

#include "list.h"
 using namespace cop3530;
namespace cop3530{


template <typename X>
  class SDAL : public List<X> {

 public :
  SDAL (size_t start_size);
  SDAL();
  void insert (X element, size_t position)override;
  void push_back (X element)override;
  void push_front (X element)override;
  X replace (X element, size_t position)override;
  X remove (size_t position)override;
  X pop_back()override;
    X pop_front()override;
  X item_at (size_t position)override;
  X peek_back()override;
  X peek_front()override;
  bool is_empty()override;
  bool is_full()override;
  size_t length()override;
  void clear()override;
  bool contains(X element, bool contains)override;
  void print (std::ostream& stream)override;
  X* contents()override;


  ~SDAL () override;

 private:

   size_t arr_size;
   X *array;
   X *newArray;

   void makeArray(size_t size)
   {
     this->array = new X [size];
     for (int i = 0; i < size; i++) array[i] = NULL;
   }
   void resizeArray()
   {
     size_t size = arr_size*(1.5);

     this->newArray = new X [size];
     for (int i = 0; i < size; i++) newArray[i] = NULL;

     for (int i = 0; i < arr_size; i++)
     {
       this->newArray[i] = this->array[i];
     }
     this->array = this->newArray;
     arr_size = arr_size*(1.5);
     std:: cout <<"THE ARRAY HAS BEEN RESIZED\n\n";
   }


 };

//-----------------------------------------------------
//Constructor

 template <typename X>
   SDAL<X>::SDAL()
   :arr_size(50)
   {
     makeArray(arr_size);
   }

 template <typename X>
   SDAL<X>::SDAL(size_t size)
   :arr_size (size)
   {
     makeArray (arr_size);
    }


//-----------------------------------------------------
//insert
 template <typename X>
   void SDAL<X> :: insert(X ele, size_t position)
{
  if (is_full()) resizeArray(); //recopy array



     for (int i = length(); i > position; i--)
      {
        array[i] = array[i-1];
      }
      array[position] = ele;

}



 //-----------------------------------------------------
 //push_back

 template <typename X>
   void SDAL<X> :: push_back(X ele)
   {
     if (is_full())resizeArray(); // recopy array
      array[length()] = ele;
   }



 //-----------------------------------------------------
//push_front
 template <typename X>
   void SDAL<X> :: push_front(X ele)
{
     if (is_full())resizeArray(); //recopy array

        for (int i = length(); i > 0; i--)
         {
           array[i] = array[i-1];
         }
         array[0] = ele;

}

 //-----------------------------------------------------
//replace

template<typename X>
  X SDAL<X> :: replace(X ele, size_t position)
  {
    X tempDat = array[position];
    array[position] = ele;
    return tempDat;
  }

//-----------------------------------------------------
//remove
 template<typename X>
   X SDAL<X>:: remove (size_t position)
   {
     X tempDat = array[position];

     for (int i = position; i < length(); i++)
     {
       array[i] = array[i+1];
     }
     array[length()-1] = NULL;
     return tempDat;
   }

//-----------------------------------------------------
//pop_back

 template<typename X>
   X SDAL<X>::pop_back()
   {
     X tempDat = array[length()-1];
     array[length() -1] = NULL;
     return tempDat;
   }


 //-----------------------------------------------------
//pop_front

 template<typename X>
   X SDAL<X>:: pop_front()
   {
     X tempDat = array[0];
     for (int i = 0; i < length(); i++)
     {
       array[i] = array[i+1];
     }
     array[length()-1] = NULL;
    return tempDat;
   }

//-----------------------------------------
//item_at

template<typename X>
X SDAL<X>::  item_at (size_t position)
{
return array[position];
}


 //-----------------------------------------
//peek_back
 template <typename X>
   X SDAL<X>:: peek_back()
   {
     return array[length()-1];
   }

 //-----------------------------------------
//peek_front
 template <typename X>
   X SDAL<X>:: peek_front()
   {
     return array[0];
   }


 //-----------------------------------------
//is_empty
template <typename X>
  bool SDAL<X>::is_empty()
  {
    if (array[0] == NULL) return true;
    else return false;
  }


//-----------------------------------------
//is_full
 template <typename X>
   bool SDAL<X>:: is_full()
   {
     if(array[arr_size-1] == NULL) return false;
     else return true;
   }


 //-----------------------------------------
//length
 template <typename X>
   size_t SDAL<X>:: length()
   {
     size_t count = 0;
     for (int i =0; i < arr_size; i++)
     {
       if(array[i] != NULL) count++;
     }
     return count;
   }

 //-----------------------------------------
//clear
template <typename X>
  void SDAL<X>:: clear()
  {
    delete array;
  }


//---------------------------------------------
// contains
 template<typename X>
   bool SDAL<X>::  contains(X element, bool contains)
   {
     //needs to be coded;
     return true;
   }


//---------------------------------------------
// print
 template <typename X>
 void SDAL<X>:: print (std::ostream& stream)
 {
   if (is_empty()) stream << "<empty list>";
   else
   {
   for (int i = 0; i < arr_size; i++)
   {
     if (array[i] != NULL)
     {
       stream << "[" << array[i] << "], ";
     }
   }
 }
}

//---------------------------------------------
// contents
 template <typename X>
   X* SDAL<X>:: contents()
   {
     return array;
   }
 //-------------------------------
 //Destructor
 template <typename X>
   SDAL<X>::~SDAL()
    {
      clear();
    }

//===========================================
//END OF SDAL.h
   }
#endif
