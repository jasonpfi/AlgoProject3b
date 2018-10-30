#include "heap.h"

T heap::parent(int index)
{
   return this->nodes.at(floor(index / 2));
}

T heap::left(int index)
{
   return this->nodes.at(2 * index);
}

T heap::right(int index)
{
   return this->nodes.at(2 * index + 1);
}

T heap::getItem(int n)
{
   return this->nodes.at(n);
}
