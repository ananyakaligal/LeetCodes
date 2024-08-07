class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        merge = []

        for x, y in zip(word1, word2):
            merge.append(x)
            merge.append(y)

        merge.append(word1[len(word2):])
        merge.append(word2[len(word1):])

        return "".join(merge)