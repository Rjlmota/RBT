#include <stack>
#include "node.h"
using namespace std;


class tree {
	private:  
		node* root;

	public:

		tree(); //Constructor

		~tree(); //Destructor

		void eraseData(node *localRoot); //Function used by destructor
		node* search(int key); // Function to search for node.
		node* search(int key, node*& previous, char &direction); // Used by removal method.
		void insert(int key); // Function to insert a node.
		void goThrough(); // Function to run through the tree.
		void upper(node* localRoot); // Function used to run through the tree.
		void remove(int key); // Function for removal of node.
		void printTree(); // Function to print tree.

};


tree::tree(){
	root = NULL;
}

tree::~tree(){
	eraseData(root);
}

void tree::eraseData(node* localRoot){
	//Adapt to RBT.
}

node* tree::search(int key){
	node* currentP = root;
	while(currentP->getKey() != key){
		if(key < currentP->getKey())
			currentP = currentP->leftChild;
		else
			currentP = currentP->rightChild;
		if(currentP == NULL)
			return NULL;
	}
	return currentP;
}

void tree::insert(int key){
	//Adapt to RBT.
}

void tree::goThrough(){
	upper(root);
}

void tree::upper(node* localRoot){
	if(localRoot != NULL){
		upper(localRoot->leftChild);
		cout << localRoot->getKey() << " ";
		upper(localRoot->rightChild);

	}
}

void tree::printTree(){
      stack<node*> pilhaGlobal;
      pilhaGlobal.push(root);
      int nVazios = 32;
      bool linhaVazia = false;

      cout << endl;
      while(linhaVazia==false)
         {
         stack<node*> pilhaLocal;
         linhaVazia = true;

         for(int j=0; j<nVazios; j++)
            cout << ' ';

         while(pilhaGlobal.empty()==false)
            {
            node* temp = pilhaGlobal.top();
            pilhaGlobal.pop();
            if(temp != NULL)
               {
               cout << temp->getKey();
               pilhaLocal.push(temp->leftChild);
               pilhaLocal.push(temp->rightChild);

               if(temp->leftChild != NULL || temp->rightChild != NULL)
                  linhaVazia = false;
               }
            else
               {
               cout << "--";
               pilhaLocal.push(NULL);
               pilhaLocal.push(NULL);
               }
            for(int j=0; j<nVazios*2-2; j++)
               cout << ' ';
            }  
         cout << endl;
         nVazios = nVazios/2;
         while(pilhaLocal.empty()==false)
            {
            pilhaGlobal.push( pilhaLocal.top() );
            pilhaLocal.pop();
            }
         }  

      cout << endl;
}  