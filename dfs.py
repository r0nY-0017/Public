from collections import defaultdict

def dfs(node, adj, vis):
    print(node, end="\t")
    vis[node] = True
    for child in adj[node]:
        if not vis[child]:
            dfs(child, adj, vis)

def reset(n, adj, vis):
    for i in range(n):
        vis[i] = False
        adj[i].clear()

def main():
    adj = defaultdict(list)
    vis = {}
    
    n = int(input("Number of Nodes: "))
    e = int(input("Number of Edges: "))
    start = int(input("Starting Node: "))
    
    print("Enter Edges:")
    for _ in range(e):
        x, y = map(int, input().split())
        adj[x].append(y)
        adj[y].append(x)
        vis[x] = vis[y] = False  # Initialize visited dictionary
    
    dfs(start, adj, vis)
    print()
    reset(n, adj, vis)

if __name__ == "__main__":
    main()
