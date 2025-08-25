# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        head = None
        tail = None

        cursor1 = list1
        cursor2 = list2

        def getLowNode(node1, node2):
            if node1 is None and node2 is None:
                return None
            if node1 is None:
                return node2
            if node2 is None:
                return node1
            if node1.val < node2.val: 
                return node1
            else:
                return node2 # also defaults to node2 if values are equal

        # determine head node to return
        head = getLowNode(cursor1, cursor2)
        if head is not None:
            if head is cursor1:
                cursor1 = cursor1.next
            elif head is cursor2:
                cursor2 = cursor2.next
            # advance cursor to avoid double counting
        tail = head

        while cursor1 is not None or cursor2 is not None:
            append = getLowNode(cursor1, cursor2)
            if append is cursor1:
                cursor1 = cursor1.next
            elif append is cursor2:
                cursor2 = cursor2.next
            tail.next = append
            tail = tail.next

        return head