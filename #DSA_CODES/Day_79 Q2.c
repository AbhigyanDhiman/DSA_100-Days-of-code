class Solution:
    def kosaraju(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)

        visited = [False] * V
        stack = []

        def dfs(u):
            visited[u] = True
            for v in adj[u]:
                if not visited[v]:
                    dfs(v)
            stack.append(u)

        for i in range(V):
            if not visited[i]:
                dfs(i)

        transpose = [[] for _ in range(V)]
        for u, v in edges:
            transpose[v].append(u)

        visited = [False] * V
        count = 0

        def dfs2(u):
            visited[u] = True
            for v in transpose[u]:
                if not visited[v]:
                    dfs2(v)

        while stack:
            node = stack.pop()
            if not visited[node]:
                dfs2(node)
                count += 1

        return count
