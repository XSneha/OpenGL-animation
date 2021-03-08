#include "Resources/Headers/Global.h"

char g_line[BUFFER_SIZE];
extern FILE* g_fp_meshfile = NULL;

GLfloat g_model_rotate;

//vector of vector of floats to hold vertex data
vec_2d_float_t* gp_vertices;

//vector of vector of floats to hold texture data
vec_2d_float_t* gp_texture;

//vector of vector of floats to hold normal data
vec_2d_float_t* gp_normals;

//vector of vector of int to hold index data int g_vertices
//vec_2d_int_t* gp_face_tri, * gp_face_texture, * gp_face_normals;

void LoadMeshData(const char * fileName, vec_2d_int_t** gp_face_tri, vec_2d_int_t** gp_face_texture, vec_2d_int_t** gp_face_normals)
{
	//Function prototype Release and destory resources
	void Unitialize(void);

	//Create vector of vector of integers and floating point numbers
	vec_2d_int_t* create_vec_2d_int(void);
	vec_2d_float_t* create_vec_2d_float(void);

	//push array of integers and floating point numbers in vector of vector of integers and floating point numbers
	void push_back_vec_2d_int(vec_2d_int_t * p_vec, int* p_arr);
	void push_back_vec_2d_float(vec_2d_float_t * p_vec, float* p_arr);

	//Awrapper arround calloc
	void* xcalloc(int, size_t);

	//code
	//Open mesh file, name of mesh file can be paraneterized
	//g_fp_meshfile = fopen("MonkeyHead.OBJ", "r");
	//if (!g_fp_meshfile)
	//{
	//	uninitialize();
	//}


	if (fopen_s(&g_fp_meshfile, fileName, "r") != 0) {
		MessageBox(NULL, TEXT("Failed to Open file /Resources/Models/MonkeyHead.OBJ"), TEXT("ERROR"), MB_OK);
		Unitialize();
	}

	//Instantiate three vectors of vector of floats to hold cartesian,texture and normal
	//coordinate
	gp_vertices = create_vec_2d_float();
	gp_texture = create_vec_2d_float();
	gp_normals = create_vec_2d_float();

	//Instantiate three vector of vector of integers to hold face data regarding cartesian
	//texture and normal coordinates
	*gp_face_tri = create_vec_2d_int();
	*gp_face_texture = create_vec_2d_int();
	*gp_face_normals = create_vec_2d_int();

	//Separator strings
	//String holding space separator for strtok

	const char* sep_space = " ";
	//string holding forward slash separator for strtok
	const char* sep_fslash = "/";

	//Token pointers
	//Character pointer forholding first word in a line
	char* first_token = NULL;

	//Character pointer for holding next word separated byspecified separator to strtok
	char* token = NULL;

	//Array of character pointers to hold strings of face entries
	//face entries can be variables in some file they are three and some file they are four
	char* face_tokens[NR_FACE_TOKENS];
	//Nuber of non-NULL tokens in the above vector
	int nr_tokens;

	//character pointer for holding string associated with vertex index
	char* token_vertex_index = NULL;

	//character pointer for holding string associated with texture index
	char* token_texture_index = NULL;

	//Character pointer for holding string associated with normal index
	char* token_normal_index = NULL;
	char* next_token1 = NULL;

	//while there is a line in the file
	while (fgets(g_line, BUFFER_SIZE, g_fp_meshfile) != NULL)
	{
		//Bind line to a separator and get first token
		first_token = strtok_s(g_line, sep_space, &next_token1);

		//if first token indicates vertex data
		if (strcmp(first_token, "v") == S_EQUAL)
		{
			//Create a vector of NR_POINT_COORDS number of floats to hold coordinates
			GLfloat* pvec_point_coord = (GLfloat*)xcalloc(NR_POINT_COORDS, sizeof(GLfloat));

			
			//	Do following NR_POINT_COORD time
			//	S1 : get next token
			//	S2 : free it to atof to get floating point number out of it
			//	S3 : Add floating point number generated to vector end of loop
			//	S4 : At the end of loop vector is construced,add it to global vector of vector of floats, named gp_vertices
			
			for (int i = 0; i != NR_POINT_COORDS; i++)
			{
				pvec_point_coord[i] = (GLfloat)atof(strtok_s(NULL, sep_space, &next_token1)); //S1,S2,S3
			}
			push_back_vec_2d_float(gp_vertices, pvec_point_coord); //S4
		}

		//if first token indicates texture data
		else if (strcmp(first_token, "vt") == S_EQUAL)
		{
			GLfloat* pvec_texture_coord = (GLfloat*)xcalloc(NR_TEXTURE_COORDS, sizeof(GLfloat));
			
			//	Do following NR_TEXTURE_COORD time
			//	S1 : Get next token
			//	S2 : Feed it to atof to get floating point number out of it
			//	S3 : Add the floating point number generated to vector End of looop
			//	S4 : At the end of loop vector is constructed, add it to global vector of vector of floats nemed g_vertices
			

			for (int i = 0; i != NR_TEXTURE_COORDS; i++)
			{
				pvec_texture_coord[i] = (GLfloat)atof(strtok_s(NULL, sep_space, &next_token1)); //S1,S2,S3
			}
			push_back_vec_2d_float(gp_texture, pvec_texture_coord);
		}

		//if first tooken indicate normal data
		else if (strcmp(first_token, "vn") == S_EQUAL)
		{
			GLfloat* pvec_normal_coord = (GLfloat*)xcalloc(NR_NORMAL_COORDS, sizeof(GLfloat));
			
			//	Do following NR_NORMAL_COORDS time
			//	S1 : Get next token
			//	S2 : Feed it to atof to get to floating point number out of it
			//	S3 : Add the floating point number generated to vector end of loop
			//	S4 : At the end of loop vector is constructed add it to globla vector of vector of floats, named g_vertices
			

			for (int i = 0; i != NR_NORMAL_COORDS; i++)
			{
				pvec_normal_coord[i] = (GLfloat)atof(strtok_s(NULL, sep_space, &next_token1)); //S1,S2,S3
			}
			push_back_vec_2d_float(gp_normals, pvec_normal_coord); // S4
		}

		//if first token indicates face data
		else if (strcmp(first_token, "f") == S_EQUAL)
		{
			//Define three vector of integers with length 3 to holds indicates of
			//trinagle's positional coordinates texture coordinates and normal
			//coordinates in g_vertices, g_texture,g_normals resp.
			GLint* pvec_vertex_indices = (GLint*)xcalloc(3, sizeof(GLint));
			GLint* pvec_texture_indices = (GLint*)xcalloc(3, sizeof(GLint));
			GLint* pvec_normal_indices = (GLint*)xcalloc(3, sizeof(GLint));

			//Initialize all char pointers in face_tokens to NULL
			memset((void*)face_tokens, 0, NR_FACE_TOKENS);

			//Extract three fields of information in face_tokens and increment nr_tokens accordingly
			nr_tokens = 0;
			while (token = strtok_s(NULL, sep_space, &next_token1))
			{
				if (strlen(token) < 3)
					break;
				face_tokens[nr_tokens] = token;
				nr_tokens++;
			}
			
			//	Every face data entry is going to have minimum three fields
			//	therefore, construct a triangle out of it with
			//	S1 : triangle coordinate data and
			//	S2 : texture coordinate index data
			//	S3 : normal coordinate index data
			//	S4 : put that data in triangle_vertex_indices,texture_vertex_indices,
			//		normal_vertex_indices.vectors will be constructed at the end of the loop
			
			for (int i = 0; i != NR_FACE_TOKENS; i++)
			{
				token_vertex_index = strtok_s(face_tokens[i], sep_fslash, &next_token1); //S1
				token_texture_index = strtok_s(NULL, sep_fslash, &next_token1); //S2
				token_normal_index = strtok_s(NULL, sep_fslash, &next_token1); //S3

				pvec_vertex_indices[i] = atoi(token_vertex_index); //S4 - 1
				pvec_texture_indices[i] = atoi(token_texture_index); //S5 -1
				pvec_normal_indices[i] = atoi(token_normal_index); //S6 -1
			}

			//Add constructed vectors to global face vectors
			push_back_vec_2d_int(*gp_face_tri, pvec_vertex_indices);
			push_back_vec_2d_int(*gp_face_texture, pvec_texture_indices);
			push_back_vec_2d_int(*gp_face_normals, pvec_normal_indices);
		}

		//Initialize line buffer to NULL
		memset((void*)g_line,(int)"\0", BUFFER_SIZE);
	}

	//Close meshfile and make file pointer NULL.
	fclose(g_fp_meshfile);
	g_fp_meshfile = NULL;

	//log vertex texture and face data in log file
	//fprintf(g_fp_logfile, "gp_vertices->size,gp_normals->size,gp_face_tri->size");
}


