#include<iostream>
using namespace std;

class Node{

	public: 
	              //declaring data
	int data;
	
	              //pointer to next Node
	Node * next;
	
	              //construction to make the ptr to NULL
	Node(){
		next = NULL;
	}
	
};

class Linkedlist{
	              // circles and heads inside linked with each other
	
	public:
	              //head is equal to circle type ptr
	Node * head;
	 	      //not relevant
        Node * tail; 
	
	              //creating linked list
	Linkedlist(){
		head = NULL;
	}
	
	              //circle inside linked with each other
	              //rules how circles will be linked
	
	              //inserting void and declaring int function
	void insert( int value){
		      //if first Node is added then
		Node * temp = new Node;
		
		      //inserting data in nodes
		temp -> data = value;
		
		     //only first node 
		if(head == NULL){
		     // tail equal to temp	
                head = temp;
              	}
		     //if any other node present
		else{
			tail -> next = temp;
		     // tail equal to temp
		}
		tail = temp;
	}
	
	void insertAt(int pos, int value){
		
		      //creating node
		Node * temp = new Node;
		temp -> data = value;
		     // using if statement
		if(pos ==1){
			temp -> next = head;
			head = temp;
		}
		else{
			
			Node * current = head;
			int i=1;
			while (i< pos-1){
				i++;
				current = current -> next;
			}
			//moving the ptrs
			temp -> next = current -> next;
			current -> next = temp;
		}
	}
	
	                //deleting 
	void delet(){
		        //store tail in temp
		Node * temp = tail;
		
		        //before tail has to point to null
		Node * current = head;
		while(current->next != tail){
			current = current -> next;
		} 
		current -> next = NULL;
		        // updating the tail
		current = tail;
		        //deleting temp
		delete temp;
	}
	
	             //delete at certain position
	void deleteAt(int pos){
	
		Node * current = head;
		if (pos ==1){
			head = current -> next;
			delete current;		
		}	
		
		else{
			
			int i=0;
			while(i < pos-2){
				i++;
				current = current -> next;
			}
			
	            // declaring temp for that pos
			Node * temp = current ->next;
		    //joining current to next of temp
			current -> next = temp -> next;
			delete temp;
		}
	}
	
	void display(){
		Node * current = head;
		
		while(current != NULL){
			cout << current -> data << "->";
			current = current -> next;
		} 
		cout << "null" <<endl;
	}
	
	void CountItems(){
		
		Node *current = head;
		int i=1;
		while(current != NULL){
			i++;
			current= current->next;
		}
		cout<<"Number of node "<< i -1<<endl;
	}
};

int main(){
	Linkedlist l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.display();
	l1.delet();
	l1.display();
	l1.insertAt(2,0);
	l1.display();
	l1.deleteAt(2);
	l1.display();
	l1.CountItems();
	return 0;
}
