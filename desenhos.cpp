#include "desenhos.h"
#include <GL/glut.h>
#include <math.h>

extern GLUquadric* quad;
extern float carroPosY;

void desenharBar(){
  
  GLfloat vertices[][3] = {
    {1.5, 1.5, -0.5}, // 0
    {1.5, -1.5, -0.5}, // 1
    {-1.5, -1.5, -0.5}, // 2
    {-1.5, 1.5, -0.5}, // 3
    {1.5, 1.5, 2}, // 4
    {1.5, -1.5, 2}, // 5
    {-1.5, -1.5, 1.5}, // 6
    {-1.5, 1.5, 1.5}, // 7

    {-2, -1.5, 1}, // 8
    {-2, 1.5, 1}, // 9
  };

  GLint faces[][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {0, 1, 5, 4},
    {1, 2, 6, 5},
    {2, 3, 7, 6},
    {4, 5, 6, 7},
    {6, 7, 9, 8}
  };

  GLfloat normais[][3] = {
    {0, 0, -1},
    {0, 0, 1},
    {1, 0, 0},
    {0, -1, 0},
    {-1, 0, 0},
    {-0.164, 0.0, 0.986},
    {-0.707, 0.0, 0.707}
  };

  glColor3f(0.5, 0.5, 0.5);
  for(int i = 0; i < 7; i++){
    glBegin(GL_QUADS);
      glNormal3fv(normais[i]);
      glVertex3fv(vertices[faces[i][0]]);
      glVertex3fv(vertices[faces[i][1]]);
      glVertex3fv(vertices[faces[i][2]]);
      glVertex3fv(vertices[faces[i][3]]);
    glEnd();
  }

  glColor3f(0.4, 0.2, 0.0);
   glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glVertex3f(-1.51, 0.5, -0.5);
    glVertex3f(-1.51, 0.5, 0.5);
    glVertex3f(-1.51, -0.5, 0.5);
    glVertex3f(-1.51, -0.5, -0.5);
  glEnd();

  glBegin(GL_QUADS);
      glColor3f(1.0, 1.0, 0.0);
      glVertex3f(-1.51, -0.6,  0.5);
      glVertex3f(-1.51,  -1.45,  0.5);
      glVertex3f(-1.51,  -1.45, 0.0);
      glVertex3f(-1.51, -0.6, 0.0);
  glEnd();

  glLineWidth(3);
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
    glVertex3f(-1.51, 0.0, -0.5);
    glVertex3f(-1.51, 0.0, 0.5);
  glEnd();
  glLineWidth(1);
}

