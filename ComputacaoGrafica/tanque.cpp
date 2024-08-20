#include <GL/freeglut.h>

float posicaoY = 0.0f;

void displayBase() {
    glColor3f(0.0f, 0.5f, 0.7f);  
    glBegin(GL_QUADS);           
        glVertex2f(-0.14f, -0.3f + posicaoY);
        glVertex2f(0.14f, -0.3f + posicaoY);
        glVertex2f(0.14f, 0.3f + posicaoY);
        glVertex2f(-0.14f, 0.3f + posicaoY);
    glEnd();
}

void displayEsteiras() {
    glColor3f(1.0f, 0.5f, 0.0f);  
    // Esteira esquerda
    glBegin(GL_QUADS);
        glVertex2f(-0.24f, -0.35f + posicaoY);
        glVertex2f(-0.13f, -0.35f + posicaoY);
        glVertex2f(-0.13f, 0.35f + posicaoY);
        glVertex2f(-0.24f, 0.35f + posicaoY);
    glEnd();
    // Esteira direita
    glBegin(GL_QUADS);
        glVertex2f(0.13f, -0.35f + posicaoY);
        glVertex2f(0.24f, -0.35f + posicaoY);
        glVertex2f(0.24f, 0.35f + posicaoY);
        glVertex2f(0.13f, 0.35f + posicaoY);
    glEnd();
}

void displayCentro() {
    glColor3f(0.0f, 0.4f, 0.0f);  
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.09f + posicaoY);
        glVertex2f(0.1f, -0.09f + posicaoY);
        glVertex2f(0.1f, 0.15f + posicaoY);
        glVertex2f(-0.1f, 0.15f + posicaoY);
    glEnd();
}

void displayCanhao() {
    glColor3f(0.6f, 0.0f, 0.6f);  
    glBegin(GL_QUADS);
        glVertex2f(-0.03f, 0.12f + posicaoY);
        glVertex2f(0.03f, 0.12f + posicaoY);
        glVertex2f(0.03f, 0.6f + posicaoY);
        glVertex2f(-0.03f, 0.6f + posicaoY);
    glEnd();
}
void gerarMovimento(int value) { 
    posicaoY += 0.01f;
    if (posicaoY > 1.0f) posicaoY = -1.0f; // Reseta a posição quando fora da tela

    glutPostRedisplay(); // Redesenha a tela
    glutTimerFunc(16, gerarMovimento, 0); //Atualiza a cada 16ms
}
void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  
    glMatrixMode(GL_PROJECTION);           
    glLoadIdentity();                     
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);     
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);          
    glMatrixMode(GL_MODELVIEW);            
    glLoadIdentity();                     

   
    displayBase();  
    displayEsteiras();    
    displayCentro();   
    displayCanhao();    

    glFlush(); // Limpa a tela
    glutSwapBuffers(); // Troca o buffer da tela
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tanque andando");
    glutDisplayFunc(display);
	glutTimerFunc(0, gerarMovimento, 0);
    init();
    
    glutMainLoop();
    return 0;
}