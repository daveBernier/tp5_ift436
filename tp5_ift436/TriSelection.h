
#include <iostream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <iterator>

using namespace std;

class TriSelection{
private:
	template<typename ForwardIterator> void selection_sort(ForwardIterator begin,
		ForwardIterator end) {
		for (auto i = begin; i != end; ++i) {
			std::iter_swap(i, std::min_element(i, end));
		}
	}
public:
	vector<int> selectionSort(vector<int> m)
	{

		selection_sort(std::begin(m), std::end(m));

		return m;
	}
}; 