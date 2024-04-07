#include<iostream>
#include <stdio.h>
#include <fstream>
#include <iomanip>
#include <Windows.h>
#include <io.h>
#include <cstdlib>
#include <string>
#include "../Project/PHeader.h"
#pragma once 

using namespace std;
int main()
{
	//reading file
	string file_name = "CA-GrQc.txt";
	ifstream my_file(file_name);
	string s;
	string from, to;
	int count = 0;
	string unique;
	//skipping first 2 lines
	for (int i = 0; i < 2; i++)
	{
		getline(my_file, s);
	}

	//reading number of nodes and edges
	int no_of_nodes, no_of_edges = 0;
	my_file >> s;
	my_file >> s;
	my_file >> no_of_nodes;
	my_file >> s;
	my_file >> no_of_edges;

	//skipping 4th line
	getline(my_file, s);
	getline(my_file, s);

	//counting unique authors and assigning data value
	LinkedList l;
	while (!my_file.eof())
	{
		my_file >> unique;
		if (l.search(unique) == -1)
		{
			l.insertAtTail(count, unique);
			count++;
		}
	}
	my_file.close();
	//cout << count << endl;
	Graph g(no_of_nodes);

	//reading file second time to add edges
	//skipping first 4 lines
	ifstream my_file2(file_name);
	for (int i = 0; i < 4; i++)
	{
		getline(my_file2, s);
		//cout << s << endl;
	}

	//add edges
	while (!my_file2.eof())
	{
		//for directed:

		int src = 0, dest = 0;
		my_file2 >> from;
		my_file2 >> to;
		src = l.search(from);
		dest = l.search(to);
		g.addEdge(src, to, dest);
		//for undirected
		// 
		//int src = 0, dest = 0;
		//my_file2 >> from;
		//my_file2 >> to;
		//src = l.search(from);
		//dest = l.search(to);
		//g.addEdge(src, dest, from, to);
	}
	my_file2.close();

	//display graph
	//g.showGraphStructure();
	
	//FOR THIRD SET OF TASKS

	//making undirected graph
	ifstream my_file3(file_name);
	for (int i = 0; i < 4; i++)
	{
		getline(my_file3, s);
		//cout << s << endl;
	}

	Graph g2(no_of_nodes);

	//add edges
	while (!my_file3.eof())
	{
		////for directed:
		//int src = 0, dest = 0;
		//my_file3 >> from;
		//my_file3 >> to;
		//src = l.search(from);
		//dest = l.search(to);
		//g.addEdge(src, to, dest);
		// 
		//for undirected

		int src = 0, dest = 0;
		my_file3 >> from;
		my_file3 >> to;
		src = l.search(from);
		dest = l.search(to);
		g2.addEdge(src, dest, from, to);
	}
	my_file3.close();
	int** a = g.degree_table();
	int** a2 = g.degree_table();
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "\n-------------------------N E T W O R K   A N A L Y S I S---------------------------------\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	char ch;
	//g.showGraphStructure();
	do {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "\n READ THE MENU INSTRUCTIONS CAREFULLY FOLKSS!\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << "\n Press z to exit:( \n 1) Press 'a' to get Number of Nodes\n 2) Press 'b' to get Number of Edges \n";
		cout << "3) Press 'c' to get Number of Source Nodes\n 4) Press 'd' to get Number of Sink Nodes\n 5) Press 'e' to get Number of Isolated Nodes\n ";
		cout << " 6) Press 'f' to get Number of Bridge Edges \n 7) Press 'j' to find Number of articulation nodes : \n ";
		cout << "8) Press 'k' to find Number of articulation nodes: \n 9) Press 'l' to get \n 10) Press 'm' to get \n";
		cout << " 10)Press 'n' to get The in-degree distribution in the form of a table: \n 11) Press 'o' to get nThe out-degree distribution in the form of a table:";
		cout << " \n12)Press 'p' to display the size of the largest strongly connected component (SCC): \n 13) Press 'q' to display the size distribution of all SCCs:";
		cout << " \n14)Press 'r' to display the size of the largest weakly connected component (WCC): \n 15) Press 's' to display the size distribution of all WCCs:";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cin >> ch;

		switch (ch)

		{
		case 'a':
			//1
			cout << "Number of nodes: " << no_of_nodes << endl;
			break;
		case 'b':
			//2
			cout << "Number of edges: " << no_of_edges << endl;
			break;
		case 'c':
			//3
			cout << "Number of source nodes: " << g.count_source_nodes() << endl;
			break;
		case 'd':
			//4
			cout << "Number of sink nodes: " << g.count_sink_nodes() << endl;
			break;
		case 'e':
			//5
			cout << "Number of isolated nodes: " << g.count_isolated_nodes() << endl;
			break;
		case 'j':
			//6
			cout << "Number of bridge edges: " << g.bridge_edges() << endl;
			break;
		case'k':
			//7
			cout << "Number of articulation nodes: " << g.articulation_nodes() << endl;
			break;
		case 'l':
			//8
			cout << "Shortest path length distribution:\n" << endl;
			g.shortest_path_length_distribution();
			cout << endl;
			//undirected();
			break;
		case 'm':
			//9
			cout << "Diameter of the graph: " << g.diameter_of_graph() << endl;
			break;
		case 'n':
			//10
			cout << "\n\n\nThe in-degree distribution in the form of a table:" << endl;
			cout << "Vertex:		";
			for (int i = 0; i < g.get_vertices(); i++)
			{
				cout << i << " ";
			}
			cout << endl << "In-Degree:	";
			for (int i = 0; i < g.get_vertices(); i++)
			{
				cout << a[i][1] << " ";
			}
			break;
		case 'o':
			//11

			cout << "\nThe out-degree distribution in the form of a table:" << endl;
			cout << "Vertex:		\n";
			for (int i = 0; i < g.get_vertices(); i++)
			{
				cout << i << " ";
			}
			cout << endl << "Out-Degree: ";
			for (int i = 0; i < g.get_vertices(); i++)
			{
				cout << a2[i][0] << " ";
			}
			break;
		case 'p':
			//12
			cout << "Size of the largest strongly connected component" << g.largest_scc_function() << endl;

			break;
		case 'q':
			//13
			cout << "Size distribution of all SCCs" << endl;
			g2.scc_function();
			break;
		case 'r':
			//14
			cout << "Size of the largest weakly connected component" << g2.largest_wcc_function() << endl;

			break;
		case 's':
			//15
			cout << "Size distribution of all WCCs" << endl;
			g2.wcc_function();
			break;
		default:
			cout << "Invalid \n";
		}

	} while (ch != 'z');

}