void desenharCasa(){
  GLfloat vertices[][3] = {
    {-2, 1.5, 0.0},
    {2, 1.5, 0.0},
    {0, 1.5, 1.45},
    {0, -1.5, 1.45},
    {-2, -1.5, 0.0},
    {2, -1.5, 0.0},
  };

  GLint faces[][3] = {
    {0, 1, 2},
    {3, 4, 5},
  };

  GLint facesQuadradas[][4] = {
    {0, 2, 3, 4},
    {1, 2, 3, 5}
  };

  glColor3f(1.0, 0.0, 0.0);
  glutSolidCube(1.5);
  glPushMatrix();
  glTranslatef(1.5f, 0.0f, 0.0f);
  glutSolidCube(1.5);
  glTranslatef(0.0f, 1.5f, 0.0f);
  glutSolidCube(1.5);
  glTranslatef(-1.5f, 0.0f, 0.0f);
  glutSolidCube(1.5);
  glTranslatef(0.75f, -0.75f, 0.75f);
  GLfloat normal[] = {0, 1, 0};
  for(int i = 0; i < 2; i++){
    glBegin(GL_TRIANGLES);
      glNormal3fv(normal);
      glVertex3fv(vertices[faces[i][0]]);
      glVertex3fv(vertices[faces[i][1]]);
      glVertex3fv(vertices[faces[i][2]]);
      normal[1] = -1;
    glEnd();
  }
  GLfloat normaisQuadradas[][3] = {
    {0.58, 0, 0.81}, 
    {-0.58, 0, 0.81}
  };
  for(int i = 0; i < 2; i++){
    glColor3f(0.945, 0.471, 0.176);
    glBegin(GL_QUADS);
      glNormal3fv(normaisQuadradas[i]);
      glVertex3fv(vertices[facesQuadradas[i][0]]);
      glVertex3fv(vertices[facesQuadradas[i][1]]);
      glVertex3fv(vertices[facesQuadradas[i][2]]);
      glVertex3fv(vertices[facesQuadradas[i][3]]);
    glEnd();
  }
  glPopMatrix();
  glBegin(GL_QUADS);
    glNormal3f(0, -1, 0);
    glColor3f(0.4, 0.2, 0.0);
    glVertex3f(0.05, -0.76, -0.5);
    glVertex3f(0.75, -0.76, -0.5);
    glVertex3f(0.75, -0.76, 0.65);
    glVertex3f(0.05, -0.76, 0.65);
  glEnd();

  glBegin(GL_QUADS);
    glNormal3f(0, -1, 0);
    glColor3f(0.2f, 0.6f, 1.0f);
    glVertex3f(1.2, -0.76, 0.05);
    glVertex3f(1.9, -0.76, 0.05);
    glVertex3f(1.9, -0.76, 0.75);
    glVertex3f(1.2, -0.76, 0.75);
  glEnd();

}

void desenharRodas(){
  glColor3f(0.0, 0.0, 0.0);
  glPushMatrix();
  glTranslatef(-0.25, -0.02, -0.325);
  glRotatef(90, 0, 1, 0);
  glutSolidTorus(0.05, 0.1, 30, 30);
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(0.5, 0.5, 0.5);
  glNormal3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    for(int i = 0; i <= 360; i++){ 
      glVertex3f(0.1 * cos(i), 0.1 * sin(i), 0);
    }
  glEnd();
  glPopMatrix();

  glColor3f(0.0, 0.0, 0.0);
  glPushMatrix();
  glTranslatef(-0.25, 2, -0.325);
  glRotatef(90, 0, 1, 0);
  glutSolidTorus(0.05, 0.1, 30, 30);
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(0.5, 0.5, 0.5);
  glNormal3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    for(int i = 0; i <= 360; i++){ 
      glVertex3f(0.1 * cos(i), 0.1 * sin(i), 0);
    }
  glEnd();
  glPopMatrix();

}

void desenharCarga(){
  glBegin(GL_QUADS); // carga
    glColor3f(1.0, 1.0, 1.0);
    glNormal3f(0, 0, -1);
    glVertex3f(-0.3, 0.730, -0.325);
    glVertex3f( 0.3, 0.730, -0.325);
    glVertex3f( 0.3, 2.225, -0.325);
    glVertex3f(-0.3, 2.225, -0.325);
  glEnd();

  glBegin(GL_QUADS); // carga
    glColor3f(1.0, 1.0, 1.0);
    glNormal3f(0, 0, 1);
    glVertex3f(-0.3, 0.730, 0.395);
    glVertex3f( 0.3, 0.730, 0.395);
    glVertex3f( 0.3, 2.225, 0.395);
    glVertex3f(-0.3, 2.225, 0.395);
  glEnd();

  glBegin(GL_QUADS); // carga
    glColor3f(1.0, 1.0, 1.0);
    glNormal3f(-1, 0, 0);
    glVertex3f(-0.3, 0.730, -0.325);
    glVertex3f(-0.3, 0.730, 0.395);
    glVertex3f(-0.3, 2.225, 0.395);
    glVertex3f(-0.3, 2.225, -0.325);
  glEnd();

  glBegin(GL_QUADS); // carga
    glColor3f(1.0, 1.0, 1.0);
    glNormal3f(1, 0, 0);
    glVertex3f( 0.3, 0.730, -0.325);
    glVertex3f( 0.3, 0.730, 0.395);
    glVertex3f( 0.3, 2.225, 0.395);
    glVertex3f( 0.3, 2.225, -0.325);
  glEnd();

  glBegin(GL_QUADS); // carga
    glColor3f(1.0, 1.0, 1.0);
    glNormal3f(0, 1, 0);
    glVertex3f(-0.3, 2.225, -0.325);
    glVertex3f( 0.3, 2.225, -0.325);
    glVertex3f( 0.3, 2.225, 0.395);
    glVertex3f(-0.3, 2.225, 0.395);
  glEnd();

  glBegin(GL_QUADS); // carga 
    glColor3f(1.0, 1.0, 1.0);
    glNormal3f(0, -1, 0);
    glVertex3f(-0.3, 0.730, -0.325);
    glVertex3f( 0.3, 0.730, -0.325);
    glVertex3f( 0.3, 0.730, 0.395);
    glVertex3f(-0.3, 0.730, 0.395);
  glEnd();

}

