//Implementing ADT List with a Pool Using Singly Linked List
//Preston Programming
//======================================================

#ifndef _PSLL_H
#define _PSLL_H

#include "list.h"

using namespace cop3530;

namespace cop3530{


template <typename X>
  class PSLL : public List<X> {
  private:

   struct node{
     X data;
     node* next;
   };

   node* head;
   node* temp;
   node* current;
   node* tail;
   node* poolHead;
   node* poolTail;
   node* poolCurr;
   node* poolTemp;


  bool freePool()
  {
  if(poolHead == NULL) return false;
  else return true;

  }

  node* findNode()
  {
   //this function returns a free node from the pool
   poolTemp = poolHead;
   if (poolHead->next != NULL)
     {
       poolHead = NULL;
     }

   else
     {
       poolHead = poolHead->next;
     }
     return poolTemp;
  }

  bool memoryWaste()
  {
   if(length() >= 100 && (poolLength() > (length()/2)))
     return true;
     else return false;
  }
  void memorySaver()
  {
   poolCurr = poolHead;
   size_t count = 0;
   size_t half = poolLength()/2;
   while (count < half)
   {
     poolCurr = poolCurr->next;
     count++;
   }
   while(poolCurr->next != NULL)
   {
     node* delNode = poolCurr;
      poolCurr = poolCurr->next;
     delete delNode;
   }
  }
  size_t poolLength()
  {
   if (poolHead ==NULL) return 0;

   size_t count = 0;
   poolCurr = poolHead;
   while (poolCurr->next != NULL)
     {
       poolCurr = poolCurr->next;
       count++;
     }
   count++;
   return count;

  }

  void clearPool()
  {

      if (poolHead == NULL)
        {
          return;
        }

      poolCurr = poolHead;

      while (poolCurr->next != NULL)
        {
           node* delNode = poolCurr;
            poolCurr = poolCurr->next;
             delete delNode;
        }

  }
public:
  template <typename dX>
      class PSLL_Iter
      {

        // type aliases required for C++ iterator compatibility
    using size_t = std::size_t;
    using value_type = dX;
    using reference = dX&;
    using pointer = dX*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;


    // type aliases for prettier code
    using self_type = PSLL_Iter;
    using self_reference = PSLL_Iter&;

  private:
    node* here;

  public:
    explicit PSLL_Iter( node* start = nullptr ) : here( start ) {}
    PSLL_Iter( const PSLL_Iter& src ) : here( src.here ) {}


    reference operator*() const {
      return here->data;
    }
    pointer operator->() const {
       return &(operator*());
    }

    self_reference operator=( PSLL_Iter<dX> const& src ) {
      if (this == &src) return (*this);
      here = src.here;
      return *this;
    }

    self_reference operator++() {
      if (here->next != nullptr){ here++;
      return *this;
    }
    here = nullptr;
    return *this;
    //temporarily fixed I guess ! :))
    //has to return end somehow
    //must fix this to not get Illegal Instruction 4
    } // preincrement

    self_type operator++(int) {
      self_type tmp (*this);
      ++(*this);
      return tmp;
    } // postincrement

    bool operator==( PSLL_Iter<dX> const& rhs ) const {
      return (here == rhs.here);
    }
    bool operator!=( PSLL_Iter<dX> const& rhs) const {
      return (here != rhs.here);
    }

  }; // end of PSLL iter class




 public :
  PSLL ();
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


  ~PSLL () override;

  using iterator = PSLL_Iter<X>;
  using const_iterator = PSLL_Iter<X const>;


  iterator begin() const {
    return PSLL_Iter<X>( head );
  }


  iterator end() const {
    return PSLL_Iter<X>();
  }

 };

  };

//-----------------------------------------------------
//Constructor

 template <typename X>
   PSLL<X>::PSLL(){
   head = NULL;
   tail = NULL;
   current = NULL;
   temp = NULL;
   poolHead = NULL;
   poolTail = NULL;
   poolCurr = NULL;
   poolTemp = NULL;

 }


 //TESTING only

 //TESTING POOL BELOW
 // template <typename X>
 // void PSLL<X>:: printPool (std::ostream& stream)
 // {
 // if (poolHead == NULL)
 //   {
 //     stream << "<empty pool>";
 //     return;
 //   }
 // poolCurr = poolHead;
 // while (poolCurr->next != NULL)
 //   {
 //     stream << "[" << poolCurr->data << "]";
 //     poolCurr = poolCurr->next;
 //   }
 // stream << "[" << poolCurr->data << "]";
 // stream << "[" << poolCurr->next->data << "]";
 // }

 //-----------------------------------------------------
