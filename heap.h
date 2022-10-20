#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m = 2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  std::size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> data;
  void heapify(int idx);
	int m;
	PComparator c;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){
  std::vector<T>().swap(data);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
	return data[0];
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty");
  }
	data[0] = data[size() - 1];
	data.pop_back();
	heapify(0);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int idx){
	if((unsigned int)(idx * 2 + 1) >= size()) return;
	int betterChild = 2 * idx + 1;
	if((unsigned int)(2 *idx + 2) < size()){
		int rChild = betterChild + 1;
		if(c(data[rChild], data[betterChild])){
			betterChild = rChild;
		}
	}
	if(c(data[betterChild], data[idx])){
		std::swap(data[idx], data[betterChild]);
		heapify(betterChild);
	}
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){
	data.push_back(item);
	std::size_t idx = data.size() - 1;
	int parent = (idx - 1) / 2;
	while(idx != 0 && c(data[idx], data[parent])){
		std::swap(data[idx], data[parent]);
		idx = parent;
		parent = (idx - 1) / 2;
	}
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
	return !size();
}

template <typename T, typename PComparator>
std::size_t Heap<T, PComparator>::size() const{
	return data.size();
}

#endif