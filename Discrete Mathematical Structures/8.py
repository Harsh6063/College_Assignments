#Q8..Write a Program to accept a directed graph G and compute the in-degree and out-degree of each vertex.


def compute_degrees(graph):#DEFAULT FUNCTION TO CALCULATE IN-DEGREES AND OUT DEGREES
    num_vertices = len(graph)
    in_degrees = [0] * num_vertices
    out_degrees = [0] * num_vertices

    for i in range(num_vertices):
        for j in range(num_vertices):
            if graph[i][j] == 1:
                out_degrees[i] += 1# CALCULATING OUT DEGREES
                in_degrees[j] += 1#CALCULATING IN DEGREES

    return in_degrees, out_degrees# RETURNING THE VALUES


#OUR GRAPH REPRESENTED AS ADJACENT MATRIX
G = [[0, 1, 1, 0],
     [0, 1, 1, 1],
     [1, 0, 0, 1],
     [1, 1, 1, 0]]

in_degrees, out_degrees = compute_degrees(G)

print("Vertex\tIn-degree\tOut-degree")#PRINTING OUT THE RESULT 
for i in range(len(G)):
    print(f"{i}\t{in_degrees[i]}\t\t{out_degrees[i]}")
