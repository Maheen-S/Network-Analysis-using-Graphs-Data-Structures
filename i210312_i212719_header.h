#pragma once
#include <iostream>
using namespace std;
static int ttime = 0;

int minimum(int value1, int value2)
{
	if (value1 < value2)
	{
		return value1;
	}
	else
	{
		return value2;
	}
}

class Node
{
private:
	int data;
	string id;
	Node* next;
public:
	Node()
	{
		this->data = 0;
		this->id = "";
		this->next = NULL;
	}
	Node(int v, string i)
	{
		this->data = v;
		this->id = i;
		this->next = NULL;
	}
	Node(int v)
	{
		this->data = v;
		this->id = "";
		this->next = NULL;
	}
	Node(string i)
	{
		this->data = 0;
		this->id = i;
		this->next = NULL;
	}
	string get_id()
	{
		return this->id;
	}
	int get_data()
	{
		return this->data;
	}
	Node* get_next()
	{
		return this->next;
	}
	void set_id(string i)
	{
		this->id = i;
	}
	void set_data(int value)
	{
		this->data = value;
	}
	void set_next(Node* n)
	{
		this->next = n;
	}
};

class LinkedList
{
private:
	Node* head;
public:
	LinkedList()
	{
		this->head = NULL;
	}
	Node* get_head()
	{
		return this->head;
	}
	void set_head(Node* h)
	{
		this->head = h;
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	void insertAtTail(Node* t)
	{
		if (isEmpty())
		{
			set_head(t);
		}
		else
		{
			Node* temp = head;
			while (temp->get_next() != NULL)
			{
				temp = temp->get_next();
			}
			temp->set_next(t);
		}
	}
	void insertAtTail(int v, string i)
	{
		Node* t = new Node(v, i);
		if (isEmpty())
		{
			set_head(t);
		}
		else
		{
			Node* temp = head;
			while (temp->get_next() != NULL)
			{
				temp = temp->get_next();
			}
			temp->set_next(t);
		}
	}
	void insertAtTail(string i)
	{
		Node* t = new Node(i);
		if (isEmpty())
		{
			set_head(t);
		}
		else
		{
			Node* temp = head;
			while (temp->get_next() != NULL)
			{
				temp = temp->get_next();
			}
			temp->set_next(t);
		}
	}
	void insertAtTail(int v)
	{
		Node* t = new Node(v);
		if (isEmpty())
		{
			set_head(t);
		}
		else
		{
			Node* temp = head;
			while (temp->get_next() != NULL)
			{
				temp = temp->get_next();
			}
			temp->set_next(t);
		}
	}
	void display()
	{
		Node* temp = get_head();
		while (temp != NULL)
		{
			cout << temp->get_id() << "--";
			temp = temp->get_next();
		}
		cout << "NULL";
	}
	int degree()
	{
		Node* temp = head;
		if (temp == NULL)
		{
			return 0;
		}
		else {
			int length = 0;
			Node* temp2 = new Node();
			temp2 = temp;
			while (temp2->get_next() != NULL)
			{
				length++;
				temp2 = temp2->get_next();
			}
			length++;
			return length;
		}
		return 0;
	}
	int search(string s)
	{
		if (isEmpty())
			return -1;
		Node* temp = get_head();
		while (temp != NULL)
		{
			if (temp->get_id() == s)
			{
				return temp->get_data();
			}
			temp = temp->get_next();
		}
		return -1;
	}
	//int search(int s)
	//{
	//	if (isEmpty())
	//		return;
	//	Node* temp = get_head();
	//	while (temp != NULL)
	//	{
	//		if (temp->get_data() == s)
	//		{
	//			return temp->get_data();
	//		}
	//		temp = temp->get_next();
	//	}
	//	return;
	//}
};
class Stack
{
private:
	Node* top;
public:
	Stack()
	{
		this->top = NULL;
	}
	Node* get_top()
	{
		return this->top;
	}
	void set_top(Node* t)
	{
		this->top = t;
	}
	bool isEmpty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}
	bool push(int v)
	{
		Node* p = new Node(v);
		if (isEmpty())
		{
			top = p;
			return true;
		}
		else
		{
			p->set_next(top);
			top = p;
			return true;
		}
	}
	bool pop()
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			return false;
		}
		else
		{
			Node* temp = top;
			top = top->get_next();
			delete temp;
			return true;
		}
	}
	int peek()
	{
		if (isEmpty())
		{
			cout << "Stack underflow" << endl;
			return 0;
		}
		else
		{
			return top->get_data();
		}
	}

};
class Queue
{
	Node* front;
	Node* rear;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	int showFront()
	{
		return front->get_data();
	}
	int size()
	{
		int count = 0;
		Node* temp = front;
		while (temp != NULL)
		{
			count++;
			temp = temp->get_next();

		}
		return count;
	}
	void enQueue(int v)
	{
		Node* n = new Node(v);
		if (rear == NULL)
		{
			front = n;
			rear = n;
			return;
		}
		else
		{
			rear->set_next(n);
			rear = n;
			n->set_next(NULL);
		}
	}
	int showRear()
	{
		return rear->get_data();
	}
	void displayQueue()
	{
		Node* temp = front;
		while (temp != NULL)
		{
			cout << temp->get_data() << endl;
			temp = temp->get_next();
		}
	}
	int deQueue()
	{
		if (front == NULL)
		{
			return -1;
		}
		int temp = front->get_data();
		front = front->get_next();
		if (front == NULL)
		{
			rear = NULL;
		}
		return temp;
	}
	bool isEmpty()
	{
		if (front == NULL && rear == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Graph
{
private:
	int vertices;
	LinkedList* adj_list;
	Queue q;
	Stack s;
public:
	Graph(int maxVertices)
	{
		this->vertices = maxVertices;
		adj_list = new LinkedList[maxVertices];
	}
	void set_vertices(int v)
	{
		this->vertices = v;
	}
	int get_vertices()
	{
		return this->vertices;
	}
	//for directed
	void addEdge(int src, string to, int counter)
	{
		adj_list[src].insertAtTail(counter, to);
	}
	void addEdge(int src, int counter)
	{
		adj_list[src].insertAtTail(counter);
	}
	//for undirected
	void addEdge(int src, int dest, string from, string to)
	{
		adj_list[src].insertAtTail(dest, to);
		adj_list[dest].insertAtTail(src, from);
	}
	void showGraphStructure()
	{
		if (adj_list->isEmpty())
		{
			cout << "Empty graph." << endl;
			return;
		}
		else
		{
			for (int i = 0; i < vertices; i++)
			{
				cout << i << " ";
				//cout << adj_list[i].get_head()->get_id();
				adj_list[i].display();
				cout << endl;
			}
		}
	}
	void BFS(int startNode)
	{
		bool* visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		visited[startNode] = true;
		q.enQueue(startNode);
		while (!q.isEmpty())
		{
			int currentVertex = q.showFront();
			cout << currentVertex << " ";
			q.deQueue();
			Node* temp = adj_list[currentVertex].get_head();
			while (temp != NULL)
			{
				int adjacentVertex = temp->get_data();
				if (!visited[adjacentVertex])
				{
					//cout << adjacentVertex << endl;
					visited[adjacentVertex] = true;
					q.enQueue(adjacentVertex);
				}
				temp = temp->get_next();
			}
		}
	}
	void DFS(int startNode)
	{
		bool* visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		visited[startNode] = true;
		s.push(startNode);
		while (!s.isEmpty())
		{
			int currentVertex = s.peek();
			cout << currentVertex << " ";
			s.pop();
			Node* temp = adj_list[currentVertex].get_head();
			while (temp != NULL)
			{
				int adjacentVertex = temp->get_data();
				if (!visited[adjacentVertex])
				{
					//cout << adjacentVertex;
					visited[adjacentVertex] = true;
					s.push(adjacentVertex);
				}
				temp = temp->get_next();
			}
		}
	}
	int degree(int v)
	{
		return adj_list[v].degree();
	}
	// return ad array, first column is out degree, second column is in degree (can be used for tasks 10 and 11 too)
	int** degree_table()
	{
		int** arr = new int* [vertices];
		for (int i = 0; i < vertices; i++)
		{
			arr[i] = new int[2];
		}
		//initialising with 0
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				arr[i][j] = 0;
			}
		}

		//first column - out degree
		for (int i = 0; i < vertices; i++)
		{
			arr[i][0] = adj_list[i].degree();
			//cout << arr[i][0] << endl;
		}

		//second column - in degree
		for (int i = 0; i < vertices; i++)
		{
			Node* temp = adj_list[i].get_head();
			while (temp != NULL)
			{
				//cout << temp->get_data() << endl;
				arr[temp->get_data()][1] += 1;

				temp = temp->get_next();
			}
		}

		////display 2d array
		//for (int i = 0; i < vertices; i++)
		//{
		//	for (int j = 0; j < 2; j++)
		//	{
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << endl;
		//}		
		//cout << arr;
		return arr;
	}

	//int count_source_nodes()
	//{
	//	LinkedList src_nodes;
	//	int count = 0;
	//	for (int i = 0; i < vertices; i++)
	//	{
	//		if (adj_list[i].get_head() != NULL && src_nodes.search(adj_list[i].get_head()->get_id())==-1)
	//		{
	//			count++;
	//			src_nodes.insertAtTail(adj_list[i].get_head()->get_id());
	//		}
	//	}
	//	return count;
	//}
	int count_source_nodes()
	{
		int count = 0;
		int** a = degree_table();
		for (int i = 0; i < vertices; i++)
		{
			if (a[i][0] != 0)
			{
				count++;
			}
		}
		return count;
	}
	int count_sink_nodes()
	{
		int count = 0;
		int** a = degree_table();
		for (int i = 0; i < vertices; i++)
		{
			if (a[i][1] != 0)
			{
				count++;
			}
		}
		return count;
	}
	int count_isolated_nodes()
	{
		int count = 0;
		int** a = degree_table();
		for (int i = 0; i < vertices; i++)
		{
			if (a[i][0] == 0 && a[i][1] == 0)
			{
				count++;
			}
		}
		return count;
	}
	//int count_sink_nodes()
	//{
	//	LinkedList sink_nodes;
	//	int count = 0;
	//	for (int i = 0; i < vertices; i++)
	//	{
	//		if (adj_list[i].get_head() != NULL)
	//		{
	//			Node* temp = adj_list[i].get_head();
	//			while (temp != NULL)
	//			{
	//				if (sink_nodes.search(temp->get_id()) == -1)
	//				{
	//					count++;
	//					sink_nodes.insertAtTail(temp->get_id());
	//				}
	//				temp = temp->get_next();
	//			}
	//		}
	//	}
	//	return count;
	//}


	int becount = 0;
	int bridge_edges_helper(int u, bool *visited, int *h, int *l, int* parent, static int t)
	{
		visited[u] = true;
		h[u] = l[u] = ++t;
		Node* temp = adj_list[u].get_head();
		while (temp!=NULL)
		{
			int v = temp->get_data(); 
			if (!visited[v])
			{
				parent[v] = u;
				bridge_edges_helper(v, visited, h, l, parent, t);
				l[u] = minimum(l[u], l[v]);
				if (l[v] > h[u])
				{
					//cout << u << " " << v << endl;
					becount++;
				}
			}
			else if (v != parent[u])
			{
				l[u] = minimum(l[u], h[v]);
			}

			temp = temp->get_next();
		}
		return becount;
	}
	int bridge_edges()
	{
		bool* visited = new bool[vertices];
		int* d = new int[vertices];
		int* l = new int[vertices];
		int* parent = new int[vertices];
		for (int i = 0; i < vertices; i++)
		{
			parent[i] = -1;
			visited[i] = false;
		}
		for (int i = 0; i < vertices; i++)
		{
			if (visited[i] == false)
			{
				bridge_edges_helper(i, visited, d, l, parent, ::ttime);
			}
		}
		return becount;
	}


	void articulation_nodes_helper(int w, bool *visited, int *d, int *l, int *parent, bool* f)
	{
		static int t = 0;
		int child = 0;
		visited[w] = true;
		d[w] = l[w] = ++t;
		Node* temp = adj_list[w].get_head();
		while (temp!=NULL)
		{
			int x = temp->get_data();
			if (!visited[x])
			{
				child++;
				parent[x] = w;
				articulation_nodes_helper(x, visited, d, l, parent, f);
				l[w] = min(l[w], l[x]);
				if (parent[w] == -1 && child > 1)
				{
					f[w] = true;
				}
				if (parent[w] != -1 && l[x] >= d[w])
				{
					f[w] = true;
				}
			}
			else if (x != parent[w])
			{
				l[w] = minimum(l[w], d[x]);
			}

			temp = temp->get_next();
		}
	}
	int articulation_nodes()
	{
		int count = 0;
		bool* visited = new bool[vertices];
		int* dis = new int[vertices];
		int* low = new int[vertices];
		int* par = new int[vertices];
		bool* ap = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			par[i] = -1;
			visited[i] = false;
			ap[i] = false;
		}
		for (int i = 0; i < vertices; i++)
		{
			if (visited[i] == false)
			{
				articulation_nodes_helper(i, visited, dis, low, par, ap);

			}
		}
		//counting the articulation nodes
		for (int i = 0; i < vertices; i++)
		{
			if (ap[i] == true)
			{
				count++;
			}
		}
		return count;
	}

