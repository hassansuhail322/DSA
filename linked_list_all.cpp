#include<iostream>
#include<stack>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
}*head;



Node* create_list(Node*head,int a[],int n)
{
    head=new Node;

    head->data=a[0];
    head->next=NULL;     // head->next=head;:: this is for circular linked list


    Node*p=head;
    Node*temp=NULL;

    for(int i=1;i<n;i++)
    {
        temp=new Node;
        temp->data=a[i];
        temp->next=NULL;             // :: this is for circualar linked list     temp->next=head;  
        p->next=temp;
        p=temp;
    }
   return head; 
}




void rev_list_stack(Node*p)
{

stack<Node*> st;
Node*temp=p;
while(temp)
{
    st.push(temp);
    temp=temp->next;
}
head=st.top();
st.pop();
head->next=NULL;
p=head;
while(!st.empty())
    {
        p->next=st.top();
        st.pop();
        p=p->next;
        p->next=NULL;
    }


}







void rev_list(Node *p)
{
    if (p->next==NULL)
    {
        head=p;
        return ;

    }
    rev_list(p->next);
    Node*temp=p->next;
    p->next=NULL;
    temp->next=p;

}





 void display(Node*p)
{
    while(p!=NULL)
    {
        cout<<p->data;
        p=p->next;
    }
}
    
//    do while loop is used for printing circrlar linked list 

void display (Node * p)
do
{
 cout<<p->data;
 p=p->next;
}
while(p!=head);
}




int  detect_loop(Node*fast)
 {  
    Node*slow=fast;
    while(fast && fast->next && slow)
    {
        slow=slow->next;
        fast=fast->next->next;
        if (fast==slow)
        {
            //delete_loop(head,fast);
            return 1;
        }
    }               
return 0;
 }




 void delete_loop(Node*temp,Node*fast)
 {
    while(1)
    {
        if(temp->next==fast->next)    // if this condition satisfy than fast->next is the starting point of the linked list;
        {
            fast->next=NULL;   
            break;
        }

        temp=temp->next;
        fast=fast->next;
    }   

 }

void move_last_node(Node*p)
{
    Node*temp=NULL;
    while(p->next!=NULL)
    {
        temp=p;
        p=p->next;

    }
    temp->next=NULL;
    p->next=head;
    head=p;
}



void sort_linked_list(Node*p)
{

 while(p->next!=NULL)
 {

     Node*temp=p->next;
     while(temp)
     {
         if (p->data>temp->data)
         {
             //swap(p->data,temp->data);
             int x=p->data;
             p->data=temp->data;
             temp->data=x;
         }
         temp=temp->next;
     }
     p=p->next;
 }

}

void  delete_duplicate(Node*p)
{
    while(p && p->next)
    {
        if (p->data==p->next->data)
        {
            p->next=p->next->next;
        }
        else
        {
            p=p->next;
        }

    }
}
 

Node* find_middle(Node* fast)
{
    Node*slow=fast;
    Node*temp;
    while(fast!=NULL && fast->next!=NULL)
    {
        temp=slow;
        fast=fast->next->next;
        slow =slow->next;
    }
    temp->next=NULL;

    return slow;
}






Node* merge_list(Node* first,Node*second)
{
    if ( first==NULL)
    {
        return second;
    }
    else if(second==NULL)
    {
        return first;
    }
        

Node*p,*third;

if (first->data < second->data)
{
    third=p=first;
    first=first->next;
    p->next=NULL;

}
else
{
    third=p=second;
    second=second->next;
    p->next=NULL;
}


while(first && second)
{
    if( first->data < second->data)
    {
        p->next=first;
        p=first;
        first=first->next;
        p->next=NULL;
    }
    else
    {
        p->next=second;
        p=second;
        second=second->next;
        p->next=NULL;

    }


}


if(first)
{
    p->next=first;
}
if(second)
{
    p->next=second;
}
return third;
}


Node* merge_sort(Node*start)
{
    if(start==NULL || start->next==NULL)
    {
        return start;
    }
Node*middle=find_middle(start);
Node*list1=merge_sort(start);
Node*list2=merge_sort(middle);

return merge_list(list1,list2);


}



Node* removeElements(Node* head, int val) {
        if(head==NULL)
        {
            return NULL;
        }
        Node *temp=new Node;
        temp->data=-1;
        temp->next=NULL;
        temp->next=head;
        head=temp;
        while(temp->next!=NULL)
        {
            if (temp->next->data==val)
            {
                temp->next=temp->next->next;
               // temp=temp->next;
                
            }
            else
            {
                temp=temp->next;
            }
            
            
        }
        
        return head->next;
    }



int main()
{
    int a[]={1,1,2,3,4,5,6};
 //  int *b{new int [3]{1,3,4}};
    int n=sizeof a/sizeof a[0];
   
   Node*first= create_list(first,a,n);
 //  Node*second= create_list(second,b,3);           //  This is second linked list
   //head=first;
   // rev_list(head);
   // rev_list_stack(head);

 // if(detect_loop(p))
 //         cout<<"This is a circrlar linked list:";
 //    else
 //     cout<<"This is not a circrlar linked list";


//move_last_node(head);
//sort_linked_list(head);
//delete_duplicate(head);

 // Node* middle= find_middle(first) ;     //  This function is used to find the fiddle of the linked list
// cout<< middle->data;
  
    //struct Node *p=head;
//   Node *third=merge_list(first,second);
  // Node*third=merge_sort(first);
  //  display(third);

//  display(first);
//  cout<<endl;

//     Node *rem=removeElements(first,1);
// display(rem);



return 0;
}








