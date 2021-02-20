#include "Resources/Headers/Global.h"

//Vector Routines implementation
vec_2d_int_t* create_vec_2d_int(void)
{
	//A wrapper around calloc
	void* xcalloc(int nr_elements, size_t size_per_element);
	//code
	//Instantiate vec_2d_int_type
	return (vec_2d_int_t*)xcalloc(1, sizeof(vec_2d_int_t));
}

vec_2d_float_t* create_vec_2d_float(void)
{
	//A wrapper around calloc
	void* xcalloc(int nr_elements, size_t size_per_element);
	//code
	//Instantiate vec_2d_float_type
	return (vec_2d_float_t*)xcalloc(1, sizeof(vec_2d_float_t));
}

void push_back_vec_2d_int(vec_2d_int_t* p_vec, GLint* p_arr)
{
	//A wrapper around realloc
	void* xrealloc(void* p, size_t new_size);

	/*
		code
		S1 : Dynamically expand array of ponters to integersto one grater then the current size using xrealloc
		S2 : Increment size field by one
		S3 : put input array at the newly added position
	*/

	p_vec->pp_arr = (GLint**)xrealloc(p_vec->pp_arr, (p_vec->size + 1) * sizeof(int**)); //S1
	p_vec->size++; //S2
	p_vec->pp_arr[p_vec->size - 1] = p_arr; //S3
}

void push_back_vec_2d_float(vec_2d_float_t* p_vec, GLfloat* p_arr)
{
	//A wrapper around realloc
	void* xrealloc(void* p, size_t new_size);

	/*
		code
		S1 : Dynamically expand array of ponters to integersto one grater then the current size using xrealloc
		S2 : Increment size field by one
		S3 : put input array at the newly added position
	*/

	p_vec->pp_arr = (GLfloat**)xrealloc(p_vec->pp_arr, (p_vec->size + 1) * sizeof(GLfloat**)); //S1
	p_vec->size++; //S2
	p_vec->pp_arr[p_vec->size - 1] = p_arr; //S3
}

void clean_vec_2d_int(vec_2d_int_t** pp_vec)
{
	/*
		S1 : Get the pointer to structure from input parameter. (API)
		S2 : For the every iteration through the pp_array,free array of
			integers whose vase address is stored at current index end of the loop
		S3 : free the structure instance of vec_2d_int_t
		S4 : set pointer variable holding base address of struct instance to NULL
	*/

	vec_2d_int_t* p_vec = *pp_vec;
	for (size_t i = 0; i != p_vec->size; i++)
	{
		free(p_vec->pp_arr[i]);
	}
	free(p_vec);
	*pp_vec = NULL;
}

void clean_vec_2d_float(vec_2d_float_t** pp_vec)
{
	/*
		S1 : Get the pointer to structure from input parameter. (API)
		S2 : For the every iteration through the pp_array,free array of
			integers whose vase address is stored at current index end of the loop
		S3 : free the structure instance of vec_2d_int_t
		S4 : set pointer variable holding base address of struct instance to NULL
	*/

	vec_2d_float_t* p_vec = *pp_vec;
	for (size_t i = 0; i != p_vec->size; i++)
	{
		free(p_vec->pp_arr[i]);
	}
	free(p_vec);
	*pp_vec = NULL;
}

void* xcalloc(int nr_elements, size_t size_per_element)
{
	//Release or destroy the resources
	void Unitialize(void);
	/*
		 code
		 S1 : Alloc memory using calloc  function passing number of elements(API) and size of element(API2) to it
		 S2 : if return value is NULL then log the error and invoke uninitialize
		 S3 :  if return value is not NULL then return it to the caller
	*/

	void* p = calloc(nr_elements, size_per_element);
	if (!p)
	{
		fprintf(gpFile, "calloc:fatal:out of memory\n");
		Unitialize();
	}
	return(p);
}

void* xrealloc(void* p, size_t new_size)
{
	//Release or destroy the resources
	void Unitialize(void);
	/*
		code
		S1 : Resize array pointed to by p (API) to new size (API2) with the help of realloc
		S2 : if return value is NULL then log the error and invoke uninitialize
		S3 :  if return value is not NULL then return it to the caller
	*/

	void* ptr = realloc(p, new_size);
	if (!ptr)
	{
		fprintf(gpFile, "realloc:fatal:out of memory\n");
		Unitialize();
	}
	return(ptr);
}
