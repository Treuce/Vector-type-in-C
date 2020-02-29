#ifndef GENERIC_H
#include <stdio.h>
#include <stdlib.h>
#define GENERIC_H


typedef enum vector_type_t
{
    Int,
    Char,
    Float,
    Double,
    Vector
} vector_type;

typedef struct vector_t {
    int size;
    void * elements;
    vector_type type;
} vector;
typedef union vector_values_t
{
    int i;
    float f;
    char c;
    double d;
    vector v;
} vector_values;
vector vector_init(int size,vector_type type);

vector vector_init_defaultvalue(int size,vector_values defaultval, vector_type type);

void addsingle_to_vector(vector * vec, vector_values value);
void addvec_to_vector_free2nd(vector * vec, vector * toadd);
void addvec_to_vector(vector * vec, vector * toadd);
void insert(vector * vec, vector_values value, int index);
void add_int_array_to_vector(vector * vec, int values[],int arraysize);
void add_char_array_to_vector(vector * vec, char values[],int arraysize);
void add_double_array_to_vector(vector * vec, double values[],int arraysize);
void add_float_array_to_vector(vector * vec, float values[],int arraysize);
void vector_remove_element(vector * vec,vector_values element);
void vector_remove_at(vector * vec,int index);
void vector_log_values(vector * vec);
void vector_destructor(vector * vec);
int vector_compare(vector * v1,vector v2);
#endif // GENERIC_H
