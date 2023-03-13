#define GL_SILENCE_DEPRECATION
#include <stdlib.h> // standard definitions
#include <math.h> // math definitions
#include <stdio.h> // standard I/O
#include <stdlib.h> // standard definitions

// include files are in a slightly different location for MacOS
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// escape key (for exit)
#define ESC 27

// Current camera position
float x = 0.0, y = -5.0; // initially 5 units south of origin
float deltaMove = 0.0; // initially camera doesn't move

// they point in the direction the camera is looking.
float lx = 0.0, ly = 1.0; // camera points initially along y-axis
float angle = 0.0; // angle of rotation for the camera direction
float deltaAngle = 0.0; // additional angle change when dragging

// Mouse drag control
int isDragging = 0; // true when dragging
int xDragStart = 0; // records the x-coordinate when dragging starts

void changeSize(int w, int h)
{
    float ratio =  ((float) w) / ((float) h); // window aspect ratio
    glMatrixMode(GL_PROJECTION); // projection matrix is active
    glLoadIdentity(); // reset the projection
    gluPerspective(45.0, ratio, 0.1, 100.0); // perspective transformation
    glMatrixMode(GL_MODELVIEW); // return to modelview mode
    glViewport(0, 0, w, h); // set viewport (drawing area) to entire window
}

void update(void)
{
    if (deltaMove) { // update camera position
        x += deltaMove * lx * 0.1;
        y += deltaMove * ly * 0.1;
    }
    glutPostRedisplay(); // redisplay everything
}

void crtajZid()
{
     glPushMatrix();
     glScalef(7, 0.2, 7);
     glutSolidCube(1);
     glPopMatrix();
}

void crtajJastuk()
{
    glColor3ub(147,85,58); //braon
    glutSolidCube(0.4);
}

void crtajPrvuSliku() {

    glPushMatrix();

    glTranslatef(0, 4.5, -3.2);
    glScalef(1.2, 1, 0.2);

    //okvir slike
    glColor3f(0.0, 0.0, 0.0);  // crna
    glutSolidCube(1.2);

    //slika
    glTranslatef(0, 0, 0.4);
    glColor3f(0.5, 0.5, 0.5);  // siva
    glutSolidCube(1);


    glPopMatrix();
}

void crtajDruguSliku() {

    glPushMatrix();

    glTranslatef(0, 4.5, -3.2);
    glScalef(1.2, 1, 0.2);

    //slika
    glTranslatef(1.8, 0, 0);
    glColor3ub(202,135,93); //braon boja
    glutSolidCube(1.2);

    //okvir unutrasnji
    glTranslatef(0, 0, 0.2);
    glColor3f(0.0, 0.0, 0.0);  // crna
    glutSolidCube(1);

    //slika
    glTranslatef(0, 0, 0.2);
    glColor3ub(202,135,93); //braon boja

    glutSolidCube(0.8);


    glPopMatrix();
}

void crtajTrecuSliku() {

    glPushMatrix();

    glTranslatef(4, 4.5, -3.2);
    glScalef(1.2, 1, 0.2);

    //okvir slike
    glColor3f(0.0, 0.0, 0.0);  // crna
    glutSolidCube(1);

    //slika
    glTranslatef(0, 0, 0.4);
    glColor3f(0.5, 0.5, 0.5);  // siva
    glutSolidCube(0.5);


    glPopMatrix();
}

