//  ========================================================================
//  Alex Bull (11213398)
//  COSC363 Assignment 1
//  ========================================================================

#include <iostream>
#include <GL/freeglut.h>
#include <cmath>
#include "loadTGA.h"
using namespace std;

#define GL_CLAMP_TO_EDGE 0x812F
float theta = 0.0;
float cdr=3.14159265/180.0;	//Conversion from degrees to radians
float eye_x=0.0, eye_z=0.0; 
float look_x=eye_x + 100*sin(cdr*theta);
float look_z=eye_z - 100*cos(cdr*theta);
int frame = 0;
int spinningTopRotation = 0;
int teapotRotation = 0;
int torusRotation = 0;
int manz = -200;
int manRotation = 0;
bool walking = false;
int leftLegRotation = 0;
int rightLegRotation = 0;
int rightArmRotation = 0;
bool leftLegForward = true;
int coiny = 0;
int coinRotation = 0;
int cameraMode = 0;
int catarmRotation = 0;
bool catarmForward = true;

GLuint texId[11];

void loadGLTextures()
{
	glGenTextures(11, texId);
    
	//left
	glBindTexture(GL_TEXTURE_2D, texId[0]);
	loadTGA("alps_rt.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	

	//front
	glBindTexture(GL_TEXTURE_2D, texId[1]);
	loadTGA("alps_ft.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	

	//right
	glBindTexture(GL_TEXTURE_2D, texId[2]);
	loadTGA("alps_lf.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	

	//back
	glBindTexture(GL_TEXTURE_2D, texId[3]);
	loadTGA("alps_bk.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	

	//top
	glBindTexture(GL_TEXTURE_2D, texId[4]);
	loadTGA("alps_up.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	

	//down
	glBindTexture(GL_TEXTURE_2D, texId[5]);
	loadTGA("grass.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    //interior mat
	glBindTexture(GL_TEXTURE_2D, texId[6]);
	loadTGA("tatami.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    //roof
	glBindTexture(GL_TEXTURE_2D, texId[7]);
	loadTGA("roof.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    //slats
	glBindTexture(GL_TEXTURE_2D, texId[8]);
	loadTGA("slats.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    //cat
    glBindTexture(GL_TEXTURE_2D, texId[9]);
	loadTGA("cat.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    
    //cat arm
    glBindTexture(GL_TEXTURE_2D, texId[10]);
	loadTGA("cat_arm.tga");
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);	
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
}

void skybox(){
    glEnable(GL_TEXTURE_2D);

    //Skybox left
    glBindTexture(GL_TEXTURE_2D, texId[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0., 0.);
    glVertex3f(-10000,  0, 10000);
    glTexCoord2f(1., 0.);
    glVertex3f(-10000, 0., -10000);
    glTexCoord2f(1., 1.);
    glVertex3f(-10000, 10000., -10000);
    glTexCoord2f(0., 1.);
    glVertex3f(-10000, 10000, 10000);
    glEnd();

    //Skybox front
    glBindTexture(GL_TEXTURE_2D, texId[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0., 0.);
    glVertex3f(-10000,  0, -10000);
    glTexCoord2f(1., 0.);
    glVertex3f(10000, 0., -10000);
    glTexCoord2f(1., 1.);
    glVertex3f(10000, 10000, -10000);
    glTexCoord2f(0., 1.);
    glVertex3f(-10000,  10000, -10000);
    glEnd();

    //Skybox right
    glBindTexture(GL_TEXTURE_2D, texId[2]);
    glBegin(GL_QUADS);
    glTexCoord2f(0., 0.);
    glVertex3f(10000,  0, -10000);
    glTexCoord2f(1., 0.);
    glVertex3f(10000, 0, 10000);
    glTexCoord2f(1., 1.);
    glVertex3f(10000, 10000,  10000);
    glTexCoord2f(0., 1.);
    glVertex3f(10000,  10000,  -10000);
    glEnd();


    //Skybox back
    glBindTexture(GL_TEXTURE_2D, texId[3]);
    glBegin(GL_QUADS);
    glTexCoord2f(0., 0.);
    glVertex3f( 10000, 0, 10000);
    glTexCoord2f(1., 0.);
    glVertex3f(-10000, 0,  10000);
    glTexCoord2f(1., 1.);
    glVertex3f(-10000, 10000,  10000);
    glTexCoord2f(0., 1.);
    glVertex3f( 10000, 10000, 10000);
    glEnd();

    //Skybox up
    glBindTexture(GL_TEXTURE_2D, texId[4]);
    glBegin(GL_QUADS);
    glTexCoord2f(0., 0.);
    glVertex3f(-10000, 10000, -10000);
    glTexCoord2f(1., 0.);
    glVertex3f(10000, 10000,  -10000);
    glTexCoord2f(1., 1.);
    glVertex3f(10000, 10000,  10000);
    glTexCoord2f(0., 1.);
    glVertex3f(-10000, 10000, 10000);
    glEnd();

    //Skybox grass
    glBindTexture(GL_TEXTURE_2D, texId[5]);
    glBegin(GL_QUADS);
    glTexCoord2f(0., 0.);
    glVertex3f(-10000, 0., 10000);
    glTexCoord2f(100., 0.);
    glVertex3f(10000, 0.,  10000);
    glTexCoord2f(100., 100.);
    glVertex3f(10000, 0., -10000);
    glTexCoord2f(0., 100.);
    glVertex3f(-10000, 0., -10000);
    glEnd();
  
    glDisable(GL_TEXTURE_2D);
}

void normal(float x1, float y1, float z1, 
            float x2, float y2, float z2,
		      float x3, float y3, float z3 )
{
	  float nx, ny, nz;
	  nx = y1*(z2-z3)+ y2*(z3-z1)+ y3*(z1-z2);
	  ny = z1*(x2-x3)+ z2*(x3-x1)+ z3*(x1-x2);
	  nz = x1*(y2-y3)+ x2*(y3-y1)+ x3*(y1-y2);

      glNormal3f(-nx, -ny, -nz);
}

void createSpinningTop(){
    
    float wx[50], wy[50], wz[50]; 
	float angStep = 10.0*3.1415926/180.0; 
    
//    float vx[50] = {0, 8, 8, 7.5, 6.7, 5, 5.5, 4, 4, 5, 5.6, 6.1, 6.8, 7.1, 7.5, 8, 8.4, 8.7, 9, 9.3, 
//                  9.8, 10, 10.2, 10.4, 10.6, 10.9, 11, 11.1, 11.2, 11.3, 11.4, 11.3, 11.2, 11.1, 11, 10.9, 10.8, 10.7, 10.6, 10.5,
//                  10.4, 10.3, 10.2, 10.1, 10, 9.9, 9.8, 9.7, 9.6, 9.5};
//    float vy[50] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
//                   19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
//                   39, 40, 41, 42, 43, 43, 42, 41, 40, 39};
//    float vz[50] = {0};

    float vx[50] = {0, 1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10, 10, 11, 12, 13, 14, 15, 15, 16, 17, 18, 
                  19, 20, 18, 16, 14, 12, 10, 8, 6, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                  2, 2, 2, 2, 2, 2, 2, 2};
    float vy[50] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
                   19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
                   39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49};
    float vz[50] = {0};
    
    for(int j=0; j< 36; j++)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for(int i=0; i<50; i++)
        {
            wx[i] = vx[i]*cos(angStep)+vz[i]*sin(angStep);
            wy[i] = vy[i];
            wz[i] = -vx[i]*sin(angStep)+vz[i]*cos(angStep);
            
            
            if(i>0) normal(wx[i-1], wy[i-1], wz[i-1], vx[i-1], vy[i-1], vz[i-1], vx[i], vy[i], vz[i]);
            glVertex3f(vx[i], vy[i], vz[i]);
            
            if(i>0) normal(wx[i-1], wy[i-1], wz[i-1], vx[i], vy[i], vz[i], wx[i], wy[i], wz[i]);
            glVertex3f(wx[i], wy[i], wz[i]);
        }
        glEnd();
        for(int i=0; i<50; i++)
        {
            vx[i] = wx[i];
            vy[i] = wy[i];
            vz[i] = wz[i];
        }
    }
    
}

void spinningTop(){
    
    glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	  glTranslatef(-350, 10, -1100);
      glScalef(2, 2, 2);
      glRotatef(spinningTopRotation, 0, 1, 0);
      createSpinningTop();
	glPopMatrix();
    
    
    spinningTopRotation+=3;

}

void pyramid(){
    
    glEnable(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, texId[7]);
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0., 0.);
    glVertex3f(0.0, 10.0, 0.0);
    glTexCoord2f(2., 0.);
    glVertex3f(-5.0, 0.0, 5.0);
    glTexCoord2f(2., 2.);
    glVertex3f(5.0, 0.0, 5.0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texId[7]);
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0., 0.);
    glVertex3f(0.0, 10.0, 0.0);
    glTexCoord2f(2., 0.);
    glVertex3f(5.0, 0.0, 5.0);
    glTexCoord2f(2., 2.);
    glVertex3f(5.0, 0.0, -5.0);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, texId[7]);
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0., 0.);
    glVertex3f(0.0, 10.0, 0.0);
    glTexCoord2f(2., 0.);
    glVertex3f(5.0, 0.0, -5.0);
    glTexCoord2f(2., 2.);
    glVertex3f(-5.0, 0.0, -5.0);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, texId[7]);
    glBegin(GL_TRIANGLES);
    glTexCoord2f(0., 0.);
    glVertex3f(0.0, 10.0, 0.0);
    glTexCoord2f(2., 0.);
    glVertex3f(-5.0, 0.0, -5.0);
    glTexCoord2f(2., 2.);
    glVertex3f(-5.0, 0.0, 5.0);
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
}

void temple(){
    
    glColor3f(0.2, 0.06, 0); //Foundation
	glPushMatrix();
	  glTranslatef(0, 5, -1000);
      glScalef(100, 1, 80);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Step
	glPushMatrix();
	  glTranslatef(0, 5, -595);
      glScalef(20, 1, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Left wall
	glPushMatrix();
	  glTranslatef(-400, 210, -1100);
      glScalef(1, 40, 60);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Right wall
	glPushMatrix();
	  glTranslatef(400, 210, -1100);
      glScalef(1, 40, 60);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Back wall
	glPushMatrix();
	  glTranslatef(0, 210, -1395);
      glScalef(80, 40, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Front-left wall
	glPushMatrix();
	  glTranslatef(-250, 210, -800);
      glScalef(30, 40, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Front-right wall
	glPushMatrix();
	  glTranslatef(255, 210, -800);
      glScalef(30, 40, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    
    glColor3f(0.3, 0.0, 0.0); //Left support 1
	glPushMatrix();
	  glTranslatef(-150, 210, -650);
      glScalef(2, 40, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Right support 1
	glPushMatrix();
	  glTranslatef(150, 210, -650);
      glScalef(2, 40, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Left support 2
	glPushMatrix();
	  glTranslatef(-350, 210, -650);
      glScalef(2, 40, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Right support 2
	glPushMatrix();
	  glTranslatef(350, 210, -650);
      glScalef(2, 40, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Left support 3
	glPushMatrix();
	  glTranslatef(-450, 210, -650);
      glScalef(2, 40, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Right support 3
	glPushMatrix();
	  glTranslatef(450, 210, -650);
      glScalef(2, 40, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Support crossbeam
	glPushMatrix();
	  glTranslatef(0, 330, -650);
      glScalef(90, 2, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.8, 1, 0.6); //Tatami floor
	glPushMatrix();
        glTranslatef(0, 11, -1100);
        glScalef(80, 0.1, 60);
        
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texId[6]);
        glBegin(GL_QUADS);
        glTexCoord2f(0., 0.);
        glVertex3f(-5, 0., 5);
        glTexCoord2f(5., 0.);
        glVertex3f(5, 0.,  5);
        glTexCoord2f(5., 10.);
        glVertex3f(5, 0., -5);
        glTexCoord2f(0., 10.);
        glVertex3f(-5, 0., -5);
        glEnd();
        glDisable(GL_TEXTURE_2D);
	glPopMatrix();

    glColor3f(0.15, 0.15, 0.15); //Lower roof
	glPushMatrix();
	  glTranslatef(0, 400, -1000);
      glScalef(100, 40, 80);
	  pyramid();
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Ceiling/lower roof trim
	glPushMatrix();
	  glTranslatef(0, 400, -1000);
      glScalef(100, 1, 80);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.8, 1, 0.6); //Roof connector
	glPushMatrix();
	  glTranslatef(0, 600, -1000);
      glScalef(60, 10, 50);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.3, 0.0, 0.0); //Upper roof trim
	glPushMatrix();
	  glTranslatef(0, 600, -1000);
      glScalef(80, 1, 70);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.15, 0.15, 0.15); //Upper roof
	glPushMatrix();
	  glTranslatef(0, 600, -1000);
      glScalef(80, 40, 70);
	  pyramid();
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence L1
	glPushMatrix();
	  glTranslatef(-105, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence R1
	glPushMatrix();
	  glTranslatef(105, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence L2
	glPushMatrix();
	  glTranslatef(-175, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence R2
	glPushMatrix();
	  glTranslatef(175, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence L3
	glPushMatrix();
	  glTranslatef(-245, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence R3
	glPushMatrix();
	  glTranslatef(245, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence L4
	glPushMatrix();
	  glTranslatef(-315, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence R4
	glPushMatrix();
	  glTranslatef(315, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence L5
	glPushMatrix();
	  glTranslatef(-385, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence R5
	glPushMatrix();
	  glTranslatef(385, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence L6
	glPushMatrix();
	  glTranslatef(-455, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence R6
	glPushMatrix();
	  glTranslatef(455, 45, -605);
      glScalef(1, 7, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence LUpper
	glPushMatrix();
	  glTranslatef(-300, 65, -605);
      glScalef(40, 1, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence LLower
	glPushMatrix();
	  glTranslatef(-300, 45, -605);
      glScalef(40, 1, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence RUpper
	glPushMatrix();
	  glTranslatef(300, 65, -605);
      glScalef(40, 1, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.55, 0.28, 0.2); //Fence RLower
	glPushMatrix();
	  glTranslatef(300, 45, -605);
      glScalef(40, 1, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    
    float shadowMat[16] = {1000,0,0,0, 1000,5,-1000, -1,0,0,1000,0, 0,0,0,1000}; //6th element changed to 5 to avoid gltiching effect
    
    glDisable(GL_LIGHTING); //Arch Foundation Left PLANAR SHADOW
    glPushMatrix();
        glMultMatrixf(shadowMat);
        glColor4f(0.2, 0.2, 0.2, 1.0);
        glTranslatef(-105, 35, -305);
        glScalef(2, 7, 2);
        glutSolidCube(10);
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
    glColor3f(0.15, 0.15, 0.15); //Arch Foundation Left
	glPushMatrix();
	  glTranslatef(-105, 35, -305);
      glScalef(2, 7, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glDisable(GL_LIGHTING); //Arch Foundation Right PLANAR SHADOW
    glPushMatrix();
        glMultMatrixf(shadowMat);
        glColor4f(0.2, 0.2, 0.2, 1.0);
	  glTranslatef(105, 35, -305);
      glScalef(2, 7, 2);
	  glutSolidCube(10);
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
    glColor3f(0.15, 0.15, 0.15); //Arch Foundation Right
	glPushMatrix();
	  glTranslatef(105, 35, -305);
      glScalef(2, 7, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glDisable(GL_LIGHTING); //Arch Left PLANAR SHADOW
    glPushMatrix();
        glMultMatrixf(shadowMat);
        glColor4f(0.2, 0.2, 0.2, 1.0);
	  glTranslatef(-105, 170, -305);
      glScalef(2, 20, 2);
	  glutSolidCube(10);
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
    glColor3f(0.6, 0.1, 0.1); //Arch Left
	glPushMatrix();
	  glTranslatef(-105, 170, -305);
      glScalef(2, 20, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glDisable(GL_LIGHTING); //Arch Right PLANAR SHADOW
    glPushMatrix();
        glMultMatrixf(shadowMat);
        glColor4f(0.2, 0.2, 0.2, 1.0);
	  glTranslatef(105, 170, -305);
      glScalef(2, 20, 2);
	  glutSolidCube(10);
    glPopMatrix();
    
    glEnable(GL_LIGHTING);
    glColor3f(0.6, 0.1, 0.1); //Arch Right
	glPushMatrix();
	  glTranslatef(105, 170, -305);
      glScalef(2, 20, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.6, 0.1, 0.1); //Arch Upper
	glPushMatrix();
	  glTranslatef(0, 280, -305);
      glScalef(30, 2, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.6, 0.1, 0.1); //Arch Lower
	glPushMatrix();
	  glTranslatef(0, 240, -305);
      glScalef(30, 2, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.6, 0.1, 0.1); //Arch Center
	glPushMatrix();
	  glTranslatef(0, 260, -305);
      glScalef(2, 2, 2);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 1
	glPushMatrix();
	  glTranslatef(-30, 1, -560);
      glScalef(8, 0.1, 4);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 2
	glPushMatrix();
	  glTranslatef(30, 1, -530);
      glScalef(8, 0.1, 4);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 3
	glPushMatrix();
	  glTranslatef(-30, 1, -500);
      glScalef(8, 0.1, 4);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 4
	glPushMatrix();
	  glTranslatef(30, 1, -470);
      glScalef(8, 0.1, 4);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 5
	glPushMatrix();
	  glTranslatef(-30, 1, -440);
      glScalef(6, 0.1, 3);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 6
	glPushMatrix();
	  glTranslatef(30, 1, -420);
      glScalef(6, 0.1, 3);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 7
	glPushMatrix();
	  glTranslatef(-20, 1, -400);
      glScalef(5, 0.1, 2);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 8
	glPushMatrix();
	  glTranslatef(20, 1, -380);
      glScalef(5, 0.1, 2);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 9
	glPushMatrix();
	  glTranslatef(-20, 1, -360);
      glScalef(5, 0.1, 2);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 10
	glPushMatrix();
	  glTranslatef(20, 1, -340);
      glScalef(5, 0.1, 2);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 11
	glPushMatrix();
	  glTranslatef(-10, 1, -320);
      glScalef(4, 0.1, 2);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
    
    glColor3f(0.6, 0.6, 0.6); //Path 12
	glPushMatrix();
	  glTranslatef(20, 1, -310);
      glScalef(2, 0.1, 1);
	  glutSolidSphere(5, 10, 10);
	glPopMatrix();
}


void glutObjectDisplay(){
    
    glColor3f(0.8, 0.8, 0.8); //Display box subdivision 1
	glPushMatrix();
	  glTranslatef(330, 45, -965);
      glScalef(1, 9, 1);
	  glutSolidCube(10);
	glPopMatrix();
    glColor3f(0.8, 0.8, 0.8); //Display box subdivision 2
	glPushMatrix();
	  glTranslatef(340, 45, -965);
      glScalef(1, 9, 1);
	  glutSolidCube(10);
	glPopMatrix();
    glColor3f(0.8, 0.8, 0.8); //Display box subdivision 3
	glPushMatrix();
	  glTranslatef(320, 45, -965);
      glScalef(1, 9, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.8, 0.8, 0.8); //Display box subdivision 4
	glPushMatrix();
	  glTranslatef(330, 45, -955);
      glScalef(1, 9, 1);
	  glutSolidCube(10);
	glPopMatrix();
        glColor3f(0.8, 0.8, 0.8); //Display box subdivision 5
	glPushMatrix();
	  glTranslatef(340, 45, -955);
      glScalef(1, 9, 1);
	  glutSolidCube(10);
	glPopMatrix();
    glColor3f(0.8, 0.8, 0.8); //Display box subdivision 6
	glPushMatrix();
	  glTranslatef(320, 45, -955);
      glScalef(1, 9, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.8, 0.8, 0.8); //Display box subdivision 7
	glPushMatrix();
	  glTranslatef(330, 45, -945);
      glScalef(1, 9, 1);
	  glutSolidCube(10);
	glPopMatrix();
        glColor3f(0.8, 0.8, 0.8); //Display box subdivision 8
	glPushMatrix();
	  glTranslatef(340, 45, -945);
      glScalef(1, 9, 1);
	  glutSolidCube(10);
	glPopMatrix();
    glColor3f(0.8, 0.8, 0.8); //Display box subdivision 9
	glPushMatrix();
	  glTranslatef(320, 45, -945);
      glScalef(1, 9, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    glColor3f(0.5, 0.5, 1); //Teapot
	glPushMatrix();
	  glTranslatef(325, 110, -955);
      glScalef(1, 1, 1);
      glRotatef(teapotRotation, 0, 1, 0);
	  glutSolidTeapot(5);
	glPopMatrix();
    
    glColor3f(1, 1, 0.3); //Torus
	glPushMatrix();
	  glTranslatef(325, 110, -955);
      glScalef(1, 1, 1);
      glRotatef(torusRotation, 0, 1, 0);
	  glutSolidTorus(2, 15, 30, 30);
	glPopMatrix();
    
    teapotRotation-=3;
    torusRotation+=3;
}

void createMan()
{
    if(walking){
        if(leftLegForward){
            leftLegRotation+=1;
            rightLegRotation-=1;
        } else {
            leftLegRotation-=1;
            rightLegRotation+=1;
        }
        
        if(leftLegRotation > 10){
            leftLegForward = false;
        }
        if(leftLegRotation < -10){
            leftLegForward = true;
        }
        
        
        glColor3f(0.15, 0.15, 0.15); //Left leg
        glPushMatrix();
        glTranslatef(-6, 50, 0);
          glRotatef(leftLegRotation, 1, 0, 0);
          glTranslatef(0, -25, 0);
          glScalef(1, 5, 1);
          glutSolidCube(10);
        glPopMatrix();

        glColor3f(0.15, 0.15, 0.15); //Right leg
        glPushMatrix();
          glTranslatef(6, 50, 0);
          glRotatef(rightLegRotation, 1, 0, 0);
          glTranslatef(0, -25, 0);
          glScalef(1, 5, 1);
          glutSolidCube(10);
        glPopMatrix();
        
    } else {
        leftLegForward = true;
        leftLegRotation = 0;
        glColor3f(0.15, 0.15, 0.15); //Left leg
        glPushMatrix();
          glTranslatef(-6, 25, 0);
          glScalef(1, 5, 1);
          glutSolidCube(10);
        glPopMatrix();

        glColor3f(0.15, 0.15, 0.15); //Right leg
        glPushMatrix();
          glTranslatef(6, 25, 0);
          glScalef(1, 5, 1);
          glutSolidCube(10);
        glPopMatrix();
    }
    
    if(cameraMode != 1){
        glColor3f(1.0, 0.85, 0.74);	//Head
        glPushMatrix();
          glTranslatef(0, 100, 0);
          glScalef(1, 2, 1);
          glutSolidCube(10);
        glPopMatrix();
    }

	glColor3f(0.3, 0.0, 0.0); //Torso
	glPushMatrix();
	  glTranslatef(0, 70, 0);
	  glScalef(2, 4, 1);
	  glutSolidCube(10);
	glPopMatrix();

	glColor3f(1.0, 0.85, 0.74);	//Left arm
	glPushMatrix();
	  glTranslatef(-15, 70, 0);
	  glScalef(1, 4, 1);
	  glutSolidCube(10);
	glPopMatrix();
    
    
    
    if(frame > 500 and frame < 560 and rightArmRotation < 90){
        rightArmRotation+=3;
    }
    
    if(frame > 620 and frame < 680 and rightArmRotation > 0){
        rightArmRotation-=3;
    }
    
    
    glColor3f(1.0, 0.85, 0.74); //Right arm
    glPushMatrix();
      glTranslatef(15, 90, 0);
      glRotatef(rightArmRotation, 1, 0, 0);
      glTranslatef(0, -20, 0);
      glScalef(1, 4, 1);
      glutSolidCube(10);
    glPopMatrix();

}

void man(){

	glPushMatrix();
	  glTranslatef(0, 0, manz);
      glRotatef(manRotation, 0, 1, 0);
	  createMan();
	glPopMatrix();
    
    if(frame == 1){
        walking = true;
    }
    if (frame < 560 and manz>-1300) {
        manz-=2;
    }
    if(frame == 560 or (frame < 560 and manz==-1300)){
        walking = false;
    }
    if(frame > 680 and frame < 770 and manRotation < 180){
        manRotation+=5;
    }
    if(frame == 770){
        walking = true;
    }
    if(frame > 770 and manz < -200){
        manz+=2;
    }
    if(frame > 770 and manz == -200){
        walking = false;
    }
    if(frame > 1500 and manRotation > 0){
        manRotation -= 5;
    }
    
}

void shrinebox(){
    
    glPushMatrix(); //Slats
        glTranslatef(-35, 41, -1375);
    
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texId[8]);
        glBegin(GL_QUADS);
        glTexCoord2f(0., 0.);
        glVertex3f(0.0, 0.0, 0.0);
        glTexCoord2f(1., 0.);
        glVertex3f(70.0, 0.0, 0.0);
        glTexCoord2f(1., 1.);
        glVertex3f(70.0, 0.0, 50.0);
        glTexCoord2f(0., 1.);
        glVertex3f(0.0, 0.0, 50.0);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    glColor3f(0.25, 0.05, 0.0); //Base
	glPushMatrix();
	  glTranslatef(0, 20, -1350);
	  glScalef(7, 4, 5);
	  glutSolidCube(10);
	glPopMatrix();
    
    
}

void coin(){
    
    if(frame == 560){
        coiny = 85;
        coinRotation = 90;
    }
    
    if(frame > 560 and frame < 620){
        coiny-=5;
        coinRotation+=20;
        
        GLUquadric *q ;
        glColor3f(1, 1, 0); //Base
        glPushMatrix();
          glTranslatef(0, coiny, -1350);
          glRotatef(coinRotation, 1, 0, 0);
          q = gluNewQuadric();
          gluDisk(q, 0, 6, 20, 20);
          gluQuadricDrawStyle(q, GLU_FILL);
        glPopMatrix();
    }
    
}

void catarm(){
    
    if(catarmForward){
        catarmRotation+=1;
    } else {
        catarmRotation-=1;
    }
    
    if(catarmRotation > 20){
        catarmForward = false;
    }
    
    if(catarmRotation < -20){
        catarmForward = true;
    }
    
    
    glPushMatrix();
    
    glTranslatef(230, 70, -1350);
    
    glRotatef(catarmRotation, 1, 0, 0);
    glScalef(20, 100, 10);
    
    
    //Right
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1, 0, 1);
    glVertex3f(-1, 0., -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glEnd();

    //Back
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1,  0, -1);
    glVertex3f(1, 0., -1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1,  1, -1);
    glEnd();

    //Left
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(1,  0, -1);
    glVertex3f(1, 0, 1);
    glVertex3f(1, 1,  1);
    glVertex3f(1,  1,  -1);
    glEnd();

    //Front
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texId[10]);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0.);
    glVertex3f(1, 0, 1);
    glTexCoord2f(0, 1);
    glVertex3f(1, 1,  1);
    glTexCoord2f(0.3, 1);
    glVertex3f(-1, 1,  1);
    glTexCoord2f(0.3, 0);
    glVertex3f( -1, 0, 1);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    //Up
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1,  -1);
    glVertex3f(1, 1,  1);
    glVertex3f(-1, 1, 1);
    glEnd();

    //Bottom;
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1, 0., 1);
    glVertex3f(1, 0.,  1);
    glVertex3f(1, 0., -1);
    glVertex3f(-1, 0., -1);
    glEnd();
    
    glPopMatrix();
    
}


void luckycat(){
    
    
    glPushMatrix();
    
    glTranslatef(300, 0, -1350);
    glScalef(50, 200, 10);
    
    //Right
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1, 0, 1);
    glVertex3f(-1, 0., -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glEnd();

    //Back
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1,  0, -1);
    glVertex3f(1, 0., -1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1,  1, -1);
    glEnd();

    //Left
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(1,  0, -1);
    glVertex3f(1, 0, 1);
    glVertex3f(1, 1,  1);
    glVertex3f(1,  1,  -1);
    glEnd();

    //Front
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texId[9]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.5, 0.);
    glVertex3f(1, 0, 1);
    glTexCoord2f(0.5, 1);
    glVertex3f(1, 1,  1);
    glTexCoord2f(1, 1);
    glVertex3f(-1, 1,  1);
    glTexCoord2f(1, 0);
    glVertex3f( -1, 0, 1);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    //Up
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1,  -1);
    glVertex3f(1, 1,  1);
    glVertex3f(-1, 1, 1);
    glEnd();

    //Bottom;
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
    glVertex3f(-1, 0., 1);
    glVertex3f(1, 0.,  1);
    glVertex3f(1, 0., -1);
    glVertex3f(-1, 0., -1);
    glEnd();
    
    glPopMatrix();
    
    catarm();
}

void initialise(void) 
{    
    float grey[4] = {0.2, 0.2, 0.2, 1.0};
    float white[4]  = {1.0, 1.0, 1.0, 1.0};
    
    loadGLTextures();
    
    glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, grey);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);
    
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialf(GL_FRONT, GL_SHININESS, 100);
    
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE);
	glClearColor (0.0, 0.0, 0.0, 0.0);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(90.0, 1.0, 0.5, 20000.0);

}

void display(void)
{
    float outsidelightpos[4] = {-1000.0, 1000.0, 1000.0, 1.0};
    float spotlightpos[4] = {325, 400, -955, 1.0};
    float spotlightdir[3] = {0, -1, 0};

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    gluLookAt (eye_x, 100, eye_z, look_x, 100, look_z, 0, 1, 0);
    
    glLightfv(GL_LIGHT0, GL_POSITION, outsidelightpos);
    glLightfv(GL_LIGHT1, GL_POSITION, spotlightpos);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 1.0);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 100.0);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotlightdir);
    
    if(cameraMode == 1){
        look_x = -100*sin(cdr*manRotation);
        look_z = eye_z - 100*cos(cdr*manRotation);
        
        eye_x = 0;
        eye_z = manz;
    }
    
	skybox();
    
    temple();
    
    spinningTop();
    
    glutObjectDisplay();
    
    man();
    
    shrinebox();
    
    coin();
    
    luckycat();

	glutSwapBuffers();
}

void special(int key, int x, int y)
 {
    
    if(key==GLUT_KEY_F1){
        if(cameraMode == 0){
            cameraMode = 1;
        } else if (cameraMode == 1) {
            cameraMode = 0;
        }
    }
    
    if (cameraMode == 0){ 
        if(key==GLUT_KEY_LEFT) theta-=5;		 //Turn left
        else if(key==GLUT_KEY_RIGHT) theta+=5;   //Turn right
        else if(key == GLUT_KEY_DOWN)
        {  //Move backward
            eye_x -= 5*sin(cdr*theta);
            eye_z += 5*cos(cdr*theta);
        }
        else if(key == GLUT_KEY_UP)
        { //Move forward
            eye_x += 5*sin(cdr*theta);
            eye_z -= 5*cos(cdr*theta);
        }
        
        look_x = eye_x + 100*sin(cdr*theta);
        look_z = eye_z - 100*cos(cdr*theta);
    }

	glutPostRedisplay();
}

void myTimer(int value)
{

    if (frame > 1700){
        frame = 0;
        manz = -200;
        leftLegForward = true;
        leftLegRotation = 0;
        manRotation = 0;
        rightArmRotation = 0;
        rightLegRotation = 0;
    }
    frame++;
    glutPostRedisplay();
    glutTimerFunc(1000/30, myTimer, frame);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize (1024, 800); 
    glutInitWindowPosition (50, 50);

    glutCreateWindow ("Alex Bull's Assignment");
    initialise();
    glutDisplayFunc(display); 
    glutSpecialFunc(special);
    
    glutTimerFunc(0, myTimer, 0);
    glutMainLoop();
    return 0;
}

