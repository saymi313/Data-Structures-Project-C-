#include <iostream>
#include <windows.h> 
#include <cstdlib>
#include "Graph_p2_lib.h"

using namespace std;

int main() {
    City cities[5];
    system("COLOR B");
    cout << "Enter the names of the cities to insert: " << endl;
    cout << "________________________________________________________________________" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> cities[i].name;
        cities[i].index = i;
    }

    Node* adj_list[5] = { nullptr };
    for (int i = 0; i < 5; i++) {
        adj_list[i] = nullptr;
    }

    
    int src_index = 0;
    int dest_index = 0;
    int distcities = 0;
    system("COLOR 9");
    cout << "Enter the source index, destination index, and distance of the cities: " << endl;
    cout << "________________________________________________________________________" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Source: ";
        cin >> src_index;
        cout << "Destination: ";
        cin >> dest_index;
        cout << "Distance: ";
        cin >> distcities;
        insert_edge(adj_list, src_index, dest_index);
        add_distance(distances, cities[src_index].name, cities[dest_index].name, distcities);
    }
    cout << "________________________________________________________________________" << endl;
    for (int i = 0; i < 50; i++) {
        cout << distances[i].distance << " ";
    }
    int op = 0;
    cout << endl;
    system("COLOR D");
    cout << "________________________________________________________________________" << endl;
    cout << "1) Find Distance between two cities" << endl;
    cout << "2) Find cities between the path" << endl;
    cout << "3) Exit" << endl;
    cout << "________________________________________________________________________" << endl;
    int city1 = 0;
    int city2 = 0;
    int source = 0;
    int destination = 0;
    system("COLOR 9");
    while (true) {
        cin >> op;
        if (op == 1) {
            cout << "Enter index of city 1: ";
            cin >> city1;
            cout << "Enter index of city 2: ";
            cin >> city2;
            int distance = find_distance(distances, cities[city1].name, cities[city2].name);
            if (distance != -1) {
                cout << "Distance between " << cities[city1].name << " and " << cities[city2].name << ": " << distance << endl;
            }
            else {
                cout << "Distance between " << cities[city1].name << " and " << cities[city2].name << " not found." << endl;
            }
            cout << "________________________________________________________________________" << endl;
        }
        else if (op == 2) {
            cout << "Enter source index: ";
            cin >> source;
            cout << "Enter destination index: ";
            cin >> destination;
            bfs(adj_list, source, destination, cities, 5);
            cout << "________________________________________________________________________" << endl;
        }
        else {
            break;
        }
    }

    return 0;
}
/*Sample innput for checking collision result 
ISB
MSR
BSI
RSM
MLT*/