void crtajKomoduCelu()
{
    glColor3f(0.5, 0.5, 0.5);  // siva
    glutSolidCube(2);

    //donja fioka
    glPushMatrix();
    glTranslatef(-0.1, -0.4, 0);
    glColor3f(0.8, 0.8, 0.8);
    glScalef(1, 0.3, 0.9);
    glutSolidCube(2);
    glPopMatrix();

    //gornja fioka
    glPushMatrix();
    glTranslatef(-0.1, 0.4, 0);
    glColor3f(0.8, 0.8, 0.8);
    glScalef(1, 0.3, 0.9);
    glutSolidCube(2);
    glPopMatrix();

    //donji rukohvat
    glPushMatrix();
    glTranslatef(-0.6, -0.4, 0);
    glColor3f(0.2, 0.2, 0.2);
    glScalef(0.6, 0.1, 0.3);
    glutSolidCube(2);
    glPopMatrix();

    //gornji rukohvat
    glPushMatrix();
    glTranslatef(-0.6, 0.4, 0);
    glColor3f(0.2, 0.2, 0.2);
    glScalef(0.6, 0.1, 0.3);
    glutSolidCube(2);
    glPopMatrix();
}

void crtajProzorCeo(){

    //okvir prozora
    glColor3ub(119,81,66); //braon
    glutSolidCube(2);

    //prozorska stakla
    glPushMatrix();
    glColor3ub(232,213,214); // svetlo bez
    glScalef(1, 0.85, 0.35);

    //levo staklo prozora
    glTranslatef(-0.1, 0, -1.2);
    glutSolidCube(2);

    //desno staklo prozora
    glTranslatef(0, 0, 2.5);
    glutSolidCube(2);
    glPopMatrix();
}

//pozivanje funkcija za iscrtavanje elemenata u sobi
void crtajSobu(){

    //*************************************************************************
    //**********************************KREVET*********************************
    //*************************************************************************

    glPushMatrix();

    //podnozje kreveta
    glTranslatef(0, 0.5, 0);
    glScalef(2, 0.2, 5);

//    glColor3ub(36,90,83); // royal zelena boja

    glColor3ub(86,57,53); //braon
    glutSolidCube(1);

    //dusek beli
    glTranslatef(0, 0.5, 0);

    glColor3f(1.0, 1.0, 1.0);  // bela boja
    glutSolidCube(1);

    //jastuk levi
    glScalef(0.8, 0.7, 0.3); // podesavanje sirine i visine jastuka
    glTranslatef(0.2, 0.9, -0.3); // da bude iznad duseka
    glTranslatef(-0.5, 0, -0.5); //levo pozicioni jastuk
    crtajJastuk();

    //jastuk desni
    glTranslatef(0.5, 0, 0); //desno pozicionirani jastuk
    crtajJastuk();
    glPopMatrix();

    //uzglavlje
    glColor3ub(86,57,53); //braon
    glPushMatrix();
    glScalef(2, 2, 0.3);
    glTranslatef(-0.01, 0.5, -7.9);
    glutSolidCube(1);
    glPopMatrix();

    //nogica leva
    glColor3ub(86,57,53); //braon
    glPushMatrix();
    glScalef(0.1, 0.7, 0.3);
    glTranslatef(-10, 0.1, 8);
    glutSolidCube(1);
    glPopMatrix();

    //nogica desna
    glColor3ub(86,57,53); //braon
    glPushMatrix();
    glScalef(0.1, 0.7, 0.3);
    glTranslatef(10, 0.1, 7.7);
    glutSolidCube(1);
    glPopMatrix();

    //*************************************************************************
    //**********************************KOMODA*********************************
    //*************************************************************************

    glPushMatrix();
    glScalef(0.6, 0.8, 0.8);
    glTranslatef(8.5, 0.8, -1.2);
    crtajKomoduCelu(); //leva komoda

    glTranslatef(0, 0, 3.5);
    crtajKomoduCelu(); //desna komoda

    glColor3ub(202,135,93); //braon boja cajnika
    glTranslatef(-0.4, 1.3, 0.3);
    glRotatef(90, 0,1, 0);
    glutWireTeapot(0.4); //cajnik
    glPopMatrix();

    //*************************************************************************
    //**********************************PROZORI********************************
    //*************************************************************************

    //levi prozor
    glPushMatrix();
    glScalef(0.1, 1.1, 0.9);
    glTranslatef(58, 4, -1.4);
    crtajProzorCeo();

    //desni prozor
    glTranslatef(0, 0, 3.4);
    crtajProzorCeo();
    glPopMatrix();

    //*************************************************************************
    //**********************************SLIKE**********************************
    //*************************************************************************

    crtajPrvuSliku();
    crtajTrecuSliku();
    crtajDruguSliku();
}


    //*************************************************************************
    //**********************************TEKSTURE*******************************
    //*************************************************************************

