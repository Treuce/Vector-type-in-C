#include "generic.h"
vector vector_init(int size, vector_type type)
{
    vector tmp = { .size = size, .type = type};
    switch (type)
    {
    case Int:
        {
            int * arr = (int*) malloc(size*sizeof(int));
            if (arr == NULL)
            {
                printf("Memory error.\n");
                exit(1);
            }
            tmp.elements = arr;
            break;
        }
    case Char:
        {
            char * arr = (char*) malloc (size);
            if (arr == NULL)
            {
                printf("Memory error.\n");
                exit(1);
            }
            tmp.elements = arr;
        }
    case Float:
        {
            float * arr = (float*) malloc(size*sizeof(float));
            if (arr == NULL)
            {
                printf("Memory error.\n");
                exit(1);
            }
            tmp.elements = arr;
        }
    case Double:
        {
            double* arr = (double*) malloc(size*sizeof(double));
            if (arr == NULL)
            {
                printf("Memory error.\n");
                exit(1);
            }
            tmp.elements = arr;
        }
    case Vector:
        {
            vector * arr = (vector*) malloc(size*sizeof(vector));
            if (arr == NULL)
            {
                printf("Memory error\n");
                exit(1);
            }
            tmp.elements = arr;
        }
    }

    return tmp;
}

vector vector_init_defaultvalue(int size,vector_values defaultval, vector_type type)
{
    vector tmp = { .size = size, .type = type};
    switch (type)
    {
    case Int:
        {
            int* arr = (int*) malloc(size * sizeof(int));
            if (arr == NULL)
            {
                printf("Memory error.\n");
                exit(1);
            }
            for (int i = 0; i < size; i++)
            {
                arr[i] = defaultval.i;
            }
            tmp.elements = arr;
            break;
        }
    case Char:
        {
            char* arr = (char*) malloc(size);
            if (arr == NULL)
            {
                printf("Memory error.\n");
                exit(1);
            }
            for (int i = 0; i < size; i++)
            {
                arr[i] = defaultval.c;
            }
            tmp.elements = arr;
            break;
        }
    case Float:
        {
            float * arr = (float*) malloc(size * sizeof(float));
            if (arr == NULL)
            {
                printf("Memory error.\n");
                exit(1);
            }
            for (int i = 0; i < size; i++)
            {
                arr[i] = defaultval.f;
            }
            tmp.elements = arr;
            break;
        }
    case Double:
        {
            double * arr = (double*) malloc(size * sizeof(double));
            if (arr == NULL)
            {
                printf("Memory error.\n");
                exit(1);
            }
            for (int i = 0; i < size; i++)
            {
                arr[i] = defaultval.d;
            }
            tmp.elements = arr;
            break;
        }
    case Vector:
        {
            vector * arr = (vector*) malloc(size * sizeof(vector));
            if (arr == NULL)
            {
                printf("Memory error.\n");
                exit(1);
            }
            for (int i = 0; i < size; i++)
            {
                arr[i] = defaultval.v;
            }
            tmp.elements = arr;
            break;
        }
    }
    return tmp;
}

void addsingle_to_vector(vector * vec, vector_values value)
{
    int newsize = (*vec).size + 1;
    switch ((*vec).type)
    {
    case Int:
        {
            int* tmp = (int*) realloc((*vec).elements,newsize * sizeof(int));
            if (tmp == NULL)
            {
                free((*vec).elements);
                printf("Memory error.\n");
                exit(1);
            }
            tmp[newsize-1] = value.i;
            (*vec).elements = tmp;
            break;
        }
    case Char:
        {
            char * tmp = (char*) realloc ((*vec).elements, newsize);
            if (tmp == NULL)
            {
                free((*vec).elements);
                printf("Memory error.\n");
                exit(1);
            }
            tmp[newsize-1] = value.c;
            (*vec).elements = tmp;
            break;
        }
    case Float:
        {
            float* tmp = (float*) realloc((*vec).elements, newsize * sizeof(float));
            if (tmp == NULL)
            {
                free((*vec).elements);
                printf("Memory error.\n");
                exit(1);
            }
            tmp[newsize-1] = value.f;
            (*vec).elements = tmp;
            break;
        }
    case Double:
        {
            double* tmp = (double*) realloc((*vec).elements, newsize * sizeof(double));
            if (tmp == NULL)
            {
                free((*vec).elements);
                printf("Memory error.\n");
                exit(1);
            }
            tmp[newsize-1] = value.d;
            (*vec).elements = tmp;
            break;
        }
    case Vector:
        {
            vector* tmp = (vector*) realloc((*vec).elements,newsize * sizeof(vector));
            vector toadd = value.v;
            if (tmp == NULL)
            {
                free((*vec).elements);
                printf("Memory error.\n");
                exit(1);
            }
            tmp[newsize-1] = toadd;
            (*vec).elements = tmp;
            break;
        }
    }
    (*vec).size = newsize;
}

