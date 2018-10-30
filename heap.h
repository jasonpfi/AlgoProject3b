#include <vector>
#include <math.h>

template<typename T>
class heap{

public:

   heap(std::vector<T> n):
      nodes(n), heapSize(n.size()) {}

   heap ():
      nodes(std::vector<T>()), heapSize(0) {}

   T& getItem(const int n);

   void swap(int i, int largest);

   void initializeMaxHeap(const std::vector<T>& v);
   void maxHeapify(int i);
   void buildMaxHeap();

   void heapsort();

   static int parent(const int index);
   static int left(const int index);
   static int right(const int index);

private:

   std::vector<T> nodes;
   int heapSize;
};
