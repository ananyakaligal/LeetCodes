# Last updated: 9/16/2025, 12:08:28 AM
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Base case: if head is null or there is only one element in the list
        if not head or not head.next:
            return head
        
        # Function to split the linked list into two halves
        def split(head):
            slow, fast = head, head.next
            while fast and fast.next:
                slow = slow.next
                fast = fast.next.next
            mid = slow.next
            slow.next = None
            return head, mid

        # Function to merge two sorted linked lists
        def merge(l1, l2):
            dummy = ListNode()
            tail = dummy
            while l1 and l2:
                if l1.val < l2.val:
                    tail.next, l1 = l1, l1.next
                else:
                    tail.next, l2 = l2, l2.next
                tail = tail.next
            tail.next = l1 or l2
            return dummy.next
        
        # Split the list into two halves
        left, right = split(head)
        
        # Recursively sort each half
        left = self.sortList(left)
        right = self.sortList(right)
        
        # Merge the sorted halves
        return merge(left, right)