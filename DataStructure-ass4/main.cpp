#include <iostream>

using namespace std;
struct Node
{
    char label;
    int cost;
};
class MinHeap
{
    Node* heap; //an array of nodes
    int _size; //size of array
public:
    MinHeap()
    {
        _size=0;
        heap=new Node[_size];
    }
//returns & removes the node with minimum cost
    Node extractMin()
    {
        if(_size<=0)
        {
            cout<<"heap underflow"<<endl;
        }
        else if(_size==1)
        {
            _size--;
            Node Min=heap[0];
            return Min;
        }
        else
        {
            Node root = heap[0];
            heap[0] = heap[_size-1];
            _size--;
            minHeapify(0,_size);

            return root;

        }

    }
// allocates array then builds a min-heap from an
//array of struct Node with the given size
    void buildMinHeap(Node[],int s)
    {
        for(int i=s/2-1; i>=0; i--)
        {
            minHeapify(i, s);
        }

    }

//restores the min-heap property for the “heap”
    void minHeapify(int i, int n)
    {
        int l = (2*i + 1);
        int r = (2*i + 2);
        int Smallest = i;
        if (l < n && heap[l].cost < heap[i].cost)
        {
            Smallest = l;
        }
        if (r < n && heap[r].cost < heap[Smallest].cost)
        {
            Smallest = r;
        }
        if (Smallest != i)
        {
            swap(heap[i].cost, heap[Smallest].cost);
            minHeapify(Smallest,n);
        }
    }
//array using the given index and size n
//decreases the node that has the given
//label to newCost
    void decreaseKey(char label,int newCost)
    {
        if(newCost<heap[label].cost)
        {
           cout<<"new key is bigger than current key"<<endl;
        }
       else
       {
        heap[label].cost=newCost;
       }
        while ( _size  > 0 && heap[parent(label)].cost > heap[label].cost)
        {
            swap(heap[label].cost, heap[parent(label)].cost);
            label = parent(label);
        }
    }

//returns the index of the parent of i
    int parent(int i)
    {
        return (i-1)/2;
    }
//returns size of the heap
    int getSize()
    {
        return _size;
    }
//checks if the node with the given label is in the heap
    bool inHeap(char la)
    {
        for(int i=(_size/2-1); i>0; i--)
        {
            if(heap[i].label==la)
                return true;
        }
        return false;
    }

};
template<class T>
class Node {
    T info;
    Node *next;
public:
    Node(){
        info=0;
        next=0;
    }
    Node(T i,Node* n){
        info=i;
        next=n;
    }
    Node* getNext(){
        return next;
    }
    void setNext(Node* n){
        next=n;
    }
    T getInfo(){
        return info;
    }
    void setInfo(T i){
        info=i;
    }
};
template<class T>
class SLL {
private:
    Node<T> *head,*tail;
public:
    SLL(){head=tail=0;}
    void addToHead(T data){
        Node<T> *t;
        t=new Node<T>;
        t->setInfo(data);
        if(head==NULL){
            t->setNext(NULL);
            head =t;
            tail=t;
        } else{
            t->setNext(head);
            head =t;
        }
    }
    void addToTail(T data){
        Node<T> *p;
        p=new Node<T>;
        p->setInfo(data);
        p->setNext(NULL);
        if (head==NULL){
            head =p;
            tail=p;
        } else{
            tail->setNext(p);
            tail=p;
        }
    }
    T removeFromHead(){
        Node<T> *p;
        T data=0;
        if (head==NULL) return data;
        else{
            p=head;
            head=head->getNext();
            data =p->getInfo();
            delete p;
            return data;
        }

    }
    T removeFromTail(){
        Node<T> *p;
        T data;
        p=head;
        if (head==NULL){
            std::cout<<"Empty"<<std::endl;
        }
        if (head==tail){
            data=head->getInfo();
            delete p;
            head=tail=0;
            return data;
        } else {
            while (p->getNext() != tail) {
                p = p->getNext();
            }
            p->setNext(NULL);
            data =tail->getInfo();
            delete tail;
            tail = p;
            return data;
        }

    }
    T getValueAtHead(){
        if (head!=NULL)
            return head->getInfo();
    }
    bool isEmpty(){
        if (head==NULL) return true;
        else return false;
    }
    void clear(){
        Node<T> *p,*t;
        p=head;
        while (p!=NULL){
            t=p;
            p=p->getNext();
            delete t;
        }
        head=tail=0;
    }
   friend ostream& operator<<(ostream& out ,const SLL<T> &sll){
        Node<T> *t;
        t=sll.head;
       while (t!=NULL){
           out<<t->getInfo()<<" ";
           t=t->getNext();
       }
       return out;
    }
};
template<class T>
class QueueSLL {
public:
    SLL<T> *sll;
public:
    int cnt;
    QueueSLL(){
        sll=new SLL<T>;
        cnt=0;
    }
    void enqueue(T data){
        sll->addToTail(data);
        cnt++;
    }

