#ifndef VECTOR_H
#define VECTOR_H

#include <sys/types.h>  // Pour size_t et ssize_t

// Enumération pour le statut des fonctions
typedef enum {
    VECTOR_SUCCESS = 0,
    VECTOR_ERROR_NULL_POINTER,
    VECTOR_ERROR_ALLOCATION,
    VECTOR_ERROR_OUT_OF_BOUNDS,
    VECTOR_ERROR_NOT_EMPTY
} VectorStatus;

// Structure du tableau dynamique
struct struct_vector{
    double* data; // Pointeur vers les données
	size_t size; // Taille actuelle du tableau
};

// Alias pour simplifier l'utilisation de la structure
typedef struct struct_vector s_vector; // Alias pour struct struct_vector
typedef s_vector* p_s_vector;          // Alias pour un pointeur vers struct_vector


// Fonctions de manipulation du vecteur

// Alloue et initialise un tableau dynamique de taille n
p_s_vector vector_alloc(size_t n);
// Libère la mémoire du tableau dynamique et met le pointeur à NULL
VectorStatus vector_free(p_s_vector *p_vector);

// Affecte la valeur v à l'index i du tableau dynamique
VectorStatus vector_set(p_s_vector p_vector, ssize_t i, double v);
// Récupère la valeur stockée à l'index i et la stocke dans pv
VectorStatus vector_get(p_s_vector p_vector, ssize_t i, double *pv);

// Insère une nouvelle valeur v à l'index i du tableau dynamique
VectorStatus vector_insert(p_s_vector p_vector, ssize_t i, double v);
// Supprime la valeur située à l'index i du tableau dynamique
VectorStatus vector_erase(p_s_vector p_vector, ssize_t i);

// Ajoute une valeur à la fin du tableau dynamique
VectorStatus vector_push_back(p_s_vector p_vector, double v);
// Supprime la dernière valeur du tableau dynamique
VectorStatus vector_pop_back(p_s_vector p_vector);
// Supprime toutes les valeurs du tableau dynamique
VectorStatus vector_clear(p_s_vector p_vector);

// Vérifie si le tableau dynamique est vide
VectorStatus vector_empty(p_s_vector p_vector);
// Vérifie si le tableau dynamique est plein
VectorStatus vector_size(p_s_vector p_vector, size_t *size);

#endif // VECTOR_H
