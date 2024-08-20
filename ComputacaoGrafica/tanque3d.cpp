#include <GL/glew.h>
#include <GL/freeglut.h>

float anguloX = 0.0f;
float anguloY = 0.0f;
float anguloZ = 0.0f;

void desenharCubo(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax, float r, float g, float b) {
    glColor3f(r, g, b);  
    glBegin(GL_QUADS);
        // Frente
        glVertex3f(xMin, yMin, zMax);
        glVertex3f(xMax, yMin, zMax);
        glVertex3f(xMax, yMax, zMax);
        glVertex3f(xMin, yMax, zMax);
        // Trás
        glVertex3f(xMin, yMin, zMin);
        glVertex3f(xMax, yMin, zMin);
        glVertex3f(xMax, yMax, zMin);
        glVertex3f(xMin, yMax, zMin);
        // Topo
        glVertex3f(xMin, yMax, zMax);
        glVertex3f(xMax, yMax, zMax);
        glVertex3f(xMax, yMax, zMin);
        glVertex3f(xMin, yMax, zMin);
        // Fundo
        glVertex3f(xMin, yMin, zMax);
        glVertex3f(xMax, yMin, zMax);
        glVertex3f(xMax, yMin, zMin);
        glVertex3f(xMin, yMin, zMin);
        // Lado direito
        glVertex3f(xMax, yMin, zMax);
        glVertex3f(xMax, yMin, zMin);
        glVertex3f(xMax, yMax, zMin);
        glVertex3f(xMax, yMax, zMax);
        // Lado esquerdo
        glVertex3f(xMin, yMin, zMax);
        glVertex3f(xMin, yMin, zMin);
        glVertex3f(xMin, yMax, zMin);
        glVertex3f(xMin, yMax, zMax);
    glEnd();
}

void displayBase() {
    desenharCubo(-0.14f, 0.14f, -0.3f, 0.3f, -0.05f, 0.14f, 0.0f, 0.5f, 0.7f);
}

void desenharEsteiras() {
    desenharCubo(-0.24f, -0.13f, -0.35f, 0.35f, -0.1f, 0.14f, 1.0f, 0.5f, 0.0f); // Esquerda
    desenharCubo(0.13f, 0.24f, -0.35f, 0.35f, -0.1f, 0.14f, 1.0f, 0.5f, 0.0f);  // Direita
}

void displayCentro() {
    desenharCubo(-0.1f, 0.1f, -0.09f, 0.15f, 0.0f, 0.3f, 0.0f, 0.4f, 0.0f);
}

void displayCanhao() {
    desenharCubo(-0.03f, 0.03f, 0.12f, 0.6f, 0.19f, 0.25f, 0.6f, 0.0f, 0.6f);
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 0.1, 100.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Aplicar rotações
    glRotatef(anguloX, 1.0f, 0.0f, 0.0f); 
    glRotatef(anguloY, 0.0f, 1.0f, 0.0f); 
    glRotatef(anguloZ, 0.0f, 0.0f, 1.0f); 

    displayBase();
    desenharEsteiras();
    displayCentro();
    displayCanhao();

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            anguloY += 5.0f; // Rotaciona em torno do eixo Y
            break;
        case GLUT_KEY_LEFT:
            anguloY -= 5.0f; // Rotaciona em torno do eixo Y
            break;
        case GLUT_KEY_UP:
            anguloX -= 5.0f; // Rotaciona em torno do eixo X
            break;
        case GLUT_KEY_DOWN:
            anguloX += 5.0f; // Rotaciona em torno do eixo X
            break;
    }
    glutPostRedisplay(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tanque 3D");
    glewInit();
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}