GLuint texture1;
GLuint texture2;
GLuint texture3;
//Funkcija za iscrtavanje texture
GLuint LoadTexture(const char* filename, int width, int height){
       GLuint texture;
       unsigned char* data;
       FILE* file;
       file=fopen(filename, "rb");
       if(file==NULL)return 0;
       data=(unsigned char*)malloc(width * height * 3);
       fread(data,width * height * 3,1,file);
       fclose(file);
       glGenTextures(1,&texture);
       glBindTexture(GL_TEXTURE_2D,texture);
       glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
       glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
       glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);
       free(data);
       return texture;
}

void teksturaUzglavlja()
{
   glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,texture1);
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_POLYGON);

    glTexCoord2d(1.0, 0.0); glVertex3f(-1.3, 1.0, -2.21);
    glTexCoord2d(1.0, 1.0); glVertex3f(-1.3, 2.34, -2.21);
    glTexCoord2d(0.0, 1.0); glVertex3f(-3.3, 2.34, -2.21);
    glTexCoord2d(0.0, 0.0); glVertex3f(-3.3, 1.0, -2.21);

    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void lights()
{
     glEnable(GL_LIGHTING);
     glEnable(GL_NORMALIZE);
     glEnable(GL_COLOR_MATERIAL);
     glDisable(GL_LIGHT0);
     glEnable(GL_LIGHTING);

     GLfloat lmodel_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
     GLfloat light1_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat light1_specular[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat light_positionSunce[] = { -15.0, -15.0, 15.0, 0.0 };
     GLfloat light_position1[] = { -7, -8.7, 3.2, 0.0 };//-7, -8.7, 4.2
     GLfloat light_position2[] = { -7, 0.1, 3.2, 0.0 };//-7, 0.1, 4.2
     GLfloat light_position3[] = { 0.5, 8, 3.2, 0.0 };//0.5, 8, 4.2

    //menjana pozicija svetla i svetlo
     glLightfv(GL_LIGHT0,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT0,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT0,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT0,GL_POSITION,light_positionSunce);

     glLightfv(GL_LIGHT1,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT1,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT1,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT1,GL_POSITION,light_position1);

     glLightfv(GL_LIGHT2,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT2,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT2,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT2,GL_POSITION,light_position2);

     glLightfv(GL_LIGHT3,GL_AMBIENT,lmodel_ambient);
     glLightfv(GL_LIGHT3,GL_DIFFUSE,light1_diffuse);
     glLightfv(GL_LIGHT3,GL_SPECULAR,light1_specular);
     glLightfv(GL_LIGHT3,GL_POSITION,light_position3);

     GLfloat mat_amb_diff[] = { 0.7, 0.7, 0.7, 1.0 };
     GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
     GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
     GLfloat low_shininess[] = { 10.0 };

     glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
     glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, low_shininess);

     glMatrixMode(GL_MODELVIEW);
}

void lightoff(unsigned char key, int x, int y) {

    if (key == 'a') {
        glDisable(GL_LIGHT0);
    }
    if (key == 's') {
        glEnable(GL_LIGHT0);
    }

    if (key == 'o') {
        glDisable(GL_LIGHT1);
    }
    if (key == 'p') {
        glEnable(GL_LIGHT1);
    }

    if (key == 'n') {
        glDisable(GL_LIGHT2);
    }
    if (key == 'm') {
        glEnable(GL_LIGHT2);
    }

    glutPostRedisplay();
}


