class solution{
	public:
		node *InsertIntoTail(int data){
			node *last=new node(data);
			if(head==NULL){
				head->next=last;
			}
			else{
				node *temp=new node();
				temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=last;
			}
			return head;
		}
	};
