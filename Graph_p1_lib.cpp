#include "Graph_p1_lib.h"
double distances[50] = { -1};
Queue::Queue() {
    front = NULL;
    rear = NULL;
    counter = 0;
}
void Queue::insertQueue(char data) {
    Qnode* newnode = new Qnode;
    newnode->data = data;
    if (empty()) {
        front = newnode;
    }
    else {
        rear->next = newnode;
    }
    rear = newnode;
    counter++;
}

char Queue::dequeue() {
    if (empty()) {
        cout << "Queue is empty" << endl;
        return '\0';
    }
    Qnode* temp = front;
    char item = front->data;
    front = front->next;
    delete temp;
    counter--;
    return item;
}

bool Queue::empty() {
    return counter == 0;
}

int hash_func(char* city1, char* city2) {
    int sum1 = 0;
    for (int i = 0; city1[i] != '\0'; i++) {
        sum1 = sum1 + city1[i];
    }
    int sum2 = 0;
    for (int j = 0; city2[j] != '\0'; j++) {
        sum2 = sum2 + city2[j];
    }
    int result = 0;
    result = sum1 + sum2;
    return result % 50;
}

void insert_edge(Node* adj_list[], int src, int dest) {
    Node* newnode = new Node();
    newnode->city = dest;
    newnode->next = adj_list[src];
    adj_list[src] = newnode;
}

int add_distance(double distances[], char* city1, char* city2, double distance) {
    int key = hash_func(city1, city2);
    cout << "Adding distance between " << city1 << " and " << city2 << " with key: " << key << endl;
    if (distances[key] != -1) {
        cout << "At key " << key;
        cout << endl;
        cout << "Distance " << distances[key] << " Already present";
        cout << endl;
    }
    distances[key] = distance;
    cout << "Distance for key " << key;
    cout<< " is " << distance;
    cout << endl;
    return static_cast<int>(distance);
}

int find_distance(double distances[], char* city1, char* city2) {
    int key = hash_func(city1, city2);
    cout << "Finding distance between " << city1 << " and " << city2 << " with key " << key << endl;
    if (distances[key] != -1) { 
        cout << "At key " << key;
        cout << endl;
        cout << "Distance " << distances[key] << " Already present";
        cout << endl;
        return static_cast<int>(distances[key]);
    }
    else {
        cout << "Distance not found for key " << key << endl;
        return -1;
    }
}

void print_path(int parent[], int src, int dest, City cities[]) {
    int n = 0;
    if (parent[dest] == -1) {
        cout << "No path exists between " << cities[src].name << " and " << cities[dest].name;
        cout << endl;
        return;
    }
    int path_index = 0;
    cout << endl;
    int* path = new int[10];
    for (int i = dest; i != -1; i = parent[i], path_index++) {
        path[path_index] = i;
    }
 
    for (int k = 0; k < n; k++) {
        n++;
    }
    cout << "Names of cities " << cities[src].name << " " << cities[dest].name << endl;
    for (int j = path_index - 1; j >= 0; j--) {
        cout << "Cities between the path " << cities[path[j]].name;
        cout << endl;
    }
    int opt = 0;
    cout << "Press 1 to find distance between cities else press 0" << endl;
    cin >> opt;

    double total;
    total= 0;
    if (opt == 1) {
        for (int j = path_index - 1; j > 0; j--) {
            total = total+find_distance(distances, cities[path[j]].name, cities[path[j - 1]].name);
        }
        cout << "Distance between cities " << total << endl;
    }
}

void bfs(Node* adj_list[], int src, int dest, City cities[], int n) {
    bool* checker = new bool[50];
    int count = 0;
    int* arr = new int[50];
    for (int i = 0; i < n; i++) {
        checker[i] = false;
        arr[i] = -1;
    }
    for (int c = 0; c < 5; c++) {
        count++;
    }
    Queue q;
    q.insertQueue(src);
    checker[src] = true;
    for (; !q.empty();) {
        int u = q.dequeue();
        Node* aj = adj_list[u];
        for (; aj;) {
            int s = aj->city;
            if (!checker[s]) {
                q.insertQueue(s);
                checker[s] = true;
                arr[s] = u;
                if (aj->city == dest) {
                    print_path(arr, src, dest, cities);
                    return;
                }
            }
            aj = aj->next;
        }
    }
    print_path(arr, src, dest, cities);
}

