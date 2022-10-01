#include <iostream>
using namespace std;
class Node {
public:
	int coef;
    int grado;
	Node* next;

	Node()
	{
		coef = 0;
        grado = 0;
		next = NULL;
	}

	Node(int coef_, int grado_)
	{
		this->coef = coef_;
		this->grado = grado_;
	}
};

class polinomio {
	Node* head;

public:
	polinomio() { head = NULL; }

	void insert(int, int);
	void imprimirLista();
    void add(int , int );
    void adition(int , int);
};

void polinomio::insert(int coef_, int grado_)
{
	Node* newNode = new Node(coef_, grado_);

	if (head == NULL) {
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next != NULL) {

	    temp = temp->next;
	}

	temp->next = newNode;
}

void polinomio::imprimirLista()
{
	Node* temp = head;

	if (head == NULL) {
		cout << "Lista vacia" << endl;
		return;
	}

    else
    {
        while (temp != NULL) {
            cout << temp->coef << "x" << temp->grado <<"\t";
            temp = temp->next;
	    }
    }
}

void polinomio::add(int coef_, int grado_)
{
    Node* newNode = new Node(coef_, grado_);

	if (head == NULL) {
		head = newNode;
		return;
	}

	Node* temp = head;
    
    if (coef_ > head->grado)
    {
        newNode->next=head;
        head = newNode;
		return;
    }
    else if (head->next==NULL)
    {
        head->next=newNode;
        return;
    }
    
    Node* temp2 = temp;
    temp=temp->next;
    
	while (temp->next != NULL) {
        if (newNode->grado > temp->grado && newNode->grado < temp2->grado )
        {
            temp2->next = newNode;
            newNode->next = temp;
            return;
        }
        temp2 = temp;
        temp = temp->next;
	}
    if (newNode->grado<temp2->grado && newNode->grado > temp->grado)
    {
        temp2->next = newNode;
        newNode->next = temp;
    }
    else
    {
        temp->next = newNode;
    }
}

void polinomio::adition(int coef_, int grado_)
{
    Node* newNode = new Node(coef_, grado_);

	if (head == NULL) {
		head = newNode;
		return;
	}

	Node* temp = head;
    Node* temp2;
	while (temp->next != NULL && grado_!=temp->grado) {
        temp2 = temp;
	    temp = temp->next;
	}
    if (temp->grado=grado_)
    {
        temp->coef = temp->coef + coef_;
        if (temp->coef == 0)
        {
            temp2->next = temp->next;
            return;
        }
        return;
    }
    else
    {
        temp->next = newNode;
    }
}

int main()
{
	polinomio list;

	list.add(3,3);
    list.add(4,1);
    list.add(1,2);
    list.add(3,4);
    list.add(-4,7);
    list.add(-4,9);
    list.add(4,11);

	cout << "Elementos de la lista: ";

	list.imprimirLista();

    cout << "\t";
	
	return 0;
}