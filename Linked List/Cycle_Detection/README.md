# Cycle Detection in a Linked List

When a node in a linked list points to one of its previous nodes, a cycle is formed.

If we traverse a linked list through the head pointer, we shall never encounter its end, i.e. NULL. This property makes its use in the standard 'hare and tortoise technique' used to detect a cycle in a singly linked list.

## Algorithm

We take two pointers, ideally 'fast' and 'slow'. Move the fast pointer two nodes and the slow pointer single node at a time. If fast reaches the end of the list, there is no cycle in the linked list, whereas if fast and slow ever point to the same node, it indicates that there is a cycle present in the linked list.

Further, to find at which node the cycle is formed, we place one of the pointers, fast or slow at the head, and move both pointers one node at a time. The node at which they meet will be the node the cycle is formed.

## Intuition
The intuition behind this algorithm comes from a circular racing track where two players will always meet each other unless they're running with the same speed.

Time Complexity: O(n)  
Space Complexity: O(1)
