class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n = len(s)
        a = [[0] * 26 for _ in range(n)]
        b = [[0] * 26 for _ in range(n)]
        
        a[0][ord(s[0]) - ord('a')] += 1
        b[n - 1][ord(s[n - 1]) - ord('a')] += 1
        
        for i in range(1, n):
            for j in range(26):
                a[i][j] = a[i - 1][j]
            a[i][ord(s[i]) - ord('a')] += 1
        
        for i in range(n - 2, -1, -1):
            for j in range(26):
                b[i][j] = b[i + 1][j]
            b[i][ord(s[i]) - ord('a')] += 1
        
        st = set()
        for i in range(1, n - 1):
            for j in range(26):
                t = chr(ord('a') + j) + s[i]
                if a[i - 1][j] > 0 and b[i + 1][j] > 0:
                    st.add(t)
        
        return len(st)