void desenharLateral(){
  glBegin(GL_QUADS); // lateral da cabine (base)
  glNormal3f(-1, 0, 0);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.3, -0.225, -0.325);
    glVertex3f(-0.3,  0.725, -0.325);
    glVertex3f(-0.3,  0.725, -0.125);
    glVertex3f(-0.3, -0.225, -0.125);
  glEnd();

  glBegin(GL_QUADS); // lateral da cabine (capo)
    glNormal3f(-1, 0, 0);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.3, -0.225, -0.125);
    glVertex3f(-0.3,  0.725, -0.125);
    glVertex3f(-0.3,  0.725, -0.025);
    glVertex3f(-0.3, 0.075, -0.025);
  glEnd();

  glBegin(GL_QUADS); // lateral da cabine (janela)
    glNormal3f(-1, 0, 0);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.3, 0.075, -0.025);
    glVertex3f(-0.3, 0.725, -0.025);
    glVertex3f(-0.3, 0.725, 0.275);
    glVertex3f(-0.3, 0.175, 0.275);
  glEnd();

  glBegin(GL_QUADS); // lateral da cabine (cima)
    glNormal3f(-1, 1, 0);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.3, 0.175, 0.275);
    glVertex3f(-0.3, 0.725, 0.275);
    glVertex3f(-0.275, 0.725, 0.325);
    glVertex3f(-0.275, 0.225, 0.325);
  glEnd();

  glBegin(GL_QUADS); // farol lateral
    glNormal3f(-1, 0, 0);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(-0.301, -0.2266, -0.3);
    glVertex3f(-0.301, -0.12, -0.3);
    glVertex3f(-0.301, -0.12, -0.2);
    glVertex3f(-0.301, -0.2266, -0.2);
  glEnd();

  glBegin(GL_QUADS); // janela
    glNormal3f(-1, 0, 0);
    glColor3f(0.5,0.5, 0.5);
    glVertex3f(-0.30005, 0.0949, -0.019);
    glVertex3f(-0.30005, 0.519, -0.019);
    glVertex3f(-0.30005, 0.519, 0.265);
    glVertex3f(-0.30005, 0.1949, 0.265);

    glVertex3f(-0.30005, 0.5499, -0.02);
    glVertex3f(-0.30005, 0.699, -0.02);
    glVertex3f(-0.30005, 0.699, 0.27);
    glVertex3f(-0.30005, 0.5499, 0.27);
  glEnd();

  glBegin(GL_QUADS); // maçaneta
  glNormal3f(-1, 0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.30005, 0.4, -0.04);
    glVertex3f(-0.30005, 0.4, -0.065);
    glVertex3f(-0.30005, 0.5, -0.065);
    glVertex3f(-0.30005, 0.5, -0.04);
  glEnd();

  // Contorno das janelas

  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_LOOP);
    glVertex3f(-0.30005, 0.095, -0.02);
    glVertex3f(-0.30005, 0.52, -0.02);
    glVertex3f(-0.30005, 0.52, 0.27);
    glVertex3f(-0.30005, 0.195, 0.27);
  glEnd();

  glBegin(GL_LINE_LOOP);
    glVertex3f(-0.30005, 0.55, -0.02);
    glVertex3f(-0.30005, 0.7, -0.02);
    glVertex3f(-0.30005, 0.7, 0.27);
    glVertex3f(-0.30005, 0.55, 0.27);
  glEnd();

  glBegin(GL_LINE_LOOP); // porta
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.30005, 0.535, -0.320);
    glVertex3f(-0.30005, 0.535, 0.270);
    glVertex3f(-0.30005, 0.195, 0.27);
    glVertex3f(-0.30005, 0.095, -0.02);
    glVertex3f(-0.30005, 0.095, -0.320);
  glEnd();

  glBegin(GL_QUADS); // retrovisor
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.32, 0.095, -0.02);
    glVertex3f(-0.35, 0.110, -0.02);
    glVertex3f(-0.35, 0.130, 0.112);
    glVertex3f(-0.32, 0.115, 0.112);
  glEnd();
  glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.32, 0.095, 0.0);
    glVertex3f(-0.3, 0.095, 0.0);
    glVertex3f(-0.3, 0.1, 0.01);
    glVertex3f(-0.32, 0.1, 0.01);
  glEnd();
  glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.32, 0.11, 0.1);
    glVertex3f(-0.3, 0.11, 0.1);
    glVertex3f(-0.3, 0.12, 0.11);
    glVertex3f(-0.32, 0.12, 0.11);
  glEnd();
}

