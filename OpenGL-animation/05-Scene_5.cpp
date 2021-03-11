
#include "Resources/Headers/Global.h"

GLuint bg_texture;
GLuint ground_texture;
vec_2d_int_t* gp_face_tree, * gp_face_texture_tree, * gp_face_normals_tree;
vec_2d_int_t* gp_face_bush, * gp_face_texture_bush, * gp_face_normals_bush;

void InitalizeNatureS4(void) {
	fprintf(gpFile, "Display Robot and nature S4\n");
	LoadMeshData("Resources/Models/lpt.obj", &gp_face_tree, &gp_face_texture_tree, &gp_face_normals_tree);
	//LoadMeshData("Resources/Models/tree2.obj", &gp_face_bush, &gp_face_texture_bush, &gp_face_normals_bush);
}

// Display robot watching beauty of nature
void DisplayNatureS4(void) {
	void DrawModelTree1();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(MODEL_X_TRANSLATE, MODEL_Y_TRANSLATE, MODEL_Z_TRANSLATE);
	//glRotatef(g_model_rotate, 0.0f, 1.0f, 0.0f);
	glScalef(MODEL_X_SCALE_FACTOR, MODEL_Y_SCALE_FACTOR, MODEL_Z_SCALE_FACTOR);

	//keep counter-clockwise winding of vertices of geometry
	glFrontFace(GL_CCW);
	DrawModelTree1();

}

void UpdateNatureS4(void) {
	g_model_rotate = g_model_rotate + MODEL_ANGLE_INCREMENT;
	//If rotation angle equals or exceeds END_ANGLE_POS then reset to START_ANGLE_POS
	if (g_model_rotate >= END_ENGLE_POS){
		g_model_rotate = START_ENGLE_POS;
	}
}

void DrawModelTree1() {
	GLfloat x = -12.0f;
	for (int i = 0; i < 11; i++) {
		if (i < 5) {
			x = x + 5.5;
			glTranslatef(x, 0.0f, 0.0f);
		}
		else {
			if (i == 5) {
				x -= 3.5;
				glTranslatef(0.0f, 0.0f, -9.0f);
			} 
			x = x - 5.5;
			glTranslatef(x, 0.0f, 0.0f);
		}
		glColor3f(0.0f, 1.0f, 0.0f);
		for (int i = 0; i != gp_face_tree->size; i++) {
			glBegin(GL_TRIANGLES); //S2
			for (int j = 0; j != NR_TRIANGLE_VERTICES; j++) {
				int vi;
				vi = gp_face_tree->pp_arr[i][j] - 1;
				//	Remark : in S4 we have to subtract gp_face_tri[i][j] by one because in mesh file indexing starts from 1 and in case of arrays/vectorsindexing starts from 0
				//textureing to model is pending
				//int ti,ni;
				//ni = gp_face_texture_tree->pp_arr[i][j] - 1;
				//ti = gp_face_normals_tree->pp_arr[i][j] - 1;
				//if(j < NR_NORMAL_COORDS)
				//	glNormal3f(gp_normals->pp_arr[ni][0], gp_normals->pp_arr[ni][1], gp_normals->pp_arr[ni][2]); // x,y,z of normals
				//if(j<NR_TEXTURE_COORDS)
				//	glTexCoord2f(gp_texture->pp_arr[ti][0], gp_texture->pp_arr[ti][1]);
				glVertex3f(gp_vertices->pp_arr[vi][0], gp_vertices->pp_arr[vi][1], gp_vertices->pp_arr[vi][2]); //S5,S6
			}
			glEnd();
		}
		/*glColor3f(1.0f, 0.5f, 0.5f);
		for (int i = 0; i != gp_face_bush->size; i++) {
			glBegin(GL_TRIANGLES); //S2
			for (int j = 0; j != NR_TRIANGLE_VERTICES; j++) {
				int vi;
				vi = gp_face_bush->pp_arr[i][j] - 1;
				glVertex3f(gp_vertices->pp_arr[vi][0], gp_vertices->pp_arr[vi][1], gp_vertices->pp_arr[vi][2]); //S5,S6
			}
			glEnd();
		}*/
	}
	
}
