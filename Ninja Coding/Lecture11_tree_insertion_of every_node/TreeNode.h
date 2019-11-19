#include <vector>
using namespace std;
//using vextor will solve prob of size and access
//vector will store the address of children
template <typename T>
class TreeNode {
	public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(T data) {
		this->data = data;
	}

};
/*if we use ll then accessing 2nd child for example will be a problem
in arrays size is a problem
*/