void desenharCarro() {
  glPushMatrix();
  glEnable(GL_DEPTH_TEST);

  glBegin(GL_QUADS); // base (horizontal)
    glNormal3f(0.0, -1.0, 0.0);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.3, -0.225, -0.325);
    glVertex3f( 0.3, -0.225, -0.325);
    glVertex3f( 0.3, -0.225, -0.125);
    glVertex3f(-0.3, -0.225, -0.125);
  glEnd();

  glBegin(GL_QUADS); // capô (inclinado)
    glNormal3f(0.0, -0.316, 0.949); // aproximada
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.3, -0.225, -0.125);
    glVertex3f( 0.3, -0.225, -0.125);
    glVertex3f( 0.3,  0.075, -0.025);
    glVertex3f(-0.3,  0.075, -0.025);
  glEnd();

  glBegin(GL_QUADS); // janela frontal (inclinada)
    glNormal3f(0.0, 0.316, -0.949); // aproximada
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.3, 0.075, -0.025);
    glVertex3f( 0.3, 0.075, -0.025);
    glVertex3f( 0.3, 0.175, 0.275);
    glVertex3f(-0.3, 0.175, 0.275);
  glEnd();

  glBegin(GL_QUADS); // parte de cima inclinada
    glNormal3f(0.0, 0.447, 0.894); // aproximada
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.3, 0.175, 0.275);
    glVertex3f( 0.3, 0.175, 0.275);
    glVertex3f( 0.275, 0.225, 0.325);
    glVertex3f(-0.275, 0.225, 0.325);
  glEnd();

  glBegin(GL_QUADS); // base superior (horizontal)
    glNormal3f(0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.275, 0.225, 0.325);
    glVertex3f( 0.275, 0.225, 0.325);
    glVertex3f( 0.275, 0.725, 0.325);
    glVertex3f(-0.275, 0.725, 0.325);
  glEnd();

  glColor3f(0.2, 0.2, 0.2); // grade frontal
  float j = 0;
  for(int i = 0; i < 4; i++) {
    glBegin(GL_QUADS);
      glNormal3f(0.0, -1.0, 0.0);
      glVertex3f(-0.215, -0.226, -0.300 + j);
      glVertex3f( 0.215, -0.226, -0.300 + j);
      j += 0.02;
      glVertex3f( 0.215, -0.226, -0.29 + j);
      glVertex3f(-0.215, -0.226, -0.29 + j);
      j += 0.02;
    glEnd();
  }

  j = 1;
  for(int i = 0; i < 2; i++) { // faróis
    glBegin(GL_QUADS);
      glNormal3f(0.0, -1.0, 0.0);
      glColor3f(0.8, 0.8, 0.8);
      glVertex3f(-0.2999 * j, -0.2266, -0.30);
      glVertex3f(-0.216  * j, -0.2266, -0.30);
      glVertex3f(-0.216  * j, -0.2266, -0.2);
      glVertex3f(-0.2999 * j, -0.2266, -0.2);
    glEnd();
    j *= -1;
  }

  glBegin(GL_QUADS); // janela frontal (vidro)
    glNormal3f(0.0, 0.316, -0.949); // mesma da janela anterior
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.29, 0.0749, -0.015);
    glVertex3f( 0.29, 0.0749, -0.015);
    glVertex3f( 0.29, 0.1725, 0.275);
    glVertex3f(-0.29, 0.1725, 0.275);
  glEnd();

  glBegin(GL_LINE_LOOP); // contorno da janela
    // sem normal (linha)
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.29, 0.075, -0.015);
    glVertex3f( 0.29, 0.075, -0.015);
    glVertex3f( 0.29, 0.175, 0.275);
    glVertex3f(-0.29, 0.175, 0.275);
  glEnd();

  desenharLateral();

  glPushMatrix();
  glScalef(-1, 1, 1); // espelha lateral direita
  desenharLateral();
  glPopMatrix();

  glBegin(GL_QUADS); // parte de trás
    glNormal3f(0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(-0.3, 0.725, 0.275);
    glVertex3f( 0.3, 0.725, 0.275);
    glVertex3f( 0.3, 0.725, -0.325);
    glVertex3f(-0.3, 0.725, -0.325);
  glEnd();

  desenharCarga();

  desenharRodas();
  glScalef(-1, 1, 1);
  desenharRodas();
  glPopMatrix();

}


