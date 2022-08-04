# What are queues?

Queues are lists where insertion is done at the end while the deletion is done at the front end. It follows the first in first out order(FIFO).

# Operations on queue

1. Enqueue- Inserts the element at the rear end of the list. 
2. Dequeue- Deletes an element from the beginning of the list. 

# Priority Queue

Priority Queue is a queue where the elements of it have an associated priority with it.
Every item has a priority associated with it.
An element with high priority is dequeued before an element with low priority.
If two elements have the same priority, they are served according to their order in the queue.

# Types of Priority Queue

1. Ascending Queue- In ascending order priority queue, the element with a lower priority value is given a higher priority in the priority list.

2. Descending Queue- The root node is the maximum element in a max heap, as you may know. It will also remove the element with the highest priority first. 

# Operations in a Priority Queue

1. Insertion- When the element is inserted in a Priority Queue it is checked if the element is in the correct order or not. If not, elements are swapped.
2. Deletion- Maximum element from the Max Heap is deleted.
3. Peek- Returns the maximum element from Max Heap or the minimum element from Min Heap.

# Circular Queue

Circular Queue is a special version of queue where the last element of the queue is connected to the first element of the queue forming a circle.

# Operations on Circular Queue

1. Front- Get the front item from queue.
2. Rear- Get the last item from queue.
3. Enqueue- This function is used to insert an element into the circular queue at rear position.
4. Dequeue- This function is used to delete an element from the circular queue from fron position.

Ref. Taken- GeeksForGeeks