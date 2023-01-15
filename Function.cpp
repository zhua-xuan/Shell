#include<iostream>
using namespace std;
#include"Function.h"

int list_tail_insert(Node* list_head, int var) {
	Node *tail = list_head;
	Node *p = new Node;
	p->var = var;
	p->link = NULL;
	if (list_head == NULL) list_head = p;
	else {
		for (; tail->link != NULL; tail = tail->link);
		tail->link = p;
	}return 0;
}

Node* list_head_insert(Node* list_head, int var) {
	Node *p = new Node;
	p->var = var;
	p->link = list_head;
	list_head = p;
	return list_head;
}

Node* list_specific_insert(Node* list_head, int location, int var) {
	Node *current = list_head;  
	int j = 1;
	if (location == 1){
		Node *m = new Node;
		m->var = var;
		m->link = current;
		list_head = m;
	}
	else{
		while (j < location - 1 && current->link != NULL){
			current = current->link;
			j++;
		}
		if (j == location - 1){ 
			Node *p = new Node;
			p->var = var;
			p->link = current->link;
			current->link = p;
		}
		else if (current->link == NULL){ 
			Node *n = new Node;
			n->var = var;
			n->link = current->link;
			current->link = n;
		}
		else cout << "not exist node" << location;
	}
	return list_head;
}

void print_list(Node* list_head) {
	if (!list_head) cout << "List is empty" << endl;
	else{
		Node *p = new Node;
		p = list_head;
		while (p){
			cout << p->var << " ";
			p = p->link;
		}
		cout << endl;
	}
}
int flag=0;    
void reverse_print_list(Node* list_head) {
	if (list_head!= NULL)
	{
		flag++;
		reverse_print_list(list_head->link);
		cout << list_head->var << " ";
		flag--;
		if (!flag) cout << endl;
	}
}

void change_specific_var(Node* list_head, int old_var, int new_var) {
	Node *p = list_head;
	for (; p != NULL; p = p->link)
		if (p->var == old_var) 
			p->var = new_var;
}

Node* del_specific_var(Node* list_head, int del_var) {
	while (del_var == list_head->var){ 
		Node *current = list_head;
		list_head = list_head->link;
		delete(current);
	}
	Node *head = list_head;
	while (head != NULL&&head->link != NULL){
		if (head->link->var == del_var){
			Node *p = head->link;
			head->link = head->link->link;
			delete(p);
		}
		else head = head->link;
	}return list_head;
}

Node *list_sort_insert(Node *head, Node *p){
	if (p->var < head->var){ 
		p->link = head;
		head = p;
		return head;
	}
	Node *cur = head;
	Node *prev;
	while (cur){
		if (p->var < cur->var) break;
		prev = cur;
		cur = cur->link;
	}
	p->link = prev->link;
	prev->link = p;
	return head;
}

Node* sort(Node* list_head) {
	if (list_head == NULL) return NULL;
	if (list_head->link == NULL) return list_head;
	Node *current = list_head->link;
	list_head->link = NULL;
	while (current){
		Node *previous = current;
		current = current->link;
		list_head = list_sort_insert(list_head, previous);
	}return list_head;
}

Tree_Node* insert(Tree_Node* T, int x) {
	Tree_Node *p = new Tree_Node;
	p->var = x;
	p->lchild = NULL;
	p->rchild = NULL;
	if (!T) T = p;
	else{
		Tree_Node *m = T;
		while (m){
			if (x > m->var) {
				if (!m->rchild) {
					m->rchild = p;
					break;
				}
				else m = m->rchild;
			}
			else{
				if (!m->lchild){
					m->lchild = p;
					break;
				}
				else m = m->lchild;
			}
		}
	}return T;
}

void postorder(Tree_Node* T) {
	if (T){
		postorder(T->lchild);
		postorder(T->rchild);
		cout << T->var << " ";
	}
}