void desenharCopoAmericano(){

    glDepthMask(GL_FALSE);

    // Parte translúcida
    glColor4f(1.0, 1.0, 1.0, 0.2);
    for (int i = 0; i < 12; i++) {
      float ang1 = i * 2 * M_PI / 12;
      float ang2 = (i + 1) * 2 * M_PI / 12;
      float angm = (ang1 + ang2) / 2;
      float xm = cos(angm);
      float ym = sin(angm);

      glBegin(GL_QUADS);
        glNormal3f(xm, ym, 0.0f);
        glVertex3f(0.5 * cos(ang1), 0.5 * sin(ang1), -0.5);
        glVertex3f(0.5 * cos(ang2), 0.5 * sin(ang2), -0.5);
        glVertex3f(0.6 * cos(ang2), 0.6 * sin(ang2), 0.7);
        glVertex3f(0.6 * cos(ang1), 0.6 * sin(ang1), 0.7);
      glEnd();

      glBegin(GL_QUADS);
        glNormal3f(xm, ym, 0.0f);
        glVertex3f(0.55 * cos(ang1), 0.55 * sin(ang1), -0.5);
        glVertex3f(0.55 * cos(ang2), 0.55 * sin(ang2), -0.5);
        glVertex3f(0.65 * cos(ang2), 0.65 * sin(ang2), 0.7);
        glVertex3f(0.65 * cos(ang1), 0.65 * sin(ang1), 0.7);
      glEnd();

      glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(0.5 * cos(ang1), 0.5 * sin(ang1), -0.5);
        glVertex3f(0.5 * cos(ang2), 0.5 * sin(ang2), -0.5);
        glVertex3f(0.55 * cos(ang2), 0.55 * sin(ang2), -0.5);
        glVertex3f(0.55 * cos(ang1), 0.55 * sin(ang1), -0.5);
      glEnd();

      glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.6 * cos(ang1), 0.6 * sin(ang1), 0.7);
        glVertex3f(0.6 * cos(ang2), 0.6 * sin(ang2), 0.7);
        glVertex3f(0.65 * cos(ang2), 0.65 * sin(ang2), 0.7);
        glVertex3f(0.65 * cos(ang1), 0.65 * sin(ang1), 0.7);
      glEnd();
    }

    // Parte superior
    for (int i = 0; i < 12; i++) {
      float ang1 = i * 2 * M_PI / 12;
      float ang2 = (i + 1) * 2 * M_PI / 12;
      float angm = (ang1 + ang2) / 2;
      float xm = cos(angm);
      float ym = sin(angm);

      glBegin(GL_QUADS);
        glNormal3f(xm, ym, 0.0f);
        glVertex3f(0.61 * cos(ang1), 0.61 * sin(ang1), 0.7);
        glVertex3f(0.61 * cos(ang2), 0.61 * sin(ang2), 0.7);
        glVertex3f(0.65 * cos(ang2), 0.65 * sin(ang2), 1.0);
        glVertex3f(0.65 * cos(ang1), 0.65 * sin(ang1), 1.0);
      glEnd();

      glBegin(GL_QUADS);
        glNormal3f(xm, ym, 0.0f);
        glVertex3f(0.66 * cos(ang1), 0.66 * sin(ang1), 0.7);
        glVertex3f(0.66 * cos(ang2), 0.66 * sin(ang2), 0.7);
        glVertex3f(0.7 * cos(ang2), 0.7 * sin(ang2), 1.0);
        glVertex3f(0.7 * cos(ang1), 0.7 * sin(ang1), 1.0);
      glEnd();

      glBegin(GL_QUADS);
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(0.65 * cos(ang1), 0.65 * sin(ang1), 1.0);
        glVertex3f(0.65 * cos(ang2), 0.65 * sin(ang2), 1.0);
        glVertex3f(0.7 * cos(ang2), 0.7 * sin(ang2), 1.0);
        glVertex3f(0.7 * cos(ang1), 0.7 * sin(ang1), 1.0);
      glEnd();
    }

    // Tampa inferior final (externa)
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0f, 0.0f, -1.0f);
    for (int i = 0; i < 12; i++) {
      glVertex3f(0.0, 0.0, -0.5);
      glVertex3f(0.5 * cos(i * 2 * M_PI / 12), 0.5 * sin(i * 2 * M_PI / 12), -0.5);
      glVertex3f(0.5 * cos((i + 1) * 2 * M_PI / 12), 0.5 * sin((i + 1) * 2 * M_PI / 12), -0.5);
    }
    glEnd();

   glDepthMask(GL_TRUE);
 
  glDisable(GL_BLEND);

  glColor4f(0.992, 0.678, 0.043, 1.0);

  for (int i = 0; i < 12; i++) {
    float ang1 = i * 2 * M_PI / 12;
    float ang2 = (i + 1) * 2 * M_PI / 12;
    float angm = (ang1 + ang2) / 2;
    float xm = cos(angm);
    float ym = sin(angm);

    glBegin(GL_QUADS);
      glNormal3f(xm, ym, 0.0f);
      glVertex3f(0.49 * cos(ang1), 0.49 * sin(ang1), -0.5);
      glVertex3f(0.49 * cos(ang2), 0.49 * sin(ang2), -0.5);
      glVertex3f(0.59 * cos(ang2), 0.59 * sin(ang2), 0.5);
      glVertex3f(0.59 * cos(ang1), 0.59 * sin(ang1), 0.5);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
      glNormal3f(0.0f, 0.0f, 1.0f);
      glVertex3f(0.0, 0.0, 0.5);
      glVertex3f(0.59 * cos(ang1), 0.59 * sin(ang1), 0.5);
      glVertex3f(0.59 * cos(ang2), 0.59 * sin(ang2), 0.5);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
      glNormal3f(0.0f, 0.0f, -1.0f);
      glVertex3f(0.0, 0.0, -0.5);
      glVertex3f(0.49 * cos(ang1), 0.49 * sin(ang1), -0.5);
      glVertex3f(0.49 * cos(ang2), 0.49 * sin(ang2), -0.5);
    glEnd();
  }

  glColor4f(1.0, 1.0, 0.85, 1.0); // quase branco
  glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.51);
    for (int i = 0; i <= 12; i++) {
      float ang = i * 2 * M_PI / 12;
      glVertex3f(0.59 * cos(ang), 0.59 * sin(ang), 0.55);
    }
  glEnd();
  
  glEnable(GL_BLEND);
  
  }


