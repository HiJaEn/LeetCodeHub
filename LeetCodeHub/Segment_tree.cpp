#include "iostream"
#include <vector>
using namespace std;
const int maxLen=0;

void build_tree(vector<int> arr,vector<int> &tree,int node,int start,int end){
	if(start == end)
		tree[node] = arr[start];
	else{
		int mid = (start+end)>>1;
	  	int left_node = 2*node+1;
	  	int right_node = 2*node+2;
	  	build_tree(arr,tree,left_node,start,mid);
	  	build_tree(arr,tree,right_node,mid+1,end);
	  	tree[node] = tree[left_node] +tree[right_node];
  }
}

void update_tree(vector<int> &arr,vector<int> &tree,int node,int start,int end,int index,int val){
	if(start == end){
		arr[index] = val;
		tree[node] = val;
	}else{
		int mid = (start+end)/2;
		int left_node = 2*node +1;
		int right_node = 2*node +2;
		if(index>=start && index<=mid){
			update_tree(arr,tree,left_node,start,mid,index,val);
		}
		else{
			update_tree(arr,tree,right_node,mid+1,end,index,val);
		}
		tree[node] = tree[left_node]+tree[right_node];
	}
}

int query_tree(vector<int> arr,vector<int> tree,int node,int start,int end,int left,int right){
	if(right<start || left>end){
		return 0;
	}
	else if(start == end){
		return tree[node];
	}
	else if(start>=left && end<=right){
		return tree[node];
	}
	else{
		int mid = (start+end)>>1;
		int left_node = 2*node +1;
		int right_node = 2*node +2;
		int sum_left = query_tree(arr,tree,left_node,start,mid,left,right);
		int sum_right = query_tree(arr,tree,right_node,mid+1,end,left,right);
		return sum_right+sum_left;
	}
}

int main(){
	vector<int> arr = {1,3,5,7,9,11};
	int size = arr.size();
	vector<int> tree(1000,0);
	build_tree(arr,tree,0,0,size-1);
	for(int i=0;i<15;i++)
		std::cout<<tree[i]<<" ";
	std::cout<<endl;
	update_tree(arr,tree,0,0,size-1,4,6);
	for(int i=0;i<15;i++)
		std::cout<<tree[i]<<" ";
	std::cout<<endl;
	int res = query_tree(arr,tree,0,0,size-1,2,5);
	std::cout<<res<<endl;
	return 0;
}

