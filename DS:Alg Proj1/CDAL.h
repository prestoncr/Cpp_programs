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
   };

   node* head;
   node* current;
   node* tail;


   void newArray()
   {
     for (size_t i = 0; i < 50; i++)
     current->data[i] = NULL;
   }
 };

//-----------------------------------------------------
//Constructor

 template <typename X>
   CDAL<X>::CDAL()

   {
     head = NULL;
     tail = NULL;
     current = NULL;
   }


//-----------------------------------------------------
//insert
 template <typename X>
   void CDAL<X> :: insert(X ele, size_t position)
{
//if position is = head call pushfront then return
//if position is = tail call pushback then return

//if list does not exist
if (head == NULL)
  {
    node* foo = new node;
    current = foo;
    newArray();
    foo->data[0] = ele;
    foo->next = tail;
    foo->previous = NULL;
    head = foo;
    tail = head;
    return;
  }

else
  {
    X tempEle1;
    X tempEle2;
    bool filled = false;
    size_t nextFree = 0;
    size_t nodeNum = position/50;
    current = head;
    for (size_t i = 0; i < nodeNum; i++)
      current = current ->next;
      nodeNum = position%50;
      for (size_t i = 0; i < 50; i++)
      {
        if(current->data[i+1] == NULL)
        {
          tempEle1 = current->data[i];
          nextFree = i+1;
          break;
        }
        if (i == 48)
        {
          tempEle1 = current->data[49];
          filled = true;
          break;
        }
      }
      size_t i = 49;
      while (i > nodeNum)
      {
        current->data[i] = current->data[i-1];
        i--;
      }
      current->data[nodeNum] = ele;
      if (!filled)
      {
        //test to see if this is redundant
        current->data[nextFree] = tempEle1;
        return;
      }

      if (current->next == NULL)
      {
        node* foo = new node;
        foo->previous = current;
        current->next = foo;
        foo->next = NULL;
        current = foo;
        newArray();
        foo->data[0] = tempEle1;
        tail = foo;
        return;
      }

      filled = false;
      current=current->next;
      while (true)
      {
        filled = false;
        for (size_t i = 0; i < 50; i++)
        {
          if(current->data[i+1] == NULL)
          {
            tempEle2 = current->data[i];
            nextFree = i+1;
            break;
          }
          if (i == 48)
          {
            tempEle2 = current->data[49];
            filled = true;
            break;
          }
        }
        if (!filled)
        {
          for (size_t i = 49; i > 0; i--)
          {
            current->data[i] = current->data[i-1];
          }
          current->data[0] = tempEle1;
          current->data[nextFree] = tempEle2;
          return;
        }
        for (size_t i = 49; i > 0; i--)
        {
          current->data[i] = current->data[i-1];
        }
        current->data[0] = tempEle1;
        tempEle1 = tempEle2;

        if (current->next == NULL)
        {
          std:: cout <<"hey ooo\n\n";
          node* foo = new node;
          foo->previous = current;
          current->next = foo;
          foo->next = NULL;
          current = foo;
          newArray();
          foo->data[0] = tempEle1;
          tail = foo;
          return;
        }
        current = current->next;
      }

  }

}// end of insert



 //-----------------------------------------------------
 //push_back

 template <typename X>
   void CDAL<X> :: push_back(X ele)
   {
     if (head == NULL)
     {
       node* foo = new node;
       current = foo;
       newArray();
       foo->data[0] = ele;
       foo->next = tail;
       foo->previous = NULL;
       head = foo;
       tail = head;
       return;
     }
     current = tail;
     if (current->data[49] != NULL)
     {
       node* foo = new node;
       foo->previous = current;
       current->next = foo;
       foo->next = NULL;
       current = foo;
       newArray();
       foo->data[0] = ele;
       tail = foo;
       return;

     }
     for (size_t i = 0; i < 50; i++)
     {
       if (current->data[i] == NULL)
       {
         current->data[i]  = ele;
         break;
       }
     }

   } // end of push back


 //-----------------------------------------------------
//push_front
 template <typename X>
   void CDAL<X> :: push_front(X ele)
   {
     insert(ele, 0);
   }

 //-----------------------------------------------------
//replace

template<typename X>
  X CDAL<X> :: replace(X ele, size_t position)
  {
    X tempEle;
    if (head==NULL)
    {
        std:: cout << "Error, cannot replace, list is empty\n";
        return NULL;
    }
    current = head;
    size_t nodeNum = position/50;
    for(size_t i = 0; i < nodeNum; i++)
      current = current->next;
    nodeNum = position%50;
    tempEle = current->data[nodeNum];
    current->data[nodeNum] = ele;
    return tempEle;
  }//end of replace

