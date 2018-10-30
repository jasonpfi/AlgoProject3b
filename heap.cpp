#include "heap.h"

template <typename T>
int heap<T>::parent(const int index)
{
   return floor(index / 2);
}

template <typename T>
int heap<T>::left(const int index)
{
   return 2 * index;
}

template <typename T>
int heap<T>::right(const int index)
{
   return 2 * index + 1;
}

template <typename T>
T& heap<T>::getItem(const int n)
{
   return this->nodes.at(n);
}

template <typename T>
void heap<T>::maxHeapify(int i)
{
   int largest;

   int l = this->left(i);
   int r = this->right(i);

   if (l <= this->heapSize && this->getItem(l) > this->getItem(i))
   {
      largest = l;
   }
   else
      largest = i;

   if (r <= this->heapSize && this->getItem(r) > this->getItem(largest))
   {
      largest = r;
   }

   if (largest != i)
   {
      this->swap(i, largest);
      this->maxHeapify(largest);
   }
}

template <typename T>
void heap<T>::swap(int i, int largest)
{
   T tmp = this->getItem(i);
   this->getItem(i) = this->getItem(largest);
   this->getItem(largest) = tmp;
}

template <typename T>
void heap<T>::buildMaxHeap()
{
   for (int i = floor(this->nodes.size() / 2); i >= 0; i--)
   {
      this->maxHeapify(i);
   }
}

template <typename T>
void heap<T>::initializeMaxHeap(const std::vector<T>& v)
{
   this->nodes = v;
   this->heapSize = v.size();
}

template <typename T>
void heap<T>::heapsort()
{
   this->buildMaxHeap();

   for (int i = this->nodes.size(); i >= 1; i--)
   {
      this->swap(1, i);;
      this->heapSize--;
      this->maxHeapify(1);
   }
}








