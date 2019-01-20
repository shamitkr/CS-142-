#include <iostream>
using namespace std;

                               // Ignoring Generic Programme 

class Node{
    public:
                               // defining data 
    int data;
                               // Pointer to the next and previous Node
    Node * next;
	Node * prev;
                               // Construct that makes the ptr to NULL
    Node(){
        next = NULL;
	prev = NULL;
    }

};

class LinkedList{
                                // Head and Circles inside linked with each other
    public:
                                // Head -> Node type ptr
    Node * head;
    Node * tail;

                                // Constructor
    LinkedList(){
        head = NULL;
        tail = NULL;
    } 
                                // Circles inside linked with each other
                                // Rules how circles will be linked

                                // Inserting
    void insert(int value){
                                // If 1st Node is added
       Node * temp = new Node; 
                                // Insert value in the node
       temp->data = value;
                                // 1st Node only.
       if(head == NULL){
            head = temp;
       }
                                // Any other Node only.
       else{
            tail->next = temp;
		temp -> prev = tail;
       }
       tail = temp;
    } 

    void insertAt(int pos, int value){
	                         // Create a node
        Node * temp = new Node;
        temp -> data = value;
                                 // Reach the place before the pos
        Node * current = head;
	                         // Update the code for 1st position
	if (pos==1){
		temp -> next = current;
		current -> prev = temp;
		head = temp;
	}	
	else{
		int i =1;
		while(i < pos-1){
			if(current -> next == NULL){
				cout<<"Linked List does not have that many elements"<<endl;
				break;
			}
			else{
			i++;
			current = current->next;
			}
		}
		if(current -> next != NULL){
		                   // Moving ptrs like magic ! if not head
		temp->next = current->next;
		current->next = temp;
		temp -> prev = current;
		temp -> next -> prev = temp;
		}
	}
    }

                                   // Deletion of last element
    void delet(){
                                  // store the tail in temp
        Node * temp = tail;
                                  // before tail has to point to null
        Node * current = head;
        while(current->next != tail){
            current = current->next;
        }
        current->next = NULL; 

                                 // updating tail
        tail = current;
                                // deleting temp
         delete temp;
    }
	void deleteat(int pos){
		                //storing data of the head
		Node * current = head ;
		                //for 1st position
		if(pos==1){
			head=current->next;
			current -> next -> prev = NULL;
			delete current;
		}
		else{
			         //finding twh position to delete
			int i=1;
			while(i<pos-1)
				{
				if(current -> next == NULL){
					cout<<"Linked List does not have that many elements"<<endl;
					break;
				}
				else{
				i++;
				current  = current-> next;
				}
			}
			if(current -> next != NULL){
				//storing the position to delete
				Node * del = current -> next;
				//pointing previous circle to next of the del(that we want to delete circle)
				current -> next = del -> next;
				current -> next -> prev = current;
				delete del;
			}
		}	
      }
	                        //count
	void count(){
	Node * current = head;
	int count=0;
        while(current != NULL){
            count++;
            current = current->next;
        }
        cout <<"Linked list have "<<count<<" elements"<< endl;
    }
                               // Displaying 
    void display(){
        Node * current = head;
	Node * last = tail;
	cout<<"print in order:"<<endl;
        while(current != NULL){
            cout << current->data << "->";
            current = current->next;
        }
        cout <<" NULL"<< endl;
	cout<<"print in reverse order"<<endl;
	while(last != NULL){
		cout<<last->data<<"->";
		last=last->prev;
	}
	cout<<"NULL"<<endl;
    }
};


int main(){
    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
	l1.insert(6);
	l1.display();
	l1.insertAt(3,7);
	l1.display();
	l1.delet();
    	l1.display();
    l1.deleteat(4);
    l1.display();
    l1.count();
    return 0;
}



