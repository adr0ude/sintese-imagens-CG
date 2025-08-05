#include <GL/glut.h>
#include <GL/freeglut.h>
#include "desenhos.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>

float carroPosY = -10.0f;
GLUquadric* quad;
int cenaAtual = 0;
int totalCenas = 8;
int temposCena[] = {6000, 6000, 17000, 6000, 8000, 8000, 7000, 7000}; 

void configurarCamera(float posX, float posY, float posZ, float dirX, float dirY, float dirZ){
  gluLookAt(posX, posY, posZ, dirX, dirY, dirZ, 0, 0, 1);
}

void primeiraCena(){
  configurarCamera(-15, 0, 3, 0, 0, 0);
  
  glPushMatrix();
  glColor3f(0.2, 0.2, 0.2); 
  glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glVertex3f(-15.0, -15.0, -0.5);
    glVertex3f( 15.0, -15.0, -0.5);
    glVertex3f( 15.0, 15.0, -0.5);
    glVertex3f(-15.0, 15.0, -0.5);
  glEnd();

  glColor3f(0.5, 0.5, 0.5); 
  glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glVertex3f(15.0, -15.0, 0.0);
    glVertex3f(0.0, -15.0, 0.0);
    glVertex3f(0.0, 15.0, 0.0);
    glVertex3f(15.0, 15.0, 0.0);
  glEnd();

  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glVertex3f(0.0, 15.0, 0.0);
    glVertex3f(0.0, -15.0, 0.0);
    glVertex3f(0.0, -15.0, -0.5);
    glVertex3f(0.0, 15.0, -0.5);
  glEnd();

  float faixaComprimento = 1.0f;
  float espaco = 1.5;
  float largura = - 15 / 2;
  glColor3f(1.0, 1.0, 0.0);

  for (float y = -15.0f; y < 15.0f; y += faixaComprimento + espaco) {
    glBegin(GL_QUADS);
      glNormal3f(0, 0, 1);
      glVertex3f(largura - 0.5, y, 0.01f);
      glVertex3f( largura, y, 0.01f);
      glVertex3f( largura, y + faixaComprimento, 0.01f);
      glVertex3f(largura - 0.5, y + faixaComprimento, 0.01f);
    glEnd();
  }
  glPopMatrix();

  glPushMatrix();
  glTranslatef(5.0f, -3, 0.5f);
  desenharBar();
  glTranslatef(-1.0f, 8.0f, 0.0f);
  glRotatef(270, 0, 0, 1);
  desenharCasa();
  glPopMatrix();

  glPushMatrix();
  glScalef(2, 2, 2);
  glTranslatef(-0.5f, carroPosY, 0.225f);
  glRotatef(180, 0, 0, 1);
  desenharCarro();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(1.0f, 2.0f, 0.0f);
  desenharPoste();
  glTranslatef(0.0f, -8.0f, 0.0f);
  desenharPoste();
  glPopMatrix();
}

void segundaCena(){
  configurarCamera(3, 3, 3, 0, 0, 0);
  glPushMatrix();
  float largura = 0;
  for(int i = 0; i < 6; i++){
    glBegin(GL_QUADS);
    if(i % 2 == 0){ 
    glColor3f(0.851, 0.569, 0.165);
    }else{
      glColor3f(0.592, 0.38, 0.086);
    }
      glNormal3f(0, 0, 1);
      glVertex3f(6, 6 - largura, 0.0);
      glVertex3f(6, 6 - largura + 2, 0.0);
      glVertex3f(-6, 6 - largura + 2, 0.0);
      glVertex3f(-6, 6 - largura, 0.0);
    largura += 2;
    glEnd();   
  }
  
  glPopMatrix();
  desenharGarrafa();
  glPushMatrix();
  glScalef(0.5, 0.5, 0.5);
  glTranslatef(2.0f, 2.0f, 0.5f);
  desenharCopoAmericano();
  glPopMatrix();
  
}

float tempoTransicao = 0.0f; // varia de 0.0 (dia) até 1.0 (noite)
bool indoParaNoite = true;   // direção da transição
bool saida = false;

void animarSubidaCarro(int value) {
  carroPosY += 0.01f;  // velocidade da translação

  if (carroPosY >= 10.0f) {
    carroPosY = 10.0f;  // limita
    return;             // para a animação
  }

  glutPostRedisplay();                  // redesenha
  glutTimerFunc(16, animarSubidaCarro, 0);  // chama de novo em ~16 ms (~60 FPS)
}