void addvec_to_vector_free2nd(vector * vec, vector * toadd)
{

    if ((*toadd).type != (*vec).type)
    {
        printf("Different data types for vectors.\n");
        free((*vec).elements);
        free((*toadd).elements);
        exit(1);
    }
    int newsize = (*vec).size + (*toadd).size;
    switch ((*vec).type)
    {
    case Int:
        {
            int * tmp = (int*) realloc((*vec).elements, newsize*sizeof(int));
            if (tmp == NULL)
            {
                free((*vec).elements);
                free((*toadd).elements);
                printf("Memory error.\n");
                exit(1);
            }
            int index = 0;
            int * secondvec = (int*) (*toadd).elements;
            for (int i = (*vec).size; i < newsize; i++)
            {
                tmp[i] = secondvec[index];
                index++;
            }
            (*vec).elements = (void*)tmp;
            break;
        }
    case Char:
        {
            char * tmp = (char*) realloc((*vec).elements, newsize);
            if (tmp == NULL)
            {
                free((*vec).elements);
                free((*toadd).elements);
                printf("Memory error.\n");
                exit(1);
            }
            int index = 0;
            char * secondvec = (char*) (*toadd).elements;
            for (int i = (*vec).size; i < newsize; i++)
            {
                tmp[i] = secondvec[index];
                index++;
            }
            (*vec).elements = (void*)tmp;
            break;
        }
    case Float:
        {
            float * tmp = (float*) realloc((*vec).elements, newsize*sizeof(float));
            if (tmp == NULL)
            {
                free((*vec).elements);
                free((*toadd).elements);
                printf("Memory error.\n");
                exit(1);
            }
            int index = 0;
            float * secondvec = (float*) (*toadd).elements;
            for (int i = (*vec).size; i < newsize; i++)
            {
                tmp[i] = secondvec[index];
                index++;
            }
            (*vec).elements = (void*)tmp;
            break;
        }
    case Double:
        {
            double * tmp = (double*) realloc((*vec).elements, newsize*sizeof(double));
            if (tmp == NULL)
            {
                free((*vec).elements);
                free((*toadd).elements);
                printf("Memory error.\n");
                exit(1);
            }
            int index = 0;
            double * secondvec = (double*) (*toadd).elements;
            for (int i = (*vec).size; i < newsize; i++)
            {
                tmp[i] = secondvec[index];
                index++;
            }
            (*vec).elements = (void*)tmp;
            break;
        }
    case Vector:
        {
            vector* tmp = (vector*) realloc((*vec).elements, newsize*sizeof(vector));
            if (tmp == NULL)
            {
                free((*vec).elements);
                free((*toadd).elements);
                printf("Memory error.\n");
                exit(1);
            }
            int index = 0;
            vector * secondvec = (vector*) (*toadd).elements;
            for (int i = (*vec).size; i < newsize; i++)
            {
                tmp[i] = secondvec[index];
                index++;
            }
            (*vec).elements = (void*) tmp;
            break;
        }
    }
    free((*toadd).elements);
    (*toadd).size = 0;
    (*toadd).elements = NULL;
    (*vec).size = newsize;
}

