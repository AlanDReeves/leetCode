class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # turn linkedlist 1 into an int
        sum1: int = 0
        multiplier = 1
        cursor = l1
        while cursor is not None:
            sum1 += (cursor.val * multiplier)
            multiplier *= 10
            cursor = cursor.next
        
        # turn linkedlist 2 into an int
        sum2: int = 0
        multiplier = 1
        cursor = l2
        while cursor is not None:
            sum2 += (cursor.val * multiplier)
            multiplier *= 10
            cursor = cursor.next

        # sum1 and sum2 should now be set correctly

        result = sum1 + sum2
        
        # convert result into linked list answer
        screen = 10
        insertNum= int(result % screen)
        start = ListNode(val=insertNum)
        cursor = start
        result -= (insertNum * int(screen // 10))

        while result > 0:
            screen *= 10
            insertNum = (result % screen) // int(screen // 10)
            new = ListNode(val=int(insertNum))
            cursor.next = new
            cursor = cursor.next
            result -= (insertNum * int(screen // 10))

        return start