bool animacaoNoiteIniciada = false;
void terceiraCena(){
  primeiraCena();
  
  if (tempoTransicao >= 1.0f) {
    if(cenaAtual == 4){
      glutTimerFunc(5000, animarSubidaCarro, 0); // começa a animação
      }
    }
  }

void quartaCena(){
  segundaCena();
  glPushMatrix();
  glTranslatef(0.0f, -0.5f, 0.0f);
  desenharGarrafa();
  glTranslatef(0.0f, -0.5f, 0.0f);
  desenharGarrafa();
  glTranslatef(-0.5f, 0.0f, 0.0f);
  desenharGarrafa();
  glTranslatef(0.0f, 0.5f, 0.0f);
  desenharGarrafa();
  glTranslatef(0.0f, 0.5f, 0.0f);
  desenharGarrafa();
  glTranslatef(0.0f, 0.5f, 0.0f);
  desenharGarrafa();
  glTranslatef(-0.5f, 0.0f, 0.0f);
  desenharGarrafa();
  glPopMatrix();
}

float faixaOffset = 0.0f;
float velocidade = 0.05f; 
float aceleracao = 0.001f;        
float velocidadeMaxima = 0.3f;
float zigzagX = 0.0f;
float zigzagDirecao = 1.0f;
float zigzagVelocidade = 0.05f;

void desenharPostesAnimados() {
  for (float y = -16.0f + faixaOffset; y < 16.0f; y += 8.0f) {
    glPushMatrix();
      glTranslatef(1.0f, y, 0.0f); // X = 4.0 posiciona no lado direito
      desenharPoste();
    glPopMatrix();
  }
}

void quintaCena(){
  configurarCamera(-5, -10, 4, -5, 0, 0);
  glPushMatrix();
  glColor3f(0.2, 0.2, 0.2); 
  glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glVertex3f(-20.0, -20.0, -0.5);
    glVertex3f( 20.0, -20.0, -0.5);
    glVertex3f( 20.0, 20.0, -0.5);
    glVertex3f(-20.0, 20.0, -0.5);
  glEnd();

  glColor3f(0.5, 0.5, 0.5); 
  glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glVertex3f(20.0, -20.0, 0.0);
    glVertex3f(0.0, -20.0, 0.0);
    glVertex3f(0.0, 20.0, 0.0);
    glVertex3f(20.0, 20.0, 0.0);
  glEnd();

  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glVertex3f(0.0, 20.0, 0.0);
    glVertex3f(0.0, -20.0, 0.0);
    glVertex3f(0.0, -20.0, -0.5);
    glVertex3f(0.0, 20.0, -0.5);
  glEnd();

  float faixaComprimento = 1.0f;
  float espaco = 1.5;
  float largura = - 15 / 2;
  glColor3f(1.0, 1.0, 0.0);

  for (float y = -16.0f + faixaOffset; y < 16.0f; y += faixaComprimento + espaco) {
    glBegin(GL_QUADS);
      glNormal3f(0, 0, 1);
      glVertex3f(largura - 0.5, y, 0.01f);
      glVertex3f(largura, y, 0.01f);
      glVertex3f(largura, y + faixaComprimento, 0.01f);
      glVertex3f(largura - 0.5, y + faixaComprimento, 0.01f);
    glEnd();
  }
  glPopMatrix();
  
  desenharPostesAnimados();
  
  glPushMatrix();
    glTranslatef(zigzagX, 0, 0); // Aplica o movimento em zig-zag
    glScalef(2, 2, 2);
    glTranslatef(-2.5f, 0, 0.700f);
    glRotatef(180, 0, 0, 1);
    desenharCarro();
  glPopMatrix();
}

float posYCarro = 10.0f;   // começa longe
float velocidadeCarro = 0.05f;
bool colidiu = false;
float anguloRotacaoColisao = 0.0f;
bool efeitoColisaoAtivo = false;
bool subindo = true;

