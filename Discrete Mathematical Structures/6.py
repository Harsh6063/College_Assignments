 #Q6....Write a Program to check if a given graph is a complete graph. Represent the graph using

#the Adjacency Matrix representation


def is_complete_graph(graph):# DEFAULT FUNCTION
    num_vertices = len(graph)

    # Check if each vertex is connected to all other vertices
    for i in range(num_vertices):
        for j in range(num_vertices):
            if i != j and graph[i][j] != 1:#CHECKS FOR THE CONNECTION OF EACH VERTEX TO EVERY OTHER VERTEX
                return False

    return True


# Example usage
G = [[0, 1, 1, 1],
     [1, 0, 1, 1],
     [1, 1, 0, 1],
     [1, 1, 1, 0]]
print("LENGTH",len(G))
result = is_complete_graph(G)
if result:
    print("The graph is a complete graph")
else:
    print("The graph is not a complete graph")