void addvec_to_vector(vector * vec, vector * toadd)
{
    if ((*toadd).type != (*vec).type)
    {
        printf("Different data types for vectors.\n");
        free((*vec).elements);
        free((*toadd).elements);
        exit(1);
    }
    int newsize = (*vec).size + (*toadd).size;
    switch ((*vec).type)
    {
    case Int:
        {
            int * tmp = (int*) realloc((*vec).elements, sizeof(int)*newsize);
            if (tmp == NULL)
            {
                printf("Memory error.\n");
                free((*toadd).elements);
                free((*vec).elements);
                exit(1);
            }
            int * second = (int*)(*toadd).elements;
            int index = 0;
            for (int i = (*vec).size; i < newsize; i++)
            {
                tmp[i] = second[index];
                index++;
            }
            (*vec).elements = tmp;
            break;
        }
    case Char:
        {
            char* tmp = (char*)realloc((*vec).elements, newsize);
            if (tmp == NULL)
            {
                printf("Memory error.\n");
                free((*toadd).elements);
                free((*vec).elements);
                exit(1);
            }
            char * second = (char*)(*toadd).elements;
            int index = 0;
            for (int i = (*vec).size; i < newsize; i++)
            {
                tmp[i] = second[index];
                index++;
            }
            (*vec).elements = tmp;
            break;
        }
    case Float:
        {
            float* tmp = (float*) realloc((*vec).elements, newsize * sizeof(float));
            if (tmp == NULL)
            {
                printf("Memory error.\n");
                free((*toadd).elements);
                free((*vec).elements);
                exit(1);
            }
            float* second = (float*)(*toadd).elements;
            int index = 0;
            for (int i = (*vec).size; i < newsize; i++)
            {
                tmp[i] = second[index];
                index++;
            }
            (*vec).elements = tmp;
            break;
        }
    case Double:
        {
            double* tmp = (double*) realloc((*vec).elements, newsize * sizeof(double));
            if (tmp == NULL)
            {
                printf("Memory error.\n");
                free((*toadd).elements);
                free((*vec).elements);
                exit(1);
            }
            double* second = (double*)(*toadd).elements;
            int index = 0;
            for (int i = (*vec).size; i < newsize; i++)
            {
                tmp[i] = second[index];
                index++;
            }
            (*vec).elements = tmp;
            break;
        }
    case Vector:
        {
            vector* tmp = (vector*) realloc((*vec).elements, newsize*sizeof(vector));
            if (tmp == NULL)
            {
                printf("Memory error.\n");
                free((*toadd).elements);
                free((*vec).elements);
                exit(1);
            }
            vector* second = (vector*)(*toadd).elements;
            int index = 0;
            for (int i = (*vec).size; i < newsize; i++)
            {
                tmp[i] = second[index];
                index++;
            }
            (*vec).elements = tmp;
            break;
        }
    }
    (*vec).size = newsize;
}


void insert(vector * vec, vector_values value, int index)
{
    if (index > (*vec).size)
    {
        printf("Can not insert at this index.\n");
        free((*vec).elements);
        exit(1);
    }
    int newsize = (*vec).size + 1;
    switch ((*vec).type)
    {
    case Int:
        {
            int* oldp = (int*)(*vec).elements;
            int* tmp = (int*) malloc (newsize*sizeof(int));
            if (tmp == NULL)
            {
                printf("Memory error.\n");
                free(oldp);
            }
            for (int i = 0; i < index; i++)
            {
                tmp[i] = oldp[i];
            }
            tmp[index] = value.i;
            int oldindex = index;
            for (int i = index+1; i < newsize; i++)
            {
                tmp[i] = oldp[oldindex];
                oldindex++;
            }
            (*vec).elements = tmp;
            free(oldp);
            break;
        }
    case Char:
        {
            char* oldp = (char*)(*vec).elements;
            char* tmp = (char*) malloc (newsize);
            for (int i = 0; i < index; i++)
            {
                tmp[i] = oldp[i];
            }
            tmp[index] = value.c;
            int oldindex = index;
            for (int i = index+1; i < newsize; i++)
            {
                tmp[i] = oldp[oldindex];
                oldindex++;
            }
            (*vec).elements = tmp;
            free(oldp);
            break;
        }
    case Float:
        {
            float* oldp = (float*)(*vec).elements;
            float* tmp = (float*) malloc (newsize*sizeof(float));
            for (int i = 0; i < index; i++)
            {
                tmp[i] = oldp[i];
            }
            tmp[index] = value.f;
            int oldindex = index;
            for (int i = index+1; i < newsize; i++)
            {
                tmp[i] = oldp[oldindex];
                oldindex++;
            }
            (*vec).elements = tmp;
            free(oldp);
            break;
    }
    case Double:
        {
            double* oldp = (double*)(*vec).elements;
            double* tmp = (double*) malloc (newsize*sizeof(double));
            for (int i = 0; i < index; i++)
            {
                tmp[i] = oldp[i];
            }
            tmp[index] = value.d;
            int oldindex = index;
            for (int i = index+1; i < newsize; i++)
            {
                tmp[i] = oldp[oldindex];
                oldindex++;
            }
            (*vec).elements = tmp;
            free(oldp);
            break;
        }
    case Vector:
        {
            vector* oldp = (vector*)(*vec).elements;
            vector* tmp = (vector*)malloc(newsize*sizeof(vector));
            for (int i = 0; i < index; i++)
            {
                tmp[i] = oldp[i];
            }
            tmp[index] = value.v;
            int oldindex = index;
            for (int i = index+1; i < newsize; i++)
            {
                tmp[i] = oldp[oldindex];
                oldindex++;
            }
            (*vec).elements = tmp;
            free(oldp);
            break;
        }
    }
    (*vec).size = newsize;
}

