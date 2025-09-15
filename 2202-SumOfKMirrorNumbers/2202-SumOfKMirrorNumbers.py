# Last updated: 9/16/2025, 12:01:46 AM
class Solution:
    def kMirror(self, k: int, n: int) -> int:
        def is_palindrome(s: str) -> bool:
            return s == s[::-1]

        def to_base_k(x: int, base: int) -> str:
            res = []
            while x > 0:
                res.append(str(x % base))
                x //= base
            return ''.join(reversed(res))

        def generate_palindromes():
            # Start with length 1 and grow
            length = 1
            while True:
                # Odd-length palindromes
                half_start = 10 ** ((length - 1) // 2)
                half_end = 10 ** ((length + 1) // 2)
                for half in range(half_start, half_end):
                    s = str(half)
                    if length % 2 == 0:
                        yield int(s + s[::-1])
                    else:
                        yield int(s + s[-2::-1])
                length += 1

        count = 0
        total = 0

        for val in generate_palindromes():
            if is_palindrome(to_base_k(val, k)):
                total += val
                count += 1
                if count == n:
                    break

        return total