void desenharRachadurasMuro() {
  glColor3f(0.1f, 0.1f, 0.1f); // cor das rachaduras (quase preto)
  glLineWidth(2.0f); // espessura da rachadura

  glBegin(GL_LINES);

  // Linha 1 (vertical quebrada)
  glVertex3f(0.5f, 0.01f, 1.0f);
  glVertex3f(0.7f, 0.01f, 1.5f);
  glVertex3f(0.7f, 0.01f, 1.5f);
  glVertex3f(0.4f, 0.01f, 2.0f);

  // Linha 2 (horizontal quebrada)
  glVertex3f(-0.5f, 0.01f, 2.0f);
  glVertex3f(0.2f, 0.01f, 2.1f);
  glVertex3f(0.2f, 0.01f, 2.1f);
  glVertex3f(0.6f, 0.01f, 2.2f);

  // Linha 3 (diagonal quebrada)
  glVertex3f(-0.3f, 0.01f, 0.8f);
  glVertex3f(0.0f, 0.01f, 1.1f);
  glVertex3f(0.0f, 0.01f, 1.1f);
  glVertex3f(0.3f, 0.01f, 1.4f);

  glEnd();
}

void sextaCena(){
  configurarCamera(15, 15, 2, 0, 0, 0);
  int linhas = 10;
  int colunas = 10;

  float larguraTijolo = 1.0f;    // eixo X
  float alturaTijolo = 0.4f;     // eixo Z
  float espacoHorizontal = 0.05f;
  float espacoVertical = 0.05f;

  for (int linha = 0; linha < linhas; linha++) {
    float z = linha * (alturaTijolo + espacoVertical); // Altura do tijolo

    float deslocamento = (linha % 2 == 0) ? 0.0f : (larguraTijolo / 2.0f);

    for (int coluna = -30; coluna < colunas; coluna++) {
      float x = coluna * (larguraTijolo + espacoHorizontal) + deslocamento;

      glColor3f(0.8f, 0.3f, 0.1f); // cor tijolo

      glBegin(GL_QUADS);
        // Face frontal do muro (em Y = 0)
      glNormal3f(1, 0, 0);
        glVertex3f(x, 0.0f, z);
        glVertex3f(x + larguraTijolo, 0.0f, z);
        glVertex3f(x + larguraTijolo, 0.0f, z + alturaTijolo);
        glVertex3f(x, 0.0f, z + alturaTijolo);
      glEnd();
    }
  }

  glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.2);
    glNormal3f(1, 0, 0);
    glVertex3f(-30.0, -0.1, -0.5);
    glVertex3f(-30.0, -0.1, 4.5);
    glVertex3f(10.0, -0.1, 4.5);
    glVertex3f(10.0, -0.1, -0.5);
  
  glColor3f(0.5, 0.5, 0.5); 
  glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glVertex3f(-20.0, -10.0, 0.0);
    glVertex3f(20.0, -10.0, 0.0);
    glVertex3f(20.0, 5.0, 0.0);
    glVertex3f(-20.0, 5.0, 0.0);
  glEnd();

  glColor3f(0.2, 0.2, 0.2); 
  glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glVertex3f(-20.0, -15.0, -0.5);
    glVertex3f(20.0, -15.0, -0.5);
    glVertex3f(20.0, 15.0, -0.5);
    glVertex3f(-20.0, 15.0, -0.5);
  glEnd();

  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glVertex3f(-20.0, 5.0, 0.0);
    glVertex3f(20.0, 5.0, 0.0);
    glVertex3f(20.0, 5.0, -0.5);
    glVertex3f(-20.0, 5.0, -0.5);
  glEnd();

  glPushMatrix();
  glScalef(3, 3, 3);
  //glRotatef(180, 0, 0, 1);
  glTranslatef(1.5f, posYCarro, 0.425f); // movimento no eixo Y
  glRotatef(anguloRotacaoColisao, 1, 0, 0); // levanta ou abaixa traseira
  desenharCarro();
  glPopMatrix();

  if (colidiu) {
    glPushMatrix();
    glTranslatef(5.0f, 0.1f, 1.0f);
    desenharRachadurasMuro();
    glScalef(3.0f, 2.0f, 2.0f); 
    glTranslatef(0.0f, 0.0f, -1.0f);
    desenharRachadurasMuro();
    glPopMatrix();
  }

}

void escreverTextoFinal() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glDisable(GL_LIGHTING); 
    glColor3f(1.0f, 1.0f, 1.0f); 

    void *fonte = GLUT_BITMAP_HELVETICA_18;

    auto drawText = [&](float x, float y, const char* texto) {
        glRasterPos2f(x, y);
        for (const char* c = texto; *c != '\0'; c++) {
            glutBitmapCharacter(fonte, *c);
        }
    };

    // Frase principal
    drawText(260, 500, "Se beber, nao dirija!");

    // Espaço e nomes
    drawText(340, 420, "Alunos");
    drawText(230, 380, "Luis Guilherme Ferreira da Costa");
    drawText(230, 340, "Maria Eduarda Araujo Sales");
    drawText(230, 300, "Pedro Henrique Silveira Gomes Sabi");

    glEnable(GL_LIGHTING); // Reativa iluminação se necessário
}

