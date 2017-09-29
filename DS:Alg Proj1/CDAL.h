//Implementing ADT List with a Chained Dynamic Array-Based List
//Preston Programming
//============================================================

#ifndef _CDAL_H_
#define _CDAL_H_

#include "list.h"
 using namespace cop3530;
namespace cop3530{


template <typename X>
  class CDAL : public List<X> {

 public :
  CDAL();
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

  ~CDAL () override;

 private:

   struct node
   {
     X data[50];
     node* next;
     node* previous;
   }

   node* head;
   node* tail;
   node* current;
   node* temp;


   void newArray()
   {
     for (int i = 0; i < 50; i++)
     current->data[i] = NULL;
   }
 };

//-----------------------------------------------------
//Constructor

 template <typename X>
   CDAL<X>::CDAL()
   :
   {
     head = NULL;
     tail = NULL;
     current = NULL;
     temp = NULL;
    head->previous = NULL;
    tail ->next = NULL;
   }


//-----------------------------------------------------
//insert
 template <typename X>
   void CDAL<X> :: insert(X ele, size_t position)
{

}



 //-----------------------------------------------------
 //push_back

 template <typename X>
   void CDAL<X> :: push_back(X ele)
   {
     if (head == NULL)
     {
       
     }

   }


 //-----------------------------------------------------
//push_front
 template <typename X>
   void CDAL<X> :: push_front(X ele)
   {

   }

 //-----------------------------------------------------
//replace

template<typename X>
  X CDAL<X> :: replace(X ele, size_t position)
  {

  }

//-----------------------------------------------------
//remove
 template<typename X>
   X CDAL<X>:: remove (size_t position)
   {

   }

//-----------------------------------------------------
//pop_back

 template<typename X>
   X CDAL<X>::pop_back()
   {

   }


 //-----------------------------------------------------
//pop_front

 template<typename X>
   X CDAL<X>:: pop_front()
   {

   }

//-----------------------------------------
//item_at

template<typename X>
X CDAL<X>::  item_at (size_t position)
{

}


 //-----------------------------------------
//peek_back
 template <typename X>
   X CDAL<X>:: peek_back()
   {

   }

 //-----------------------------------------
//peek_front
 template <typename X>
   X CDAL<X>:: peek_front()
   {

   }


 //-----------------------------------------
//is_empty
template <typename X>
  bool CDAL<X>::is_empty()
  {

  }


//-----------------------------------------
//is_full
 template <typename X>
   bool CDAL<X>:: is_full()
   {

   }


 //-----------------------------------------
//length
 template <typename X>
   size_t CDAL<X>:: length()
   {

   }

 //-----------------------------------------
//clear
template <typename X>
  void CDAL<X>:: clear()
  {

  }


//---------------------------------------------
// contains
 template<typename X>
   bool CDAL<X>::  contains(X element, bool contains)
   {

   }


//---------------------------------------------
// print
 template <typename X>
 void CDAL<X>:: print (std::ostream& stream)
 {

 }

//---------------------------------------------
// contents
 template <typename X>
   X* CDAL<X>:: contents()
   {

   }
 //-------------------------------
 //Destructor
 template <typename X>
   CDAL<X>::~CDAL()
    {

    }

//===========================================
//END OF SDAL.h
   }
#endif