void desenharGarrafa() {
  glPushMatrix();
  glColor4f(0.4f, 0.2f, 0.05f, 1.0);

  // Corpo da garrafa (base)
  glPushMatrix();
  glTranslatef(0.0, 0.0, 0.0);
  gluCylinder(quad, 0.3, 0.3, 1.0, 32, 32); // altura 1.0
  glPopMatrix();

  // Ombro (0.0 + 1.0)
  glPushMatrix();
  glTranslatef(0.0, 0.0, 1.0);
  gluCylinder(quad, 0.3, 0.15, 0.2, 32, 32); // altura 0.2
  glPopMatrix();

  // Pescoço (1.0 + 0.2)
  glPushMatrix();
  glTranslatef(0.0, 0.0, 1.2);
  gluCylinder(quad, 0.15, 0.15, 0.4, 32, 32); // altura 0.4
  glPopMatrix();

  // Bico (1.2 + 0.4)
  glPushMatrix();
  glTranslatef(0.0, 0.0, 1.6);
  gluCylinder(quad, 0.13, 0.13, 0.1, 32, 32); // altura 0.1
  glPopMatrix();

  // Tampa (1.6 + 0.1)
  glColor4f(0.3f, 0.2f, 0.05f, 1.0f);
  glPushMatrix();
  glTranslatef(0.0, 0.0, 1.7);
  gluDisk(quad, 0.0, 0.13, 32, 1);
  glPopMatrix();

  glPopMatrix();
}