void add_int_array_to_vector(vector * vec, int values[],int arraysize)
{
    int newsize = (*vec).size + arraysize;

    int* tmp = realloc((*vec).elements,newsize*sizeof(int));
    if (tmp == NULL)
    {
        printf("Memory error.\n");
        free(tmp);
        exit(1);
    }
    int index = 0;
    for (int i = (*vec).size; i < newsize; i++)
    {
        tmp[i] = values[index];
        index++;
    }
    (*vec).elements = tmp;
    (*vec).size = newsize;
}
void add_char_array_to_vector(vector * vec, char values[],int arraysize)
{
    int newsize = (*vec).size + arraysize;

    char* tmp = realloc((*vec).elements,newsize);
    if (tmp == NULL)
    {
        printf("Memory error.\n");
        free(tmp);
        exit(1);
    }
    int index = 0;
    for (int i = (*vec).size; i < newsize; i++)
    {
        tmp[i] = values[index];
        index++;
    }
    (*vec).elements = tmp;
    (*vec).size = newsize;
}
void add_float_array_to_vector(vector * vec, float values[],int arraysize)
{
    int newsize = (*vec).size + arraysize;

    float* tmp = realloc((*vec).elements,newsize*sizeof(float));
    if (tmp == NULL)
    {
        printf("Memory error.\n");
        free(tmp);
        exit(1);
    }
    int index = 0;
    for (int i = (*vec).size; i < newsize; i++)
    {
        tmp[i] = values[index];
        index++;
    }
    (*vec).elements = tmp;
    (*vec).size = newsize;
}
int vector_compare(vector * v1,vector v2)
{
    if ((*v1).type != v2.type)
        return 0;
    if ((*v1).size != v2.size)
        return 0;
    switch ((*v1).type)
    {
    case Int:
        {
            int * v1_arr = (int*)(*v1).elements;
            int * v2_arr = (int*)v2.elements;
            for (int i = 0; i < (*v1).size; i++)
            {
                if (v1_arr[i] != v2_arr[i])
                    return 0;
            }
            break;
        }
    case Char:
        {
            char * v1_arr = (char*)(*v1).elements;
            char * v2_arr = (char*)v2.elements;
            for (int i = 0; i < (*v1).size; i++)
            {
                if (v1_arr[i] != v2_arr[i])
                    return 0;
            }
            break;
        }
    case Float:
        {
            float * v1_arr = (float*)(*v1).elements;
            float * v2_arr = (float*)v2.elements;
            for (int i = 0; i < (*v1).size; i++)
            {
                if (v1_arr[i] != v2_arr[i])
                    return 0;
            }
        }
    case Double:
        {
            double * v1_arr = (double*)(*v1).elements;
            double * v2_arr = (double*)v2.elements;
            for (int i = 0; i < (*v1).size; i++)
            {
                if (v1_arr[i] != v2_arr[i])
                    return 0;
            }
        }
    case Vector:
        {
            vector * v1_arr = (vector*)(*v1).elements;
            vector * v2_arr = (vector*)v2.elements;
            for (int i = 0; i < (*v1).size; i++)
            {
                if (vector_compare(v1_arr,(*v2_arr)))
                    return 0;
            }
        }
    }
    return 1;
}
void add_double_array_to_vector(vector * vec, double values[],int arraysize)
{
    int newsize = (*vec).size + arraysize;

    double* tmp = realloc((*vec).elements,newsize*sizeof(double));
    if (tmp == NULL)
    {
        printf("Memory error.\n");
        free(tmp);
        exit(1);
    }
    int index = 0;
    for (int i = (*vec).size; i < newsize; i++)
    {
        tmp[i] = values[index];
        index++;
    }
    (*vec).elements = tmp;
    (*vec).size = newsize;
}

