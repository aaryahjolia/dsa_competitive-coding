## Insertion in Singly Linked List

Insertion in a Singly Linked List involves adding a new node with data to the list. There are several ways to insert a node depending on where we want to place it.

### Types of Insertion

1. **Insert at the Beginning**  
   Inserting a node at the start of the list. This involves updating the new node’s `next` pointer to the current head and then updating the head to the new node.

2. **Insert at the End**  
   Adding a node at the end of the list. This requires traversing to the last node and updating its `next` pointer to the new node.

3. **Insert at a Given Position**  
   Inserting a node at a specific position in the list. This involves traversing to the position just before the desired location, updating pointers to link the new node into the list.

### Node Structure

The structure of the node remains the same as in a singly linked list, with each node containing a `val` and a pointer to the `next` node.

```python
class SinglyListNode:
    def __init__(self, value):
        self.val = value
        self.next = None
```

### Example of Insertion Functions in Python

Here's how you might implement each type of insertion:

1. **Insert at the Beginning**

```python
def insert_at_beginning(head, value):
    new_node = SinglyListNode(value)
    new_node.next = head
    return new_node
```

2. **Insert at the End**

```python
def insert_at_end(head, value):
    new_node = SinglyListNode(value)
    if not head:
        return new_node
    temp = head
    while temp.next:
        temp = temp.next
    temp.next = new_node
    return head
```

3. **Insert at a Given Position**

```python
def insert_at_position(head, value, position):
    new_node = SinglyListNode(value)
    if position == 1:
        new_node.next = head
        return new_node
    temp = head
    for _ in range(position - 2):
        if temp is None:
            return head  # Position is out of bounds
        temp = temp.next
    new_node.next = temp.next
    temp.next = new_node
    return head
```

### Complexity

The time complexity for each insertion type is as follows:

1. **Insert at the Beginning: 𝑂(1)**
2. **Insert at the End: 𝑂(N) (due to traversal)**
3. **Insert at a Given Position: 𝑂(N)**
