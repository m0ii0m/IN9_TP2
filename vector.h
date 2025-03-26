#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>  // Pour size_t et ssize_t

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
	//À compléter
};

typedef struct struct_vector s_vector;
typedef s_vector* p_s_vector;

// Fonctions de manipulation du vecteur
p_s_vector vector_alloc(size_t n);
VectorStatus vector_free(p_s_vector *p_vector);

VectorStatus vector_set(p_s_vector p_vector, ssize_t i, double v);
VectorStatus vector_get(p_s_vector p_vector, ssize_t i, double *pv);

VectorStatus vector_insert(p_s_vector p_vector, ssize_t i, double v);
VectorStatus vector_erase(p_s_vector p_vector, ssize_t i);

VectorStatus vector_push_back(p_s_vector p_vector, double v);
VectorStatus vector_pop_back(p_s_vector p_vector);
VectorStatus vector_clear(p_s_vector p_vector);

VectorStatus vector_empty(p_s_vector p_vector);
VectorStatus vector_size(p_s_vector p_vector, size_t *size);

#endif // VECTOR_H
