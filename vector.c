#include "vector.h"
#include <stdlib.h> // Pour malloc, free, realloc

// Alloue et initialise un tableau dynamique
p_s_vector vector_alloc(size_t n) {
    // À implémenter
    return NULL;
}

// Libère la mémoire du tableau dynamique et met le pointeur à NULL
VectorStatus vector_free(p_s_vector *p_vector) {
    // À implémenter
    return VECTOR_ERROR_NULL_POINTER;
}

// Affecte la valeur v à l'index i du tableau dynamique
VectorStatus vector_set(p_s_vector p_vector, ssize_t i, double v) {
    // À implémenter
    return VECTOR_ERROR_NULL_POINTER;
}

// Récupère la valeur stockée à l'index i et la stocke dans pv
VectorStatus vector_get(p_s_vector p_vector, ssize_t i, double *pv) {
    // À implémenter
    return VECTOR_ERROR_NULL_POINTER;
}

// Insère une nouvelle valeur v à l'index i du tableau dynamique
VectorStatus vector_insert(p_s_vector p_vector, ssize_t i, double v) {
    // À implémenter
    return VECTOR_ERROR_NULL_POINTER;
}

// Supprime la valeur située à l'index i du tableau dynamique
VectorStatus vector_erase(p_s_vector p_vector, ssize_t i) {
    // À implémenter
    return VECTOR_ERROR_NULL_POINTER;
}

// Ajoute une valeur à la fin du tableau dynamique
VectorStatus vector_push_back(p_s_vector p_vector, double v) {
    // À implémenter
    return VECTOR_ERROR_NULL_POINTER;
}

// Supprime la dernière valeur du tableau dynamique
VectorStatus vector_pop_back(p_s_vector p_vector) {
    // À implémenter
    return VECTOR_ERROR_NULL_POINTER;
}

// Supprime toutes les valeurs du tableau dynamique
VectorStatus vector_clear(p_s_vector p_vector) {
    // À implémenter
    return VECTOR_ERROR_NULL_POINTER;
}

// Vérifie si le tableau dynamique est vide
VectorStatus vector_empty(p_s_vector p_vector) {
    // À implémenter
    return VECTOR_ERROR_NULL_POINTER;
}

// Récupère le nombre d'éléments stockés dans le tableau dynamique
VectorStatus vector_size(p_s_vector p_vector, size_t *size) {
    // À implémenter
    return VECTOR_ERROR_NULL_POINTER;
}