	void shortest_path_length_distribution()
	{
		int* distribution = new int[vertices];
		int diameter = -1;
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				distribution[j] = -1;
			}
			Queue q;
			distribution[i] = 0;
			q.enQueue(i);
			while (q.isEmpty() == false)
			{
				int v1 = q.deQueue();
				Node* temp = adj_list[v1].get_head();
				while (temp != NULL)
				{
					int v2 = temp->get_data();
					if (distribution[v1] + 1 < distribution[v2])
					{
						distribution[v2] = distribution[v1] + 1;
						q.enQueue(v2);
					}
					temp = temp->get_next();
				}
			}
			cout << "Vertex " << i << ":" << endl;
			for (int k = 0; k < vertices; k++)
			{
				if ((distribution[k] != -1) && (distribution[k] > diameter))
				{
					diameter = distribution[k];
				}
				if (distribution[k] != -1)
				{
					cout << k << ": " << distribution[k] << "  |  ";
					
				}
				else
				{
					cout << k << ": " << "-1" << "  |  ";
				}
			}
			cout << endl;
		}
	}
	int diameter_of_graph()
	{
		int* distribution = new int[vertices];
		int diameter = -1;
		for (int i = 0; i < vertices; i++)
		{
			for (int j = 0; j < vertices; j++)
			{
				distribution[j] = -1;
			}
			Queue q;
			distribution[i] = 0;
			q.enQueue(i);
			while (q.isEmpty() == false)
			{
				int v1 = q.deQueue();
				Node* temp = adj_list[v1].get_head();
				while (temp != NULL)
				{
					int v2 = temp->get_data();
					if (distribution[v1] + 1 < distribution[v2])
					{
						distribution[v2] = distribution[v1] + 1;
						q.enQueue(v2);
					}
					temp = temp->get_next();
				}
			}
			for (int k = 0; k < vertices; k++)
			{
				if ((distribution[k] != -1) && (distribution[k] > diameter))
				{
					diameter = distribution[k];
				}	
			}
		}
		return diameter;
	}
	
	void wcc_function()
	{
		int max = -1;
		bool* visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		Stack s;
		for (int i = 0; i < vertices; i++)
		{
			if (!visited[i])
			{
				s.push(i);
				LinkedList wcc;
				while (!s.isEmpty())
				{
					int v1 = s.peek();
					s.pop();
					if (!visited[v1])
					{
						visited[v1] = true;
						wcc.insertAtTail(v1);
						Node* temp = adj_list[v1].get_head();
						while (temp != NULL)
						{
							int v2 = temp->get_data();
							if (!visited[v2])
							{
								s.push(v2);
							}
							temp = temp->get_next();
						}
					}
				}
				int count = 0;
				cout << "WCC: ";
				Node* temp2 = wcc.get_head();
				while (temp2 != NULL)
				{
					count++;
					cout << temp2->get_data() << " " << temp2->get_id() << " ";
					temp2 = temp2->get_next();
				}
				cout << endl;
				cout << "Size of WCC: " << count << endl;
				if (count > max)
				{
					max = count;
				}
			}
		}
		cout << "The size of the largest WCC: " << max << endl;
	}

	void fill_order(int s, bool* visited, Stack& stack)
	{
		visited[s] = true;
		Node* temp = adj_list[s].get_head();
		while (temp != NULL)
		{
			if (!visited[temp->get_data()])
			{
				fill_order(temp->get_data(), visited, stack);
			}
			temp = temp->get_next();
		}
		stack.push(s);
	}

	void graph_transopse(Graph& g)
	{
		for (int i = 0; i < vertices; i++)
		{
			Node* temp = adj_list[i].get_head();
			while (temp != NULL)
			{
				g.addEdge(temp->get_data(), i);
				temp = temp->get_next();
			}
		}
	}

	int scc = 0;

	void DFS(int s, bool* visited)
	{
		visited[s] = true;
		Node* temp = adj_list[s].get_head();
		cout << temp->get_data() << " " << temp->get_id() << " ";
		scc++;
		while (temp != NULL)
		{
			if (!visited[temp->get_data()])
			{
				DFS(temp->get_data(), visited);
			}
			temp = temp->get_next();
		}
	}

	void scc_function()
	{
		int max = -1;
		Stack stack;
		bool* visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < vertices; i++)
		{
			if (visited[i] == false)
			{
				fill_order(i, visited, stack);
			}
		}
		Graph t_graph(vertices);
		graph_transopse(t_graph);

		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		while (!stack.isEmpty())
		{
			int s = stack.peek();
			stack.pop();

			if (visited[s] == false)
			{
				scc = 0;
				cout << "SCC: ";
				t_graph.DFS(s, visited);
				cout << endl << "Size of SCC: " << scc << endl << endl;
				if (max < scc)
				{
					max = scc;
				}
			}
		}
		cout << endl << "The size of largest SCC: " << max << endl << endl;
	}

	int largest_scc_function()
	{
		int max = -1;
		Stack stack;
		bool* visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		for (int i = 0; i < vertices; i++)
		{
			if (visited[i] == false)
			{
				fill_order(i, visited, stack);
			}
		}
		Graph t_graph(vertices);
		graph_transopse(t_graph);
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		while (!stack.isEmpty())
		{
			int s = stack.peek();
			stack.pop();
			if (visited[s] == false)
			{
				scc = 0;
				//cout << "SCC: ";
				t_graph.DFS(s, visited);
				//cout << endl << "Size of SCC: " << scc << endl << endl;
				if (max < scc)
				{
					max = scc;
				}
			}
		}
		return max;
	}

	int largest_wcc_function()
	{
		int max = -1;
		bool* visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		Stack s;
		for (int i = 0; i < vertices; i++)
		{
			if (!visited[i])
			{
				s.push(i);
				LinkedList wcc;
				while (!s.isEmpty())
				{
					int v1 = s.peek();
					s.pop();
					if (!visited[v1])
					{
						visited[v1] = true;
						wcc.insertAtTail(v1);
						Node* temp = adj_list[v1].get_head();
						while (temp != NULL)
						{
							int v2 = temp->get_data();
							if (!visited[v2])
							{
								s.push(v2);
							}
							temp = temp->get_next();
						}
					}
				}
				int count = 0;
				//cout << "WCC: ";
				Node* temp2 = wcc.get_head();
				while (temp2 != NULL)
				{
					count++;
					//cout << temp2->get_data() << " " << temp2->get_id() << " ";
					temp2 = temp2->get_next();
				}
				//cout << endl;
				//cout << "Size of WCC: " << count << endl;
				if (count > max)
				{
					max = count;
				}
			}
		}
		return max;
	}



};