    T dequeue(){
        return sll->removeFromHead();
        cnt--;
    }
    T front(){
        return sll->getValueAtHead();
    }
    bool isEmpty(){
        return sll->isEmpty();
    }
    void clear(){
        sll->clear();
    }

};
class WeightedGraph
{
 int** g;
 int nVertices;
public:
bool isConnected(int u, int v) {
    return (g[u-1][v-1] == 1);
}

int getNVertices(int s)//returns the number of vertices
{
    int numofvertices = 0 ;
    QueueSLL<char> Q ;
    bool *visited = new bool[nVertices+1];

    for (int i = 1; i <= nVertices; ++i)
    {
    visited[i] = false;
    }
    Q.enqueue(s);
    visited[s] = true;
    cout << "Graph starting from vertex ";
    cout << s << " : " << endl;
    while (!Q.isEmpty()) {
        int v = Q.dequeue();
        cout << v << " ";
        numofvertices ++ ;
        for (int i = 1; i <= nVertices; i++)
            {
            if (isConnected(v, i) && !visited[i]) {
                Q.enqueue(i);
                visited[i] = true;
            }
            }
    }
    cout << endl;
    cout<<"the number of vertices is "<<numofvertices<<endl;
    delete [] visited;
}



 int getWeight(char,char)//returns weight of the edge connecting the given vertices
 {

 }
// returns the indices of the neighbors of the vertex v as an int array
 int* returnNeighbors(int v){
        int a[nVertices];
        for (int i = 0; i < nVertices; ++i) {
            if (g[v][i]>0){
                a[i]=g[v][i];
            } else
                a[i]=0;
        }
        return a;
    }

 int numNeighbors(int v);//returns the number of neighbors of the vertex v
//allocates the adjacency matrix & initializes edge weights from the specified file
void loadGraphFromFile(ifstream& fi){
        int numofvertices,numbofedges,cost;
        char labelOFtheFirstVertex,labelOFthesecondVertex;
        fi >> numofvertices;
        fi >> numofedges;
        g = new int*[numofvertices];
        for(int i=0;i<numofvertices;i++)
            g[i] = new int[numofedges];
        for(int i=0;i<numofvertices;i++) {
            for (int j = 0; j < numofedges; j++) {
                g[i][j] = 0;
            }
        }
        for (int i = 0; i < numofedges; ++i) {
            fi>>labelOFtheFirstVertex>>labelOFthesecondVertex>>cost;
            g[labelOFtheFirstVertex-'a'][labelOFthesecondVertex-'a']=cost;
        }
    }
//find the shortest path from the start vertex to all other vertices, by filling the prev array and the distances array
void dijkstra(char startVertex, char* prev, Node<int> distances[] ) {
        MinHeap m;
        Node n;
        int numOFneighbors = numNeighbors(startVertex - 'a');
        int *arr = returnNeighbors(startVertex - 'a');
        for (int i = 0; i < nVertices; ++i) {
            if (arr[i] > 0) {
                distances[i].cost = arr[i];
                distances[i].label = i + 'a';
            } else {
                distances[i].cost = 0;
                distances[i].label = i + 'a';
            }
        }
        m.buildMinHeap(distances,numOFneighbors);
        bool sptSet[nVertices];
        int parent[nVertices];
        for (int i = 0; i < nVertices; ++i) {
            sptSet[i]= false;
            parent[i]=-1;
        }
        for (int i = 0; i < nVertices-1; ++i) {
            Node u=m.extractMin();
            sptSet[u.label-'a']= true;
            for (int j = 0; j < nVertices; ++j) {
                if (!sptSet[j]&&g[u.label-'a'][j]&&distances[u.label-'a'].cost+g[u.label-'a'][j]<distances[j].cost){
                    parent[j]=u.cost;
                    distances[j].cost=distances[u.label-'a'].cost+g[u.label-'a'][j];
                }
            }
        }
    }
};
int main()
{
    cWeightedGraph wg;
 ifstream ifile("graph.txt");
 wg.loadGraphFromFile(ifile);
 char* p;
 p = new char[wg.getNVertices()];
 Node* n;
 n=new Node[wg.getNVertices()];
 wg.dijkstra('g',p,n);
 cout<<endl<<"Node\tCost\tPrevious";
 for(int i=0;i<wg.getNVertices();i++)
 {
 cout<<endl<<n[i].label<<"\t"<<n[i].cost<<"\t"<<p[i];
 }
 ifile.close();
 return 0;

    return 0;
}
