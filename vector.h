typedef struct vector_t {
    int size;
    int * elements;
} vector;


vector vector_init(int size)
{
    int * arr = calloc(size,sizeof(int));
    vector tmp = { .size = size, .elements = arr};
    return tmp;
}


vector vector_init_defaultvalue(int size,int defaultval)
{
    int * arr = malloc(size*sizeof(int));
    vector tmp = { .size = size, .elements = arr};
    for (int i = 0; i < size; i++)
    {
        tmp.elements[i] = defaultval;
    }
    return tmp;
}


void addsingle_to_vector(vector * vec, int value)
{
    int newsize = (*vec).size + 1;
    //int * newp = realloc((*vec).elements,newsize * sizeof(int));
    (*vec).elements = realloc((*vec).elements,newsize * sizeof(int));
    (*vec).elements[newsize-1] = value;
    //(*vec).elements = newp;
    (*vec).size = newsize;
}

void addvec_to_vector_free2nd(vector * vec, vector * toadd)
{
    int newsize = (*vec).size + (*toadd).size;
    //int * newp = realloc((*vec).elements,newsize*sizeof(int));
    (*vec).elements = realloc((*vec).elements,newsize*sizeof(int));
    int index = 0;
    for (int i = (*vec).size; i < newsize; i++)
    {
        (*vec).elements[i] = (*toadd).elements[index];
        index++;
    }
    free((*toadd).elements);
    (*toadd).size = 0;
    (*toadd).elements = NULL;
    //(*vec).elements = newp;
    (*vec).size = newsize;
}
void addvec_to_vector(vector * vec, vector * toadd)
{
    int newsize = (*vec).size + (*toadd).size;
    //int * newp = realloc((*vec).elements,newsize*sizeof(int));
    (*vec).elements = realloc((*vec).elements,newsize*sizeof(int));
    int index = 0;
    for (int i = (*vec).size; i < newsize; i++)
    {
        (*vec).elements[i] = (*toadd).elements[index];
        index++;
    }
    //(*vec).elements = newp;
    (*vec).size = newsize;
}


void insert(vector * vec, int value, int index)
{
    int newsize = (*vec).size + 1;
    int * newp = realloc((*vec).elements,newsize*sizeof(int));
    newp[index] = value;
    for (int i = index + 1; i <= newsize; i++)
    {
        newp[i] = (*vec).elements[i - 1];
    }
    (*vec).elements = newp;
    (*vec).size = newsize;
}

void addarray_to_vector(vector * vec, int values[],int arraysize)
{
    int newsize = (*vec).size + arraysize;
    //int * newp = realloc((*vec).elements,newsize*sizeof(int));
    (*vec).elements = realloc((*vec).elements,newsize*sizeof(int));

    int index = 0;
    for (int i = (*vec).size; i < newsize; i++)
    {
        (*vec).elements[i] = values[index];
        index++;
    }
    //(*vec).elements = newp;
    (*vec).size = newsize;
}
void vector_remove_element(vector * vec,int element)
{
    int * newp = realloc((*vec).elements,((*vec).size - 1)*sizeof(int));
    int index2 = 0;
    int found = 0;
    for (int i = 0; i < (*vec).size; i++)
    {
        if ((*vec).elements[i] == element && found == 0)
        {
            found = 1;
            continue;
        }
        else {
            newp[index2] = (*vec).elements[i];
            index2++;
        }
    }
    (*vec).elements = newp;
    (*vec).size -= 1;
}

void vector_remove_at(vector * vec,int index)
{
    int * newp = malloc(((*vec).size - 1)*sizeof(int));
    //(*vec).elements = realloc((*vec).elements,((*vec).size - 1)*sizeof(int));
    int index2 = 0;
    for (int i = 0; i < (*vec).size; i++)
    {
        if (i == index)
        {
            continue;
        }
        else {
            newp[index2] = (*vec).elements[i];
            index2++;
        }
    }
    //free((*vec).elements);
    (*vec).elements = newp;
    (*vec).size -= 1;
}
