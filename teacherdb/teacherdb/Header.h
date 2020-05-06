#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
vector<string> splitStrings(string str, char dl)
{
	string word = "";
	int num = 0;
	str = str + dl;
	int l = str.size();
	vector<string> substr_list;
	for (int i = 0; i < l; i++) {
		if (str[i] != dl)
			word = word + str[i];

		else {
			if ((int)word.size() != 0)
				substr_list.push_back(word);
			word = "";
		}
	}
	return substr_list;
}
class teacher
{
public:
	string tid;
	string name;
	string phno;
	string dept;
	string Buf;
	char buf[100];
};
istream& operator >> (istream& in, teacher& t)
{
	cout << "Enter tid:-";
	in >> t.tid;
	cout << "Enter teacher name:-";
	in >> t.name;
	cout << "Enter phno.:-";
	in >> t.phno;
	cout << "Enter dept.:-";
	in >> t.dept;
	return in;
}
ostream& operator << (ostream& out, teacher& t)
{
	out << t.tid << "\t" << t.name << "\t" << t.phno << "\t" << t.dept << "\t";
	return out;
}
class node
{
public:
	teacher value[4];
	node* child[4];
	node* next, * per;
	node* parent;
	int size;
	node();
};
class btree
{
public:
	node* head;
	int flag, flage, ds;
	string st[1000];
	string error = "";
	void insert(teacher key);
	void search(teacher key);
	btree del(teacher key);
	void display();
	void read();
	void write();
	btree();
private:
	node* split(node* n);
	node* findlevel(teacher key, node* n);
};
node::node() {
	size = 4;
	for (int i = 0; i < size; i++) {
		value[i].tid = "";
		value[i].name = "";
		value[i].phno = "";
		value[i].dept = "";
		child[i] = NULL;
	}
	size = 0;
	next = NULL;
	per = NULL;
	parent = NULL;
}
btree::btree() {
	head = NULL;
	flag = 0;
	flage = 0;
	ds = 0;
}
void btree::insert(teacher key) {
	error = "";
	if (head == NULL) {
		head = new node;
		head->value[head->size] = key;
		head->size++;
		return;
	}
	node* n = findlevel(key, head);
	int i;

	for (i = 0; i < n->size; i++) {
		if (key.tid == n->value[i].tid) {
			if (key.phno < n->value[i].phno)
				break;
			else if (key.phno > n->value[i].phno)
				continue;
			else {
				error = "already exits";
				return;
			}

		}
		if (key.tid < n->value[i].tid) {
			break;
		}
	}
	if (i == n->size) {
		n->value[i] = key;
		n->size++;
	}
	else {
		teacher temp;
		for (; i < n->size; i++) {
			temp = n->value[i];
			n->value[i] = key;
			key = temp;
		}
		n->value[i] = key;
		n->size++;
	}
	if (n->size > 3) {
		node* x = split(n);
	}
	return;
}
node* btree::findlevel(teacher key, node* n) {
	node* ptr = n;
	int i;
	for (i = 0; i < ptr->size; i++) {
		if (key.tid < ptr->value[i].tid) {
			if (ptr->child[i] != NULL) {
				return(findlevel(key, ptr->child[i]));
			}
			else {
				return ptr;
			}
		}
	}
	if (i == ptr->size && key.tid > ptr->value[i].tid) {
		if (ptr->child[i] != NULL) {
			return(findlevel(key, ptr->child[i]));
		}
		else
		{
			return ptr;
		}
	}
	return ptr;
}
btree btree::del(teacher key) {
	error = "";
	node* n = head;
	int x = 0;
	btree b;
	teacher a[1000];
	while (n->child[0] != NULL) {
		n = n->child[0];

	}
	while (n != NULL) {

		for (int i = 0; i < n->size; i++) {
			if ((key.tid.compare(n->value[i].tid)))
				a[x++] = n->value[i];
			else {
				flage = 1;
			}
		}
		n = n->next;
	}
	if (flage == 0) {
		error="element not found\n";
		b.head = head;
		return b;
	}
	for (int i = 0; i <= x; i++) {
		b.insert(a[i]);
		b.flage = 1;
	}
	return b;
}