void vector_remove_element(vector * vec,vector_values element)
{
    switch ((*vec).type)
    {
    case Int:
        {
            int* tmp = (int*)malloc(sizeof(int)*((*vec).size-1));
            int* elements = (int*)(*vec).elements;
            int found = 0;
            int index = 0;
            for (int i = 0; i < (*vec).size; i++)
            {
                if (elements[i] == element.i && found == 0)
                {
                    found = 1;
                    continue;
                }
                else
                {
                    tmp[i] = elements[index];
                    index++;
                }
            }
            free((*vec).elements);
            (*vec).elements = tmp;
            break;
        }
    case Char:
        {
            char* tmp = (char*)malloc((*vec).size-1);
            char* elements = (char*)(*vec).elements;
            int found = 0;
            int index = 0;
            for (int i = 0; i < (*vec).size; i++)
            {
                if (elements[i] == element.c && found == 0)
                {
                    found = 1;
                    continue;
                }
                else
                {
                    tmp[i] = elements[index];
                    index++;
                }
            }
            free((*vec).elements);
            (*vec).elements = tmp;
            break;
        }
    case Float:
        {
            float* tmp = (float*)malloc(((*vec).size-1)*sizeof(float));
            float* elements = (float*)(*vec).elements;
            int found = 0;
            int index = 0;
            for (int i = 0; i < (*vec).size; i++)
            {
                if (elements[i] == element.f && found == 0)
                {
                    found = 1;
                    continue;
                }
                else
                {
                    tmp[i] = elements[index];
                    index++;
                }
            }
            free((*vec).elements);
            (*vec).elements = tmp;
            break;
        }
    case Double:
        {
            double* tmp = (double*)malloc(((*vec).size-1)*sizeof(double));
            double* elements = (double*)(*vec).elements;
            int found = 0;
            int index = 0;
            for (int i = 0; i < (*vec).size; i++)
            {
                if (elements[i] == element.d && found == 0)
                {
                    found = 1;
                    index++;
                    continue;
                }
                else
                {
                    tmp[i] = elements[index];
                    index++;
                }
            }
            free((*vec).elements);
            (*vec).elements = tmp;
            break;
        }
        case Vector:
        {
            vector* tmp = (vector*) malloc(((*vec).size-1)*sizeof(vector));
            vector* elements = (vector*)(*vec).elements;
            int found = 0;
            int index = 0;
            for (int i = 0; i < (*vec).size; i++)
            {
                if (vector_compare(&elements[i],element.v) && found == 0)
                {
                    found = 1;
                    index++;
                    continue;
                }
                else
                {
                    tmp[i] = elements[index];
                    index++;
                }
            }
            free((*vec).elements);
            (*vec).elements = tmp;
            break;
        }
    }
    (*vec).size -= 1;
}

