# Last updated: 9/16/2025, 12:10:48 AM
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # If one of the lists is empty, return the other one
        if not list1:
            return list2
        if not list2:
            return list1

        # Ensure that list1 starts with the smaller element
        if list1.val > list2.val:
            list1, list2 = list2, list1

        # The head of the merged list is list1
        head = list1

        while list1 and list2:
            prev=None
            while list1 and list1.val<=list2.val:
                prev=list1
                list1=list1.next
            prev.next=list2
            list1,list2=list2,list1

        return head        