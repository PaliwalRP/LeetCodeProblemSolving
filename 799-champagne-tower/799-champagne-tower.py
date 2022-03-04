class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        @cache
        def rec(r = query_row,c = query_glass):
            if r < 0 or c < 0 : return 0
            if r == 0 and c == 0 : return poured
            return max(rec(r - 1,c - 1) - 1, 0) / 2 + max(rec(r - 1,c) - 1, 0) / 2
        return min(1,rec())