node* btree::split(node* n) {
	int m = (n->size / 2);
	int x = 0;
	node* ptr;
	if (n->parent == NULL) {
		head = new node;
		ptr = head;
		ptr->value[x] = n->value[m];
		ptr->size++;
	}
	else {
		ptr = n->parent;
		for (x = 0; x < ptr->size; x++) {
			if (n->value[m].tid < ptr->value[x].tid) {
				break;
			}
		}
		teacher temp = n->value[m];
		teacher temp2;
		node* ad1, * ad2;
		ad1 = ptr->child[x];
		int y = x;
		for (; x < ptr->size; x++) {
			temp2 = ptr->value[x];
			ptr->value[x] = temp;
			temp = temp2;

			ad2 = ptr->child[x + 1];
			ptr->child[x + 1] = ad1;
			ad1 = ad2;
		}
		ptr->value[x] = temp;
		ptr->child[x + 1] = ad1;
		x = y;
		ptr->size++;
	}
	node* c1 = new node;
	node* c2 = new node;
	ptr->child[x] = c1;
	ptr->child[x + 1] = c2;
	c1->next = c2;
	c2->per = c1;
	if (x != 0) {
		if (ptr->child[x - 1] != NULL) {
			ptr->child[x - 1]->next = c1;
			c1->per = ptr->child[x - 1];
		}
	}

	if (ptr->child[x + 2] != NULL) {
		c2->next = ptr->child[x + 2];
		ptr->child[x + 2]->per = c2;
	}
	if (n->child[0] == NULL) {
		for (int i = 0; i < m; i++) {
			c1->value[i] = n->value[i];
			c1->size++;
		}
		for (int i = m, x = 0; i < n->size; i++, x++) {
			c2->value[x] = n->value[i];
			c2->size++;
		}
		if (n->next != NULL) {
			c2->next = n->next;
		}
		if (n->per != NULL)
			n->per->next = c1;
	}
	else {
		c1->child[0] = n->child[0];
		c1->child[0]->parent = c1;
		for (int i = 0; i < m; i++) {
			c1->value[i] = n->value[i];
			c1->child[i + 1] = n->child[i + 1];
			c1->child[i + 1]->parent = c1;
			c1->size++;
		}
		c2->child[0] = n->child[m + 1];
		c2->child[0]->parent = c2;
		for (int i = m + 1, x = 0; i < n->size; i++, x++) {
			c2->value[x] = n->value[i];
			c2->child[x + 1] = n->child[i + 1];
			c2->child[x + 1]->parent = c2;
			c2->size++;
		}

	}


	c1->parent = ptr;
	c2->parent = ptr;
	if (ptr->size > 3) {
		ptr = split(ptr);
	}

	return c2;
}
void btree::display() {
	node* n = head;
	if (n == NULL) {
		error = "no element persent";
		return;
	}
	st[ds++] = "tid\tNAME\tphno.\tDEPT\t \n";
	while (n->child[0] != NULL) {
		n = n->child[0];

	}
	while (n != NULL) {

		for (int i = 0; i < n->size; i++) {
			if (n->value[i].tid == "") {
				continue;
			}
			st[ds++] = n->value[i].tid + "\t" + n->value[i].name + "\t" + n->value[i].phno + "\t" + n->value[i].dept + "\t\n";
		}
		n = n->next;
	}
	return;
}
void btree::search(teacher key) {
	error = "";
	node* ptr = head;
	cout << key.tid;
	ds = 0;
	st[ds++] = "tid\tNAME\tphno.\tDEPT\t\n";
	int x = 0;
	while (ptr != NULL) {

		if (ptr->child[0] == NULL) {
			for (int i = 0; i < ptr->size; i++) {
				cout << "for1";
				if ((key.tid) == (ptr->value[i].tid)) {
					flag = 1;
					st[ds++] = ptr->value[i].tid + "\t" + ptr->value[i].name + "\t" + ptr->value[i].phno + "\t" + ptr->value[i].dept + "\t\n";
					return;
				}
			}
			break;
		}
		else
		{
			int i;
			for (i = 0; i < ptr->size; i++) {
				cout << "for2";
				if (key.tid < ptr->value[i].tid) {
					break;
				}
			}
			ptr = ptr->child[i];
			cout << x++ << "\t";
			cout << "->";
		}

	}

	error="tid not found";
	return;
}
void btree::write() {
	node* n = head;
	ds = 0;
	for (int i = 0; i < 1000; i++)
	{
		st[i] = "";
	}
	while (n->child[0] != NULL) {
		n = n->child[0];

	}
	while (n != NULL) {

		for (int i = 0; i < n->size; i++) {
			if (n->value[i].tid == "")
				continue;
			st[ds++] = n->value[i].tid + "|" + n->value[i].name + "|" + n->value[i].phno + "|" + n->value[i].dept + "|";
		}
		n = n->next;
	}
	return;
}
void btree::read() {
	char dl = '|';
	teacher t;
	for (int i = 0; i < ds; i++) {
		vector<string> res = splitStrings(st[i], dl);
		t.tid = res[0];
		t.name = res[1];
		t.phno = res[2];
		t.dept = res[3];
		int temp = ds;
		insert(t);
		ds = temp;
	}
}