//-----------------------------------------------------
//remove
 template<typename X>
   X CDAL<X>:: remove (size_t position)
   {
     if (head == NULL)
     {
       std:: cout << "Error cannot remove from an empty list\n";
       return NULL;
     }

     X returnEle;
     size_t nodeNum = position/50;
     current = head;
     for (size_t i =0; i < nodeNum; i++) current = current->next;
     nodeNum = position%50;
     returnEle = current->data[nodeNum];

     for (size_t i = nodeNum; i < 49; i++)
     {
       current->data[i] = current->data[i+1];
     }

        if (current->next == NULL) return returnEle;
        current = current->next;
     while(true)
     {
       current->previous->data[49] = current->data[0];
       for (size_t i = 0; i < 49; i++)
       {
         current->data[i] = current->data[i+1];
       }
       if (current->next == NULL) return returnEle;
       current = current->next;
     }



   }//end of remove

//-----------------------------------------------------
//pop_back

 template<typename X>
   X CDAL<X>::pop_back()
   {
     if (head == NULL)
     {
       std:: cout << "Error cannot pop, empty list\n";
       return NULL;
     }
     current = tail;
     X tempEle;
     for (size_t i = 0; i < 49; i++)
     {
       if (current->data[i] == NULL)
       {
         tempEle = current->data[i-1];
         current->data[i-1] = NULL;
         break;
       }
     }
     return tempEle;
   }


 //-----------------------------------------------------
//pop_front

 template<typename X>
   X CDAL<X>:: pop_front()
   {
     remove(0);
   }

//-----------------------------------------
//item_at

template<typename X>
X CDAL<X>::  item_at (size_t position)
{
  if (head == NULL)
  {
    std:: cout << "Error cannot get item in empty list\n";
    return NULL;
  }
  size_t nodeNum = position/50;
  current = head;
  for (size_t i =0; i < nodeNum; i++) current = current->next;
  nodeNum = position%50;
  return current->data[nodeNum];
}


 //-----------------------------------------
//peek_back
 template <typename X>
   X CDAL<X>:: peek_back()
   {
     if (head == NULL)
     {
       std:: cout << "Error cannot peek, empty list\n";
       return NULL;
     }

    current = tail;
    for (size_t i = 0; i < 50; i++)
    {
      if (current->data[i] == NULL)
      {
        return current->data[i-1];
      }
    }

   }

 //-----------------------------------------
//peek_front
 template <typename X>
   X CDAL<X>:: peek_front()
   {
     if (head == NULL)
     {
       std:: cout << "Error cannot peek, empty list";
       return NULL;
     }
     return head->data[0];
   }


 //-----------------------------------------
//is_empty
template <typename X>
  bool CDAL<X>::is_empty()
  {
    if (head == NULL) return true;
    else if (head->data[0] == NULL) return true;
    else return false;
  }


//-----------------------------------------
//is_full
 template <typename X>
   bool CDAL<X>:: is_full()
   {
     return false;
   }


 //-----------------------------------------
//length
 template <typename X>
   size_t CDAL<X>:: length()
   {
     if (is_empty()) return 0;
     size_t len = 0;
     current = head;
    while (true)
    {
      for (size_t i = 0; i < 50; i++)
              if(current->data[i] != NULL) len++;
      if (current->next!= NULL) current = current->next;
      else break;
    }
    return len;
   }

 //-----------------------------------------
//clear
template <typename X>
  void CDAL<X>:: clear()
  {
    current = head;
    while (true)
    {
      node* delPtr = current;
      delete delPtr;
      if (current->next!= NULL) current = current->next;
      else break;
    }

  }


//---------------------------------------------
// contains
 template<typename X>
   bool CDAL<X>::  contains(X element, bool contains)
   {
     //needs to be coded
     return false;
   }


//---------------------------------------------
// print
 template <typename X>
 void CDAL<X>:: print (std::ostream& stream)
 {
   if (is_empty())
   {
     std:: cout << "<empty list>";
      return;
    }
   current = head;
   while (true)
   {
     for (size_t i = 0; i < 50; i++)
     {
       if (current->data[i]!= NULL) stream << "[" << current->data[i] << "],";
     }
     if (current->next != NULL) current = current->next;
     else break;
   }
 }

//---------------------------------------------
// contents
 template <typename X>
   X* CDAL<X>:: contents()
   {
     if (is_empty())
     {
       std:: cout << "Error, empty list\n";
       return NULL;
     }
     X tmpArr[length()];
     size_t nextele = 0;
     while(true)
     {
       for (size_t i = 0; i < 50; i++)
       {
         if (current->data[i]!= NULL)
         {
           tmpArr[nextele] = current->data[i];
           nextele++;
         }
       }
       if (current->next != NULL) current = current->next;
       else break;
     }
     return tmpArr;

   }
 //-------------------------------
 //Destructor
 template <typename X>
   CDAL<X>::~CDAL()
    {
    //  clear();
    }

//===========================================
//END OF SDAL.h
}

#endif
