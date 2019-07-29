#include <iostream>
#include <vector>
using namespace std;

class Heap
{
	vector<int> v;
	bool minheap;

	bool compare(int parentData, int childData){
		if(minheap){
			return parentData>childData;
		}
		else{
			return parentData<childData;
		}

	}

public:
	Heap(bool type=true){
		minheap = type;
		v[0] = -1;
	}
	void insert(int data){
		v.push_back(data);

		int child = v.size()-1;
		int parent = child/2;

		while(compare(v[parent],v[child]) && parent != 0){
			swap(v[parent], v[child]);
			child = parent;
			parent = child/2;

		}
	}

	bool empty(){
		return v.size() <= 1;
	}
	int top(){
		if(empty()){
			return -1;
		}
		return v[1];
	}

	void pop(){
		
	}



	
	
};

int main(int argc, char const *argv[])
{
	Heap h;
	h.insert(5);
	h.insert(10);
	h.insert(15);
	return 0;
}







