#include "vector.h"
#include <stdlib.h> // Pour malloc, free, realloc

// Alloue et initialise un tableau dynamique
p_s_vector vector_alloc(size_t n) {
    // Vérifie si n est supérieur à 0
    if (n > 0) {
        // Alloue de la mémoire pour le tableau dynamique
        p_s_vector vector = malloc(sizeof(s_vector));
        if (vector != NULL) {
            vector->size = n;
            vector->data = malloc(n * sizeof(double));
            if (vector->data == NULL) {
                free(vector);
                return NULL;
            }
            // Initialise les valeurs du tableau à 0
            for (size_t i = 0; i < n; i++) {
                vector->data[i] = 0.0;
            }
            return vector;
        }
    }
    // Si n est 0 ou l'allocation échoue, retourne NULL
    return NULL;
}

// Libère la mémoire du tableau dynamique et met le pointeur à NULL
VectorStatus vector_free(p_s_vector *p_vector) {
    // Vérifie si le pointeur est valide
    if (p_vector != NULL && *p_vector != NULL) {
        // Libère la mémoire du tableau de données
        free((*p_vector)->data);
        // Libère la mémoire de la structure elle-même
        free(*p_vector);
        // Met le pointeur à NULL pour éviter les accès ultérieurs
        *p_vector = NULL;
        return VECTOR_SUCCESS;
    }
    // Si le pointeur est NULL, retourne une erreur
    if (p_vector == NULL) {
        return VECTOR_ERROR_NULL_POINTER;
    }
    // Si le tableau est vide, retourne une erreur
    if ((*p_vector)->data == NULL) {
        return VECTOR_ERROR_NOT_EMPTY;
    }
    // Si la taille est 0, retourne une erreur
    if ((*p_vector)->size == 0) {
        return VECTOR_ERROR_NOT_EMPTY;
    }
    return VECTOR_ERROR_NULL_POINTER;
}

// Affecte la valeur v à l'index i du tableau dynamique
VectorStatus vector_set(p_s_vector p_vector, ssize_t i, double v) {

    // Vérifie si le pointeur est valide
    if (p_vector == NULL || p_vector->data == NULL) {
        return VECTOR_ERROR_NULL_POINTER;
    }

    // Vérifie si l'index est valide
    if (i < 0 || (size_t)i >= p_vector->size) {
        return VECTOR_ERROR_OUT_OF_BOUNDS;
    }

    // Affecte la valeur v à l'index i
    p_vector->data[i] = v;

    return VECTOR_SUCCESS;
}

// Récupère la valeur stockée à l'index i et la stocke dans pv
VectorStatus vector_get(p_s_vector p_vector, ssize_t i, double *pv) {

    // Vérifie si le pointeur est valide
    if (p_vector == NULL || p_vector->data == NULL || pv == NULL) {
        return VECTOR_ERROR_NULL_POINTER;
    }

    // Vérifie si l'index est valide
    if (i < 0 || (size_t)i >= p_vector->size) {
        return VECTOR_ERROR_OUT_OF_BOUNDS;
    }
    
    // Récupère la valeur à l'index i
    *pv = p_vector->data[i];

    return VECTOR_SUCCESS;
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