void animarEfeitoColisao(int value) {
  if (!efeitoColisaoAtivo) return;

  if (subindo) {
    anguloRotacaoColisao += 1.5f; // Levanta traseira
    if (anguloRotacaoColisao >= 30.0f) {
      subindo = false;
    }
  } else {
    anguloRotacaoColisao -= 1.5f; // Volta ao normal
    if (anguloRotacaoColisao <= 0.0f) {
      anguloRotacaoColisao = 0.0f;
      efeitoColisaoAtivo = false; // Fim do efeito
      return;
    }
  }

  glutPostRedisplay();
  glutTimerFunc(16, animarEfeitoColisao, 0);
}

void animarColisaoComMuro(int value) {
  if (!colidiu) {
    posYCarro -= velocidadeCarro;

    if (posYCarro <= 0.225f) {
      posYCarro = 0.225f;
      colidiu = true;
      efeitoColisaoAtivo = true;
      subindo = true;
      glutTimerFunc(0, animarEfeitoColisao, 0); // inicia o efeito de batida
    }

    glutPostRedisplay();
    glutTimerFunc(16, animarColisaoComMuro, 0);
  }
}

void atualizarZigZag(int value) {
    zigzagX += zigzagVelocidade * zigzagDirecao;

    // Inverte a direção ao atingir limite (zig-zag)
    if (zigzagX > 1.0f || zigzagX < -1.0f)
        zigzagDirecao *= -1.0f;

    glutPostRedisplay();
    glutTimerFunc(16, atualizarZigZag, 0); // 60 FPS
}

void atualizarAnimacao(int value) {
    // Aumenta a velocidade com aceleração
    velocidade += aceleracao;

    // Limita a velocidade, se quiser
    if (velocidade > velocidadeMaxima)
        velocidade = velocidadeMaxima;

    // Move as faixas
    faixaOffset -= velocidade;

    // Reinicia o loop da faixa se sair da tela
    if (faixaOffset < -(1.0f + 1.5f)) // faixaComprimento + espaco
        faixaOffset = 0.0f;

    glutPostRedisplay();
    glutTimerFunc(16, atualizarAnimacao, 0);
}

void atualizarNoite(int valor) {
  const float velocidade = 0.001f;

  if (indoParaNoite) {
    tempoTransicao += velocidade;
    if (tempoTransicao >= 1.0f) {
      tempoTransicao = 1.0f;
      indoParaNoite = false;
    }
  }

  glutPostRedisplay();
  glutTimerFunc(16, atualizarNoite, 0);
}

void atualizar() {
  carroPosY += 0.01f;
  if (carroPosY >= 0.0f) carroPosY = 0.0f;
  glutPostRedisplay(); 
}

void configurarLuzAmbiente(float tempoTransicao) {
  GLfloat luz_ambiente[] = {
      static_cast<GLfloat>(0.3 * (1.0 - tempoTransicao)),
      static_cast<GLfloat>(0.3 * (1.0 - tempoTransicao)),
      static_cast<GLfloat>(0.3 * (1.0 - tempoTransicao)),
      1.0f
  };

  GLfloat luz_difusa[] = {
      static_cast<GLfloat>(0.8 * (1.0 - tempoTransicao)),
      static_cast<GLfloat>(0.8 * (1.0 - tempoTransicao)),
      static_cast<GLfloat>(0.8 * (1.0 - tempoTransicao)),
      1.0f
  };

  GLfloat posicao_luz[] = {0.0, -2.0, 10.0, 1.0};

  glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
  glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz);
}

