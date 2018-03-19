#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct PolyNode * PtrToNode;
struct PolyNode{
//	int len;
	int coe;
	int exp;
	PtrToNode next;
};
typedef PtrToNode List;

void Init(List head)
{
	int len;
	cin >> len;
	List ptr = head;
	head -> next = NULL;
	if ( !len )	return;
//	head -> len = len;
	for (int i = 0; i < len; i++) {
		List p = (List)malloc(sizeof(struct PolyNode));
		cin >> p -> coe;
		cin >> p -> exp;
		ptr -> next = p;
		ptr = p;
	}
	ptr -> next = NULL;
}

void showList(List head)
{
	if (NULL == head -> next) {
		cout << 0 << " " << 0;
		return;
	}
	bool first_flag = true;
	List ptr = head -> next;
	while(ptr) {
		if ( first_flag ) {
			cout << ptr -> coe << " " << ptr -> exp;
			first_flag = false;	
		}
		else if (ptr -> coe)	{ cout << " " << ptr -> coe << " " << ptr -> exp; }
		ptr = ptr -> next;
	}
}

void Attach(List p1, List p2)
{
	p1 -> coe = p2 -> coe;
	p1 -> exp = p2 -> exp;
}

void Attach(List p1, List p2, List p3)
{
	p3 -> coe = p1 -> coe + p2 -> coe;
	p3 -> exp = p1 -> exp; 	
}

List plusList(List h1,List h2)
{
	if ( !h1 -> next && !h2 -> next )	return NULL;
	else if ( !h1 -> next )	return h2;
	else if ( !h2 -> next )	return h1;
	List head,p1,p2,p3;
	p1 = h1 -> next;
	p2 = h2 -> next;
	head = (List)malloc(sizeof(struct PolyNode));
	List ptr = head;
	while(p1 && p2) {
		p3 = (List)malloc(sizeof(struct PolyNode));
		if(p1 -> exp == p2 -> exp)	{
			Attach(p1,p2,p3);
			p1 = p1 -> next;
			p2 = p2 -> next;
		}
		else if(p1 -> exp > p2 -> exp) {
			Attach(p3,p1);
			p1 = p1 -> next;
		}
		else {
			Attach(p3,p2);
			p2 = p2 -> next;
		}
		if(p3 -> coe != 0) {
			ptr -> next = p3;
			ptr = p3;	
		}
	}
	List p = (p1? p1 : p2);
	while(p) {
		p3 = (List)malloc(sizeof(struct PolyNode));
		Attach(p3,p);
		p = p -> next;
		ptr -> next = p3;
		ptr = p3;
	}
	ptr -> next = NULL;
	return head;
}

void Multiply(List p1, List p2, List head)
{
	List p3 = (List)malloc(sizeof(struct PolyNode));
	p3 -> coe = p1 -> coe * p2 -> coe;
	p3 -> exp = p1 -> exp + p2 -> exp;
	if ( NULL == head -> next ) {
		head -> next = p3;
		p3 -> next = NULL;
		return;
	}
	List p = head;
	List q = head -> next;
	while( q ) {
		if ( q -> exp == p3 -> exp ) {
			q -> coe += p3 -> coe;
			return;
		}
		else if ( q -> exp < p3 -> exp )	break;
		p = p -> next;
		q = q -> next;
	}
	p -> next = p3;
	p3 -> next = ( q? q : NULL);
}

List multiplyList(List h1, List h2)
{
	if ( !h1 -> next || !h2 -> next )	return NULL;
	List head = (List)malloc(sizeof(struct PolyNode));
	List res1 = (List)malloc(sizeof(struct PolyNode));
	List res2 = (List)malloc(sizeof(struct PolyNode));
	head -> next = NULL;
	res1 -> next = NULL;
	res2 -> next = NULL;
	List p1 = h1 -> next;
	List p2 = h2 -> next;
	while ( p2 ) {
		Multiply( p1, p2, res1 );
		p2 = p2 -> next;
	}
//	cout << "List 1 :" << endl;
//	showList(res1);
	p1 = p1 -> next;
	while ( p1 ) {
		p2 = h2 -> next;
		while ( p2 ) {
			Multiply( p1, p2, res2 );
			p2 = p2 -> next;
		}
		p1 = p1 -> next;
	}
//	cout << "List 2 :" << endl;
//	showList(res2);
	head = plusList(res1,res2);
	return head;
}

int main()
{
//	freopen("F://input.txt","r",stdin);
	List p1,p2,p3,p4;
	p1 = (List)malloc(sizeof(struct PolyNode));
	p2 = (List)malloc(sizeof(struct PolyNode));
	Init(p1);
	Init(p2);
	p3 = multiplyList(p1,p2);
	p4 = plusList(p1,p2);
	showList(p3);
	cout << endl;
	showList(p4);
	return 0;
}
