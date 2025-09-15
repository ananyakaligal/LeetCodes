# Last updated: 9/16/2025, 12:08:27 AM
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None

        # Initialize two pointers
        pointerA, pointerB = headA, headB

        # Traverse both lists
        while pointerA is not pointerB:
            # Move to the next node or switch to the head of the other list
            pointerA = pointerA.next if pointerA else headB
            pointerB = pointerB.next if pointerB else headA

        # Both pointers meet at the intersection node or at None
        return pointerA

        