import random


class Node:
    def __init__(self, data, next=None) -> None:
        self.data = data
        self.next = next


class LinkedList:
    def __init__(self) -> None:
        self.head = None

    def append(self, data):
        if not self.head:
            self.head = Node(data)
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = Node(data)

    def __str__(self):
        node = self.head
        while node is not None:
            print(node.data)
            node = node.next
        return "End"
    
    def search(self, target) -> bool:
        current = self.head
        while current.next:
            if current.data == target:
                return True
            else:
                current = current.next
        return False
    
    def remove(self, target):
        if self.head == target:
            self.head = self.head.next
            return
        current = self.head
        previous = None
        while current:
            if current.data == target:
                previous.next = current.next
            previous = current
            current = current.next
        return

    def reverse_list(self):
        current = self.head
        previous = None
        while current:
            next = current.next
            current.next = previous
            previous = current
            current = next
        self.head = previous

    def detect_cycle(self):
        slow = self.head
        fast = self.head

        while True:
            try:
                slow = slow.next
                fast = fast.next.next
                if slow is fast:
                    return True
            except:
                return False
            

a_list = LinkedList()

for i in range(5):
    item = random.randint(1, 30)
    a_list.append(item)
    # print(item, end=" ")

print()
print(a_list.search(10))
print(a_list)
a_list.reverse_list()
print(a_list)