void desenharPoste() {

  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_QUADS);
    glNormal3f(1, 0, 0);
    glVertex3f(0.0, -0.1, 0.0);
    glVertex3f(0.0, 0.1, 0.0);
    glVertex3f(0.0, 0.1, 4.0);
    glVertex3f(0.0, -0.1, 4.0);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(0.1, -0.1, 0.0);
    glVertex3f(0.1, 0.1, 0.0);
    glVertex3f(0.1, 0.1, 4.0);
    glVertex3f(0.1, -0.1, 4.0);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(0.0, -0.1, 0.0);
    glVertex3f(0.1, -0.1, 0.0);
    glVertex3f(0.1, -0.1, 4.0);
    glVertex3f(0.0, -0.1, 4.0);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(0.0, 0.1, 0.0);
    glVertex3f(0.1, 0.1, 0.0);
    glVertex3f(0.1, 0.1, 4.0);
    glVertex3f(0.0, 0.1, 4.0);
  glEnd();

  glBegin(GL_QUADS);
    glVertex3f(0.0, -0.1, 4.0);
    glVertex3f(0.0, 0.1, 4.0);
    glVertex3f(-0.5, 0.1, 4.2);
    glVertex3f(-0.5, -0.1, 4.2);
  glEnd();

  glColor3f(1.0, 1.0, 0.0);
  glBegin(GL_QUADS);
  glNormal3f(0, 0, 1);
    glVertex3f(-0.5, -0.1, 4.2);
    glVertex3f(-0.5, 0.1, 4.2);
    glVertex3f(-0.9, 0.1, 4.2);
    glVertex3f(-0.9, -0.1, 4.2);
  glEnd();

  glBegin(GL_QUADS);
  glNormal3f(1, 0, 0);
    glVertex3f(-0.9, -0.1, 4.2);
    glVertex3f(-1.0, -0.1, 4.5);
    glVertex3f(-1.0, 0.1, 4.5);
    glVertex3f(-0.9, 0.1, 4.2);
  glEnd();

}
