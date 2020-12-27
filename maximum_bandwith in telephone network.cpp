
#include<bits/stdc++.h>
using namespace std;
int V = 0;
int graph[500][500];
//definition of node
struct node{
	int node,value;
};
//class priority queue 
class priorityqueue{
	private:
		vector<node> p_q;
	public:
	//function for swaping
	void swap(node &a,node &b){
		node temp = a;
		a = b;
		b = temp;
	}
	//heapify function
	void heapify(int i){
		int largest = i;
		int r = 2*i + 2;
		int l = 2*i + 1;
		if(r < p_q.size() && p_q[largest].value < p_q[r].value){
			largest = r;
		} 
		if(l < p_q.size() && p_q[largest].value < p_q[l].value){
			largest = l;
		} 
		if(largest != i){
			swap(p_q[i],p_q[largest]);
			heapify(largest);
		}
	}
	//push function for pushing element
	void push(int n , int key){
		//cout<<"push function is called"<<endl;
		node temp;
		temp.node = n;
		temp.value = key;
		p_q.push_back(temp);
		for(int i = p_q.size()/2 - 1 ; i >= 0; i-- ){
			heapify(i);
		}
	}
	//pop function for poping element
	int pop(){
		//cout<<"pop function is called"<<endl;
		int temp = p_q[0].node;
		p_q[0]=p_q[p_q.size()-1];
		p_q.pop_back();
		heapify(0);
		return temp;		
	}
	//function for checking whether priority queue is empty or not
	bool empty(){
		//cout<<"empty function is called"<<endl;
		if(p_q.size()==0)
		  return true;
		else
		 return false;
	}
};
//function for finding maximum element
int maximum(int a ,int b){
	if(a>b)
	  return a;
	else 
	  return b;
}
//function for finding minimum element
int minimum(int a ,int b){
	if(a<b)
	  return a ;
	  else
	    return b;
}
void extended_dikstra(int s, int d){
	//cout<<"called dijkstra"<<endl;
	
	int max_band[V];//store maximum bandwidth from source for every vertex
	// loop for initial assigning	
	for(int j=0;j<V;j++)
	{
		max_band[j]=INT_MIN;
		
	}
	max_band[s]=INT_MAX;
	//priority queue
	priorityqueue pq;
	pq.push(s,max_band[s]);
	while(!pq.empty()){
		int temp = pq.pop();
		for(int e=0 ; e< V;e++){
			if (graph[temp][e] != 0) 
			{ 
				//for storing maximum bandwidth from source to every vertex relaxation condition
				int distance=maximum(minimum(max_band[temp],graph[temp][e]),max_band[e]);
				
				if(distance>max_band[e])
				//pushing vertex into priority queue	
				pq.push(e,max_band[e]);
				//asigning updated maximum bandwidth to max_band array
				max_band[e]=distance;
				
			} 
		}
	}
	cout<<"maximum bandwidth between "<<s << " and "<<d<<" is "<<max_band[d];
}
int main(){
	int a,b;
	cout<<"enter the number of switching center"<<endl;
	cin>>V;
	cout<<"enter the adjacency matrix"<<endl;
	//taking input of adjacency matrix
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			cin>>graph[i][j];
	cout<<"enter source and destinaton"<<endl;
	cin>>a>>b;
	extended_dikstra(a,b);
	
	return 0;
}
