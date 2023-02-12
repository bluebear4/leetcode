# python 自带 kmp
class Solution:
    def substringXorQueries(self, s: str, queries: list[list[int]]) -> list[list[int]]:
        res = []
        for querie in queries:
            find_str = bin(querie[0]^querie[1]).replace('0b', '')
            pos = s.find(find_str)
            if pos == -1:
                res.append([-1,-1])
            else:
                res.append([pos,pos + len(find_str) - 1])
        return res