void renderScene(void)
{
    // Clear color and depth buffers
    glClearColor(0.0, 0.0, 0.0, 1.0); // sky color is light blue
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Set the camera centered at (x,y,1) and looking along directional
    // vector (lx, ly, 0), with the z-axis pointing up
    gluLookAt(
            x,      y,      1.0,
            x + lx, y + ly, 1.0,
            0.0,    0.0,    1.0);

    glPushMatrix();
    glTranslatef(0, 2, 1);
    glRotatef(90, 1, 0,0);

    glColor3ub(236,161,80); //braon pod
    glPushMatrix();
    glTranslatef(0, -3.5, -3);
    glRotatef(45, 0, 1, 0);
    crtajZid();
    teksturaUzglavlja();

    glPushMatrix();
    glTranslatef(-2.3, 0.3, 0);
    crtajSobu();
    glPopMatrix();

    glColor3f(0.7, 0.7, 0.7); //siva
    glTranslatef(0, 3.5, -3.5);
    glRotatef(90, 1, 0, 0);
    crtajZid();

    glColor3ub(255,202,109); //zuti zid
    glTranslatef(3.6, 3.5, 0.1);
    glRotatef(90, 0, 0, 1);
    crtajZid();

    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers(); // Make it all visible
}

//----------------------------------------------------------------------
// User-input callbacks
//
// processNormalKeys: ESC, q, and Q cause program to exit
// pressSpecialKey: Up arrow = forward motion, down arrow = backwards
// releaseSpecialKey: Set incremental motion to zero
//----------------------------------------------------------------------

void processNormalKeys(unsigned char key, int xx, int yy)
{
    if (key == ESC || key == 'q' || key == 'Q') exit(0);
}

void pressSpecialKey(int key, int xx, int yy)
{
    switch (key) {
        case GLUT_KEY_UP : deltaMove = 1.0; break;
        case GLUT_KEY_DOWN : deltaMove = -1.0; break;
    }
}

void releaseSpecialKey(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP : deltaMove = 0.0; break;
        case GLUT_KEY_DOWN : deltaMove = 0.0; break;
    }
}

void mouseMove(int x, int y)
{
    if (isDragging) { // only when dragging
        // update the change in angle
        deltaAngle = (x - xDragStart) * 0.005;

        // camera's direction is set to angle + deltaAngle
        lx = -sin(angle + deltaAngle);
        ly = cos(angle + deltaAngle);
    }
}

void mouseButton(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) { // left mouse button pressed
            isDragging = 1; // start dragging
            xDragStart = x; // save x where button first pressed
        }
        else  { /* (state = GLUT_UP) */
            angle += deltaAngle; // update camera turning angle
            isDragging = 0; // no longer dragging
        }
    }
}

//----------------------------------------------------------------------
// Main program  - standard GLUT initializations and callbacks
//----------------------------------------------------------------------
int main(int argc, char **argv)
{
    // general initializations
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 400);
    glutCreateWindow("OpenGL/GLUT Sampe Program");
    lights();

    // register callbacks
    glutReshapeFunc(changeSize); // window reshape callback
    glutDisplayFunc(renderScene); // (re)display callback
    glutIdleFunc(update); // incremental update
    glutIgnoreKeyRepeat(1); // ignore key repeat when holding key down
    glutMouseFunc(mouseButton); // process mouse button push/release
    glutMotionFunc(mouseMove); // process mouse dragging motion
    glutKeyboardFunc(processNormalKeys); // process standard key clicks
    glutSpecialFunc(pressSpecialKey); // process special key pressed
                        // Warning: Nonstandard function! Delete if desired.
    glutSpecialUpFunc(releaseSpecialKey); // process special key release
    glutKeyboardFunc(lightoff);


    texture1=LoadTexture("ovde upisati putanju do fajla teksture", 316, 316);

    glEnable(GL_DEPTH_TEST);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 0; // this is just to keep the compiler happy
}