void vector_remove_at(vector * vec,int index)
{
    switch ((*vec).type)
    {
    case Int:
        {
            int * tmp = malloc(((*vec).size - 1) * sizeof(int));
            int * elements = (int*)(*vec).elements;
            int ind = 0;
            int ind2 = 0;
            for (int i = 0; i < (*vec).size; i++)
            {
                if (i == index)
                {
                    ind++;
                    continue;
                }
                else
                {
                    tmp[ind2] = elements[ind];
                    ind2++;
                    ind++;
                }
            }
            free(elements);
            (*vec).elements = tmp;
            break;
        }
    case Char:
        {
            char * tmp = malloc((*vec).size - 1);
            char * elements = (char*)(*vec).elements;
            int ind = 0;
            int ind2 = 0;
            for (int i = 0; i < (*vec).size; i++)
            {
                if (i == index)
                {
                    ind++;
                    continue;
                }
                else
                {
                    tmp[ind2] = elements[ind];
                    ind2++;
                    ind++;
                }
            }
            free(elements);
            (*vec).elements = tmp;
            break;
        }
    case Float:
        {
            float * tmp = malloc(((*vec).size - 1) * sizeof(float));
            float * elements = (float*)(*vec).elements;
            int ind = 0;
            int ind2 = 0;
            for (int i = 0; i < (*vec).size; i++)
            {
                if (i == index)
                {
                    ind++;
                    continue;
                }
                else
                {
                    tmp[ind2] = elements[ind];
                    ind2++;
                    ind++;
                }
            }
            free(elements);
            (*vec).elements = tmp;
            break;
        }
    case Double:
        {
            double * tmp = malloc(((*vec).size - 1) * sizeof(double));
            double * elements = (double*)(*vec).elements;
            int ind = 0;
            int ind2 = 0;
            for (int i = 0; i < (*vec).size; i++)
            {
                if (i == index)
                {
                    ind++;
                    continue;
                }
                else
                {
                    tmp[ind2] = elements[ind];
                    ind2++;
                    ind++;
                }
            }
            free(elements);
            (*vec).elements = tmp;
            break;
        }
    case Vector:
        {
            vector* tmp = malloc(((*vec).size - 1)*sizeof(vector));
            vector* elements = (vector*)(*vec).elements;
            int ind = 0;
            int ind2 = 0;
            for (int i = 0; i < (*vec).size; i++)
            {
                if (i == index)
                    {
                        ind++;
                        continue;
                    }
                else
                {
                    tmp[ind2] = elements[ind];
                    ind2++;
                    ind++;
                }
            }
            free(elements[index].elements);
            free(elements);
            (*vec).elements = tmp;
            break;
        }
    }
    (*vec).size -= 1;
}
void vector_log_values(vector * vec)
{
    switch ((*vec).type)
    {
        case Int:
        {
            printf("Vector size is: %d\nValues:\n",(*vec).size);
            int * pointer = (int*)(*vec).elements;
            for (int i = 0; i < (*vec).size; i++)
            {
                printf("    %d\n",pointer[i]);
            }
            printf("\n");
            break;
        }
        case Char:
            {
            printf("Vector size is: %d\nValues:\n",(*vec).size);
            char * pointer = (char*)(*vec).elements;
            for (int i = 0; i < (*vec).size; i++)
            {
                printf("    %c\n",pointer[i]);
            }
            printf("\n");
            break;
            }
        case Float:
            {
            printf("Vector size is: %d\nValues:\n",(*vec).size);
            float * pointer = (float*)(*vec).elements;
            for (int i = 0; i < (*vec).size; i++)
            {
                printf("    %f\n",pointer[i]);
            }
            printf("\n");
            break;
            }
        case Double:
            {
            printf("Vector size is: %d\nValues:\n",(*vec).size);
            double * pointer = (double*)(*vec).elements;
            for (int i = 0; i < (*vec).size; i++)
            {
                printf("    %f\n",pointer[i]);
            }
            printf("\n");
            break;
            }
        case Vector:
            {
                printf("Vector size is: %d\nValues:\n",(*vec).size);
                vector* pointer = (vector*)(*vec).elements;
                //printf("%p\n",pointer);
                for (int i = 0; i < (*vec).size; i++)
                {
                    vector tmp = pointer[i];
                    vector_log_values(&tmp);
                }
                printf("\n");
                break;
            }
    }
}
void vector_destructor(vector * vec)
{
    if ((*vec).type == Vector)
    {
        for (int i = 0; i < (*vec).size; i++)
        {
            vector * tmp = (vector*)(*vec).elements;
            vector_destructor(&tmp[i]);
        }
    }

    free((*vec).elements);
    (*vec).size = 0;
    (*vec).type = -1;
}
