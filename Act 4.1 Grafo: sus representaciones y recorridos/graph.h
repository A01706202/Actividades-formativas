/*-------------
Michelle Aylin Calzada Montes
A01706202
Act 4.1
--------------*/

#ifndef GRAPH_H
#define GRAPH_H

#pragma once
#include <bits/stdc++.h>

#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;


class Graph {
	private:
	    vector<vector<int> > adj_matrix;
		vector<vector<int> > adj_list;
		int nu_vert;
		int nu_edges;

	public:
		Graph(){}
		string printAdjMat();
		string printAdjList();
		string DFS(int init_v, int target_v);
		string BFS(int init_v, int target_v);
		string to_string(int i);
		string print_vector(vector<int> vec);
		void loadGraphMat(string filename, int v, int edges);
		void loadGraphList(string filename, int v, int edges);	
};

string Graph::printAdjMat(){
	string res = "";
	for(int i=0; i<adj_matrix.size(); i++){
		for(int j=0; j<adj_matrix[i].size(); j++){
			res += to_string(adj_matrix[i][j]) + " ";
		}
	}
	return res;
}


string Graph::printAdjList(){
	string res = "";
	for(int i=0; i<adj_list.size(); i++){
		res += "vertex " + to_string(i) + " : ";
		sort(adj_list[i].begin(), adj_list[i].end());
		for(int j=0; j<adj_list[i].size(); j++){
			res += to_string(adj_list[i][j]) + " ";
		}
	}
	return res;
}


string Graph::DFS(int init_v, int target_v){

	vector<vector<int> > adj_list_copy;
	for (int i=0; i<adj_list.size(); i++){
		adj_list_copy.push_back(adj_list[i]);
	}

	vector<int> stack;
	vector<int> visit;
	int current = init_v;
	bool find = false;	

	while (!find && !(visit.size() >= nu_vert)){

		bool already_visited = false;
		for (int i=0; i<visit.size(); i++){
			if(current == visit[i]) {
				already_visited = true;
				break;
			}
		}

		if (!already_visited) visit.push_back(current);

		if (current == target_v){
			find = true;
			break;
		}

		for (int i=0; i<adj_list_copy[current].size(); i++){
			for (int j=0; j<visit.size(); j++){
				if(adj_list_copy[current][i] == visit[j])
					adj_list_copy[current].erase(adj_list_copy[current].begin()+i);
			}
		}
		if (adj_list_copy[current].size() > 0){
			stack.push_back(current);
			
			//Checa al último hijo del nodo
			int temp_index = current;
			current = adj_list_copy[current].back();
			adj_list_copy[temp_index].pop_back();
		} 
		else {
			
			//Si choca con la pared
			current = stack[stack.size()-1];
			stack.pop_back();
		}
	}
	// Add to the stack the found value to complete path
	stack.push_back(current);
	
	// Convert list to string
	string visited_str = print_vector(visit);
	string path_str = print_vector(stack);
	string res = "visited: " + visited_str + "path: " + path_str;
	res = res.substr(0, res.size()-1);
	return res;
}


string Graph::BFS(int init_v, int target_v){
	vector<vector<int> > queue;
	vector<vector<int> > visit;
	int current = init_v;
	int parent = -1;
	bool find = false;

	while (true){

		visit.push_back(vector<int>({parent, current}));

		if (current == target_v){
			find = true;
			break;
		}

		for (int i=0; i<adj_list[current].size(); i++){
			int val = adj_list[current][i];
			bool already_visited = false;
			for (int j=0; j<visit.size(); j++){
				if (visit[j][1] == val){
					already_visited = true;
					break;
				}
			}
			if (!already_visited) queue.push_back(vector<int>({current, val}));
		}

		parent = queue[0][0];
		current = queue[0][1];
		queue.erase(queue.begin());
	}

	vector<int> path;
	int fnd = target_v;
	
	do {
		for (int i=0; i<visit.size(); i++){
			if (visit[i][1] == fnd){
				path.insert(path.begin(), fnd);
				fnd = visit[i][0];
			}
		}
	} while (fnd != -1);

	vector<int> converted_visited;
	for (int i=0; i<visit.size(); i++){
		converted_visited.push_back(visit[i][1]);
	}

	//Lista a string
	string visited_str = print_vector(converted_visited);
	string path_str = print_vector(path);
	string res = "visited: " + visited_str + "path: " + path_str;
	res = res.substr(0, res.size()-1);
	return res;	
}

string Graph::to_string(int i){
	stringstream aux;
	aux << i;
	return aux.str();
}

string Graph::print_vector(vector<int> vec){
	string result = "";
	for (int i=0; i<vec.size(); i++){
		result = result + to_string(vec[i]) + " ";
	}
	return result;
}

void Graph::loadGraphMat(string filename, int v, int edges){
	nu_vert = v;
	nu_edges = edges;
	
	//Matriz de adyacencia
	for (int i=0; i<v; i++){
		vector<int> row(v, 0);
		adj_matrix.push_back(row);
	}

	ifstream file;
	file.open(filename.c_str());
	while(file.good()){
		string init_vertex;
		string end_vertex;
		getline(file, init_vertex, ',');
		getline(file, end_vertex, '\n');
		init_vertex = init_vertex.substr(1, init_vertex.length()-1);
		end_vertex = end_vertex.substr(1, end_vertex.length()-2);
		stringstream init(init_vertex);
		
		int init_node;
		init >> init_node;
		stringstream end(end_vertex);
		int end_node;
		end >> end_node;
		
		// Llenado del grafo
		adj_matrix[init_node][end_node] = 1;
		adj_matrix[end_node][init_node] = 1;
	}
}


void Graph::loadGraphList(string filename, int v, int edges){
	nu_vert = v;
	nu_edges = edges;
	
	//Lista de adyacencia
	for (int i=0; i<v; i++){
		vector<int> row;
		adj_list.push_back(row);
	}
	
	ifstream file;
	file.open(filename.c_str());
	while(file.good()){
		string init_vertex;
		string end_vertex;
		getline(file, init_vertex, ',');
		getline(file, end_vertex, '\n');
		init_vertex = init_vertex.substr(1, init_vertex.length()-1);
		end_vertex = end_vertex.substr(1, end_vertex.length()-2);
		stringstream init(init_vertex);
		
		int init_node;
		init >> init_node;
		stringstream end(end_vertex);
		int end_node;
		end >> end_node;
		
		//Llenado del grafo
		adj_list[init_node].push_back(end_node);
		adj_list[end_node].push_back(init_node);
	}
}

#endif
