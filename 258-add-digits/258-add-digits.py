class Solution:
    def addDigits(self, num: int) -> int:
        if num == 0:
            return num
        digit = num % 9
        if digit == 0:
            digit = 9
        return digit
        