void configurarLuzPoste(float tempoTransicao) {
  if (tempoTransicao > 0.5f) { 
      GLfloat luz_poste_ambiente[] = {0.3f, 0.3f, 0.1f, 1.0f};
      GLfloat luz_poste_difusa[]   = {0.8f, 0.8f, 0.3f, 1.0f};
      GLfloat posicao_poste[]      = {-0.9f, -2.0f, 4.1f, 1.0f};
      GLfloat direcao_poste[]      = {0.0f, 0.0f, -1.5f};
      GLfloat luz_poste_especular[] = {1.0f, 1.0f, 0.5f, 1.0f};

      glEnable(GL_LIGHT1);
      glLightfv(GL_LIGHT1, GL_AMBIENT, luz_poste_ambiente);
      glLightfv(GL_LIGHT1, GL_DIFFUSE, luz_poste_difusa);
      glLightfv(GL_LIGHT1, GL_POSITION, posicao_poste);
      glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 65.0f);
      glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direcao_poste);
      glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 3.0f);
      glLightfv(GL_LIGHT1, GL_SPECULAR, luz_poste_especular);
  } else {
      glDisable(GL_LIGHT1);
  }
}

void configurarCorDeFundo(float tempoTransicao) {
    float r = (1.0 - tempoTransicao) * 0.0f + tempoTransicao * 0.0f;
    float g = (1.0 - tempoTransicao) * 0.7f + tempoTransicao * 0.0f;
    float b = (1.0 - tempoTransicao) * 1.0f + tempoTransicao * 0.2f;

    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void trocarCena(int value) {
  cenaAtual++;

  if (cenaAtual >= totalCenas) {
    cenaAtual = totalCenas - 1;
  }

  glutPostRedisplay();
  glutTimerFunc(temposCena[cenaAtual], trocarCena, 0);
}

static bool colisaoIniciada = false;
static bool zigzagIniciado = false;

void draw() {
    configurarCorDeFundo(tempoTransicao);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 0.1, 100);

    
  //quarta e segunda cena = 3, 3, 3
  //primeira e terceira cena = -15, 0, 3
  //quinta cena = -5, -10, 4, -5, 0, 0
  switch (cenaAtual) {
    case 0:
      glutIdleFunc(atualizar);
      primeiraCena();
      break;
    case 1:
      glClearColor(0.467, 0.0, 0.0, 1.0);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      segundaCena();
      break;
    case 2:
      terceiraCena(); // transição dia/noite
      break;
    case 3:
      glClearColor(0.467, 0.0, 0.0, 1.0);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      quartaCena(); // mesa com mais garrafas
      break;
    case 4:
      tempoTransicao = 1.0f;
      glutIdleFunc(NULL);
      terceiraCena();
      break;
    case 5:
      tempoTransicao = 1.0f;
      quintaCena(); // caminhão na rua
      break;
    case 6:
      tempoTransicao = 1.0f;
      sextaCena(); // colisão no muro
      break;
    case 7:
      glClearColor(0.0, 0.0, 0.0, 1.0); // fundo preto
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      escreverTextoFinal();
      break;
  }
  
  if (cenaAtual == 2 && !animacaoNoiteIniciada) {
      glutTimerFunc(0, atualizarNoite, 0);
      animacaoNoiteIniciada = true;
  }
  
  if (cenaAtual == 6 && !colisaoIniciada) {
    glutTimerFunc(0, animarColisaoComMuro, 0);
    colisaoIniciada = true;
  }

  if (cenaAtual == 5 && !zigzagIniciado) {
    glutTimerFunc(0, atualizarZigZag, 0);
    zigzagIniciado = true;
  }

    configurarLuzAmbiente(tempoTransicao);
    configurarLuzPoste(tempoTransicao);
    
    glutSwapBuffers();
}


void init() {
    glClearColor(0.0, 0.7, 1.0, 1.0); // Céu azul claro
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glDepthFunc(GL_LESS);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_COLOR_MATERIAL);      
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  quad = gluNewQuadric();

  GLfloat luz_ambiente[] = {0.3, 0.3, 0.3, 1.0};
  GLfloat luz_difusa[] = {0.8, 0.8, 0.8, 1.0};
  GLfloat luz_especular[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat posicao_luz[] = {0.0, -2.0, 10.0, 1.0};

  glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
  glLightfv(GL_LIGHT0, GL_SPECULAR, luz_especular);
  glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz);

  GLfloat mat_ambient[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat mat_diffuse[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat mat_brilho[] = {120.0};

  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_brilho);
}

int main(int argc, char **argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(1000, 1000);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Trabalho Síntese de Imagens");
  glutDisplayFunc(draw);
  
  
  glutTimerFunc(0, atualizarAnimacao, 0);
  glutTimerFunc(temposCena[0], trocarCena, 0);
  init();
  PlaySoundA("audio-cg.wav", NULL, SND_FILENAME | SND_ASYNC);
  glutMainLoop();
  return 0;
}
