#include "Global.h"

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

}

void UpdateNatureS4(void) {

}
