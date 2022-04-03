#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class node{
	public:
		int data;
		node *next;
		
		node(int data){
			this->data=data;
			next=NULL;
		}
};

class linkedListe{
	private:
		node *header;
		node *tail;
		int size;
	public:
		linkedListe(){
			header=NULL;
			tail=NULL;
			size=0;
		}
		node *getHeader(){
			return header;
		}
		void setHeader(node *llist){
			this->header=llist;
		}
		int getSize(){
			return size;
		}
		void append(int data){
			node *n = new node(data);
			if(header == NULL){
				header=n;
				tail=n;
			}
			else{
				tail->next=n;
				tail=n;
			}
			size++;
		}
		void toString(){
			node *temp;
			temp=header;
			int i=0;
			while(temp!=NULL){
				cout << "Data["<< i << "]=" << temp->data << "\n";
				i++;
				temp=temp->next;
			}
			cout << endl;
		}
		void remove_first(){
			if(header != NULL){
				node *temp=header;
				header=header->next;
				delete(temp);
				size--;
			}
		}
		void remove_last(){
			if(header->next == NULL){
				remove_first();
			}
			else if(header != NULL){
				node *cur=header;
				node *prev;
				while(cur->next != NULL){
					prev=cur;
					cur=cur->next;
				}
				tail=prev;
				prev->next=NULL;
				delete cur;
				size--;
			}
		}
		void removeAt(int);
};
		bool campare_lists(linkedListe *head1,linkedListe *head2){
			node *temp1=head1->getHeader(),*temp2=head2->getHeader();
			while(temp1 && temp2){
				if(temp1->data != temp2->data){
					delete temp1;
					delete temp2;
					return false;
				}
				temp1=temp1->next;
				temp2=temp2->next;
			}
			delete temp1;
			delete temp2;
			return true;
		}
		
		linkedListe *ConcatTwoLinkeListe(linkedListe *head1,linkedListe *head2){
			if(head1->getSize()==0 && head2->getSize()==0){
				return head1;
			}
			else if(head1->getSize()>0 && head2->getSize()==0){
				return head1;
			}
			else if(head1->getSize()==0 && head2->getSize()>0){
				return head2;
			}
			else{
				node *temp1=head1->getHeader(),*temp2=head2->getHeader();
				linkedListe *NewLinkListe=new linkedListe();
	
				while(temp1){
					NewLinkListe->append(temp1->data);
					temp1=temp1->next;
				}
				while(temp2){
					NewLinkListe->append(temp2->data);
					temp2=temp2->next;
				}
				return  NewLinkListe;
			}
		}
		
		node *reverseList(node *llist){
			if(llist==NULL || llist->next==NULL)
				return llist;
			node* cur=llist;
			node *next,*prev=NULL;
			
			while(cur != NULL){
				next=cur->next;
				cur->next=prev;
				prev=cur;
				cur=next;
			}
			return prev;
		}
		void linkedListe::removeAt(int pos){
			if(pos<0 || pos>this->getSize())
				return;
			else if(pos==0)
				this->remove_first();
			else if(pos==this->getSize())
				this->remove_last();
			else if(this->getHeader() != NULL){
				node *prev;
				node *cur=header;
				for(int i=0;i<this->getSize();i++){
					prev=cur;
					cur=cur->next;
				}
				prev->next=cur->next;
				delete cur;
				size--;
			}
		}
int main(){
	linkedListe *l=new linkedListe();
	l->append(0);
	l->append(1);
	l->append(2);
	l->append(48);
	l->append(48);
	l->append(48);
	l->append(9845);
	l->append(798);
	l->append(9856);
	l->append(848);
	l->append(652);
	l->append(854);
	l->append(48);
	l->append(120);
	l->append(48);
	l->append(74);
	
	linkedListe *y=new linkedListe();
	y->append(188);
	y->append(1);
	
	l->remove_first();
	l->remove_last();
	
//	l->toString();
//	cout << campare_lists(l,l) <<endl;
//	l->toString();
//	y->toString();
	linkedListe *a=new linkedListe();
	a->append(17);
	a->append(120);
	a->append(87);
	a->append(987);

	
	linkedListe *o=ConcatTwoLinkeListe(l,l);
	o=ConcatTwoLinkeListe(o,o);
	o=ConcatTwoLinkeListe(o,o);
	o=ConcatTwoLinkeListe(o,o);
//	o->toString();
//	cout << o->getSize() <<endl;
//	cout << "before";
//	a->toString();
//	cout << "after";
	a->setHeader(reverseList(a->getHeader()));
	a->toString();
//	a->removeAt(1);
	a->toString();
	return 0;
}
