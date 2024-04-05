#Q7...Write a Program to check if a given graph is a complete graph. Represent the graph using

#the Adjacency List representation.


def is_complete_graph(graph):# DEFAULT FUNCTION
    num_vertices = len(graph)

    # Check if each vertex is connected to all other vertices
    for vertex in range(num_vertices):
        connected_vertices = set(graph[vertex])#CONVERTS THE KEY TO A SET
        if len(connected_vertices) != num_vertices - 1:# CALCULATES THE LENGTH OF THE SET AND CHECKS THE CONDITION
            return False

    return True


# GRAPH AS ADJACENCY LIST
G = {
    0: [0, 0, 3],
    1: [1, 3, 2 ],
    2: [0, 1, 3],
    3: [0, 1, 2]
    }
print("LENGTH",len(G))
result = is_complete_graph(G)
if result:
    print("The graph is a complete graph")
else:
    print("The graph is not a complete graph")

