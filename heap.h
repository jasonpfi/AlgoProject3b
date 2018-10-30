#include <vector>
#include <math.h>

template<typename T>
class heap{

public:

   heap(std::vector<T> n):
      nodes(n) {}

   heap ():
      nodes(std::vector<T>()) {}

   T parent(int index);
   T left(int index);
   T right(int index);
   T getItem(int n);

   void initializeMaxHeap();
   void maxHeapify();
   void buildMaxHeap();

   void heapSort();

private:

   std::vector<T> nodes;
}