//insert
 template <typename X>
   void PSLL<X> :: insert(X ele, size_t position)
   {
     node* foo;
     size_t count = 0;
     if(freePool())
     {
       //use node in free pool
       //set foo to a node in the Pool
       foo = findNode();
     }
     else
     {
        foo = new node;
     }

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
     void PSLL<X> :: push_back(X ele)
     {
        node* foo;
       if(freePool())
       {
         foo = findNode();
       }
       else
       {
         foo = new node;
       }

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
       void PSLL<X> :: push_front(X ele)
       {
         node* foo;
         if(freePool()) foo = findNode();
         else foo = new node;

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
        X PSLL<X> :: replace(X ele, size_t position)
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
        X PSLL<X>:: remove (size_t position)
           {
             size_t count = 0;
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

          if (poolHead == NULL) poolHead = current;
          else
            {
            poolCurr = poolHead;
            while (poolCurr->next != NULL)
              {
                poolCurr = poolCurr->next;
              }
              poolCurr = current;
            }

          }
             else std:: cout << "Error, could not REMOVE\n\n";
             return tempDat;

           }


//-----------------------------------------------------
//pop_back

    template<typename X>
      X PSLL<X>::pop_back()
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

            if (poolHead == NULL) poolHead = tail;
            else
              {
              poolCurr = poolHead;
              while (poolCurr->next != NULL)
                {
                  poolCurr = poolCurr->next;
                }
                poolCurr = tail;
              }
           	tail = current;

        }
          else std:: cout << "Error, could not POP_BACK\n\n";
          return tempDat;

    }
//-----------------------------------------------------
//pop_front

      template<typename X>
        X PSLL<X>:: pop_front()
        {
          X tempDat = NULL;

          if (head != NULL)
            {
              tempDat = head->data;

              if (poolHead == NULL) poolHead = head;
              else
                {
                poolCurr = poolHead;
                while (poolCurr->next != NULL)
                  {
                    poolCurr = poolCurr->next;
                  }
                  poolCurr = head;
                }
              head = head->next;
            }

          else std:: cout << "Error, could not POP_FRONT\n\n";

         return tempDat;
       }

 //-----------------------------------------
 //item_at

 template<typename X>
 X PSLL<X>::  item_at (size_t position)
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
   X PSLL<X>:: peek_back()
   {
     return tail->data;
   }

 //-----------------------------------------
 //peek_front
 template <typename X>
   X PSLL<X>:: peek_front()
   {
     return head->data;
   }


 //-----------------------------------------
 //is_empty
 template <typename X>
  bool PSLL<X>::is_empty()
  {
    if (head!=NULL) return false;
  }


 //-----------------------------------------
 //is_full
 template <typename X>
   bool PSLL<X>:: is_full()
   {
     //Linked List cannot be full?
     return false;
   }

   //-----------------------------------------
  //length
   template <typename X>
     size_t PSLL<X>:: length()
     {
       if (head ==NULL) return 0;

       size_t count = 0;
       current = head;
       while (current->next != NULL)
         {
  	 current = current->next;
  	 count++;
         }

       return count;
     }

//-----------------------------------------
//clear
template <typename X>
 void PSLL<X>:: clear()
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
     clearPool();
 }

 //---------------------------------------------
 // contains
  template<typename X>
    bool PSLL<X>::  contains(X element, bool contains)
    {
      //Needs to be coded
      return false;
    }

//---------------------------------------------
// print
 template <typename X>
 void PSLL<X>:: print (std::ostream& stream)
 {

   if (head == NULL)
     {
       stream << "<empty list>";
       return;
     }
   current = head;
   while (current->next != tail)
     {
       stream << "[" << current->data << "],";
       current = current->next;
     }
   stream << "[" << current->data << "], ";
   stream << "[" << current->next->data << "]";

 }

 //---------------------------------------------
 // contents
  template <typename X>
    X* PSLL<X>:: contents()
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
    PSLL<X>::~PSLL()
     {
        if(head != NULL) clear();
     }



//=======================================
//END OF PSLL.h

#endif
