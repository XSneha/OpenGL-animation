#include "Resources/Headers/Global.h"

GLuint bg_texture;
GLuint ground_texture;

void InitalizeNatureS4(void) {
	LoadGLTextures(&bg_texture, MAKEINTRESOURCE(BG_TEXTURE));
	LoadGLTextures(&ground_texture, MAKEINTRESOURCE(GROUND_TEXTURE));
	LoadGLTextures(&robot_texture, MAKEINTRESOURCE(ROBOT_BODY));
	LoadGLTextures(&robot_texture_dark, MAKEINTRESOURCE(ROBOT_BODY_DARK));
	LoadGLTextures(&robot_face, MAKEINTRESOURCE(ROBOT_FACE));
	LoadGLTextures(&robot_body, MAKEINTRESOURCE(ROBOT_FRONT));
	glBindTexture(GL_TEXTURE_2D, 0);

	fprintf(gpFile, "Display Robot and nature S4\n");
}

// Display robot watching beauty of nature
void DisplayNatureS4(void) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/*
		Model transformation
		S1 : Translate the model in X, Y, Z direction respectely
			by MODEL_X_TRANSLATE, MODEL_Y_TRANSLATE, MODEL_Z_TRANSLATE
		S2 : Rotate the model around Y-axis by angle mentioned in gp_rotate
		S3 : perform scaling transformation along X, Y, Z respectively by
			MODEL_X_SCALE_FACTOR,MODEL_Y_SCALE_FACTOR,MODEL_Z_SCALE_FACTOR
	*/

	glTranslatef(MODEL_X_TRANSLATE, MODEL_Y_TRANSLATE, MODEL_Z_TRANSLATE);
	glRotatef(g_model_rotate, 0.0f, 1.0f, 0.0f);
	glScalef(MODEL_X_SCALE_FACTOR, MODEL_Y_SCALE_FACTOR, MODEL_Z_SCALE_FACTOR);

	//keep counter-clockwise winding of vertices of geometry
	glFrontFace(GL_CCW);

	//Set Polygon mode mentioning front and back faces and GL_LINE
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	/*
		S1 : for every face index maintained in triangular form in gp_face_tri
		Do following
		S2 : Set geometry primitive to GL_TRIANGLES
		S3 : Extract triangle from outer loop index for every point of a triangle
		S4 : calculate the index in g_veritices in variable in vi
		S5 : calculate X ,Y , Z coordinate of point
		S6 :  send to glVertex3f

		Remark : in S4 we have to subtract gp_face_tri[i][j] by one because in mesh file indexing starts from 1 and in case of arrays/vectorsindexing starts from 0
	*/

	for (int i = 0; i != gp_face_tri->size; i++) //S1
	{
		glBegin(GL_TRIANGLES); //S2
		for (int j = 0; j != NR_TRIANGLE_VERTICES; j++) //S3
		{
			int vi = gp_face_tri->pp_arr[i][j] - 1; //S4
			glVertex3f(gp_vertices->pp_arr[vi][0], gp_vertices->pp_arr[vi][1], gp_vertices->pp_arr[vi][2]); //S5,S6
		}
		glEnd();
	}
}

void UpdateNatureS4(void) {
	g_model_rotate = g_model_rotate + MODEL_ANGLE_INCREMENT;
	//If rotation angle equals or exceeds END_ANGLE_POS then reset to START_ANGLE_POS
	if (g_model_rotate >= END_ENGLE_POS)
	{
		g_model_rotate = START_ENGLE_POS;
	}
}
