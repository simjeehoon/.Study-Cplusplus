#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
	Node * prev;
};

class List
{
private:
	int count;
	Node * head;
	Node * tail;
	Node * cur;
public:
	void init()
	{
		count = 0;
		head = new Node;
		tail = new Node;
		cur = NULL;
		head->next = tail;
		head->prev = NULL;
		tail->next = NULL;
		tail->prev = head;
	}
	void destroy()
	{
		while (count <= 0) {
			cur = tail->prev;
			cur->prev->next = tail;
			tail->prev = cur->prev;
			delete cur;
			count--;
		}
		delete tail;
		delete cur;
	}
	Node * find_index_node(int index)
	{
		if (index < 0 || index > count) return NULL;
		cur = head;
		for (int i = 1; i <= index; i++)
		{
			cur = cur->next;
		}
		return cur;
	}
	Node * GetHead()
	{
		return head;
	}
	int insert_to_next(Node * node, int data)
	{
		cur = node->next;
		node->next = new Node;
		cur->prev = node->next;
		node->next->data = data;
		node->next->next = cur;
		node->next->prev = node;
		count++;
		return count;
	}
	int remove(Node *node)
	{
		if (node == head || node == tail) return -1;
		cur = node;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		delete cur;
		count--;
		return count;
	}
	void exchange(Node * node1, Node* node2)
	{
		cur = node1->next;
		node1->next = node2->next;
		node2->next = cur;

		cur = node1->prev;
		node1->prev = node2->prev;
		node2->prev = cur;

		node1->prev->next = node1;
		node1->next->prev = node1;
		node2->prev->next = node2;
		node2->next->prev = node2;	
	}
	void show_all()
	{
		if (count == 0)
		{
			cout << "노드없음" << endl;
			return;
		}
		cur = head;
		for (int i = 1; i <= count; i++)
		{
			cur = cur->next;
			cout << i << "번째 : " << cur->data << endl;
		}
	}
	int GetCount()
	{
		return count;
	}
};
int main()
{
	List list;
	int index;
	list.init();
	list.insert_to_next(list.GetHead(), 101);
	list.insert_to_next(list.find_index_node(1), 102);
	list.insert_to_next(list.find_index_node(1), 102);
	list.insert_to_next(list.GetHead(), 100);
	list.remove(list.find_index_node(3));
	list.insert_to_next(list.find_index_node(list.GetCount()), 103);
	list.insert_to_next(list.find_index_node(list.GetCount()), 104);
	list.insert_to_next(list.find_index_node(list.GetCount()), 105);
	list.exchange(list.find_index_node(2), list.find_index_node(5));
	list.show_all();
	return 0;
}