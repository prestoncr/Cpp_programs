//Implementing ADT List with a Simple Singly Linked List
//Preston Programming
//======================================================

#ifndef _SSLL_H_
#define _SSLL_H_

#include "list.h"
 using namespace cop3530;
namespace cop3530{


template <typename X>
  class SSLL : public List<X> {

 public :
  SSLL ();
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


  ~SSLL () override;

 private:

  struct node{
    X data;
    node* next;
  };
  node* head;
  node* temp;
  node* current;
  node* tail;


 };

//-----------------------------------------------------
//Constructor

 template <typename X>
   SSLL<X>::SSLL(){
   head = NULL;
   tail = NULL;
   current = NULL;
   temp = NULL;

 }


//-----------------------------------------------------
//insert
 template <typename X>
   void SSLL<X> :: insert(X ele, size_t position)
   {
     size_t count = 0;
     node* foo = new node;
     foo-> data = ele;

      if (position == 0)
       {
	 push_front (ele);
       }

      else if (head != NULL)
       {
	 current = head;


     while (current->next != NULL && count != position)
       {
	 temp = current;
	 current = current->next;
	 count++;
       }
        temp->next = foo;
        foo->next = current;
       }

    else
      {
	std:: cout <<"Error occurred trying to INSERT\n\n";
      }


   }



 //-----------------------------------------------------
 //push_back

 template <typename X>
   void SSLL<X> :: push_back(X ele)
   {

     node* foo = new node;
     foo->data = ele;
     foo->next = NULL;

       if (head != NULL)
	 {
	   current = head;
	   while (current->next != NULL)
	     {
	       current = current->next;
	     }
	   current ->next = foo;
	 }

       else head = foo;
     tail = foo;

   }



 //-----------------------------------------------------
//push_front
 template <typename X>
   void SSLL<X> :: push_front(X ele)
   {
      node* foo = new node;
     foo->data = ele;
     foo->next = NULL;

     if (head != NULL)
       {
	        foo->next = head;
	         head = foo;
       }

     else
       {
	        head = foo;
	         tail = foo;
	          foo ->next = tail;
       }

   }




 //-----------------------------------------------------
//replace

template<typename X>
  X SSLL<X> :: replace(X ele, size_t position)
  {
    size_t count = 0;
    X tempDat = NULL;



     if  (head != NULL)
       {
     current = head;

     while (current->next != NULL && count != position)
         {
	   current = current->next;
	   count++;
         }
     tempDat = current->data;
     current->data = ele;

       }

     else std::cout <<"Error occurred trying to REPLACE\n\n";
     return tempDat;

  }

//-----------------------------------------------------
//remove
 template<typename X>
   X SSLL<X>:: remove (size_t position)
   {
     size_t count =0;
     X tempDat = NULL;

     if (head != NULL)
       {
	 current = head;

        while (current->next != NULL && count != position)
         {
	   temp = current;
	   current = current->next;
	   count++;
         }
	tempDat = current->data;
	temp->next = current->next;

       }
     else std:: cout << "Error, could not REMOVE\n\n";
     return tempDat;

   }

//-----------------------------------------------------
//pop_back

 template<typename X>
   X SSLL<X>::pop_back()
   {
     X tempDat = NULL;


     if (head != NULL)
       {

	 current = head;
	 while (current->next != tail)
	   {

	     current = current->next;
	   }


	 tempDat = tail->data;
	  tail = current;


       }
     else std:: cout << "Error, could not POP_BACK\n\n";
     return tempDat;

   }


 //-----------------------------------------------------
//pop_front

 template<typename X>
   X SSLL<X>:: pop_front()
   {
     X tempDat = NULL;

     if (head != NULL)
       {
	 tempDat = head->data;
	 head = head->next;

       }

     else std:: cout << "Error, could not POP_FRONT\n\n";

    return tempDat;
    }

//-----------------------------------------
//item_at

template<typename X>
X SSLL<X>::  item_at (size_t position)
{
  X tempDat = NULL;
 size_t count = 0;

   if (head != NULL)
    {
    current = head;

   while (current->next != NULL && count != position)
     {
     current = current->next;
     count++;
     }
   tempDat = current->data;

    }
   else std:: cout << "Error, could not find ITEM_AT\n\n";
   return tempDat;

}


 //-----------------------------------------
//peek_back
 template <typename X>
   X SSLL<X>:: peek_back()
   {
     return tail->data;
   }

 //-----------------------------------------
//peek_front
 template <typename X>
   X SSLL<X>:: peek_front()
   {
     return head->data;
   }


 //-----------------------------------------
//is_empty
template <typename X>
  bool SSLL<X>::is_empty()
  {
    if (head!=NULL) return false;
  }


//-----------------------------------------
//is_full
 template <typename X>
   bool SSLL<X>:: is_full()
   {
     //Linked List cannot be full?
     return false;
   }


 //-----------------------------------------
//length
 template <typename X>
   size_t SSLL<X>:: length()
   {
     if (head ==NULL) return 0;

     size_t count = 0;
     current = head;
     while (current->next != NULL)
       {
	 current = current->next;
	 count++;
       }
     count++;
     return count;

   }

 //-----------------------------------------
//clear
template <typename X>
  void SSLL<X>:: clear()
  {

    if (head == NULL)
      {
	       std:: cout << "Error, cannont clear a list that does not exist\n\n";
        return;
      }

    current = head;

    while (current->next != tail)
      {
	       node* delNode = current;
	        current = current->next;
	         delete delNode;
      }
      node* delNode = tail;
      delete delNode;
  }


//---------------------------------------------
// contains
 template<typename X>
   bool SSLL<X>::  contains(X element, bool contains)
   {
     //Needs to be coded
     return false;
   }


//---------------------------------------------
// print
 template <typename X>
 void SSLL<X>:: print (std::ostream& stream)
 {

   if (head == NULL)
     {
       stream << "<empty list>";
       return;
     }
   current = head;
   while (current->next != NULL)
     {
       stream << "[" << current->data << "]";
       current = current->next;
     }
   stream << "[" << current->data << "]";


 }

//---------------------------------------------
// contents
 template <typename X>
   X* SSLL<X>:: contents()
   {

     size_t count = 0;
     if (head == NULL)
       {
	 std::cout << "Error, list is empty\n\n";
	 return NULL;
       }

     X itemArr[length()];
     current = head;
     while (current->next != NULL)
       {
	 itemArr[count] = current->data;
	 count++;
	 current = current->next;
       }
     itemArr[count] = current->data;
     X* returnArr = itemArr;

     //only works by assigning each data into an array
     //then printing the array
     //cannot just print *data

     return returnArr;


   }
 //-------------------------------
 //Destructor
 template <typename X>
   SSLL<X>::~SSLL()
    {
       if(head != NULL) clear();
    }

//===========================================
//END OF SSLL.h
   }
#endif
