class KthLargest:
   def __init__(self, k, nums):
      self.array = nums
      self.k = k
   def add(self, val):
      self.array.append(val)
      self.array.sort()
      return self.array[len(self.array)-self.k]
ob = KthLargest(3, [4,5,8,2])
print(ob.add(3))
print(ob.add(5))
print(ob.add(10))
print(ob.add(9))
print(ob.add(4))