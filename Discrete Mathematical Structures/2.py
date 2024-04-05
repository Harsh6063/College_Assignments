'''Q2... Create a class RELATION, use Matrix notation to represent a relation. Include member functions to check if the relation is Reflexive, Symmetric, Anti-symmetric, Transitive. Using these functions check whether the given relation is. Equivalence or Partial Order relation or None'''
class RELATION:
    def __init__(self, matrix):
        self.matrix = matrix

    def is_reflexive(self):#CHECKS FOR REFLEXIVITY
        for i in range(len(self.matrix)):
            if self.matrix[i][i] != 1:
                return False
        return True

    def is_symmetric(self):#CHECKS FOR SYMMETRICITY
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                if self.matrix[i][j] != self.matrix[j][i]:
                    return False
        return True

    def is_antisymmetric(self):#CHECKS FOR ANTI-SYMMETRICITY
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                if i != j and self.matrix[i][j] == 1 and self.matrix[j][i] == 1:
                    return False
        return True

    def is_transitive(self):#CHECKS FOR TRANSITIVITY
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                if self.matrix[i][j] == 1:
                    for k in range(len(self.matrix[j])):
                        if self.matrix[j][k] == 1 and self.matrix[i][k] != 1:
                            return False
        return True

    def is_equivalence_relation(self):#CHECKS FOR EQUIVALENCE RELATION
        return self.is_reflexive() and self.is_symmetric() and self.is_transitive()

    def is_partial_order_relation(self):#CHECKS FOR PARTIAL-ORDER RELATION
        return self.is_reflexive() and self.is_antisymmetric() and self.is_transitive()


# MATRIX ENTRY
relation_matrix = [
    [1, 1, 0],
    [1, 1, 1],
    [0, 1, 1]
]

relation = RELATION(relation_matrix)

print("Reflexive:", relation.is_reflexive())
print("Symmetric:", relation.is_symmetric())
print("Anti-symmetric:", relation.is_antisymmetric())
print("Transitive:", relation.is_transitive())

if relation.is_equivalence_relation():
    print("The relation is an Equivalence relation.")
elif relation.is_partial_order_relation():
    print("The relation is a Partial Order relation.")
else:
    print("The relation is neither an Equivalence relation nor a Partial Order relation.")
