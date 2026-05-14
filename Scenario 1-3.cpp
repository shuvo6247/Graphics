#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <cstdlib>

using namespace std;

const int totalDrops =1000;
float busPosition = -100.0;
float speed =0.8;
float busPosition2=-200;
float sunPosX = 400.0f;
float sunPosY = 400.0f;
float speedY = 0.8f;
float cloudposition = -500;
float cloudpositiony = -50;
float cloudSpeed =1.2;
static float angle =0.0f;
float dropX[totalDrops], dropY[totalDrops];

// ---- Scenario 1 Bird Flock System ----
// 3 flocks: Flock A = 5 birds, Flock B = 3 birds, Flock C = 2 birds
// Each flock flies together with gap between them

// Flock A: 5 birds
float sc1_AX[5]  = { -300, -330, -310, -355, -340 };
float sc1_AY[5]  = {  680,  695,  668,  685,  702  };
float sc1_ASpd   = 1.55f;
float sc1_AWing[5] = {0, 0.8f, 1.6f, 2.4f, 3.2f};
bool  sc1_AWait  = false;
int   sc1_ATimer = 0;
const int SC1_A_PAUSE = 180;

// Flock B: 3 birds
float sc1_BX[3]  = { -600, -630, -615 };
float sc1_BY[3]  = {  675,  690,  660  };
float sc1_BSpd   = 1.50f;
float sc1_BWing[3]= {0, 1.2f, 2.4f};
bool  sc1_BWait  = false;
int   sc1_BTimer = 0;
const int SC1_B_PAUSE = 160;

// Flock C: 2 birds
float sc1_CX[2]  = { -650, -675 };
float sc1_CY[2]  = {  688,  670  };
float sc1_CSpd   = 1.45f;
float sc1_CWing[2]= {0, 1.8f};
bool  sc1_CWait  = false;
int   sc1_CTimer = 0;
const int SC1_C_PAUSE = 200;

void myInit ()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 700, 0, 800, -10.0, 10.0);
}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)///radius_x,radius_y,centre_position_x,centre_position_y///
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0; i<=360; i++)
    {
        float angle = 3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();


}
///ob29
void background1(){
///background and sky main color

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0,100);
    glVertex2f(800,100);
    glColor3ub(102, 204, 255);
    glVertex2f(800,800);
    glVertex2f(0,800);
    glEnd();
                             ///2nd building front area geeen
    glBegin(GL_QUADS);
    glColor3ub(90,147,48);
    glVertex2f(0,100);
    glVertex2f(800,100);
    glVertex2f(800,119.5);
    glVertex2f(0,119.5);
    glEnd();
                                      ///road color gray

    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex2f(0,30);
    glVertex2f(800,30);
    glVertex2f(800,80);
    glVertex2f(0,80);
    glEnd();



                              ///1st building front area geeen
    glBegin(GL_QUADS);
    glColor3ub(90, 147, 48);
    glVertex2f(0,82);
    glVertex2f(800,82);
    glVertex2f(800,90);
    glVertex2f(0,90);
    glEnd();
                         ///last small tree area geeen
    glBegin(GL_QUADS);
    glColor3ub(90, 147, 48);
    glVertex2f(0,38);
    glVertex2f(800,38);
    glVertex2f(800,0);
    glVertex2f(0,0);
    glEnd();
    }
void background(){
     ///background and sky main color

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 147);
    glVertex2f(0,100);
    glVertex2f(800,100);
    glColor3ub(102, 204, 255);
    glVertex2f(800,800);
    glVertex2f(0,800);
    glEnd();
                             ///2nd building front area geeen
    glBegin(GL_QUADS);
    glColor3ub(90,147,48);
    glVertex2f(0,100);
    glVertex2f(800,100);
    glVertex2f(800,119.5);
    glVertex2f(0,119.5);
    glEnd();
                                      ///road color gray

    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.2);
    glVertex2f(0,30);
    glVertex2f(800,30);
    glVertex2f(800,80);
    glVertex2f(0,80);
    glEnd();



                              ///1st building front area geeen
    glBegin(GL_QUADS);
    glColor3ub(90, 147, 48);
    glVertex2f(0,82);
    glVertex2f(800,82);
    glVertex2f(800,90);
    glVertex2f(0,90);
    glEnd();
                         ///last small tree area geeen
    glBegin(GL_QUADS);
    glColor3ub(90, 147, 48);
    glVertex2f(0,38);
    glVertex2f(800,38);
    glVertex2f(800,0);
    glVertex2f(0,0);
    glEnd();
}
//ob2
void road(){
      glBegin(GL_LINES);//Road top bar
    glLineWidth(2);
	glColor3f(1.0,1.0,1.0);
    glVertex2f(0,81);
    glVertex2f(800,81);
    glEnd();

    glBegin(GL_LINES);//Road middle bar
    glLineWidth(2);
	glColor3f(1.0,1.0,1.0);
    glVertex2f(0,62);
    glVertex2f(800,62);
    glEnd();

    glBegin(GL_LINES);//Road Bottop bar
    glLineWidth(2);
	glColor3f(1.0,1.0,1.0);
    glVertex2f(0,39);
    glVertex2f(800,39);
    glEnd();}
///ob3
void tree1(){ glBegin(GL_QUADS);  ///Bottom tree1 form right  ///
    glColor3ub(75,35,5);
    glVertex2f(680,0);
    glVertex2f(685,0);
    glVertex2f(685,20);
    glVertex2f(680,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(675,10);
    glVertex2f(690,10);
    glVertex2f(682.5,40);
    glVertex2f(682.5,40);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(676,15);
    glVertex2f(689,15);
    glVertex2f(682.5,45);
    glVertex2f(682.5,45);
    glEnd();





}
//ob4
void tree2(){ glBegin(GL_QUADS);  ///Bottom tree2   ///
    glColor3ub(75,35,5);
    glVertex2f(580,0);
    glVertex2f(585,0);
    glVertex2f(585,20);
    glVertex2f(580,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(575,10);
    glVertex2f(590,10);
    glVertex2f(582.5,40);
    glVertex2f(582.5,40);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(576,15);
    glVertex2f(589,15);
    glVertex2f(582.5,45);
    glVertex2f(582.5,45);
    glEnd();



}
//ob5
void tree3(){ glBegin(GL_QUADS);  ///Bottom tree3   ///
    glColor3ub(75,35,5);
    glVertex2f(480,0);
    glVertex2f(485,0);
    glVertex2f(485,20);
    glVertex2f(480,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(475,10);
    glVertex2f(490,10);
    glVertex2f(482.5,40);
    glVertex2f(482.5,40);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(476,15);
    glVertex2f(489,15);
    glVertex2f(482.5,45);
    glVertex2f(482.5,45);
    glEnd();

}
//ob6
void tree4(){
   glBegin(GL_QUADS);  ///Bottom tree4///
    glColor3ub(75,35,5);
    glVertex2f(380, 0);
    glVertex2f(385, 0);
    glVertex2f(385, 20);
    glVertex2f(380, 20);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(375, 10);
    glVertex2f(390, 10);
    glVertex2f(382.5, 40);
    glVertex2f(382.5, 40);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(376, 15);
    glVertex2f(389, 15);
    glVertex2f(382.5, 45);
    glVertex2f(382.5, 45);
glEnd();


}
//ob7
void tree5(){glBegin(GL_QUADS);  ///Bottom tree5   ///
   glColor3ub(75,35,5);
    glVertex2f(280, 0);
    glVertex2f(285, 0);
    glVertex2f(285, 20);
    glVertex2f(280, 20);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(275, 10);
    glVertex2f(290, 10);
    glVertex2f(282.5, 40);
    glVertex2f(282.5, 40);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(276, 15);
    glVertex2f(289, 15);
    glVertex2f(282.5, 45);
    glVertex2f(282.5, 45);
glEnd();


}

//ob8
void tree6()
{glBegin(GL_QUADS);  ///Bottom tree6   ///
    glColor3ub(75,35,5);;
    glVertex2f(180, 0);
    glVertex2f(185, 0);
    glVertex2f(185, 20);
    glVertex2f(180, 20);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(175, 10);
    glVertex2f(190, 10);
    glVertex2f(182.5, 40);
    glVertex2f(182.5, 40);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(176, 15);
    glVertex2f(189, 15);
    glVertex2f(182.5, 45);
    glVertex2f(182.5, 45);
glEnd();


}
//ob9
void tree7(){
   glColor3ub(75,35,5);
glBegin(GL_QUADS);  ///Bottom tree7///
    glVertex2f(80, 0);
    glVertex2f(85, 0);
    glVertex2f(85, 20);
    glVertex2f(80, 20);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(75, 10);
    glVertex2f(90, 10);
    glVertex2f(82.5, 40);
    glVertex2f(82.5, 40);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(76, 15);
    glVertex2f(89, 15);
    glVertex2f(82.5, 45);
    glVertex2f(82.5, 45);
glEnd();


}
//ob10
void firstBuilding(){
     ///...1st Building main part-1
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(50,90);
    glVertex2f(110,90);
    glVertex2f(110,475);
    glVertex2f(50,475);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(52.5,90);        //1st Building main part 2
    glVertex2f(106,90);
    glVertex2f(106,460);
    glVertex2f(52.5,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(110,90);         //1st Building 2nd part 2
    glVertex2f(140,90);
    glVertex2f(140,420);
    glVertex2f(110,420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(110,90);         //1st Building 2nd part 1
    glVertex2f(137.5,90);
    glVertex2f(137.5,410);
    glVertex2f(110,410);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(113,370);   //part 2 1st Building 6th floor2..........outlook
    glVertex2f(137.5,370);
    glVertex2f(137.5,400);
    glVertex2f(113,400);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(113,365);   //part 2 1st Building 6th floor2..........outlook
    glVertex2f(123,365);
    glVertex2f(123,400);
    glVertex2f(113,400);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(118,365);   //Door 1st Building 6th floor2..........outlook-1
    glVertex2f(119,365);
    glVertex2f(119,392);
    glVertex2f(118,392);
    glEnd();

/////////////****
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,90);  //1st Building 1st floor1
    glVertex2f(197,90);
    glVertex2f(197,145);
    glVertex2f(90,145);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,145);   //1st Building 2nd floor1
    glVertex2f(197,145);
    glVertex2f(197,200);
    glVertex2f(90,200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,200);   //1st Building 3rd floor1
    glVertex2f(197,200);
    glVertex2f(197,255);
    glVertex2f(90,255);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,255);   //1st Building 4th floor1
    glVertex2f(197,255);
    glVertex2f(197,310);
    glVertex2f(90,310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,310);   //1st Building 5th floor1
    glVertex2f(197,310);
    glVertex2f(197,365);
    glVertex2f(90,365);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,365);   //1st Building 6th floor1
    glVertex2f(197,365);
    glVertex2f(197,420);
    glVertex2f(90,420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(90,420);   //1st Building 7th floor1
    glVertex2f(197,420);
    glVertex2f(197,475);
    glVertex2f(90,475);
    glEnd();



    glColor3ub(0, 51, 204);
    glRasterPos2f(133, 465);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'H');

    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'O');

    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'T');

    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'E');

    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'L');


    glBegin(GL_QUADS);              ///SIRI GHORE.//
    glColor3ub(204, 204, 204);
    glVertex2f(90,475);
    glVertex2f(120,475);
    glVertex2f(120,515);
    glVertex2f(90,515);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(92,475);
    glVertex2f(118,475);
    glVertex2f(118,510);
    glVertex2f(92,510);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(100,475);
    glVertex2f(110,475);
    glVertex2f(110,505);
    glVertex2f(100,505);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(105,483);
    glVertex2f(106,483);
    glVertex2f(106,492);
    glVertex2f(105,492);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(110,420);   //part 2 1st Building 7th floor2 white
    glVertex2f(194,420);
    glVertex2f(194,460);
    glVertex2f(110,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,365);   //part 2 1st Building 6th floor2
    glVertex2f(194,365);
    glVertex2f(194,405);
    glVertex2f(140,405);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,310);   //part 2 1st Building 5th floor2
    glVertex2f(194,310);
    glVertex2f(194,350);
    glVertex2f(140,350);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,255);   //part 2 1st Building 4th floor2
    glVertex2f(194,255);
    glVertex2f(194,295);
    glVertex2f(140,295);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,200);   //part 2 1st Building 3rd floor2
    glVertex2f(194,200);
    glVertex2f(194,240);
    glVertex2f(140,240);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,145);   //part 2 1st Building 2nd floor2
    glVertex2f(194,145);
    glVertex2f(194,185);
    glVertex2f(140,185);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(140,90);  //part 2 1st Building 1st floor2
    glVertex2f(194,90);
    glVertex2f(194,130);
    glVertex2f(140,130);
    glEnd();



    ///design of main building....red and glass..............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,420);  //7 1st Building main part3
    glVertex2f(67,420);
    glVertex2f(67,460);
    glVertex2f(52.5,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,365);  //6 1st Building main part3
    glVertex2f(67,365);
    glVertex2f(67,405);
    glVertex2f(52.5,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,310);  //5 1st Building main part3
    glVertex2f(67,310);
    glVertex2f(67,350);
    glVertex2f(52.5,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,255);  //4 1st Building main part3
    glVertex2f(67,255);
    glVertex2f(67,295);
    glVertex2f(52.5,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,200);  //3 1st Building main part3
    glVertex2f(67,200);
    glVertex2f(67,240);
    glVertex2f(52.5,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,145);  //2 1st Building main part3
    glVertex2f(67,145);
    glVertex2f(67,185);
    glVertex2f(52.5,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(52.5,90);  //1 1st Building main part3
    glVertex2f(67,90);
    glVertex2f(67,130);
    glVertex2f(52.5,130);
    glEnd();
    /////////.....................
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,420);  //7 1st Building main part3
    glVertex2f(106,420);
    glVertex2f(106,460);
    glVertex2f(95,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,365);  //6 1st Building main part3
    glVertex2f(106,365);
    glVertex2f(106,405);
    glVertex2f(95,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,310);  //5 1st Building main part3
    glVertex2f(106,310);
    glVertex2f(106,350);
    glVertex2f(95,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,255);  //4 1st Building main part3
    glVertex2f(106,255);
    glVertex2f(106,295);
    glVertex2f(95,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,200);  //3 1st Building main part3
    glVertex2f(106,200);
    glVertex2f(106,240);
    glVertex2f(95,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(95,145);  //2 1st Building main part3
    glVertex2f(106,145);
    glVertex2f(106,185);
    glVertex2f(95,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(85,90);  //door
    glVertex2f(106,90);
    glVertex2f(106,130);
    glVertex2f(85,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(95,90);  //door 1 main
    glVertex2f(96,90);
    glVertex2f(96,130);
    glVertex2f(95,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(96,100);  //door 1 main
    glVertex2f(97,100);
    glVertex2f(97,120);
    glVertex2f(96,120);
    glEnd();

    //////////............................

    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,420);  //7 1st Building main part3
    glVertex2f(110,420);
    glVertex2f(110,421);
    glVertex2f(50,421);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,365);  //6 1st Building main part3
    glVertex2f(137.5,365);
    glVertex2f(137.5,366);
    glVertex2f(50,366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,310);  //5 1st Building main part3
    glVertex2f(110,310);
    glVertex2f(110,311);
    glVertex2f(50,311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,255);  //4 1st Building main part3
    glVertex2f(110,255);
    glVertex2f(110,256);
    glVertex2f(50,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,199);  //3 1st Building main part3
    glVertex2f(110,199);
    glVertex2f(110,200);
    glVertex2f(50,200);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,145);  //2 1st Building main part3
    glVertex2f(110,145);
    glVertex2f(110,146);
    glVertex2f(50,146);
    glEnd();

    ///////...............................
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,405);  //7 1st Building main part3
    glVertex2f(110,405);
    glVertex2f(110,406);
    glVertex2f(50,406);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,350);  //6 1st Building main part3
    glVertex2f(110,350);
    glVertex2f(110,351);
    glVertex2f(50,351);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,295);  //5 1st Building main part3
    glVertex2f(110,295);
    glVertex2f(110,296);
    glVertex2f(50,296);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,240);  //4  main part3
    glVertex2f(110,240);
    glVertex2f(110,241);
    glVertex2f(50,241);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,185);  //3 1st Building main part3
    glVertex2f(110,185);
    glVertex2f(110,186);
    glVertex2f(50,186);
    glEnd();
   glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(50,130);  //2 1st Building main part3
    glVertex2f(110,130);
    glVertex2f(110,131);
    glVertex2f(50,131);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(140,90);  // part2
    glVertex2f(141,90);
    glVertex2f(141,420);
    glVertex2f(140,420);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(110,365);  //6 1st Building main part3
    glVertex2f(120,365);
    glVertex2f(120,385);
    glVertex2f(110,385);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(128,365);  //6 1st Building main part3
    glVertex2f(137.5,365);
    glVertex2f(137.5,385);
    glVertex2f(128,385);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(57,80,80);
    glVertex2f(120,370);  //6 1st Building main part3
    glVertex2f(128,370);
    glVertex2f(128.5,372);
    glVertex2f(120,372);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(57,80,80);
    glVertex2f(120,379);  //6 1st Building main part3
    glVertex2f(128,379);
    glVertex2f(128.5,381);
    glVertex2f(120,381);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(110,310);  //5 2nd part2
    glVertex2f(137.5,310);
    glVertex2f(137.5,350);
    glVertex2f(110,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(110,255);  //4 2nd part3
    glVertex2f(137.5,255);
    glVertex2f(137.5,295);
    glVertex2f(110,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(110,200);  //3 2nd part3
    glVertex2f(137.5,200);
    glVertex2f(137.5,240);
    glVertex2f(110,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(110,145);  //2 2nd part3
    glVertex2f(137.5,145);
    glVertex2f(137.5,185);
    glVertex2f(110,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(110,90);  //1 1st Building main part3
    glVertex2f(137.5,90);
    glVertex2f(137.5,130);
    glVertex2f(110,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(117,90);  //1 1st Building main part3
    glVertex2f(118,90);
    glVertex2f(118,130);
    glVertex2f(117,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(127,90);  //1 1st Building main part3
    glVertex2f(128,90);
    glVertex2f(128,130);
    glVertex2f(127,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(118,100);  //1 1st Building main part3
    glVertex2f(119,100);
    glVertex2f(119,120);
    glVertex2f(118,120);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(128,100);  //1 1st Building main part3
    glVertex2f(129,100);
    glVertex2f(129,120);
    glVertex2f(128,120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(110,90);   //partation
    glVertex2f(111,90);
    glVertex2f(111,475);
    glVertex2f(110,475);
    glEnd();

    //..7th Floor design...................

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(113,425);   //part 2 1st Building 7th floor2
    glVertex2f(191,425);
    glVertex2f(191,455);
    glVertex2f(113,455);
    glEnd();

    //....door.....window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(113,420);   //d1 1st Building 7th floor2
    glVertex2f(123,420);
    glVertex2f(123,455);
    glVertex2f(113,455);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(118,430);   //d1 1st Building 7th floor2
    glVertex2f(119,430);
    glVertex2f(119,445);
    glVertex2f(118,445);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(133,432);   //w1 1st Building 7th floor2
    glVertex2f(153,432);
    glVertex2f(153,448);
    glVertex2f(133,448);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(133.5,433);   //w1 1st Building 7th floor2
    glVertex2f(152.5,433);
    glVertex2f(152.5,447);
    glVertex2f(133.5,447);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,432);   //w1 1st Building 7th floor2
    glVertex2f(144,432);
    glVertex2f(144,448);
    glVertex2f(143,448);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,432);   //w2 1st Building 7th floor2
    glVertex2f(183,432);
    glVertex2f(183,448);
    glVertex2f(163,448);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,433);   //w2 1st Building 7th floor2
    glVertex2f(182.5,433);
    glVertex2f(182.5,447);
    glVertex2f(163.5,447);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,432);   //w2 1st Building 7th floor2
    glVertex2f(174,432);
    glVertex2f(174,448);
    glVertex2f(173,448);
    glEnd();


    //....6th Floor Design..........Door window

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,370);   //part 2 1st Building 6th floor2..........Inlook
    glVertex2f(191,370);
    glVertex2f(191,400);
    glVertex2f(141,400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,377);   //w1 1st Building 6th floor2
    glVertex2f(153,377);
    glVertex2f(153,393);
    glVertex2f(141,393);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,378);   //w1 1st Building 6th floor2
    glVertex2f(152.5,378);
    glVertex2f(152.5,392);
    glVertex2f(141,392);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,377);   //w1 1st Building 6th floor2
    glVertex2f(144,377);
    glVertex2f(144,393);
    glVertex2f(143,393);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,377);   //w2 1st Building 6th floor2
    glVertex2f(183,377);
    glVertex2f(183,393);
    glVertex2f(163,393);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,378);   //w2 1st Building 6th floor2
    glVertex2f(182.5,378);
    glVertex2f(182.5,392);
    glVertex2f(163.5,392);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,377);   //w2 1st Building 6th floor2
    glVertex2f(174,377);
    glVertex2f(174,393);
    glVertex2f(173,393);
    glEnd();


    ///5th floor......design

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,315);   //part 2 1st Building 5th floor2.........
    glVertex2f(191,315);
    glVertex2f(191,345);
    glVertex2f(141,345);
    glEnd();


    ///....door.....window


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,322);   //w1 1st Building 5th floor2
    glVertex2f(153,322);
    glVertex2f(153,338);
    glVertex2f(141,338);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,323);   //w1 1st Building 5th floor2
    glVertex2f(152.5,323);
    glVertex2f(152.5,337);
    glVertex2f(141,337);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,322);   //w1 1st Building 5th floor2
    glVertex2f(144,322);
    glVertex2f(144,338);
    glVertex2f(143,338);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,322);   //w2 1st Building 5th floor2
    glVertex2f(183,322);
    glVertex2f(183,338);
    glVertex2f(163,338);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,323);   //w2 1st Building 5th floor2
    glVertex2f(182.5,323);
    glVertex2f(182.5,337);
    glVertex2f(163.5,337);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,322);   //w2 1st Building 5th floor2
    glVertex2f(174,322);
    glVertex2f(174,338);
    glVertex2f(173,338);
    glEnd();


    ///....4TH floor design............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,260);   //part 2 1st Building 5th floor2.........
    glVertex2f(191,260);
    glVertex2f(191,290);
    glVertex2f(141,290);
    glEnd();


    ///....door.....window


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,267);   //w1 1st Building 4th floor2
    glVertex2f(153,267);
    glVertex2f(153,283);
    glVertex2f(141,283);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,268);   //w1 1st Building 4th floor2
    glVertex2f(152.5,268);
    glVertex2f(152.5,282);
    glVertex2f(141,282);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,267);   //w1 1st Building 4th floor2
    glVertex2f(144,267);
    glVertex2f(144,283);
    glVertex2f(143,283);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,267);   //w2 1st Building 4th floor2
    glVertex2f(183,267);
    glVertex2f(183,283);
    glVertex2f(163,283);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,268);   //w2 1st Building 4th floor2
    glVertex2f(182.5,268);
    glVertex2f(182.5,282);
    glVertex2f(163.5,282);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,267);   //w2 1st Building 4th floor2
    glVertex2f(174,267);
    glVertex2f(174,283);
    glVertex2f(173,283);
    glEnd();


    ///....3TH floor design............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,205);   //part 2 1st Building 3th floor2.........
    glVertex2f(191,205);
    glVertex2f(191,235);
    glVertex2f(141,235);
    glEnd();

    ///....door.....window


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,212);   //w1 1st Building 3rd floor2
    glVertex2f(153,212);
    glVertex2f(153,228);
    glVertex2f(141,228);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,213);   //w1 1st Building 3rd floor2
    glVertex2f(152.5,213);
    glVertex2f(152.5,227);
    glVertex2f(141,227);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,212);   //w1 1st Building 3rd floor2
    glVertex2f(144,212);
    glVertex2f(144,228);
    glVertex2f(143,228);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,212);   //w2 1st Building 3rd floor2
    glVertex2f(183,212);
    glVertex2f(183,228);
    glVertex2f(163,228);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,213);   //w2 1st Building 3rd floor2
    glVertex2f(182.5,213);
    glVertex2f(182.5,227);
    glVertex2f(163.5,227);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,212);   //w2 1st Building 3rd floor2
    glVertex2f(174,212);
    glVertex2f(174,228);
    glVertex2f(173,228);
    glEnd();


    ///....2nd floor design............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,150);   //part 2 1st Building 2nd floor2.........
    glVertex2f(191,150);
    glVertex2f(191,180);
    glVertex2f(141,180);
    glEnd();


    ///....door.....window


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,157);   //w1 1st Building 2nd floor2
    glVertex2f(153,157);
    glVertex2f(153,173);
    glVertex2f(141,173);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,158);   //w1 1st Building 2nd floor2
    glVertex2f(152.5,158);
    glVertex2f(152.5,172);
    glVertex2f(141,172);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,157);   //w1 1st Building 2nd floor2
    glVertex2f(144,157);
    glVertex2f(144,173);
    glVertex2f(143,173);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,157);   //w2 1st Building 2nd floor2
    glVertex2f(183,157);
    glVertex2f(183,173);
    glVertex2f(163,173);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,158);   //w2 1st Building 2nd floor2
    glVertex2f(182.5,158);
    glVertex2f(182.5,172);
    glVertex2f(163.5,172);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,157);   //w2 1st Building 2nd floor2
    glVertex2f(174,157);
    glVertex2f(174,173);
    glVertex2f(173,173);
    glEnd();


    ///....1st floor design............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(141,95);   //part 2 1st Building 1st floor red.........
    glVertex2f(191,95);
    glVertex2f(191,125);
    glVertex2f(141,125);
    glEnd();


    ///....door.....window

    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(196,90);   //d2 AB2 1st floor
    glVertex2f(206,90);
    glVertex2f(206,125);
    glVertex2f(196,125);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(201,100);   //d2 1st Building 1st floor
    glVertex2f(202,100);
    glVertex2f(202,115);
    glVertex2f(201,115);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(141,102);   //w1 1st Building 1st floor2
    glVertex2f(153,102);
    glVertex2f(153,118);
    glVertex2f(141,118);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(141,103);   //w1 1st Building 1st floor2
    glVertex2f(152.5,103);
    glVertex2f(152.5,117);
    glVertex2f(141,117);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(143,102);   //w1 1st Building 1st floor2
    glVertex2f(144,102);
    glVertex2f(144,118);
    glVertex2f(143,118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(163,102);   //w2 1st Building 1st floor2
    glVertex2f(183,102);
    glVertex2f(183,118);
    glVertex2f(163,118);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(163.5,103);   //w2 1st Building 1st floor2
    glVertex2f(182.5,103);
    glVertex2f(182.5,117);
    glVertex2f(163.5,117);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(173,102);   //w2 1st Building 1st floor2
    glVertex2f(174,102);
    glVertex2f(174,118);
    glVertex2f(173,118);
    glEnd();


}
//ob11
void secondBuilding(){
glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(200,120);
    glVertex2f(287,120);
    glVertex2f(287,395);
    glVertex2f(200,395);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(202.5,120);        //2nd building main part 2
    glVertex2f(284,120);
    glVertex2f(284,380);
    glVertex2f(202.5,380);
    glEnd();

   ///....1st floor design............

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(205,125);   //part 2 2nd building 1st floor red.........
    glVertex2f(281,125);
    glVertex2f(281,155);
    glVertex2f(205,155);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(281,125);   //part 2 2nd building 1st floor.......red
    glVertex2f(267,125);
    glVertex2f(267,155);
    glVertex2f(281,155);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205,120);   //d2 2nd building 1st floor
    glVertex2f(215,120);
    glVertex2f(215,155);
    glVertex2f(205,155);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209,132);   //d2 2nd building 1st floor
    glVertex2f(210,132);
    glVertex2f(210,147);
    glVertex2f(209,147);
    glEnd();

        glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(223,131);   //w1 2nd building 1st floor2
    glVertex2f(243,131);
    glVertex2f(243,147);
    glVertex2f(223,147);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(223.5,132);   //w1 2nd building 1st floor2
    glVertex2f(242.5,132);
    glVertex2f(242.5,146);
    glVertex2f(223.5,146);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(233.1,131);   //w1 2nd building 1st floor2
    glVertex2f(234,131);
    glVertex2f(234,147);
    glVertex2f(233.1,147);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(253,131);   //w2 2nd building 1st floor2
    glVertex2f(273,131);
    glVertex2f(273,147);
    glVertex2f(253,147);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(253.5,132);   //w2 2nd building 1st floor2
    glVertex2f(272.5,132);
    glVertex2f(272.5,146);
    glVertex2f(253.5,146);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(263.1,131);   //w2 2nd building 1st floor2
    glVertex2f(264,131);
    glVertex2f(264,147);
    glVertex2f(263.1,147);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,160);  //2nd building 1st floor1
    glVertex2f(284,160);
    glVertex2f(284,175);
    glVertex2f(202.5,175);
    glEnd();

       ///....2nd floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(205,180);   //part 2 2nd building 2nd floor red.........
    glVertex2f(281,180);
    glVertex2f(281,210);
    glVertex2f(205,210);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(281,180);   //part 2 2nd building 2nd floor.......red
    glVertex2f(264,180);
    glVertex2f(264,210);
    glVertex2f(281,210);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205,175);   //d2 2nd building 2nd floor
    glVertex2f(215,175);
    glVertex2f(215,210);
    glVertex2f(205,210);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209,187);   //d2 2nd building 2nd floor
    glVertex2f(210,187);
    glVertex2f(210,202);
    glVertex2f(209,202);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(223,186);   //w1 2nd building 2nd floor2
    glVertex2f(243,186);
    glVertex2f(243,202);
    glVertex2f(223,202);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(223.5,187);   //w1 2nd building 2nd floor2
    glVertex2f(242.5,187);
    glVertex2f(242.5,201);
    glVertex2f(223.5,201);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(233.1,186);   //w1 2nd building 2nd floor2
    glVertex2f(234,186);
    glVertex2f(234,202);
    glVertex2f(233.1,202);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(253,186);   //w2 2nd building 2nd floor2
    glVertex2f(273,186);
    glVertex2f(273,202);
    glVertex2f(253,202);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(253.5,187);   //w2 2nd building 2nd floor2
    glVertex2f(272.5,187);
    glVertex2f(272.5,201);
    glVertex2f(253.5,201);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(263.1,186);   //w2 2nd building 2nd floor2
    glVertex2f(264,186);
    glVertex2f(264,202);
    glVertex2f(263.1,202);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,215);  //2nd building 2nd floor1
    glVertex2f(284,215);
    glVertex2f(284,230);
    glVertex2f(202.5,230);
    glEnd();

    ///....3rd floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(205,235);   //part 2 2nd building 3rd floor red.........
    glVertex2f(281,235);
    glVertex2f(281,265);
    glVertex2f(205,265);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(281,235);   //part 2 2nd building 3rd floor.......red
    glVertex2f(264,235);
    glVertex2f(264,265);
    glVertex2f(281,265);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205,230);   //d2 2nd building 3rd floor
    glVertex2f(215,230);
    glVertex2f(215,265);
    glVertex2f(205,265);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209,242);   //d2 2nd building 2nd floor
    glVertex2f(210,242);
    glVertex2f(210,257);
    glVertex2f(209,257);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(223,241);   //w1 2nd building 3rd floor2
    glVertex2f(243,241);
    glVertex2f(243,257);
    glVertex2f(223,257);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(223.5,242);   //w1 2nd building 2nd floor2
    glVertex2f(242.5,242);
    glVertex2f(242.5,256);
    glVertex2f(223.5,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(233.1,241);   //w1 2nd building 3rd floor2
    glVertex2f(234,241);
    glVertex2f(234,257);
    glVertex2f(233.1,257);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(253,241);   //w2 2nd building 3rd floor2
    glVertex2f(273,241);
    glVertex2f(273,257);
    glVertex2f(253,257);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(253.5,242);   //w2 2nd building 3rd floor2
    glVertex2f(272.5,242);
    glVertex2f(272.5,256);
    glVertex2f(253.5,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(263.1,241);   //w2 2nd building 3rd floor2
    glVertex2f(264,241);
    glVertex2f(264,257);
    glVertex2f(263.1,257);
    glEnd();

    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,270);  //2nd building 3rd floor1
    glVertex2f(284,270);
    glVertex2f(284,285);
    glVertex2f(202.5,285);
    glEnd();

    ///....4th floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(205,290);   //part 2 2nd building 4th floor red.........
    glVertex2f(281,290);
    glVertex2f(281,320);
    glVertex2f(205,320);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(281,290);   //part 2 2nd building 4th floor.......red
    glVertex2f(264,290);
    glVertex2f(264,320);
    glVertex2f(281,320);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205,285);   //d2 2nd building 4th floor
    glVertex2f(215,285);
    glVertex2f(215,320);
    glVertex2f(205,320);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209,297);   //d2 2nd building 5th floor
    glVertex2f(210,297);
    glVertex2f(210,312);
    glVertex2f(209,312);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(223,296);   //w1 2nd building 4th floor2
    glVertex2f(243,296);
    glVertex2f(243,312);
    glVertex2f(223,312);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(223.5,297);   //w1 2nd building 4th floor2
    glVertex2f(242.5,297);
    glVertex2f(242.5,311);
    glVertex2f(223.5,311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(233.1,296);   //w1 2nd building 4th floor2
    glVertex2f(234,296);
    glVertex2f(234,312);
    glVertex2f(233.1,312);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(253,297);   //w2 2nd building 4th floor2
    glVertex2f(273,297);
    glVertex2f(273,312);
    glVertex2f(253,312);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(253.5,297);   //w2 2nd building 4th floor2
    glVertex2f(272.5,297);
    glVertex2f(272.5,311);
    glVertex2f(253.5,311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(263.1,297);   //w2 2nd building 4th floor2
    glVertex2f(264,297);
    glVertex2f(264,312);
    glVertex2f(263.1,312);
    glEnd();

     //floor divided
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(202.5,325);  //2nd building 4th floor1
    glVertex2f(284,325);
    glVertex2f(284,340);
    glVertex2f(202.5,340);
    glEnd();

    ///....5th floor design............///y+55 korchi

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(205,345);   //part 2 2nd building 5th floor red.........
    glVertex2f(281,345);
    glVertex2f(281,375);
    glVertex2f(205,375);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(281,345);   //part 2 2nd building 5th floor.......red
    glVertex2f(264,345);
    glVertex2f(264,375);
    glVertex2f(281,375);
    glEnd();

    //Door and window
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(205,340);   //d2 2nd building 5th floor
    glVertex2f(215,340);
    glVertex2f(215,375);
    glVertex2f(205,375);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(209,352);   //d2 2nd building 5th floor
    glVertex2f(210,352);
    glVertex2f(210,367);
    glVertex2f(209,367);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(223,351);   //w1 2nd building 5th floor2
    glVertex2f(243,351);
    glVertex2f(243,367);
    glVertex2f(223,367);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(223.5,352);   //w1 2nd building 5th floor2
    glVertex2f(242.5,352);
    glVertex2f(242.5,366);
    glVertex2f(223.5,366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(233.1,351);   //w1 2nd building 5th floor2
    glVertex2f(234,351);
    glVertex2f(234,367);
    glVertex2f(233.1,367);
    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(253,352);   //w2 2nd building 4th floor2
    glVertex2f(273,352);
    glVertex2f(273,367);
    glVertex2f(253,367);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(128,197,215);
    glVertex2f(253.5,352);   //w2 2nd building 5th floor2
    glVertex2f(272.5,352);
    glVertex2f(272.5,366);
    glVertex2f(253.5,366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(263.1,352);   //w2 2nd building 5th floor2
    glVertex2f(264,352);
    glVertex2f(264,367);
    glVertex2f(263.1,367);
    glEnd();
    ///End 2nd building//


}

//ob12
void tower(float angle) {
glPushMatrix();

    glBegin(GL_QUADS);
        glColor3ub(140, 140, 140);
        glVertex2f(273, 395);
        glVertex2f(274, 395);
        glVertex2f(274, 520);//tower body
        glVertex2f(273, 520);
    glEnd();

    glColor3ub(102, 102, 102);
    circle(8, 11.5, 273, 500);
    glColor3ub(217, 217, 217);// tower circle
    circle(7.5, 10, 273, 500);

    glLineWidth(2);
    glTranslatef(273, 500, 0);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(-273, -500, 0);
    glBegin(GL_LINES);
        glColor3ub(140, 140, 140);//pakha
        glVertex2f(269, 500);
        glVertex2f(277, 500);
        glVertex2f(273, 504);
        glVertex2f(273, 496);

    glEnd();
    glPopMatrix();
}
//ob18
void triangleTree(){

    glBegin(GL_QUADS); ///triangle tree 2nd Building///
    glColor3ub(75,35,5);
    glVertex2f(290,90);
    glVertex2f(295,90);
    glVertex2f(295,120);
    glVertex2f(290,120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(139, 146, 22);
    glVertex2f(280,120);
    glVertex2f(305,120);
    glVertex2f(292.5,180);
    glVertex2f(292.5,180);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(139, 146, 22);
    glVertex2f(281,135);
    glVertex2f(304,135);
    glVertex2f(292.5,190);
    glVertex2f(292.5,190);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(139, 146, 22);
    glVertex2f(282,150);
    glVertex2f(303,150);
    glVertex2f(292.5,180);
    glVertex2f(292.5,180);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(139, 146, 22);
    glVertex2f(283,160);
    glVertex2f(302,160);
    glVertex2f(292.5,190);
    glVertex2f(292.5,190);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(139, 146, 22);
    glVertex2f(284,170);
    glVertex2f(301,170);
    glVertex2f(292.5,200);
    glVertex2f(292.5,200);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(139, 146, 22);
    glVertex2f(285,180);
    glVertex2f(300,180);
    glVertex2f(292.5,210);
    glVertex2f(292.5,210);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(139, 146, 22);
    glVertex2f(286,190);
    glVertex2f(299,190);
    glVertex2f(292.5,260);
    glVertex2f(292.5,260);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(139, 146, 22);
    glVertex2f(286,200);
    glVertex2f(299,200);
    glVertex2f(292.5,270);
    glVertex2f(292.5,270);
    glEnd();
}
///ob13
 void thirdBuilding(){
 ///white part///
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(575,90);
    glVertex2f(635,90);
    glVertex2f(635,475);
    glVertex2f(575,475);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(577.5,90);        //3rd Building main part 2
    glVertex2f(631,90);
    glVertex2f(631,460);
    glVertex2f(577.5,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(635,90);         //3rd Building 2nd part 2
    glVertex2f(665,90);
    glVertex2f(665,420);
    glVertex2f(635,420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(635,90);         //3rd Building 2nd part 1
    glVertex2f(662.5,90);
    glVertex2f(662.5,410);
    glVertex2f(635,410);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(637,370);   //part 2 3rd Building 6th floor2..........outlook
    glVertex2f(662.5,370);
    glVertex2f(662.5,400);
    glVertex2f(637,400);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(123, 88, 71);
    glVertex2f(638,365);   //part 2 3rd Building 6th floor2..........outlook
    glVertex2f(648,365);
    glVertex2f(648,400);
    glVertex2f(638,400);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(643,365);   //Door 3rd Building 6th floor2..........outlook-1
    glVertex2f(644,365);
    glVertex2f(644,392);
    glVertex2f(643,392);
    glEnd();

/////////////****
    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,90); //3rd Building 3rd Building floor1
    glVertex2f(667,90);
    glVertex2f(667,145);
    glVertex2f(615,145);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,145);   //3rd Building 2nd floor1
    glVertex2f(667,145);
    glVertex2f(667,200);
    glVertex2f(615,200);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,200);   //3rd Building 3rd floor1
    glVertex2f(667,200);
    glVertex2f(667,255);
    glVertex2f(615,255);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,255);   //3rd Building 4th floor1
    glVertex2f(667,255);
    glVertex2f(667,310);
    glVertex2f(615,310);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,310);   //3rd Building 5th floor1
    glVertex2f(667,310);
    glVertex2f(667,365);
    glVertex2f(615,365);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,365);   //3rd Building 6th floor1
    glVertex2f(667,365);
    glVertex2f(667,420);
    glVertex2f(615,420);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(204, 204, 204);
    glVertex2f(615,420);   //3rd Building 7th floor1
    glVertex2f(667,420);
    glVertex2f(667,475);
    glVertex2f(615,475);
    glEnd();

     ///design of main building....red and glass....

    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,420);  //7 3rd Building main part3
    glVertex2f(592,420);
    glVertex2f(592,460);
    glVertex2f(577.5,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,365);  //6 3rd Building main part3
    glVertex2f(592,365);
    glVertex2f(592,405);
    glVertex2f(577.5,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,310);  //5 3rd Building main part3
    glVertex2f(592,310);
    glVertex2f(592,350);
    glVertex2f(577.5,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,255);  //4 3rd Building main part3
    glVertex2f(592,255);
    glVertex2f(592,295);
    glVertex2f(577.5,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,200);  //3 3rd Building main part3
    glVertex2f(592,200);
    glVertex2f(592,240);
    glVertex2f(577.5,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,145);  //2 3rd Building main part3
    glVertex2f(592,145);
    glVertex2f(592,185);
    glVertex2f(577.5,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(177,124,119);
    glVertex2f(577.5,90);  //1 3rd Building main part3
    glVertex2f(592,90);
    glVertex2f(592,130);
    glVertex2f(577.5,130);
    glEnd();
    /////////.....................
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,420);  //7 3rd Building main part3
    glVertex2f(631,420);
    glVertex2f(631,460);
    glVertex2f(620,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,365);  //6 3rd Building main part3
    glVertex2f(631,365);
    glVertex2f(631,405);
    glVertex2f(620,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,310);  //5 3rd Building main part3
    glVertex2f(631,310);
    glVertex2f(631,350);
    glVertex2f(620,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,255);  //4 3rd Building main part3
    glVertex2f(631,255);
    glVertex2f(631,295);
    glVertex2f(620,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,200);  //3 3rd Building main part3
    glVertex2f(631,200);
    glVertex2f(631,240);
    glVertex2f(620,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(620,145);  //2 3rd Building main part3
    glVertex2f(631,145);
    glVertex2f(631,185);
    glVertex2f(620,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(610,90);  //door
    glVertex2f(631,90);
    glVertex2f(631,130);
    glVertex2f(610,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(620,90);  //door 1 main
    glVertex2f(621,90);
    glVertex2f(621,130);
    glVertex2f(620,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(621,100);  //door 1 main
    glVertex2f(622,100);
    glVertex2f(622,120);
    glVertex2f(621,120);
    glEnd();

    //////////............................

    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,420);  //7 3rd Building main part3
    glVertex2f(635,420);
    glVertex2f(635,421);
    glVertex2f(575,421);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,365);  //6 3rd Building main part3
    glVertex2f(662.5,365);
    glVertex2f(662.5,366);
    glVertex2f(575,366);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,310);  //5 3rd Building main part3
    glVertex2f(635,310);
    glVertex2f(635,311);
    glVertex2f(575,311);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,255);  //4 3rd Building main part3
    glVertex2f(635,255);
    glVertex2f(635,256);
    glVertex2f(575,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,199);  //3 3rd Building main part3
    glVertex2f(635,199);
    glVertex2f(635,200);
    glVertex2f(575,200);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,145);  //2 3rd Building main part3
    glVertex2f(635,145);
    glVertex2f(635,146);
    glVertex2f(575,146);
    glEnd();

    ///////...............................
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,405);  //7 3rd Building main part3
    glVertex2f(635,405);
    glVertex2f(635,406);
    glVertex2f(575,406);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,350);  //6 3rd Building main part3
    glVertex2f(635,350);
    glVertex2f(635,351);
    glVertex2f(575,351);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,295);  //5 3rd Building main part3
    glVertex2f(635,295);
    glVertex2f(635,296);
    glVertex2f(575,296);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,240);  //4 3rd Building main part3
    glVertex2f(635,240);
    glVertex2f(635,241);
    glVertex2f(575,241);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,185);  //3 3rd Building main part3
    glVertex2f(635,185);
    glVertex2f(635,186);
    glVertex2f(575,186);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(179, 179, 179);
    glVertex2f(575,130);  //2 3rd Building main part3
    glVertex2f(635,130);
    glVertex2f(635,131);
    glVertex2f(575,131);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(89, 89, 89);
    glVertex2f(665,90);  // part2 last black line
    glVertex2f(666,90);
    glVertex2f(666,460);
    glVertex2f(665,460);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,420);  //7 2nd part3
    glVertex2f(662.5,420);
    glVertex2f(662.5,460);
    glVertex2f(635,460);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,365);  //6 2nd part3
    glVertex2f(662.5,365);
    glVertex2f(662.5,405);
    glVertex2f(635,405);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,310);  //5 part3
    glVertex2f(662.5,310);
    glVertex2f(662.5,350);
    glVertex2f(635,350);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,255);  //4 2nd part3
    glVertex2f(662.5,255);
    glVertex2f(662.5,295);
    glVertex2f(635,295);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,200);  //3 2nd part3
    glVertex2f(662.5,200);
    glVertex2f(662.5,240);
    glVertex2f(635,240);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(635,145);  //2 2nd part3
    glVertex2f(662.5,145);
    glVertex2f(662.5,185);
    glVertex2f(635,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(143,175,175);
    glVertex2f(635,90);  //1 3rd Building main part3
    glVertex2f(662.5,90);
    glVertex2f(662.5,130);
    glVertex2f(635,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(642,90);  //1 main part3
    glVertex2f(643,90);
    glVertex2f(643,130);
    glVertex2f(642,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 77);
    glVertex2f(652,90);  //1 main part3
    glVertex2f(653,90);
    glVertex2f(653,130);
    glVertex2f(652,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(643,100);  //1 main part3
    glVertex2f(644,100);
    glVertex2f(644,120);
    glVertex2f(643,120);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(653,100);  ///1 main part3
    glVertex2f(654,100);
    glVertex2f(654,120);
    glVertex2f(653,120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(635,90);   ///partation of Blue line
    glVertex2f(636,90);
    glVertex2f(636,460);
    glVertex2f(635,460);
    glEnd();
 }
 //ob14

void forthBuilding(){
 glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);///4th Building main part 2
    glVertex2f(483.5,440);
    glVertex2f(555.2,440);
    glVertex2f(555.2,472);
    glVertex2f(483.5,472);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(483.5,440);        ///4th Building main part 2
    glVertex2f(555.2,440);
    glVertex2f(555.2,467);
    glVertex2f(483.5,467);
    glEnd();
///white part///
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);///4th Building main part 2
    glVertex2f(475,119);
    glVertex2f(563.5,119);
    glVertex2f(563.5,442);
    glVertex2f(475,442);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(85,119,119);
    glVertex2f(477.5,119);        ///4th Building main part 2
    glVertex2f(561,119);
    glVertex2f(561,434);
    glVertex2f(477.5,434);
    glEnd();

    ///floor divided y+40//
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,150);  ///4th Building 1st floor1
    glVertex2f(563,150);
    glVertex2f(563,154);
    glVertex2f(475,154);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,190);  ///4th Building 2nd floor1
    glVertex2f(563,190);
    glVertex2f(563,193);
    glVertex2f(475,193);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,230);  ///4th Building 3rd floor1
    glVertex2f(563,230);
    glVertex2f(563,234);
    glVertex2f(475,234);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,270);  ///4th Building 4th floor1
    glVertex2f(563,270);
    glVertex2f(563,273);
    glVertex2f(475,273);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,310);  ///4th Building 5th floor1
    glVertex2f(563,310);
    glVertex2f(563,314);
    glVertex2f(475,314);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,310);  ///4th Building 6th floor1
    glVertex2f(563,310);
    glVertex2f(563,314);
    glVertex2f(475,314);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,350);  ///4th Building 7th floor1
    glVertex2f(563,350);
    glVertex2f(563,353);
    glVertex2f(475,353);
    glEnd();
    //floor divided
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(475,390);  ///4th Building 8th floor1
    glVertex2f(563,390);
    glVertex2f(563,394);
    glVertex2f(475,394);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(491,119);  /// 4th Building white line vertical
    glVertex2f(491.5,119);
    glVertex2f(491.5,440);
    glVertex2f(491,440);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(505,119);  /// 4th Building white line vertical
    glVertex2f(505.5,119);
    glVertex2f(505.5,440);
    glVertex2f(505,440);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(519,119);  /// 4th Building white line vertical
    glVertex2f(519.5,119);
    glVertex2f(519.5,440);
    glVertex2f(519,440);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(533,119);  /// 4th Building white line vertical
    glVertex2f(533.5,119);
    glVertex2f(533.5,440);
    glVertex2f(533,440);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(242, 242, 242);
    glVertex2f(547,119);  /// 4th Building white line vertical
    glVertex2f(547.5,119);
    glVertex2f(547.5,440);
    glVertex2f(547,440);
    glEnd();

    ///Door
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(505,140);  ///4th Building 1st floor1
    glVertex2f(533,140);
    glVertex2f(533,144);
    glVertex2f(505,144);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(532,119);  /// 4th Building white line vertical
    glVertex2f(533.6,119);
    glVertex2f(533.6,140);
    glVertex2f(532,140);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(518,119);  /// 4th Building white line vertical
    glVertex2f(519.6,119);
    glVertex2f(519.6,140);
    glVertex2f(518,140);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 26, 51);
    glVertex2f(505,119);  ///4th Building white line vertical
    glVertex2f(506.6,119);
    glVertex2f(506.6,140);
    glVertex2f(505,140);
    glEnd();
    ///End 4th Building///

    ///Hospital signboard

    glColor3ub(0, 51, 204);
    glRasterPos2f(504,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'H');
    glColor3ub(0, 51, 204);
    glRasterPos2f(509,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'0');
    glColor3ub(0, 51, 204);
    glRasterPos2f(513,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'S');
    glColor3ub(0, 51, 204);
    glRasterPos2f(517,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'P');
    glColor3ub(0, 51, 204);
    glRasterPos2f(521,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'I');
    glColor3ub(0, 51, 204);
    glRasterPos2f(525,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'T');
     glColor3ub(0, 51, 204);
    glRasterPos2f(529,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'A');
    glColor3ub(0, 51, 204);
    glRasterPos2f(534,455);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'L');
}
//ob16
void foodCourt(){
 /// Food court big Right part///
    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74);///Food Court main part 2
    glVertex2f(373,90);
    glVertex2f(466,90);
    glVertex2f(466,442);
    glVertex2f(373,442);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(91,102,108);
    glVertex2f(377.5,90);        ///Food Court main part 2
    glVertex2f(461,90);
    glVertex2f(461,440);
    glVertex2f(377.5,440);
    glEnd();

  //floor divided
    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74);
    glVertex2f(282.5,270);  ///Middle divided left right
    glVertex2f(466,270);
    glVertex2f(466,281);
    glVertex2f(282.5,281);
    glEnd();

   ///stairs Top chad
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(371,442);  ///3//
    glVertex2f(467.5,442);
    glVertex2f(467.5,451);
    glVertex2f(371,451);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(20, 25, 33);
    glVertex2f(371,454);  ///2//
    glVertex2f(467.5,454);
    glVertex2f(467.5,451);
    glVertex2f(371,451);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(367,454);  ///1//
    glVertex2f(471.5,454);
    glVertex2f(471.5,463);
    glVertex2f(367,463);
    glEnd();

    ///stairs Top End//

    glBegin(GL_QUADS);
    glColor3ub(72, 85, 93);
    glVertex2f(377.5,433);
    glVertex2f(461,433);
    glVertex2f(461,440);
    glVertex2f(377.5,440);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(382,290);        ///black Food Court Right part
    glVertex2f(457,290);
    glVertex2f(457,429);
    glVertex2f(382,429);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(254, 246, 223);
    glVertex2f(383.5,293.6);        /// white color Food Court Right part
    glVertex2f(455.4,293.6);
    glVertex2f(455.4,425.4);
    glVertex2f(383.5,425.4);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(382,314.2);  ///middle line 2
    glVertex2f(457,314.2);
    glVertex2f(457,310.2);
    glVertex2f(382,310.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(368,409.1);  ///middle line 1
    glVertex2f(457,409.1);
    glVertex2f(457,405.1);
    glVertex2f(368,405.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(368,429.1);  ///middle line for sign board
    glVertex2f(382,429.1);
    glVertex2f(382,426);
    glVertex2f(368,426);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(402,290);   ///partation of Blue line
    glVertex2f(400.6,290);
    glVertex2f(400.6,426);
    glVertex2f(402,426);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(420,290);   ///partation of Blue line
    glVertex2f(418.6,290);
    glVertex2f(418.6,426);
    glVertex2f(420,426);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(438,290);   ///partation of Blue line
    glVertex2f(436.5,290);
    glVertex2f(436.5,426);
    glVertex2f(438,426);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(52, 67, 74);
    glVertex2f(388.5,255.6);        ///  Food Court board Black
    glVertex2f(450.2,255.6);
    glVertex2f(450.2,283.4);
    glVertex2f(388.5,283.4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(182, 138, 94);
    glVertex2f(386.5,258.3);        /// Food Court board
    glVertex2f(448.3,258.3);
    glVertex2f(448.3,287);
    glVertex2f(386.5,287);
    glEnd();
   glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(386.5,281.2);  /// food court board middle line 1
    glVertex2f(448.3,281.2);
    glVertex2f(448.3,279);
    glVertex2f(386.5,279);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(386.5,273.2);  ///middle line 2
    glVertex2f(448.3,273.2);
    glVertex2f(448.3,271);
    glVertex2f(386.5,271);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(250, 201, 143);
    glVertex2f(386.5,265.2);  ///middle line 3
    glVertex2f(448.3,265.2);
    glVertex2f(448.3,263);
    glVertex2f(386.5,263);
    glEnd();

    glColor3ub(31, 46, 53);
    glRasterPos2f(400,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'F');
    glColor3ub(31, 46, 53);
    glRasterPos2f(404,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'O');
    glColor3ub(31, 46, 53);
    glRasterPos2f(408,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'O');
    glColor3ub(31, 46, 53);
    glRasterPos2f(412,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'D');
    glColor3ub(31, 46, 53);
    glRasterPos2f(416,270);
     glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,' ');
    glColor3ub(31, 46, 53);
    glRasterPos2f(420,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'C');
    glColor3ub(31, 46, 53);
    glRasterPos2f(424,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'O');
     glColor3ub(31, 46, 53);
    glRasterPos2f(428,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'U');
    glColor3ub(31, 46, 53);
    glRasterPos2f(432,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'R');
    glColor3ub(31, 46, 53);
    glRasterPos2f(436,270);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,'T');

   glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6,241.4);  ///middle line
    glVertex2f(460.9,241.4);
    glVertex2f(460.9,239.2);
    glVertex2f(377.6,239.2);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6,230.4);  ///middle line
    glVertex2f(460.9,230.4);
    glVertex2f(460.9,228.2);
    glVertex2f(377.6,228.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6,220.4);  ///middle line
    glVertex2f(460.9,220.4);
    glVertex2f(460.9,218.2);
    glVertex2f(377.6,218.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6,210.5);  ///middle line
    glVertex2f(460.9,210.5);
    glVertex2f(460.9,208.4);
    glVertex2f(377.6,208.4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 45, 51);
    glVertex2f(377.6,200.5);  ///middle line
    glVertex2f(460.9,200.5);
    glVertex2f(460.9,198.4);
    glVertex2f(377.6,198.4);
    glEnd();

    ///Door///
    glBegin(GL_QUADS);
    glColor3ub(104, 111, 119);
    glVertex2f(397,110);        ///black color Food court door
    glVertex2f(442,110);
    glVertex2f(442,230);
    glVertex2f(397,230);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(398.5,110);        /// Food Court black color
    glVertex2f(440,110);
    glVertex2f(440,226.5);
    glVertex2f(398.5,226.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(254, 242, 205);
    glVertex2f(401.5,110);        /// Food Court Right part
    glVertex2f(437,110);
    glVertex2f(437,220.5);
    glVertex2f(401.5,220.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(399,118.7);  ///
    glVertex2f(440,118.7);
    glVertex2f(440,124.6);
    glVertex2f(399,124.6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(420,110);   ///partation of Blue line
    glVertex2f(416.6,110);
    glVertex2f(416.6,226);
    glVertex2f(420,226);
    glEnd();
     glBegin(GL_QUADS);
    glColor3ub(104, 111, 119);
    glVertex2f(421,110);   ///partation
    glVertex2f(419.6,110);
    glVertex2f(419.6,226);
    glVertex2f(421,226);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(34, 45, 51);
    glVertex2f(424,110);   ///partation of Blue line
    glVertex2f(420.6,110);
    glVertex2f(420.6,226);
    glVertex2f(424,226);
    glEnd();


    ///End Right part///

    ///Food Court left part
    glBegin(GL_QUADS);
    glColor3ub(91, 102, 108);///Food Court small left part
    glVertex2f(288,110);
    glVertex2f(373,110);
    glVertex2f(373,270);
    glVertex2f(288,270);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(293,120);        ///black Food Court small left part
    glVertex2f(368,120);
    glVertex2f(368,259);
    glVertex2f(293,259);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(254, 246, 223);
    glVertex2f(295,124);        /// white color Food Court small left part
    glVertex2f(366,124);
    glVertex2f(366,256);
    glVertex2f(295,256);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(294.5,190);  ///middle line
    glVertex2f(368,190);
    glVertex2f(368,187);
    glVertex2f(294.5,187);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(350,120);   ///partation of Blue line
    glVertex2f(348.6,120);
    glVertex2f(348.6,256);
    glVertex2f(350,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(332,120);   ///partation of Blue line
    glVertex2f(330.6,120);
    glVertex2f(330.6,256);
    glVertex2f(332,256);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(314,120);   ///partation of Blue line
    glVertex2f(312.6,120);
    glVertex2f(312.6,256);
    glVertex2f(314,256);
    glEnd();

    ///top Boundary
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(284.3,280);   ///partation of Blue line
    glVertex2f(282.5,280);
    glVertex2f(282.5,321);
    glVertex2f(284.3,321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(302,280);   ///partation of Blue line
    glVertex2f(300.2,280);
    glVertex2f(300.2,321);
    glVertex2f(302,321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(320,280);   ///partation of Blue line
    glVertex2f(318.2,280);
    glVertex2f(318.2,321);
    glVertex2f(320,321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(338,280);   ///partation of Blue line
    glVertex2f(336.1,280);
    glVertex2f(336.1,321);
    glVertex2f(338,321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(356,280);   ///partation of Blue line
    glVertex2f(354.2,280);
    glVertex2f(354.2,321);
    glVertex2f(356,321);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(373,280);   ///partation of Blue line
    glVertex2f(371.2,280);
    glVertex2f(371.2,321);
    glVertex2f(373,321);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(282.5,314);  ///middle line
    glVertex2f(372,314);
    glVertex2f(372,309.6);
    glVertex2f(282.5,309.6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(282.5,304);  ///middle line
    glVertex2f(372,304);
    glVertex2f(372,300);
    glVertex2f(282.5,300);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(27, 45, 54);
    glVertex2f(282.5,294);  ///middle line
    glVertex2f(372,294);
    glVertex2f(372,290);
    glVertex2f(282.5,290);
    glEnd();
    ///End top Boundary//
    ///End left part//



    ///stairs//
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(284,90);  ///Bottom3
    glVertex2f(471.5,90);
    glVertex2f(471.5,99);
    glVertex2f(284,99);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(20, 25, 33);
    glVertex2f(286,102);  ///middle2
    glVertex2f(468,102);
    glVertex2f(468,99);
    glVertex2f(286,99);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(33, 46, 47);
    glVertex2f(286,102);  ///Top1
    glVertex2f(468,102);
    glVertex2f(468,110);
    glVertex2f(286,110);
    glEnd();

    ///stairs End//
}
//ob19
void triangleTree1(){

    glBegin(GL_QUADS);  ///tree.........beside 4th Building........1   ///
    glColor3ub(139,99,47);
    glVertex2f(650,90);
    glVertex2f(655,90);
    glVertex2f(655,110);
    glVertex2f(650,110);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0,99,47);
    glVertex2f(640,110);
    glVertex2f(665,110);
    glVertex2f(652.5,140);
    glVertex2f(652.5,140);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,99,47);
    glVertex2f(641,120);
    glVertex2f(664,120);
    glVertex2f(652.5,160);
    glVertex2f(652.5,160);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,99,47);
    glVertex2f(642,130);
    glVertex2f(663,130);
    glVertex2f(652.5,180);
    glVertex2f(652.5,180);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(642.5,140);
    glVertex2f(662.5,140);
    glVertex2f(652.5,185);
    glVertex2f(652.5,185);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(643,150);
    glVertex2f(662,150);
    glVertex2f(652.5,195);
    glVertex2f(652.5,195);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(643.5,160);
    glVertex2f(661.5,160);
    glVertex2f(652.5,210);
    glVertex2f(652.5,210);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(644,170);
    glVertex2f(661,170);
    glVertex2f(652.5,230);
    glVertex2f(652.5,230);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(644.5,180);
    glVertex2f(660.5,180);
    glVertex2f(652.5,250);
    glVertex2f(652.5,250);
    glEnd();

}
//ob20
void triangleTree2(){
 glBegin(GL_QUADS);  ///tree.........beside 4th Building........2   ///
    glColor3ub(139,99,47);
    glVertex2f(670,90);
    glVertex2f(675,90);
    glVertex2f(675,120);
    glVertex2f(670,120);
    glEnd();


    glBegin(GL_QUADS);  ///triangle tree 1.........beside 3rd building........2   ///
    glColor3ub(0,99,47);
    glVertex2f(660,120);
    glVertex2f(685,120);
    glVertex2f(672.5,180);
    glVertex2f(672.5,180);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,99,47);
    glVertex2f(661,135);
    glVertex2f(684,135);
    glVertex2f(672.5,190);
    glVertex2f(672.5,190);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,99,47);
    glVertex2f(662,150);
    glVertex2f(683,150);
    glVertex2f(672.5,180);
    glVertex2f(672.5,180);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,99,47);
    glVertex2f(663,160);
    glVertex2f(682,160);
    glVertex2f(672.5,190);
    glVertex2f(672.5,190);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,99,47);
    glVertex2f(664,170);
    glVertex2f(681,170);
    glVertex2f(672.5,200);
    glVertex2f(672.5,200);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,99,47);
    glVertex2f(665,180);
    glVertex2f(680,180);
    glVertex2f(672.5,210);
    glVertex2f(672.5,210);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,99,47);
    glVertex2f(666,190);
    glVertex2f(679,190);
    glVertex2f(672.5,260);
    glVertex2f(672.5,260);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,99,47);
    glVertex2f(666,200);
    glVertex2f(679,200);
    glVertex2f(672.5,270);
    glVertex2f(672.5,270);
    glEnd();
}
//ob21
void triangleTree3(){
 glBegin(GL_QUADS);  ///tree.........beside 4th Building........3   ///
    glColor3ub(139,99,47);
    glVertex2f(680,90);
    glVertex2f(685,90);
    glVertex2f(685,100);
    glVertex2f(680,100);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(675,100);
    glVertex2f(690,100);
    glVertex2f(682.5,130);
    glVertex2f(682.5,130);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(676,110);
    glVertex2f(689,110);
    glVertex2f(682.5,140);
    glVertex2f(682.5,140);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(677,122);
    glVertex2f(688,122);
    glVertex2f(682.5,155);
    glVertex2f(682.5,155);
    glEnd();




}
//ob22
void triangleTree4(){
glBegin(GL_QUADS);  ///tree.........beside 4th Building........4   ///
    glColor3ub(139,99,47);
    glVertex2f(690,90);
    glVertex2f(695,90);
    glVertex2f(695,105);
    glVertex2f(690,105);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0,99,47);
    glVertex2f(685,105);
    glVertex2f(700,105);
    glVertex2f(692.5,135);
    glVertex2f(692.5,135);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 102, 0);
    glVertex2f(686,115);
    glVertex2f(699,115);
    glVertex2f(692.5,145);
    glVertex2f(692.5,145);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 102, 0);
    glVertex2f(687,127);
    glVertex2f(698,127);
    glVertex2f(692.5,165);
    glVertex2f(692.5,165);
    glEnd();
}
//ob17
void triangleTree5(){
    glPushMatrix();
    glTranslatef(-620,0,0);
    triangleTree1();
    glPopMatrix();

}
//ob28
void triangleTree6(){
    glPushMatrix();
    glTranslatef(-660,0,0);
    triangleTree2();
    glPopMatrix();

}
//ob15
void sun(){
glPushMatrix();
    glTranslatef(sunPosX, sunPosY, 0.0f);
glColor3ub(253, 183, 77);    ///.........S U N.....................///
    circle(18,36,0,0);
glPopMatrix();
}
//ob23
void sunCoverCloud(){
  glColor3ub(232,241,255);        ///....Megh.......1 covering sun....///
    circle(13,20,400,665);
    glColor3ub(252,254,255);
    circle(11,18,400,665);

    glColor3ub(232,241,255);
    circle(10,20,410,675);
    glColor3ub(252,254,255);
    circle(10,20,412,672);

    glColor3ub(232,241,255);
    circle(13,20,410,655);

     glColor3ub(221,229,247);
    circle(9,20,420,680);
    glColor3ub(252,254,255);
    circle(8,18,420,679);

    glColor3ub(232,241,255);
    circle(9,20,420,650);
    glColor3ub(252,254,255);
    circle(8,18,420,652);

    glColor3ub(221,229,247);
    circle(9,20,430,685);
    glColor3ub(252,254,255);
    circle(8,18,430,683);

    glColor3ub(232,241,255);
    circle(9,20,425,655);
    glColor3ub(252,254,255);
    circle(8,18,435,657);

    glColor3ub(232,241,255);
    circle(9,20,440,675);

    glColor3ub(221,229,247);
    circle(8,18,445,665);
    glColor3ub(252,254,255);
    circle(8,18,443,663);
    glColor3ub(252,254,255);
    circle(18,18,420,664);
    glColor3ub(252,254,255);
    circle(18,25,417,665);
}
//ob24
void cloud(){
    glPushMatrix();
    glTranslatef(cloudposition,cloudpositiony,0);

  glColor3ub(232,241,255);
    circle(13,20,400,665);
    glColor3ub(252,254,255);
    circle(11,18,400,665);

    glColor3ub(232,241,255);
    circle(10,20,410,675);
    glColor3ub(252,254,255);
    circle(10,20,412,672);

    glColor3ub(232,241,255);
    circle(13,20,410,655);

     glColor3ub(221,229,247);
    circle(9,20,420,680);
    glColor3ub(252,254,255);
    circle(8,18,420,679);

    glColor3ub(232,241,255);
    circle(9,20,420,650);
    glColor3ub(252,254,255);
    circle(8,18,420,652);

    glColor3ub(221,229,247);
    circle(9,20,430,685);
    glColor3ub(252,254,255);
    circle(8,18,430,683);

    glColor3ub(232,241,255);
    circle(9,20,425,655);
    glColor3ub(252,254,255);
    circle(8,18,435,657);

    glColor3ub(232,241,255);
    circle(9,20,440,675);

    glColor3ub(221,229,247);
    circle(8,18,445,665);
    glColor3ub(252,254,255);
    circle(8,18,443,663);
    glColor3ub(252,254,255);
    circle(18,18,420,664);
    glColor3ub(252,254,255);
    circle(18,25,417,665);
    glPopMatrix();
}
//ob25
void cloud2(){
    glPushMatrix();
    glTranslatef(-250,30,0);

  glColor3ub(232,241,255);
    circle(13,20,400,665);
    glColor3ub(252,254,255);
    circle(11,18,400,665);

    glColor3ub(232,241,255);
    circle(10,20,410,675);
    glColor3ub(252,254,255);
    circle(10,20,412,672);

    glColor3ub(232,241,255);
    circle(13,20,410,655);

     glColor3ub(221,229,247);
    circle(9,20,420,680);
    glColor3ub(252,254,255);
    circle(8,18,420,679);

    glColor3ub(232,241,255);
    circle(9,20,420,650);
    glColor3ub(252,254,255);
    circle(8,18,420,652);

    glColor3ub(221,229,247);
    circle(9,20,430,685);
    glColor3ub(252,254,255);
    circle(8,18,430,683);

    glColor3ub(232,241,255);
    circle(9,20,425,655);
    glColor3ub(252,254,255);
    circle(8,18,435,657);

    glColor3ub(232,241,255);
    circle(9,20,440,675);

    glColor3ub(221,229,247);
    circle(8,18,445,665);
    glColor3ub(252,254,255);
    circle(8,18,443,663);
    glColor3ub(252,254,255);
    circle(18,18,420,664);
    glColor3ub(252,254,255);
    circle(18,25,417,665);
    glPopMatrix();
}
///ob26
void bus(){
    glPushMatrix();
     glTranslatef(busPosition, 0, 0);

glBegin(GL_QUADS);
    glColor3ub(255, 81, 76);
    glVertex2f(90, 98);  //bus......
    glVertex2f(95, 98);
    glVertex2f(95, 100);
    glVertex2f(90, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(26, 26, 0);
    glVertex2f(94, 89);   // bus font glass
    glVertex2f(96, 89);
    glVertex2f(96, 100);
    glVertex2f(94, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(255, 81, 76);
    glVertex2f(10, 80);  //.....bus
    glVertex2f(90, 80);
    glVertex2f(90, 105);
    glVertex2f(10, 105);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(255, 81, 76);
    glVertex2f(10, 55);  //top..........lowerpart
    glVertex2f(92, 55);
    glVertex2f(92, 80);
    glVertex2f(10, 80);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(0, 51, 0);
    glVertex2f(11, 81);  //top..........
    glVertex2f(89, 81);
    glVertex2f(89, 102);
    glVertex2f(11, 102);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(12, 85);  //window..........
    glVertex2f(20, 85);
    glVertex2f(20, 100);
    glVertex2f(12, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(22, 85);  //window..........
    glVertex2f(30, 85);
    glVertex2f(30, 100);
    glVertex2f(22, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(32, 85);  //window..........
    glVertex2f(40, 85);
    glVertex2f(40, 100);
    glVertex2f(32, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(42, 85);  //window..........
    glVertex2f(50, 85);
    glVertex2f(50, 100);
    glVertex2f(42, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(52, 85);  //window..........
    glVertex2f(60, 85);
    glVertex2f(60, 100);
    glVertex2f(52, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 247, 255);
    glVertex2f(62, 55);  //..door..........
    glVertex2f(70, 55);
    glVertex2f(70, 95);
    glVertex2f(62, 95);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(72, 85);  //window..........
    glVertex2f(80, 85);
    glVertex2f(80, 100);
    glVertex2f(72, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(82, 85);  //window..........
    glVertex2f(88, 85);
    glVertex2f(88, 100);
    glVertex2f(82, 100);
glEnd();

glColor3ub(255, 255, 204);          //body design
circle(4, 8, 45, 65);
glColor3ub(255, 255, 204);
circle(2, 4, 55, 75);
glColor3ub(255, 255, 204);
circle(3, 6, 15, 75);
glColor3ub(255, 255, 204);
circle(2, 4, 35, 65);
glColor3ub(255, 255, 204);
circle(2, 4, 75, 75);

glColor3ub(0, 0, 0);          //....chaka....back
circle(5, 10, 25, 55);
glColor3ub(255, 255, 255);
circle(3, 6, 25, 55);

glColor3ub(0, 0, 0);
circle(5, 10, 78, 55);
glColor3ub(255, 255, 255);
circle(3, 6, 78, 55);
  glPopMatrix();
}
//ob27
void bus2(){

    glPushMatrix();
    glTranslatef(busPosition2,0,0);

glBegin(GL_QUADS);
    glColor3ub(43, 58, 139);
    glVertex2f(90, 98);  //bus...................
    glVertex2f(95, 98);
    glVertex2f(95, 100);
    glVertex2f(90, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(26, 26, 0);
    glVertex2f(94, 89);   // bus font glass
    glVertex2f(96, 89);
    glVertex2f(96, 100);
    glVertex2f(94, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(43, 58, 139);
    glVertex2f(10, 80);  //.....bus
    glVertex2f(90, 80);
    glVertex2f(90, 105);
    glVertex2f(10, 105);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(43, 58, 139);
    glVertex2f(10, 55);  //top..........lowerpart
    glVertex2f(92, 55);
    glVertex2f(92, 80);
    glVertex2f(10, 80);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(0, 51, 0);
    glVertex2f(11, 81);  //top..........
    glVertex2f(89, 81);
    glVertex2f(89, 102);
    glVertex2f(11, 102);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(12, 85);  //window..........
    glVertex2f(20, 85);
    glVertex2f(20, 100);
    glVertex2f(12, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(22, 85);  //window..........
    glVertex2f(30, 85);
    glVertex2f(30, 100);
    glVertex2f(22, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(32, 85);  //window..........
    glVertex2f(40, 85);
    glVertex2f(40, 100);
    glVertex2f(32, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(42, 85);  //window..........
    glVertex2f(50, 85);
    glVertex2f(50, 100);
    glVertex2f(42, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(52, 85);  //window..........
    glVertex2f(60, 85);
    glVertex2f(60, 100);
    glVertex2f(52, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 247, 255);
    glVertex2f(62, 55);  //..door..........
    glVertex2f(70, 55);
    glVertex2f(70, 95);
    glVertex2f(62, 95);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(72, 85);  //window..........
    glVertex2f(80, 85);
    glVertex2f(80, 100);
    glVertex2f(72, 100);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(230, 255, 255);
    glVertex2f(82, 85);  //window..........
    glVertex2f(88, 85);
    glVertex2f(88, 100);
    glVertex2f(82, 100);
glEnd();

glColor3ub(255, 255, 204);          //circle design
circle(4, 8, 45, 65);
glColor3ub(255, 255, 204);
circle(2, 4, 55, 75);
glColor3ub(255, 255, 204);
circle(3, 6, 15, 75);
glColor3ub(255, 255, 204);
circle(2, 4, 35, 65);
glColor3ub(255, 255, 204);
circle(2, 4, 75, 75);

glColor3ub(0, 0, 0);          //....chaka....back
circle(5, 10, 25, 55);
glColor3ub(255, 255, 255);
circle(3, 6, 25, 55);

glColor3ub(0, 0, 0);
circle(5, 10, 78, 55);
glColor3ub(255, 255, 255);
circle(3, 6, 78, 55);
glPopMatrix();

}
void addDrop() {
    static int index = 0;
    dropX[index] = rand() % 1900;
    dropY[index] = 1000;
    index = (index + 1) % totalDrops;

}

void updateRain(int value) {
    for (int i = 0; i < totalDrops; i++) {
        dropY[i] -= 15;

        if (dropY[i] < 0) {
            dropY[i] = 1000;
            dropX[i] = rand() % 1900;
        }
    }

    for (int i = 0; i < 10; i++) {addDrop(); }

    glutPostRedisplay();
    glutTimerFunc(16, updateRain, 0);
}
//ob30
void drawRainfall() {
    glColor3f(0.3f, 0.4f, 0.3f);
    glBegin(GL_LINES);
    for (int i = 0; i < totalDrops; i++) {
        glVertex2f(dropX[i], dropY[i]);
        glVertex2f(dropX[i], dropY[i] - 20);
    }
    glEnd();
}



// ============================================================
// BEZIER CURVE - Scenario 1: Decorative Bridge Arch over Road
// ============================================================
void drawBezierPoint(float t, float p0x, float p0y, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float &bx, float &by)
{
    float mt = 1.0f - t;
    bx = mt*mt*mt*p0x + 3*mt*mt*t*p1x + 3*mt*t*t*p2x + t*t*t*p3x;
    by = mt*mt*mt*p0y + 3*mt*mt*t*p1y + 3*mt*t*t*p2y + t*t*t*p3y;
}

void drawBezierBridge()
{
    int segments = 60;
    float bx, by;

    glColor3ub(220, 50, 50);
    glLineWidth(4);

    // Arch segments across full road x=0 to x=800, each arch width=160
    float archPts[6][4] = {
        {0,   160},
        {160, 320},
        {320, 480},
        {480, 640},
        {640, 800}
    };
    int numArches = 5;

    for (int a = 0; a < numArches; a++) {
        float x0 = a * 160.0f;
        float x1 = x0 + 160.0f;
        float cx0 = x0 + 40.0f;
        float cx1 = x1 - 40.0f;

        glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= segments; i++) {
            float t = (float)i / segments;
            drawBezierPoint(t, x0,39, cx0,81, cx1,81, x1,39, bx, by);
            glVertex2f(bx, by);
        }
        glEnd();

        // Cables from arch peak down to road base
        glColor3ub(180, 30, 30);
        glLineWidth(1);
        for (int j = 1; j <= 5; j++) {
            float t = j / 6.0f;
            drawBezierPoint(t, x0,39, cx0,81, cx1,81, x1,39, bx, by);
            glBegin(GL_LINES);
            glVertex2f(bx, by);
            glVertex2f(bx, 39);
            glEnd();
        }
        glColor3ub(220, 50, 50);
        glLineWidth(4);
    }

    glLineWidth(1);
}

void updateTime(int value) {
    cloudposition += cloudSpeed;
    busPosition2 += 0.90;
    busPosition += speed;
    sunPosY += speedY;
    angle -= 1.0f;

    if (busPosition > 800)   busPosition = -100.0;
    if (busPosition2 > 800)  busPosition2 = -100.0;
    if (cloudposition > 800) cloudposition = -450.0;
    if (sunPosY > 705)       sunPosY = 705;
    if (angle < -360)        angle += 360;

    glutPostRedisplay();
    glutTimerFunc(16, updateTime, 0);
}

// ============================================================
// ===     SCENARIO 2: RIVER CITY SCENE (33.txt)           ===
// ============================================================

void Circle(float x, float y, float r)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 500; i++)
    {
        float a = 2 * 3.1416f * i / 500;
        glVertex2f(x + cos(a) * r, y + sin(a) * r);
    }
    glEnd();
}



//////////////////////////////////////////////////////////////////////  GROUND
void Ground(float x, float y, float scale) //obj1
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);
    glColor3ub(0, 50, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-200 , 0 );
    glVertex2f(200 , 0 );
    glVertex2f(200 , 20 );
    glVertex2f(-200 , 20 );
    glEnd();
    glPopMatrix();
}



/////////////////////////////////////////////////////////////////////  SKY

int nightSky = -1;

void Sky(float x, float y, float scale, float a, float b, float c) //obj2
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);
    if(nightSky == 1)
        glColor3ub(10, 15, 40);
    else
        glColor3ub(255, 190, 140);
    glBegin(GL_POLYGON);
    glVertex2f(200 , 20 );
    glVertex2f(-200 , 20 );
    glVertex2f(-200 , 150 );
    glVertex2f(200 , 150 );
    glEnd();
    glPopMatrix();
}




//////////////////////////////////////////////////////////////////////  RIVER
float moveWave[7] = {0,0,0,0,0,0,0};
float waveSpeed[7] = {1.2f, 1.0f, 1.4f, 0.8f, 1.1f, 0.9f, 1.3f};
// ============================================================
// BEZIER CURVE - Scenario 2: River Waves
// ============================================================
void drawBezierWave(float x1, float y1, float cx1, float cy1, float cx2, float cy2, float x2, float y2, int segments)
{
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= segments; i++) {
        float t  = (float)i / segments;
        float mt = 1.0f - t;
        float bx = mt*mt*mt*x1 + 3*mt*mt*t*cx1 + 3*mt*t*t*cx2 + t*t*t*x2;
        float by = mt*mt*mt*y1 + 3*mt*mt*t*cy1 + 3*mt*t*t*cy2 + t*t*t*y2;
        glVertex2f(bx, by);
    }
    glEnd();
}

void River(float y, float scale)//obj3
{
    glPushMatrix();
    glTranslatef(0, y, 0);
    glScalef(scale, scale, 1);

    // ---------------- river base ----------------
    glColor3ub(0, 100, 200);
    glBegin(GL_POLYGON);
        glVertex2f(-200, -100);
        glVertex2f(-200 , -60);
        glVertex2f(200 , -60);
        glVertex2f(200 , -100);
    glEnd();

    // ---------------- waves (Bezier curves) ----------------
    glColor3ub(255,255,255);
    glLineWidth(2);

    // Wave 1
    glPushMatrix();
    glTranslatef(moveWave[0], 0, 0);
    drawBezierWave(-190,-82, -175,-77, -160,-77, -145,-82, 20);
    drawBezierWave(-145,-82, -132,-87, -120,-87, -105,-82, 20);
    glPopMatrix();

    // Wave 2
    glPushMatrix();
    glTranslatef(moveWave[1], 0, 0);
    drawBezierWave(-100,-88, -83,-83, -67,-83, -50,-88, 20);
    drawBezierWave(-50,-88, -38,-93, -25,-93, -10,-88, 20);
    glPopMatrix();

    // Wave 3
    glPushMatrix();
    glTranslatef(moveWave[2], 0, 0);
    drawBezierWave(-20,-80, -5,-75, 12,-75, 28,-80, 20);
    drawBezierWave(28,-80, 45,-85, 60,-85, 78,-80, 20);
    glPopMatrix();

    // Wave 4
    glPushMatrix();
    glTranslatef(moveWave[3], 0, 0);
    drawBezierWave(60,-92, 88,-87, 118,-87, 148,-92, 20);
    drawBezierWave(148,-92, 165,-97, 180,-97, 198,-92, 20);
    glPopMatrix();

    // Wave 5
    glPushMatrix();
    glTranslatef(moveWave[4], 0, 0);
    drawBezierWave(-170,-78, -152,-73, -135,-73, -118,-78, 20);
    drawBezierWave(-118,-78, -103,-83, -88,-83, -72,-78, 20);
    glPopMatrix();

    // Wave 6
    glPushMatrix();
    glTranslatef(moveWave[5], 0, 0);
    drawBezierWave(0,-85, 15,-80, 32,-80, 50,-85, 20);
    drawBezierWave(50,-85, 65,-90, 80,-90, 98,-85, 20);
    glPopMatrix();

    // Wave 7
    glPushMatrix();
    glTranslatef(moveWave[6], 0, 0);
    drawBezierWave(100,-78, 118,-73, 135,-73, 155,-78, 20);
    drawBezierWave(155,-78, 172,-83, 188,-83, 205,-78, 20);
    glPopMatrix();

    glPopMatrix();
}


void moveRiver(int value) // AF1
{
    for(int i = 0; i < 7; i++)
    {
        moveWave[i] += waveSpeed[i];
        if(moveWave[i] > 400) moveWave[i] -= 400;
    }

    glutPostRedisplay();
    glutTimerFunc(20, moveRiver, 0);
}





//////////////////////////////////////////////////////////////////////    ROAD
void Road(float x, float y, float scale)//obj4
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);


    glColor3ub(50, 50, 50);
    glBegin(GL_POLYGON);
    glVertex2f(-200, 0);
    glVertex2f(200, 0);
    glVertex2f(200, -60);
    glVertex2f(-200, -60);
    glEnd();


    glColor3ub(255, 255, 255);
    float dashLength = 5.0f;
    float gap = 5.0f;
    float startX = -195;

    for(int i = 0; i < 80; i++)
    {
    glBegin(GL_LINES);
    glVertex2f(startX, -30);
    glVertex2f(startX + dashLength, -30);
    glEnd();

    startX += dashLength + gap;
    }

    glPopMatrix();
}

int nlRoad = 1;

void RoadLight(float x, float y, float scale)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);

    // Base
    glColor3ub(50, 50, 50);
    glBegin(GL_POLYGON);
        glVertex2f(-1, 0);
        glVertex2f(4, 0);
        glVertex2f(3.8, 0.4);
        glVertex2f(-0.8, 0.4);
    glEnd();

    // Base top
    glColor3ub(180, 180, 180);
    glBegin(GL_POLYGON);
        glVertex2f(-0.8, 0.4);
        glVertex2f(3.8, 0.4);
        glVertex2f(2.5, 3);
        glVertex2f(0.5, 3);
    glEnd();

    // Pole of the light
    glColor3ub(180, 180, 180);
    glBegin(GL_POLYGON);
        glVertex2f(1, 3);
        glVertex2f(2, 3);
        glVertex2f(2, 15);
        glVertex2f(1, 15);
    glEnd();

    // Light part
    if (nlRoad == 1)
        glColor3ub(255, 220, 120); // yellow
    else
        glColor3ub(200, 220, 255); // off
    glBegin(GL_POLYGON);
        glVertex2f(0.8, 15);
        glVertex2f(2.2, 15);
        glVertex2f(3.5, 19);
        glVertex2f(-0.5, 19);
    glEnd();

    // Top
    glColor3ub(180, 180, 180);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, 19);
        glVertex2f(3.5, 19);
        glVertex2f(2.2, 20);
        glVertex2f(0.8, 20);
    glEnd();

    glPopMatrix();
}


void CallingRoadLight()  //obj5
{
    RoadLight(0, 0, 1);
	RoadLight(35, 0, 1);
	RoadLight(70, 0, 1);
	RoadLight(105, 0, 1);
	RoadLight(140, 0, 1);
	RoadLight(175, 0, 1);
	RoadLight(-35, 0, 1);
	RoadLight(-70, 0, 1);
	RoadLight(-105, 0, 1);
	RoadLight(-140, 0, 1);
	RoadLight(-175, 0, 1);

}




//////////////////////////////////////////////////////////////////////     CLOUDS

float moveCloud1 = 0.0f;
float moveCloud2 = 0.0f;
float moveCloud3 = 0.0f;
float moveCloud4 = 0.0f;

float speedCloud = 0.0f;
int moveClouds = -1;



void Cloud1(float y, float scale)//obj6
{
    glPushMatrix();
    glTranslatef(moveCloud1, y, 0);
    glScalef(scale, scale, 1);
    if(nightSky == - 1)
    {
        glColor3ub(220, 220, 220);
    }
    else
    glColor3ub(51, 64, 89);
    Circle(-150, 70, 9);
    Circle(-138, 72, 11);
    Circle(-125, 70, 9);
    Circle(-132, 67, 7);
    Circle(-145, 67, 6);
    glPopMatrix();
}

void Cloud2(float y, float scale)//obj7
{
    glPushMatrix();
    glTranslatef(moveCloud2, y, 0);
    glScalef(scale, scale, 1);
    if(nightSky == - 1)
    {
        glColor3ub(220, 220, 220);
    }
    else
    glColor3ub(51, 64, 89);
    Circle(-60, 70, 10);
    Circle(-70, 68, 8);
    Circle(-50, 68, 8);
    Circle(-65, 75, 7);
    Circle(-55, 75, 7);
    glPopMatrix();
}

void Cloud3(float y, float scale)//obj8
{
    glPushMatrix();
    glTranslatef(moveCloud3, y, 0);
    glScalef(scale, scale, 1);
    if(nightSky == - 1)
    {
        glColor3ub(220, 220, 220);
    }
    else
    glColor3ub(51, 64, 89);
    Circle(-5, 80, 10);
    Circle(-10, 68, 8);
    Circle(0, 68, 8);
    glPopMatrix();
}

void Cloud4(float y, float scale)//obj9
{
    glPushMatrix();
    glTranslatef(moveCloud4, y, 0);
    glScalef(scale, scale, 1);
    if(nightSky == - 1)
    {
        glColor3ub(220, 220, 220);
    }
    else
    glColor3ub(51, 64, 89);
    Circle(110, 70, 7);
    Circle(118, 73, 9);
    Circle(125, 68, 6);
    Circle(133, 70, 8);
    Circle(126, 76, 6);
    glPopMatrix();
}

void moveCloud(int value)  // AF2
{

if(moveClouds == 1)
{
    moveCloud1 += 0.5f + speedCloud ;
    moveCloud2 += 0.3f+ speedCloud ;
    moveCloud3 += 0.4f+ speedCloud ;
    moveCloud4 += 0.3f+ speedCloud ;


    if(speedCloud >1)
    {
    if(moveCloud1 > 360) moveCloud1 = -120;
    if(moveCloud2 > 300) moveCloud2 = -170;
    if(moveCloud3 > 240) moveCloud3 = -230;
    if(moveCloud4 > 100) moveCloud4 = -350;
    }

    else
    {
    if(moveCloud1 < -360) moveCloud1 = 120;
    if(moveCloud2 < -300) moveCloud2 = 170;
    if(moveCloud3 < -240) moveCloud3 = 230;
    if(moveCloud4 < -100) moveCloud4 = 350;

    }

}



    glutPostRedisplay();
    glutTimerFunc(20, moveCloud, 0);
}





////////////////////////////////////////////////////////////////////////   CAR
int   dirCar1 = -1;    // Car1
float speedCar1 = 0.0f;
float moveCar1  = 0.0f;
float angle1 = 0.0f;
float wheelSpeed1 = 0.0f;

int hlCar1 = 1;
int blCar1 = 1;


int   dirCar2 = 1;  // Car2
float speedCar2 = 0.0f;
float moveCar2  = 0.0f;
float angle2 = 0.0f;
float wheelSpeed2 = 0.0f;

int hlCar2 = 1;
int blCar2 = 1;

float accel = 0.3f;
float maxSpeed = 6.0f;

void moveCar(int value) // AF3
{
    moveCar1 += dirCar1 * speedCar1;
    moveCar2 += dirCar2 * speedCar2;

    // Move
    if(moveCar1 > 360)  moveCar1 = -360;
    if(moveCar1 < -360) moveCar1 = 360;

    if(moveCar2 > 360)  moveCar2 = -360;
    if(moveCar2 < -360) moveCar2 = 360;

    // brake and backlight
    if(speedCar1 == 0)
    blCar1 = 1;
    else
    blCar1 = 0;

    if(speedCar2 == 0)
    blCar2 = 1;
    else
    blCar2 = 0;

    // wheel speed sync
    wheelSpeed1 = speedCar1 * 1.5f;
    wheelSpeed2 = speedCar2 * 1.5f;

    glutPostRedisplay();
    glutTimerFunc(20, moveCar, 0);
}
void updateWheelRotation(int value) // AF4
{
    if(speedCar1 > 0)
        angle1 += dirCar1 * wheelSpeed1*(-1);

    if(speedCar2 > 0)
        angle2 += dirCar2 * wheelSpeed2*(-1);

    if(angle1 >= 360) angle1 -= 360;
    if(angle1 < 0)    angle1 += 360;

    if(angle2 >= 360) angle2 -= 360;
    if(angle2 < 0)    angle2 += 360;

    glutPostRedisplay();
    glutTimerFunc(16, updateWheelRotation, 0);
}

void Wheel(float x, float y, float r , float angle)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Tyre Outer
    glColor3ub(30, 30, 30); // dark tyre
    Circle(0, 0, r);

    // Rim
    glColor3ub(180, 180, 180);
    Circle(0, 0, r * 0.7f);

    // Center Cap
    glColor3ub(220, 220, 220);
    Circle(0, 0, r * 0.15f);

    // Spokes
    glLineWidth(2);
    glColor3ub(200, 200, 200);

    glBegin(GL_LINES);
        glVertex2f(0, 0); glVertex2f( r*0.7f, 0);
        glVertex2f(0, 0); glVertex2f(-r*0.7f, 0);
        glVertex2f(0, 0); glVertex2f(0,  r*0.7f);
        glVertex2f(0, 0); glVertex2f(0, -r*0.7f);
    glEnd();

    glPopMatrix();
}

void CarBody1()
{
    glColor3ub(80, 200, 170);  //body
    glBegin(GL_POLYGON);
    glVertex2f(130, -18);
    glVertex2f(135, -10);
    glVertex2f(155, -10);
    glVertex2f(160, -18);
    glVertex2f(170, -18);
    glVertex2f(170, -25);
    glVertex2f(110, -25);
    glVertex2f(116, -18);
    glEnd();


    //windows
    glColor3ub(200, 235, 255);
    glBegin(GL_POLYGON);
    glVertex2f(134, -18);
    glVertex2f(144, -18);
    glVertex2f(144, -11);
    glVertex2f(138, -11);
    glEnd();


     glBegin(GL_POLYGON);
    glVertex2f(146, -18);
    glVertex2f(156, -18);
    glVertex2f(152, -11);
    glVertex2f(146, -11);
    glEnd();




    if(hlCar1 == 1)     //headlight
    {
    glBegin(GL_POLYGON);
    glColor4ub(120, 100, 50, 50);
    glVertex2f(96, -26);
    glVertex2f(114.3, -20);
    glVertex2f(116, -18);
    glVertex2f(96, -12);
    glEnd();
        glColor3ub(255, 255, 200);
    }
    else
    {
        glColor3ub(120, 120, 120);
    }
    glBegin(GL_POLYGON);
    glVertex2f(114.3, -20);
    glVertex2f(119, -20);
    glVertex2f(120, -18);
    glVertex2f(116, -18);
    glEnd();

    if(blCar1 == 1)
    {
        glColor3ub(200, 0, 0);

    }
    else
    {
        glColor3ub(90, 90, 90);   // dark gray

    }

    glBegin(GL_POLYGON);  //headlight
    glVertex2f(166, -20);
    glVertex2f(170, -20);
    glVertex2f(170, -18);
    glVertex2f(166, -18);
    glEnd();



}

void Car1(float y, float scale)//obj10
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(moveCar1, y, 0);
    glScalef(scale, scale, 1);

    CarBody1();
    Wheel(123, -23, 4, angle1);
    Wheel(161, -23, 4, angle1);

    glPopMatrix();
}

void CarBody2()
{
    glColor3ub(0, 0, 0);  //Head
    glBegin(GL_POLYGON);
    glVertex2f(-90, -55);
    glVertex2f(-70, -55);
    glVertex2f(-70, -45);
    glVertex2f(-90, -45);
    glEnd();


    //windows
    glColor3ub(180, 220, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-90, -45);
    glVertex2f(-70, -45);
    glVertex2f(-79, -36);
    glVertex2f(-90, -36);
    glEnd();


    glColor3ub(255, 190, 120); //back
    glBegin(GL_POLYGON);
    glVertex2f(-130, -50);
    glVertex2f(-90, -50);
    glVertex2f(-90, -25);
    glVertex2f(-130, -25);
    glEnd();


    glColor3ub(0, 0, 0); //bottom
    glBegin(GL_POLYGON);
    glVertex2f(-130, -55);
    glVertex2f(-90, -55);
    glVertex2f(-90, -50);
    glVertex2f(-130, -50);
    glEnd();


    if(hlCar2 == 1)     //headlight
    {
        glBegin(GL_POLYGON);
        glColor4ub(120, 100, 50, 50);
        glVertex2f(-70, -48);
        glVertex2f(-48, -54);
        glVertex2f(-48, -36);
        glVertex2f(-70, -45);
        glEnd();
        glColor3ub(255, 255, 200);
    }
    else
    {
        glColor3ub(120, 120, 120);
    }
    glBegin(GL_POLYGON);
    glVertex2f(-74, -48);
    glVertex2f(-70, -48);
    glVertex2f(-70, -45);
    glVertex2f(-74, -45);
    glEnd();

    if(blCar2 == 1)
    {
        glColor3ub(200, 0, 0);

    }
    else
    {
        glColor3ub(90, 90, 90);   // dark gray

    }

    glBegin(GL_POLYGON);  //headlight
    glVertex2f(-130, -52);
    glVertex2f(-126, -52);
    glVertex2f(-126, -50);
    glVertex2f(-130, -50);
    glEnd();


}

void Car2(float y, float scale)//obj11
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(moveCar2, y, 0);
    glScalef(scale, scale, 1);

    CarBody2();
    Wheel(-78, -53, 5, angle2);
    Wheel(-118, -53, 5, angle2);

    glPopMatrix();
}






/////////////////////////////////////////////////////////////////////   STARS
int callStars = 1;

void Stars()
{
    glColor3ub(255, 255, 255);

    float starsNight[26][2] = {
        {-190, 92}, {-186, 74}, {-170, 84}, {-151, 72}, {-136, 89},
        {-115, 72}, {-111, 91}, {-94, 85},  {-73, 87},  {-53, 78},
        {-35, 89},  {-28, 78},  {-19, 90},  {6, 83},
        {20, 87},   {25, 95},   {34, 76},   {47, 87},
        {92, 85},   {104, 76},  {109, 87},  {126, 81},
        {141, 91},  {160, 86},  {177, 75},  {186, 92}
    };

    float starsDay[15][2] = {
        {-170, 84}, {-136, 89}, {-151, 72},
        {-111, 91}, {-73, 87}, {-53, 78},
        {-35, 89},  {-19, 90}, {6, 83},
        {20, 87},
        {92, 85},   {109, 87},
        {141, 91}, {160, 86},  {186, 92}
    };

    if (nightSky == 1)
    {
        for(int i = 0; i < 26; i++)
        {
            Circle(starsNight[i][0], starsNight[i][1], 1.5);
        }
    }
    else
    {
        for(int i = 0; i < 15; i++)
        {
            Circle(starsDay[i][0], starsDay[i][1], 1.5);
        }
    }
}

void CallingStars()//obj12
{
    if(callStars == 1)
    {
        Stars();
    }
}




/////////////////////////////////////////////////////////////////////   BOAT
int nlBoat = 1;
float boatSpeed = 0;
int moveBoat = -1;

void BoatMovement(int value) // AF5
{
     if(moveBoat == 1)
    {
        boatSpeed  -= 1.2f;
        if(boatSpeed < -400) boatSpeed = +230;
    }

    glutPostRedisplay();
    glutTimerFunc(20, BoatMovement, 0);
}

void Boat(float y, float scale)//obj13
{
    glPushMatrix();

    glTranslatef(boatSpeed, y, 0);
    glScalef(scale, scale, 1);

    glColor3ub(20, 20, 20); //Bottom
    glBegin(GL_POLYGON);
    glVertex2f(60, -95);
    glVertex2f(40, -85);
    glVertex2f(180, -85);
    glVertex2f(170, -95);
    glEnd();

    glColor3ub(235, 235, 235); //Top
    glBegin(GL_POLYGON);
    glVertex2f(70, -85);
    glVertex2f(70, -78);
    glVertex2f(170, -78);
    glVertex2f(170, -85);
    glEnd();


    glColor3ub(180, 200, 220); //Under Chimni
    glBegin(GL_POLYGON);
    glVertex2f(75, -78);
    glVertex2f(75, -75);
    glVertex2f(165, -75);
    glVertex2f(165, -78);
    glEnd();



    glColor3ub(40, 40, 40); // Chimni1
    glBegin(GL_POLYGON);
    glVertex2f(85, -75);
    glVertex2f(90, -65);
    glVertex2f(100, -65);
    glVertex2f(95, -75);
    glEnd();



    glBegin(GL_POLYGON); // Chimni2
    glVertex2f(112.5, -75);
    glVertex2f(118, -65);
    glVertex2f(127, -65);
    glVertex2f(122, -75);
    glEnd();


    glBegin(GL_POLYGON); // Chimni3
    glVertex2f(140, -75);
    glVertex2f(145, -65);
    glVertex2f(155, -65);
    glVertex2f(150, -75);
    glEnd();


    glColor3ub(60, 80, 120); // Door
    glBegin(GL_POLYGON);
    glVertex2f(80, -85);
    glVertex2f(80, -80);
    glVertex2f(85, -80);
    glVertex2f(85, -85);
    glEnd();



    //window

    if(nlBoat == 1)
         glColor3ub(255, 220, 120);
    else
         glColor3ub(180, 220, 255);
    glBegin(GL_POLYGON);
    glVertex2f(95, -82);
    glVertex2f(95, -80);
    glVertex2f(115, -80);
    glVertex2f(115, -82);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(120, -82);
    glVertex2f(120, -80);
    glVertex2f(140, -80);
    glVertex2f(140, -82);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(145, -82);
    glVertex2f(145, -80);
    glVertex2f(168, -80);
    glVertex2f(168, -82);
    glEnd();


    glPopMatrix();

}





/////////////////////////////////////////////////////////////////////   SUNMOON
int callMoon = 1;
float moveSunMoon =40;

void moveSunMoonLocation(int value) //AF6
{

    moveSunMoon += 0.5f;

    if(moveSunMoon > 80) moveSunMoon = 80;

    glutPostRedisplay();
    glutTimerFunc(20, moveSunMoonLocation, 0);
}

void SunMoon(float x, float y, float scale)//obj14
{
    glPushMatrix();
    glTranslatef(x, moveSunMoon, 0);
    glScalef(scale, scale, 1);

    if(nightSky == 1)
    glColor3ub(245, 245, 220);
    else
    glColor3ub(255, 100, 60);


    // Circle 1

    Circle(0, 0, 12);

    // Circle 2
    if(nightSky == 1)
    {
    glColor3ub(10, 15, 40);
    Circle(-4, 2, 10);
    }



    glPopMatrix();
}

void CallingSunMoon(float x, float y, float scale)
{
    if(callMoon == 1)
    {
        SunMoon(x, y, scale);
    }
}





/////////////////////////////////////////////////////////////////////   TREE
float leafOffset = 0.0f;
int moveLeaf = 1;
void DrawTrunk()
{
    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-170, 0);
    glVertex2f(-168, 0);
    glVertex2f(-168, 4.2);
    glVertex2f(-170, 4.2);
    glEnd();
}

void DrawLeaves()
{
    if(moveLeaf == -1)
    {
        leafOffset = 0;
    }
    glColor3ub(0, 153, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-174 - leafOffset, 4.2);
    glVertex2f(-164 - leafOffset, 4.2);
    glVertex2f(-169 - leafOffset, 8.2);
    glEnd();

    glColor3ub(0, 130, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-173 + leafOffset, 6.2);
    glVertex2f(-165 + leafOffset, 6.2);
    glVertex2f(-169 + leafOffset, 10.2);
    glEnd();

    glColor3ub(0, 153, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-172 - leafOffset, 9.2);
    glVertex2f(-166 - leafOffset, 9.2);
    glVertex2f(-169 - leafOffset, 12.2);
    glEnd();

    glColor3ub(0, 130, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-171 + leafOffset, 11.2);
    glVertex2f(-167 + leafOffset, 11.2);
    glVertex2f(-169 + leafOffset, 13.7);
    glEnd();



}


void DrawTree(float x, float y, float scale)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, 1);
    DrawTrunk();
    DrawLeaves();
    glPopMatrix();
}

void timer(int value) //AF7
{
    leafOffset = 0.2*sin(value*0.1f);
    glutPostRedisplay();
    glutTimerFunc(30,timer,value+1);
}

void CallingTree() //obj15
{
    DrawTree(0, 0, 1);
    DrawTree(50, 10, 1);
    DrawTree(70, 5, 1);
    DrawTree(100, 0, 1);
    DrawTree(160, 10, 1);
    DrawTree(230, 20, 1);
    DrawTree(250, 5, 1);
    DrawTree(290, 10, 1);
    DrawTree(340, 20, 1);
    DrawTree(360, 10, 1);
}






/////////////////////////////////////////////////////////////////////   BUILDING
int ntWindow = -1;
int nlBuilding1 = 1;
int nlBuilding2 = -1;
int nlBuilding3 = -1;
int nlBuilding4 = 1;
int nlBuilding5 = 1;
int nlBuilding6 = -1;
int nlBuilding7 = 1;

int nlBackBuilding1 = 1;
int nlBackBuilding2 = 1;
int nlBackBuilding3 = -1;
int nlBackBuilding4 = 1;
void Building1(float x, float y, float scalex, float scaley)//obj16
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scalex, scaley, 1);

    glColor3ub(160,0,0); //left Side
    glBegin(GL_POLYGON);
    glVertex2f(-200, 40);
    glVertex2f(-196, 40);
    glVertex2f(-196, 10);
    glVertex2f(-200, 10);
    glEnd();

    glColor3ub(0,0,180); //right Side
    glBegin(GL_POLYGON);
    glVertex2f(-196, 38);
    glVertex2f(-180, 38);
    glVertex2f(-180, 10);
    glVertex2f(-196, 10);
    glEnd();


    //window

    if(nlBuilding1 == 1)
         glColor3ub(255, 220, 120);
    else
         glColor3ub(190, 200, 215);



    glBegin(GL_POLYGON);
    glVertex2f(-194, 36);
    glVertex2f(-190, 36);
    glVertex2f(-190, 30);
    glVertex2f(-194, 30);
    glEnd();

    if(ntWindow == 1)
        glColor3ub(255, 255, 255 );
    else
         glColor3ub(190, 200, 215);
     //200, 220, 255
    glBegin(GL_POLYGON);
    glVertex2f(-186, 36);
    glVertex2f(-182, 36);
    glVertex2f(-182, 30);
    glVertex2f(-186, 30);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-194, 26);
    glVertex2f(-190, 26);
    glVertex2f(-190, 20);
    glVertex2f(-194, 20);
    glEnd();

    if(nlBuilding1 == 1)
         glColor3ub(255, 220, 120);
    else
         glColor3ub(190, 200, 215);

    glBegin(GL_POLYGON);
    glVertex2f(-186, 26);
    glVertex2f(-182, 26);
    glVertex2f(-182, 20);
    glVertex2f(-186, 20);
    glEnd();

    //glColor3ub(0,0,0); //door
    glColor3ub(150, 105, 65);
    glBegin(GL_POLYGON);
    glVertex2f(-186, 18);
    glVertex2f(-182, 18);
    glVertex2f(-182, 10);
    glVertex2f(-186, 10);
    glEnd();



    glColor3ub(0,0,0); //roof
    glBegin(GL_POLYGON);
    glVertex2f(-200, 38);
    glVertex2f(-200, 40);
    glVertex2f(-180, 40);
    glVertex2f(-180, 38);
    glEnd();


    glPopMatrix();
}

void Building2(float x, float y, float scalex, float scaley)//obj17
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scalex, scaley, 1);

    glColor3ub(180,0,0); //left Side
    glBegin(GL_POLYGON);
    glVertex2f(-125, 48);
    glVertex2f(-125, 10);
    glVertex2f(-150, 10);
    glVertex2f(-150, 45);
    glVertex2f(-155, 45);
    glVertex2f(-155, 48);
    glEnd();

    glColor3ub(0,0,200); //right Side
    glBegin(GL_POLYGON);
    glVertex2f(-125, 48);
    glVertex2f(-125, 10);
    glVertex2f(-147, 10);
    glVertex2f(-147, 46.5);
    glVertex2f(-150, 46.5);
    glVertex2f(-150, 48);
    glEnd();


                         //window
    if(ntWindow == 1)
        glColor3ub(255, 255, 255 );
    else
         glColor3ub(190, 200, 215);
    glBegin(GL_POLYGON);
    glVertex2f(-144, 46);
    glVertex2f(-138, 46);
    glVertex2f(-138, 38);
    glVertex2f(-144, 38);
    glEnd();
    if(nlBuilding2 == 1)
         glColor3ub(255, 220, 120);
    else
         glColor3ub(190, 200, 215);
    glBegin(GL_POLYGON);
    glVertex2f(-134, 46);
    glVertex2f(-128, 46);
    glVertex2f(-128, 38);
    glVertex2f(-134, 38);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-144, 34);
    glVertex2f(-138, 34);
    glVertex2f(-138, 26);
    glVertex2f(-144, 26);
    glEnd();

    if(ntWindow == 1)
        glColor3ub(255, 255, 255 );
    else
         glColor3ub(190, 200, 215);
    glBegin(GL_POLYGON);
    glVertex2f(-134, 34);
    glVertex2f(-128, 34);
    glVertex2f(-128, 26);
    glVertex2f(-134, 26);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-144, 22);
    glVertex2f(-138, 22);
    glVertex2f(-138, 14);
    glVertex2f(-144, 14);
    glEnd();

     if(nlBuilding2 == 1)
         glColor3ub(255, 220, 120);
    else
         glColor3ub(190, 200, 215);
    glBegin(GL_POLYGON);
    glVertex2f(-134, 22);
    glVertex2f(-128, 22);
    glVertex2f(-128, 14);
    glVertex2f(-134, 14);
    glEnd();

    glPopMatrix();
}

void Building3(float x, float y, float scalex, float scaley)//obj18
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scalex, scaley, 1);

    glColor3f(0.1f, 0.5f, 0.9f);
    glBegin(GL_QUADS);
        glVertex2f(-110, 10);
        glVertex2f(-75, 10);
        glVertex2f(-75, 60);
        glVertex2f(-110, 60);
    glEnd();


    glColor3f(0.5f, 0.6f, 0.8f);
    glBegin(GL_LINES);
        glVertex2f(-110, 55); glVertex2f(-75, 55);
        glVertex2f(-110, 50); glVertex2f(-75, 50);
        glVertex2f(-110, 45); glVertex2f(-75, 45);
        glVertex2f(-110, 40); glVertex2f(-75, 40);
        glVertex2f(-110, 35); glVertex2f(-75, 35);
        glVertex2f(-110, 30); glVertex2f(-75, 30);
        glVertex2f(-110, 25); glVertex2f(-75, 25);
        glVertex2f(-110, 20); glVertex2f(-75, 20);
        glVertex2f(-110, 15); glVertex2f(-75, 15);
    glEnd();

    if(nlBuilding3 == 1)
    {
    glColor3ub(255, 220, 120);

    glBegin(GL_POLYGON);
    glVertex2f(-104, 56);
    glVertex2f(-102, 56);
    glVertex2f(-102, 59);
    glVertex2f(-104, 59);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-98, 51);
    glVertex2f(-96, 51);
    glVertex2f(-96, 54);
    glVertex2f(-98, 54);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-86, 51);
    glVertex2f(-84, 51);
    glVertex2f(-84, 54);
    glVertex2f(-86, 54);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-101, 46);
    glVertex2f(-99, 46);
    glVertex2f(-99, 49);
    glVertex2f(-101, 49);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-92, 41);
    glVertex2f(-90, 41);
    glVertex2f(-90, 44);
    glVertex2f(-92, 44);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-101, 31);
    glVertex2f(-99, 31);
    glVertex2f(-99, 34);
    glVertex2f(-101, 34);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-94, 31);
    glVertex2f(-92, 31);
    glVertex2f(-92, 34);
    glVertex2f(-94, 34);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-86, 31);
    glVertex2f(-84, 31);
    glVertex2f(-84, 34);
    glVertex2f(-86, 34);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-94, 21);
    glVertex2f(-92, 21);
    glVertex2f(-92, 24);
    glVertex2f(-94, 24);
    glEnd();

    }


    glPopMatrix();
}

void Building4(float x, float y, float scalex, float scaley)//obj19
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scalex, scaley, 1);

    // Left Side
    glColor3ub(190, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-45, 10);
    glVertex2f(-38, 10);
    glVertex2f(-38, 60);
    glVertex2f(-45, 60);
    glEnd();

    // Right Side
    glColor3ub(0, 0, 200);
    glBegin(GL_POLYGON);
    glVertex2f(-38, 10);
    glVertex2f(-17, 10);
    glVertex2f(-17, 60);
    glVertex2f(-38, 60);
    glEnd();

    // Windows
   if(nlBuilding4 == 1)
         glColor3ub(255, 220, 120);
    else
         glColor3ub(190, 200, 215);

    // Top row
    glBegin(GL_POLYGON);
    glVertex2f(-36, 50); glVertex2f(-32, 50);
    glVertex2f(-32, 54); glVertex2f(-36, 54);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-30, 50); glVertex2f(-26, 50);
    glVertex2f(-26, 54); glVertex2f(-30, 54);
    glEnd();




    glBegin(GL_POLYGON);
    glVertex2f(-24, 50); glVertex2f(-20, 50);
    glVertex2f(-20, 54); glVertex2f(-24, 54);
    glEnd();

    // Middle row
    glBegin(GL_POLYGON);
    glVertex2f(-36, 38); glVertex2f(-32, 38);
    glVertex2f(-32, 42); glVertex2f(-36, 42);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-30, 38); glVertex2f(-26, 38);
    glVertex2f(-26, 42); glVertex2f(-30, 42);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-24, 38); glVertex2f(-20, 38);
    glVertex2f(-20, 42); glVertex2f(-24, 42);
    glEnd();

    // Bottom row
    glBegin(GL_POLYGON);
    glVertex2f(-36, 26); glVertex2f(-32, 26);
    glVertex2f(-32, 30); glVertex2f(-36, 30);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-30, 26); glVertex2f(-26, 26);
    glVertex2f(-26, 30); glVertex2f(-30, 30);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-24, 26); glVertex2f(-20, 26);
    glVertex2f(-20, 30); glVertex2f(-24, 30);
    glEnd();

    // Window Lines
    glColor3ub(0, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-36, 48); glVertex2f(-20, 48);
    glVertex2f(-36, 36); glVertex2f(-20, 36);
    glVertex2f(-36, 24); glVertex2f(-20, 24);
    glEnd();

    // Door
    glBegin(GL_POLYGON);
    glVertex2f(-30, 10);
    glVertex2f(-26, 10);
    glVertex2f(-26, 20);
    glVertex2f(-30, 20);
    glEnd();

    // Roof
    glBegin(GL_POLYGON);
    glVertex2f(-45, 58);
    glVertex2f(-17, 58);
    glVertex2f(-17, 60);
    glVertex2f(-45, 60);
    glEnd();

    glPopMatrix();
}

void Building5(float x, float y, float scalex, float scaley)//obj20
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scalex, scaley, 1);

    glColor3ub(200,0,0); //left Side
    glBegin(GL_POLYGON);
    glVertex2f(0, 10);
    glVertex2f(0, 50);
    glVertex2f(46, 50);
    glVertex2f(46, 10);
    glEnd();

    glColor3ub(0,0,180); //right Side
    glBegin(GL_POLYGON);
    glVertex2f(46, 50);
    glVertex2f(46, 10);
    glVertex2f(55, 10);
    glVertex2f(55, 50);
    glEnd();


    //window

    if(nlBuilding5 == 1)
         glColor3ub(255, 220, 120);
    else
         glColor3ub(190, 200, 215);

//////////////////row 1

    glBegin(GL_POLYGON);
    glVertex2f(4, 40);
    glVertex2f(8, 40);
    glVertex2f(8, 46);
    glVertex2f(4, 46);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(12, 40);
    glVertex2f(16, 40);
    glVertex2f(16, 46);
    glVertex2f(12, 46);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(20, 40);
    glVertex2f(24, 40);
    glVertex2f(24, 46);
    glVertex2f(20, 46);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(28, 40);
    glVertex2f(32, 40);
    glVertex2f(32, 46);
    glVertex2f(28, 46);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(36, 40);
    glVertex2f(40, 40);
    glVertex2f(40, 46);
    glVertex2f(36, 46);
    glEnd();

///////////////row 2
    glBegin(GL_POLYGON);
    glVertex2f(4, 30);
    glVertex2f(8, 30);
    glVertex2f(8, 36);
    glVertex2f(4, 36);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(12, 30);
    glVertex2f(16, 30);
    glVertex2f(16, 36);
    glVertex2f(12, 36);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(20, 30);
    glVertex2f(24, 30);
    glVertex2f(24, 36);
    glVertex2f(20, 36);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(28, 30);
    glVertex2f(32, 30);
    glVertex2f(32, 36);
    glVertex2f(28, 36);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(36, 30);
    glVertex2f(40, 30);
    glVertex2f(40, 36);
    glVertex2f(36, 36);
    glEnd();

////////////////////// row 3

    glBegin(GL_POLYGON);
    glVertex2f(4, 20);
    glVertex2f(8, 20);
    glVertex2f(8, 26);
    glVertex2f(4, 26);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(12, 20);
    glVertex2f(16, 20);
    glVertex2f(16, 26);
    glVertex2f(12, 26);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(20, 20);
    glVertex2f(24, 20);
    glVertex2f(24, 26);
    glVertex2f(20, 26);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(28, 20);
    glVertex2f(32, 20);
    glVertex2f(32, 26);
    glVertex2f(28, 26);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(36, 20);
    glVertex2f(40, 20);
    glVertex2f(40, 26);
    glVertex2f(36, 26);
    glEnd();



    glColor3ub(0,0,0); //roof
    glBegin(GL_POLYGON);
    glVertex2f(0, 50);
    glVertex2f(55, 50);
    glVertex2f(55, 52);
    glVertex2f(0, 52);
    glEnd();


    glPopMatrix();
}
void Building6(float x, float y, float scalex, float scaley)//obj21
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scalex, scaley, 1);

    glColor3ub(200,0,0); //left Side
    glBegin(GL_POLYGON);
    glVertex2f(70, 10);
    glVertex2f(90, 10);
    glVertex2f(90, 60);
    glVertex2f(70, 60);
    glEnd();

    glColor3ub(0,0,180); //right Side
    glBegin(GL_POLYGON);
    glVertex2f(90, 10);
    glVertex2f(90, 60);
    glVertex2f(100, 60);
    glVertex2f(100, 10);
    glEnd();


                          //window

    //Left Window
    if(nlBuilding6 == 1)
         glColor3ub(255, 220, 120);
    else
         glColor3ub(190, 200, 215);

    glBegin(GL_POLYGON);
    glVertex2f(74, 52);
    glVertex2f(78, 52);
    glVertex2f(78, 56);
    glVertex2f(74, 56);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(82, 52);
    glVertex2f(86, 52);
    glVertex2f(86, 56);
    glVertex2f(82, 56);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(74, 44);
    glVertex2f(78, 44);
    glVertex2f(78, 48);
    glVertex2f(74, 48);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(82, 44);
    glVertex2f(86, 44);
    glVertex2f(86, 48);
    glVertex2f(82, 48);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(74, 36);
    glVertex2f(78, 36);
    glVertex2f(78, 40);
    glVertex2f(74, 40);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(82, 36);
    glVertex2f(86, 36);
    glVertex2f(86, 40);
    glVertex2f(82, 40);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(74, 28);
    glVertex2f(78, 28);
    glVertex2f(78, 32);
    glVertex2f(74, 32);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(82, 28);
    glVertex2f(86, 28);
    glVertex2f(86, 32);
    glVertex2f(82, 32);
    glEnd();


    // Right Window

    if(ntWindow == 1)
        glColor3ub(255, 255, 255 );
    else
         glColor3ub(190, 200, 215);

    glBegin(GL_POLYGON);
    glVertex2f(92, 52);
    glVertex2f(94, 52);
    glVertex2f(94, 56);
    glVertex2f(92, 56);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(96, 52);
    glVertex2f(98, 52);
    glVertex2f(98, 56);
    glVertex2f(96, 56);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(92, 44);
    glVertex2f(94, 44);
    glVertex2f(94, 48);
    glVertex2f(92, 48);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(96, 44);
    glVertex2f(98, 44);
    glVertex2f(98, 48);
    glVertex2f(96, 48);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(92, 36);
    glVertex2f(94, 36);
    glVertex2f(94, 40);
    glVertex2f(92, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(96, 36);
    glVertex2f(98, 36);
    glVertex2f(98, 40);
    glVertex2f(96, 40);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(92, 28);
    glVertex2f(94, 28);
    glVertex2f(94, 32);
    glVertex2f(92, 32);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(92, 28);
    glVertex2f(94, 28);
    glVertex2f(94, 32);
    glVertex2f(92, 32);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(96, 28);
    glVertex2f(98, 28);
    glVertex2f(98, 32);
    glVertex2f(96, 32);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(92, 20);
    glVertex2f(94, 20);
    glVertex2f(94, 24);
    glVertex2f(92, 24);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(96, 20);
    glVertex2f(98, 20);
    glVertex2f(98, 24);
    glVertex2f(96, 24);
    glEnd();

    glColor3ub(0,0,0); //door
    glBegin(GL_POLYGON);
    glVertex2f(75, 10);
    glVertex2f(85, 10);
    glVertex2f(85, 25);
    glVertex2f(75, 25);
    glEnd();



    glColor3ub(0,0,0); //roof right
    glBegin(GL_POLYGON);
    glVertex2f(70, 60);
    glVertex2f(85, 75);
    glVertex2f(90, 60);
    glEnd();

    glColor3ub(200,200,0); //roof left
    glBegin(GL_POLYGON);
    glVertex2f(85, 75);
    glVertex2f(100, 60);
    glVertex2f(90, 60);
    glEnd();

    glColor3ub(0,200,0); //roof bottom
    glBegin(GL_POLYGON);
    glVertex2f(70, 60);
    glVertex2f(72, 64);
    glVertex2f(96, 64);
    glVertex2f(100, 60);
    glEnd();



    glPopMatrix();
}

void Building7(float x, float y, float scalex, float scaley)//obj22
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scalex, scaley, 1);

    glColor3ub(160,0,0); //left Side
    glBegin(GL_POLYGON);
    glVertex2f(125, 10);
    glVertex2f(130, 10);
    glVertex2f(130, 50);
    glVertex2f(125, 50);
    glEnd();

    glColor3ub(0,0,200); //right Side
    glBegin(GL_POLYGON);
    glVertex2f(130, 10);
    glVertex2f(130, 50);
    glVertex2f(155, 50);
    glVertex2f(155, 10);
    glEnd();


    //window
    if(nlBuilding7 == 1)
         glColor3ub(255, 220, 120);
    else
         glColor3ub(190, 200, 215);

    glBegin(GL_POLYGON);
    glVertex2f(138, 40);
    glVertex2f(142, 40);
    glVertex2f(142, 46);
    glVertex2f(138, 46);
    glEnd();

    if(ntWindow == 1)
        glColor3ub(255, 255, 255 );
    else
         glColor3ub(190, 200, 215);
    glBegin(GL_POLYGON);
    glVertex2f(148, 40);
    glVertex2f(152, 40);
    glVertex2f(152, 46);
    glVertex2f(148, 46);
    glEnd();

    if(nlBuilding7 == 1)
         glColor3ub(255, 220, 120);
    else
         glColor3ub(190, 200, 215);
    glBegin(GL_POLYGON);
    glVertex2f(134, 30);
    glVertex2f(138, 30);
    glVertex2f(138, 36);
    glVertex2f(134, 36);
    glEnd();

    if(ntWindow == 1)
        glColor3ub(255, 255, 255 );
    else
         glColor3ub(190, 200, 215);
    glBegin(GL_POLYGON);
    glVertex2f(144, 30);
    glVertex2f(148, 30);
    glVertex2f(148, 36);
    glVertex2f(144, 36);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(138, 20);
    glVertex2f(142, 20);
    glVertex2f(142, 26);
    glVertex2f(138, 26);
    glEnd();

    if(nlBuilding7 == 1)
         glColor3ub(255, 220, 120);
    else
         glColor3ub(190, 200, 215);
    glBegin(GL_POLYGON);
    glVertex2f(148, 20);
    glVertex2f(152, 20);
    glVertex2f(152, 26);
    glVertex2f(148, 26);
    glEnd();



    glPopMatrix();
}

void BackBuilding1(float x, float y, float scalex, float scaley)//obj23
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scalex, scaley, 1);

    glColor3ub(50, 70, 90); //left Side
    glBegin(GL_POLYGON);
    glVertex2f(-175, 20);
    glVertex2f(-170, 20);
    glVertex2f(-170, 65);
    glVertex2f(-175, 65);
    glEnd();

    glColor3ub(90, 120, 150); //right Side
    glBegin(GL_POLYGON);
    glVertex2f(-170, 20);
    glVertex2f(-170, 65);
    glVertex2f(-160, 65);
    glVertex2f(-160, 55);
    glVertex2f(-155, 50);
    glVertex2f(-155, 20);
    glEnd();


    if(nlBackBuilding1 == 1)
    {
    glColor3ub(255, 220, 120);

    glBegin(GL_POLYGON);
    glVertex2f(-168, 56);
    glVertex2f(-166, 56);
    glVertex2f(-166, 60);
    glVertex2f(-168, 60);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-164, 50);
    glVertex2f(-162, 50);
    glVertex2f(-162, 54);
    glVertex2f(-164, 54);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-166, 42);
    glVertex2f(-164, 42);
    glVertex2f(-164, 46);
    glVertex2f(-166, 46);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-162, 34);
    glVertex2f(-160, 34);
    glVertex2f(-160, 38);
    glVertex2f(-162, 38);
    glEnd();

    }


    glPopMatrix();
}

void BackBuilding2(float x, float y, float scalex, float scaley)//obj24
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scalex, scaley, 1);

    glColor3ub(110, 70, 40); //left Side
    glBegin(GL_POLYGON);
    glVertex2f(-60, 20);
    glVertex2f(-56, 20);
    glVertex2f(-56, 70);
    glVertex2f(-60, 70);
    glEnd();

    glColor3ub(160, 120, 80); //right Side
    glBegin(GL_POLYGON);
    glVertex2f(-56, 20);
    glVertex2f(-56, 70);
    glVertex2f(-45, 70);
    glVertex2f(-45, 65);
    glVertex2f(-40, 60);
    glVertex2f(-40, 20);
    glEnd();


    if(nlBackBuilding2 == 1)
    {
    glColor3ub(255, 220, 120);

    glBegin(GL_POLYGON);
    glVertex2f(-54, 62);
    glVertex2f(-52, 62);
    glVertex2f(-52, 66);
    glVertex2f(-54, 66);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-50, 54);
    glVertex2f(-48, 54);
    glVertex2f(-48, 58);
    glVertex2f(-50, 58);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-54, 42);
    glVertex2f(-52, 42);
    glVertex2f(-52, 46);
    glVertex2f(-54, 46);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-52, 32);
    glVertex2f(-50, 32);
    glVertex2f(-50, 36);
    glVertex2f(-52, 36);
    glEnd();


    }


    glPopMatrix();
}


void BackBuilding3(float x, float y, float scalex, float scaley)//obj25
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scalex, scaley, 1);

    glColor3ub(60, 90, 60);
    glBegin(GL_POLYGON);
    glVertex2f(80, 20);
    glVertex2f(80, 90);
    glVertex2f(70, 90);
    glVertex2f(65, 83);
    glVertex2f(65, 75);
    glVertex2f(60, 70);
    glVertex2f(60, 20);
    glEnd();


    if(nlBackBuilding3 == 1)
    {
    glColor3ub(255, 220, 120);

    glBegin(GL_POLYGON);
    glVertex2f(70, 76);
    glVertex2f(74, 76);
    glVertex2f(74, 82);
    glVertex2f(70, 82);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(64, 60);
    glVertex2f(68, 60);
    glVertex2f(68, 66);
    glVertex2f(64, 66);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(64, 46);
    glVertex2f(68, 46);
    glVertex2f(68, 52);
    glVertex2f(64, 52);
    glEnd();


    }


    glPopMatrix();
}


void BackBuilding4(float x, float y, float scalex, float scaley)//obj26
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scalex, scaley, 1);

    glColor3ub(170, 160, 90); //left Side
    glBegin(GL_POLYGON);
    glVertex2f(165, 20);
    glVertex2f(165, 80);
    glVertex2f(150, 80);
    glVertex2f(150, 60);
    glVertex2f(148, 56);
    glVertex2f(148, 20);
    glEnd();

    glColor3ub(120, 110, 60); //right Side
    glBegin(GL_POLYGON);
    glVertex2f(165, 20);
    glVertex2f(172, 20);
    glVertex2f(172, 70);
    glVertex2f(170, 75);
    glVertex2f(170, 80);
    glVertex2f(165, 80);
    glEnd();


    if(nlBackBuilding4 == 1)
    {
    glColor3ub(255, 220, 120);

    glBegin(GL_POLYGON);
    glVertex2f(154, 72);
    glVertex2f(156, 72);
    glVertex2f(156, 76);
    glVertex2f(154, 76);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(158, 64);
    glVertex2f(160, 64);
    glVertex2f(160, 68);
    glVertex2f(158, 68);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(152, 56);
    glVertex2f(154, 56);
    glVertex2f(154, 60);
    glVertex2f(152, 60);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(156, 56);
    glVertex2f(158, 56);
    glVertex2f(158, 60);
    glVertex2f(156, 60);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(160, 50);
    glVertex2f(162, 50);
    glVertex2f(162, 54);
    glVertex2f(160, 54);
    glEnd();



    }


    glPopMatrix();
}





/////////////////////////////////////////////////////////////////////   HANDELKEY

// ============================================================
// SCENARIO SWITCH VARIABLE
// ============================================================
int currentScenario = 1;  // 1=City Scene  2=River City  3=Train&Bridge

// ============================================================
// DISPLAY FUNCTIONS
// ============================================================

int winWidth = 1450;
int winHeight = 750;

void reshape(int w, int h)
{
    winWidth = w;
    winHeight = h;
    glViewport(0, 0, w, h);
    glutPostRedisplay();
}

void sc1_drawBird(float x, float y, float wingA)
{
    // Wing flap: wingA oscillates 0..1
    float dip = 6.0f * sinf(wingA);   // wing tip vertical displacement
    glColor3ub(10, 10, 20);
    glLineWidth(1.8f);
    glBegin(GL_LINE_STRIP);            // left wing
    glVertex2f(x - 14, y - dip);
    glVertex2f(x - 7,  y + 3);
    glVertex2f(x,      y);
    glEnd();
    glBegin(GL_LINE_STRIP);            // right wing
    glVertex2f(x,      y);
    glVertex2f(x + 7,  y + 3);
    glVertex2f(x + 14, y - dip);
    glEnd();
    glLineWidth(1.0f);
}

void sc1_updateBird(int value)
{
    // --- Flock A (5 birds) ---
    if(sc1_AWait) {
        sc1_ATimer--;
        if(sc1_ATimer <= 0) {
            // reset all 5 birds to left entry positions
            float baseX[5] = {-60,-90,-75,-115,-100};
            float baseY[5] = {680, 695, 668, 685, 702};
            for(int i=0;i<5;i++){sc1_AX[i]=baseX[i]; sc1_AY[i]=baseY[i];}
            sc1_AWait = false;
        }
    } else {
        bool allOut = true;
        for(int i=0;i<5;i++){
            sc1_AX[i]  += sc1_ASpd;
            sc1_AWing[i]+= 0.18f;
            if(sc1_AX[i] < 840) allOut = false;
        }
        if(allOut){ sc1_AWait=true; sc1_ATimer=SC1_A_PAUSE; }
    }

    // --- Flock B (3 birds) ---
    if(sc1_BWait) {
        sc1_BTimer--;
        if(sc1_BTimer <= 0) {
            float baseX[3] = {-60,-90,-75};
            float baseY[3] = {675, 690, 660};
            for(int i=0;i<3;i++){sc1_BX[i]=baseX[i]; sc1_BY[i]=baseY[i];}
            sc1_BWait = false;
        }
    } else {
        bool allOut = true;
        for(int i=0;i<3;i++){
            sc1_BX[i]  += sc1_BSpd;
            sc1_BWing[i]+= 0.18f;
            if(sc1_BX[i] < 840) allOut = false;
        }
        if(allOut){ sc1_BWait=true; sc1_BTimer=SC1_B_PAUSE; }
    }

    // --- Flock C (2 birds) ---
    if(sc1_CWait) {
        sc1_CTimer--;
        if(sc1_CTimer <= 0) {
            float baseX[2] = {-60,-85};
            float baseY[2] = {688, 670};
            for(int i=0;i<2;i++){sc1_CX[i]=baseX[i]; sc1_CY[i]=baseY[i];}
            sc1_CWait = false;
        }
    } else {
        bool allOut = true;
        for(int i=0;i<2;i++){
            sc1_CX[i]  += sc1_CSpd;
            sc1_CWing[i]+= 0.18f;
            if(sc1_CX[i] < 840) allOut = false;
        }
        if(allOut){ sc1_CWait=true; sc1_CTimer=SC1_C_PAUSE; }
    }

    glutPostRedisplay();
    glutTimerFunc(16, sc1_updateBird, 0);
}

void displayScenario1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, winWidth, winHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 700, 0, 800, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    background();
    road();
    firstBuilding(); secondBuilding(); tower(angle); thirdBuilding(); forthBuilding();
    sun(); foodCourt();
    triangleTree5(); triangleTree6(); triangleTree(); triangleTree1();
    triangleTree2(); triangleTree3(); triangleTree4();
    sunCoverCloud(); cloud(); cloud2();
    bus(); bus2();
    drawBezierBridge();
    if(!sc1_AWait) for(int i=0;i<5;i++) sc1_drawBird(sc1_AX[i], sc1_AY[i], sc1_AWing[i]);
    if(!sc1_BWait) for(int i=0;i<3;i++) sc1_drawBird(sc1_BX[i], sc1_BY[i], sc1_BWing[i]);
    if(!sc1_CWait) for(int i=0;i<2;i++) sc1_drawBird(sc1_CX[i], sc1_CY[i], sc1_CWing[i]);

    glutSwapBuffers();
    glFlush();
}

void displayScenario1Rain()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, winWidth, winHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 700, 0, 800, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    background1();
    road();
    firstBuilding(); secondBuilding(); tower(angle); thirdBuilding(); forthBuilding();
    foodCourt();
    triangleTree5(); triangleTree6(); triangleTree(); triangleTree1();
    triangleTree2(); triangleTree3(); triangleTree4();
    cloud(); cloud2();
    drawRainfall(); drawRainfall();
    drawBezierBridge();
    if(!sc1_AWait) for(int i=0;i<5;i++) sc1_drawBird(sc1_AX[i], sc1_AY[i], sc1_AWing[i]);
    if(!sc1_BWait) for(int i=0;i<3;i++) sc1_drawBird(sc1_BX[i], sc1_BY[i], sc1_BWing[i]);
    if(!sc1_CWait) for(int i=0;i<2;i++) sc1_drawBird(sc1_CX[i], sc1_CY[i], sc1_CWing[i]);

    glutSwapBuffers();
}

void displayScenario2()
{
    glClearColor(1.0f, 0.745f, 0.549f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, winWidth, winHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -100, 155);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Ground(0, 0, 1);
    Road(0, 0, 1);
    River(0, 1);
    Sky(0, 0, 1, 10, 15, 40);
    CallingStars();
    CallingSunMoon(40, 80, 1.0f);

    BackBuilding1(0, 0, 1, 1);
    BackBuilding2(0, 0, 1, 1);
    BackBuilding3(0, 0, 1, 1);
    BackBuilding4(0, 0, 1, 1);

    CallingTree();

    Cloud1(0, 1); Cloud2(0, 1); Cloud3(0, 1); Cloud4(0, 1);

    Building1(0, 0, 1, 1);
    Building2(0, 0, 1, 1);
    Building3(0, 0, 1, 1);
    Building4(0, 0, 1, 1);
    Building5(0, 0, 1, 1);
    Building6(0, 0, 1, 1);
    Building7(0, 0, 1, 1);

    Car1(0, 1); Car2(0, 1);
    Boat(0, 1);

    CallingRoadLight();
    RoadLight(0, -60, 1);   RoadLight(35, -60, 1);  RoadLight(70, -60, 1);
    RoadLight(105, -60, 1); RoadLight(140, -60, 1); RoadLight(175, -60, 1);
    RoadLight(-35, -60, 1); RoadLight(-70, -60, 1); RoadLight(-105, -60, 1);
    RoadLight(-140, -60, 1); RoadLight(-175, -60, 1);

    glutSwapBuffers();
    glFlush();
}


void s3_bogi(float x,float y,float z);
void s3_train_tier(float x,float y,float z);
void s3_train_door(float x,float y,float z);
void s3_windowline(float a,float b,float c);
void s3_bridge_blinkinglight();
void s3_bridge_blinkinglight2();
void s3_cargo_design(float a , float b , float c);
void s3_car1wheels(float x,float y , float z);

bool s3_fogOn = false;
float s3_fogDensity = 0.55f;  // 0.0 = no fog, 1.0 = full white
float s3_cloud1 = 0.0f;
float s3_cloud2 = 0.0f;
float s3_train_pos = 0.0f;
float s3_train_speed = 7.0f;
float s3_boatPosition2 = -278.0f;
float s3_boatSpeed2 = 6.0f;
float s3_cargoPosition3= 0.0;
float s3_cargoSpeed3 = -3;
float s3_car2_move = 0.0f;
float s3_car2_speed = 6.0f;
float s3_waveX[4] = {0, 80, 120, 160};
float s3_waveY[4] = {0, 20, -20, 0};
float s3_waveMove = 0.0f;
float s3_birdX[4] = {100, 300, 660, 700};
float s3_birdY[4] = {840, 780, 830, 800};

//s3_Train
void s3_Train()
{
    glPushMatrix();
    glTranslatef(s3_train_pos, 0.0f, 0.0f);

    //Train_tier
    s3_train_tier(0,0,0);
    s3_train_tier(-100,0,0);
    s3_train_tier(-200,0,0);
    s3_train_tier(-300,0,0);
    s3_train_tier(-400,0,0);
    s3_train_tier(-500,0,0);

    //Train_Body
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // White body
        glVertex2f(90,540);
        glVertex2f(600,540);
        glVertex2f(600,590);
        glVertex2f(90,590);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255); // White body polygon
        glVertex2f(600, 590);
        glVertex2f(613, 590);
        glVertex2f(624, 590);
        glVertex2f(640, 590);
        glVertex2f(658, 590);
        glVertex2f(673, 587.5);
        glVertex2f(684, 584);
        glVertex2f(694, 579);
        glVertex2f(701, 575);
        glVertex2f(707, 571);
        glVertex2f(713, 566);
        glVertex2f(718, 560);
        glVertex2f(721, 557);
        glVertex2f(722, 555);
        glVertex2f(723, 553);
        glVertex2f(723, 552);
        glVertex2f(723, 550);
        glVertex2f(723, 549);
        glVertex2f(722, 547);
        glVertex2f(720, 546);
        glVertex2f(718, 544);
        glVertex2f(716, 543);
        glVertex2f(713, 542);
        glVertex2f(711, 541);
        glVertex2f(707, 540);
        glVertex2f(703, 540);
        glVertex2f(700, 540);
        glVertex2f(697, 539);
        glVertex2f(694, 539);
        glVertex2f(691, 539);
        glVertex2f(687, 539);
        glVertex2f(682, 539);
        glVertex2f(660, 539);
        glVertex2f(631, 539);
        glVertex2f(600, 540);
        glVertex2f(600, 590);
    glEnd();

    //Windows
    glBegin(GL_QUADS);
    glColor3ub(30, 30, 30); // Dark gray windows
        glVertex2f(655, 560);
        glVertex2f(705, 560);
        glVertex2f(677, 580);
        glVertex2f(655, 580);

        glVertex2f(620, 560);
        glVertex2f(650, 560);
        glVertex2f(650, 580);
        glVertex2f(620, 580);

    glColor3ub(0, 128, 0); //Green Design
        glVertex2f(90, 545);
        glVertex2f(660, 545);
        glVertex2f(705, 551);
        glVertex2f(90, 551);

    glColor3ub(0, 128, 0); //Green Design
        glVertex2f(90, 552);
        glVertex2f(705, 552);
        glVertex2f(660, 556);
        glVertex2f(90, 556);
    glEnd();

    s3_bogi(0,0,0);
    s3_bogi(-105,0,0);
    s3_bogi(-205,0,0);
    s3_bogi(-310,0,0);
    s3_bogi(-410,0,0);
    s3_bogi(-515,0,0);

    s3_train_door(10,0,0);
    s3_train_door(-94,0,0);
    s3_train_door(-194,0,0);
    s3_train_door(-298,0,0);
    s3_train_door(-398,0,0);

    glPopMatrix();
}

//Train_Door
void s3_train_door(float x,float y , float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_QUADS);
    glColor3ub(215, 221, 194);
        glVertex2f(576, 540);
        glVertex2f(590, 540);
        glVertex2f(590, 575);
        glVertex2f(576, 575);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(576, 540);
        glVertex2f(576, 575);

        glVertex2f(576, 575);
        glVertex2f(590, 575);

        glVertex2f(590, 575);
        glVertex2f(590, 540);
    glEnd();

   //s3_Train window
    glBegin(GL_QUADS);
    glColor3ub(64, 114, 89);
        glVertex2f(578, 560);
        glVertex2f(588, 560);
        glVertex2f(588, 572);
        glVertex2f(578, 572);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(58, 59, 53);
        glVertex2f(510, 560);
        glVertex2f(570, 560);
        glVertex2f(570, 580);
        glVertex2f(510, 580);
    glEnd();

    glPopMatrix();
}

//Bogi
void s3_bogi(float x,float y , float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_QUADS);
    glColor3ub(99, 101, 100);
        glVertex2f(605, 540);
        glVertex2f(610, 540);
        glVertex2f(610, 590);
        glVertex2f(605, 590);
    glEnd();
    glPopMatrix();
}

//Traintier
void s3_train_tier(float x,float y , float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
        for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=10.13;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+627.3872299289397,y+ 540.118203258706);
        }

        for(int i=0;i<200;i++)
        {
            glColor3ub(0,0,0);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=10.13;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+650,y+  540);
        }
    glEnd();

    glBegin(GL_POLYGON);
         for(int i=0;i<200;i++)
         {
            glColor3ub(0,0,0);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=10.13;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+673,y+540);
         }
    glEnd();
    glPopMatrix();
}

//Train_timer
void s3_train_update(int value)
{
    s3_train_pos += s3_train_speed;
    if (s3_train_pos > 1900)
        s3_train_pos = -700;

    glutPostRedisplay();
    glutTimerFunc(16, s3_train_update, 0);
}

void s3_Land() //F02
{
    glColor3ub(93, 199, 101);
    glBegin(GL_POLYGON);
        glVertex2f(0,50);
        glVertex2f(99.5,136.2);
        glVertex2f(140.3,181.5);
        glVertex2f(200,200);
        glVertex2f(255,195.9);
        glVertex2f(290.6,263.8);
        glVertex2f(350.4,327.7);
        glVertex2f(350,350);
        glVertex2f(378.4,359);
        glVertex2f(396.03,385.5);
        glVertex2f(427.1,398.5);
        glVertex2f(0,400);
        glVertex2f(0,50);

    glColor3ub(206, 171, 85);
        glVertex2f(0,83);
        glVertex2f(72.5,155.8);
        glVertex2f(150,200);
        glVertex2f(210,170);
        glVertex2f(280,250);
        glVertex2f(300,300);
        glVertex2f(300,350);
        glVertex2f(360,360);
        glVertex2f(380,380);
    glEnd();
}

void s3_drawWave(float moveX, float moveY)
{
    glPushMatrix();

    glTranslatef(moveX + s3_waveMove, moveY, 0);

    glColor3ub(220,240,255);
    glLineWidth(3);

    glBegin(GL_LINE_STRIP);

    int segments = 50;

    for(int i=0; i<=segments; i++)
    {
        float t = (float)i / segments;
        float omt = 1.0f - t;

        // Cubic B�zier formula
        float x = omt*omt*omt*s3_waveX[0] + 3*t*omt*omt*s3_waveX[1] + 3*t*t*omt*s3_waveX[2] + t*t*t*s3_waveX[3];

        float y = omt*omt*omt*s3_waveY[0] + 3*t*omt*omt*s3_waveY[1] + 3*t*t*omt*s3_waveY[2] + t*t*t*s3_waveY[3];

        glVertex2f(x, y);
    }

    glEnd();

    glPopMatrix();
}

void s3_river() //F03
{
    // Draw river water body
    // Top of river reduced to 480 so boat (y=490-610) is visible above water surface
    glColor3ub(67, 172, 217);
    glBegin(GL_QUADS);
        glVertex2f(820,480);
        glVertex2f(820,0);
        glVertex2f(1900,0);
        glVertex2f(1900,480);

        glVertex2f(820,480);
        glVertex2f(820,420);
        glVertex2f(760,440);
        glVertex2f(740,500);

        glVertex2f(820, 300);
        glVertex2f(820, 430);
        glVertex2f(600, 360);
        glVertex2f(620, 280);

        glVertex2f(800, 0);
        glVertex2f(820, 0);
        glVertex2f(820, 280);
        glVertex2f(800, 280);

        glVertex2f(600, 0);
        glVertex2f(800, 0);
        glVertex2f(800, 300);
        glVertex2f(600, 280);

        glVertex2f(150,0);
        glVertex2f(600, 0);
        glVertex2f(800, 360);
        glVertex2f(450, 350);

        glVertex2f(800, 280);
        glVertex2f(820, 280);
        glVertex2f(820, 290);
        glVertex2f(800, 290);
    glEnd();

    // Draw animated waves OUTSIDE glBegin/glEnd
    s3_drawWave(900,150);
    s3_drawWave(580,230);
    s3_drawWave(600,250);
    s3_drawWave(700,350);
    s3_drawWave(460,320);
    s3_drawWave(1000,310);
}

void s3_updateWave(int value)
{
    s3_waveMove += 2.0f;

    if(s3_waveMove > 1200)
        s3_waveMove = -100;

    glutPostRedisplay();
    glutTimerFunc(16, s3_updateWave, 0);
}

void s3_boat27() //F15 //AF15
{
    glPushMatrix();
    // Place boat in river below bridge. boatPosition2 = left edge of boat on screen.
    // Boat local coords: x 0-278, y 0-120. Translate to river area (y=350-470).
    glTranslatef(s3_boatPosition2, 490, 0.0f); // Original y position - in river below bridge

    /////body - hull bottom stripe
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(15,0);
    glVertex2f(265,0);
    glVertex2f(262,5);
    glVertex2f(25,5);
    glEnd();

    // Hull main body
    glBegin(GL_QUADS);
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(25,5);
    glVertex2f(262,5);
    glVertex2f(275,25);
    glVertex2f(5,25);
    glEnd();

    // Containers row 1
    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(35,25);
    glVertex2f(75,25);
    glVertex2f(75,45);
    glVertex2f(35,45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.8f);
    glVertex2f(75,25);
    glVertex2f(115,25);
    glVertex2f(115,45);
    glVertex2f(75,45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.6f, 0.2f);
    glVertex2f(115,25);
    glVertex2f(155,25);
    glVertex2f(155,45);
    glVertex2f(115,45);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(155,25);
    glVertex2f(195,25);
    glVertex2f(195,45);
    glVertex2f(155,45);
    glEnd();

    // Containers row 2
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.8f);
    glVertex2f(50,45);
    glVertex2f(90,45);
    glVertex2f(90,65);
    glVertex2f(50,65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.6f, 0.2f);
    glVertex2f(95,45);
    glVertex2f(135,45);
    glVertex2f(135,65);
    glVertex2f(95,65);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.8f, 0.0f, 0.0f);
    glVertex2f(140,45);
    glVertex2f(180,45);
    glVertex2f(180,65);
    glVertex2f(140,65);
    glEnd();

    // Left chimney
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(25,25);
    glVertex2f(25,85);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(19,75);
    glVertex2f(30,75);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(15,65);
    glVertex2f(35,65);
    glEnd();

    // Left funnel base
    glBegin(GL_QUADS);
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(5,25);
    glVertex2f(75,25);
    glVertex2f(70,35);
    glVertex2f(0,35);
    glEnd();

    glLineWidth(2);
    for (int i = 1; i <= 70; i+=10) {
        glBegin(GL_LINES);
        glColor3f(0.38f, 0.38f, 0.38f);
        glVertex2f(i,35);
        glVertex2f(i,40);
        glEnd();
    }
    glBegin(GL_LINES);
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(0,40);
    glVertex2f(70,40);
    glEnd();

    // Wheelhouse (white cabin)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(205,25);
    glVertex2f(265,25);
    glVertex2f(260,80);
    glVertex2f(210,80);
    glEnd();

    // Wheelhouse windows
    for (int i = 215; i <= 250; i+=5) {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,65);
        glVertex2f(i+4,65);
        glVertex2f(i+4,70);
        glVertex2f(i,70);
        glEnd();
    }
    for (int i = 215; i <= 250; i+=5) {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,55);
        glVertex2f(i+4,55);
        glVertex2f(i+4,60);
        glVertex2f(i,60);
        glEnd();
    }
    for (int i = 215; i <= 250; i+=5) {
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(i,45);
        glVertex2f(i+4,45);
        glVertex2f(i+4,50);
        glVertex2f(i,50);
        glEnd();
    }

    // Wheelhouse top
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(225,80);
    glVertex2f(245,80);
    glVertex2f(242,90);
    glVertex2f(228,90);
    glEnd();

    // Right chimney
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(235,90);
    glVertex2f(235,120);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(229,115);
    glVertex2f(240,115);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(225,105);
    glVertex2f(245,105);
    glEnd();

    // Right funnel base
    glBegin(GL_QUADS);
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(215,25);
    glVertex2f(275,25);
    glVertex2f(278,35);
    glVertex2f(218,35);
    glEnd();

    glLineWidth(2);
    for (int i = 218; i <= 278; i+=10) {
        glBegin(GL_LINES);
        glColor3f(0.38f, 0.38f, 0.38f);
        glVertex2f(i,35);
        glVertex2f(i,40);
        glEnd();
    }
    glBegin(GL_LINES);
    glColor3f(0.38f, 0.38f, 0.38f);
    glVertex2f(218,40);
    glVertex2f(278,40);
    glEnd();

    // Deck line
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(71,32);
    glVertex2f(218,32);
    glEnd();

    glPopMatrix();
}

void s3_updateboat2(int value)
{
    s3_boatPosition2 += s3_boatSpeed2;

    if (s3_boatPosition2 > 1900.0f) {
        s3_boatPosition2 = -278.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(80, s3_updateboat2, 0);
}

//s3_Cloud1
void s3_Cloud1(float x,float y , float z) //F4.1 //AF4.1
{
    if(!s3_fogOn)
    {

    glPushMatrix();
    glTranslatef(x,y,z);

    glColor3ub(213, 229, 243);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
    {
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=19.54;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+780,y+920);
    }

    for(int i=0;i<200;i++)
    {
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=21.87;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+760.13,y+932.23);
    }

    for(int i=0;i<200;i++)
    {
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=20.46;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+760,y+920);
    }

    for(int i=0;i<200;i++)
    {

            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=20;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+740,y+920);
    }

    for(int i=0;i<200;i++)
    {
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=15;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+715,y+920);
    }

    for(int i=0;i<200;i++)
    {
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=12.71;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+802,y+920);
    }
    glEnd();
    glPopMatrix();
    }

}

//s3_Cloud2
void s3_Cloud2(float x, float y, float z) //F4.2 //AF4.2
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.8f, 0.8f, 1.0f); // Smaller cloud
    s3_Cloud1(0, 0, 0); // Reuse existing cloud shape
    glPopMatrix();

}

//Cloud_Timer
void s3_updateCloud(int value) //F4.3  //AF4.3
{
    s3_cloud1 += 0.4f;
    if (s3_cloud1 > 1900)
        s3_cloud1 = -1900;

    s3_cloud2 += 0.6f;
    if (s3_cloud2 > 1500)
        s3_cloud2 = -1500;

    glutPostRedisplay();
    glutTimerFunc(5, s3_updateCloud, 0);
}

void s3_Flower(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);

    //glColor3ub(180, 0, 0);
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
    {
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=5.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+200,y+298);
    }

    for(int i=0;i<200;i++)
    {
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=5.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+210,y+292);
    }

    for(int i=0;i<200;i++)
    {
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=5.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+205,y+286);
    }

    for(int i=0;i<200;i++)
    {

            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=5.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+195,y+286);
    }

    for(int i=0;i<200;i++)
    {
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=5.0;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+190,y+292);
    }

    glEnd();
    glPopMatrix();

}

void s3_BackFlower(float x, float y, float z)
{
    if(!s3_fogOn)
    {

    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.6f, 0.6f, 1.0f); // Smaller flower
    glColor3ub(100, 0, 200);
    s3_Flower(0, 0, 0); // Reuse existing flower shape
    glPopMatrix();
    }

}

void s3_RightFlower(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.9f, 0.9f, 1.0f); // Smaller flower
    glColor3ub(220, 220, 0);
    s3_Flower(0, 0, 0); // Reuse existing flower shape
    glPopMatrix();

}

void s3_drawBird(float x, float y)
{
    glColor3ub(5, 5, 5);

    glBegin(GL_TRIANGLES);

    glVertex2f(x, y);
    glVertex2f(x - 15, y + 8);
    glVertex2f(x - 15, y - 8);

    glEnd();
}

void s3_updateBird(int value)
{
    for(int i = 0; i < 4; i++)
    {
        s3_birdX[i] += 2.0f;   // move right
    }

    // reset when they go off screen
    for(int i = 0; i < 4; i++)
    {
        if(s3_birdX[i] > 2000)
            s3_birdX[i] = -100;
    }

    glutPostRedisplay();
    glutTimerFunc(16, s3_updateBird, 0);
}


void s3_Trees(float x, float y, float z) //F21
{
    //LEFT 6 SMALL TREES
    glPushMatrix();
    glTranslatef(x,y,z);

    glColor3ub(58, 176, 89);
    glBegin(GL_TRIANGLES);
        glVertex2f(280,380);
        glVertex2f(300,460);
        glVertex2f(320,380);

        glVertex2f(315,400);
        glVertex2f(326,462);
        glVertex2f(340,400);

        glVertex2f(340,380);
        glVertex2f(360,460);
        glVertex2f(380,380);

        glVertex2f(380,400);
        glVertex2f(400,460);
        glVertex2f(420,400);

        glVertex2f(368,440);
        glVertex2f(380,480);
        glVertex2f(392,440);
    glEnd();

    glPopMatrix();
}

void s3_tree2(float a, float b, float c,float sx, float sy, float sz) //F22
{
    glPushMatrix();
    glTranslatef(a,b,c);
    glScalef(sx, sy, sz);

    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
    {
            glColor3ub(58, 176, 89);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=35;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+45.02,y+640.33);
    }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
        for(int i=0;i<200;i++)
        {
            glColor3ub(58, 176, 89);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=35;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+98.65498528917,y+640.5215088246986);
        }
    glEnd();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
        for(int i=0;i<200;i++)
            {
                glColor3ub(58, 176, 89);
                float local_pi=3.1416;
                float A=(i*2*local_pi)/200;
                float r=35;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x+70.7470193767515,y+689.3604491714192);
            }
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(41, 159, 76);
        glVertex2f(66, 620);
        glVertex2f(70, 620);
        glVertex2f(70, 704);
        glVertex2f(66, 694);

        glVertex2f(70, 632);
        glVertex2f(96, 658);
        glVertex2f(88, 653);
        glVertex2f(70, 635);

        glVertex2f(66, 644);
        glVertex2f(44, 666);
        glVertex2f(48, 658);
        glVertex2f(66, 640);
    glEnd();

    glPopMatrix();
}

void s3_tree3(float p,float r,float t) //F23.1
{
    glColor3ub(7, 100, 87);
    glPushMatrix();
    glTranslatef(p,r,t);

    glBegin(GL_TRIANGLES);
        glVertex2f(700,650);
        glVertex2f(715,677);
        glVertex2f(726,650);

        glVertex2f(725,655);
        glVertex2f(735,690);
        glVertex2f(745,655);

        glVertex2f(745,650);
        glVertex2f(755,685);
        glVertex2f(765,650);
    glEnd();

    glPopMatrix();
}

void s3_tree3detailing(float p,float r,float t) //F23.2
{
    glColor3ub(61, 67, 60);
    glPushMatrix();
    glTranslatef(p,r,t);
    glBegin(GL_QUADS);

    glVertex2f(715, 645);
    glVertex2f(715, 643);
    glVertex2f(765, 643);
    glVertex2f(765, 645);

    glEnd();

    glPopMatrix();
}

//Mountains
void s3_Mountain() //F5.1
{   //1ST s3_Mountain
    glColor3ub(93, 199, 101);
    glBegin(GL_POLYGON);
        glVertex2f(0,700);
        glVertex2f(31.4,746.8);
        glVertex2f(46.3,778.8);
        glVertex2f(77.5,843.2);
        glVertex2f(103.9,874.1);
        glVertex2f(137.3,900.9);
        glVertex2f(170.5,923.3);
        glVertex2f(199.7,941.7);
        glVertex2f(231.6,947.8);
        glVertex2f(256.8,949.1);
        glVertex2f(305.6,943);
        glVertex2f(354.5,924.7);
        glVertex2f(378.2,877.1);
        glVertex2f(400,837.2);
        glVertex2f(437.3,769);
        glVertex2f(469.6,673.9);
        glVertex2f(494.2,638.5);
        glVertex2f(509.3,598.9);
        glVertex2f(533.4,563.00);
        glVertex2f(559.9,530.4);
        glVertex2f(600,480);
        glVertex2f(614.2,462.2);
        glVertex2f(650.8,400);
        glVertex2f(0,400);

    //2nd s3_Mountain
    glColor3ub(81, 172, 56);
        glVertex2f(650.8,400);
        glVertex2f(614.2,462.2);
        glVertex2f(600,480);
        glVertex2f(559.9,530.4);
        glVertex2f(533.4,563.00);
        glVertex2f(509.3,598.9);
        glVertex2f(494.2,638.5);
        glVertex2f(469.6,673.9);
        glVertex2f(437.3,769);
        glVertex2f(400,837.2);
        glVertex2f(440,882.4);
        glVertex2f(483.6,893.9);
        glVertex2f(527.2,880.04);
        glVertex2f(576.9,846.9);
        glVertex2f(600,800);
        glVertex2f(614.3,768.1);
        glVertex2f(638.7,724.5);
        glVertex2f(653.3,694.2);
        glVertex2f(668.6,662.7);
        glVertex2f(714.9,609.1);
        glVertex2f(740.1,529.8);
        glVertex2f(805.4,442.4);
        glVertex2f(790.8,437.6);
        glVertex2f(762.9,429.7);
        glVertex2f(722.7,427.8);
        glVertex2f(680,420);
        glVertex2f(643.2,414);
        glVertex2f(614.2,462.2);
        glVertex2f(600,480);
        glVertex2f(559.9,530.4);
        glVertex2f(533.4,563.00);
        glVertex2f(509.3,598.9);
        glVertex2f(494.2,638.5);
        glVertex2f(469.6,673.9);
        glVertex2f(437.3,769);
        glVertex2f(400,837.2);
    glEnd();
}

void s3_backgroundmountain() //F5.2
{
    glColor3ub(67, 128, 153);
    glBegin(GL_TRIANGLES);
        glVertex2f(300,750);
        glVertex2f(400,950);
        glVertex2f(500,750);

        glVertex2f(80,800);
        glVertex2f(150,950);
        glVertex2f(250,800);

        glVertex2f(20,700);
        glVertex2f(110,970);
        glVertex2f(250,700);

    glColor3ub(70, 116, 135);
        glVertex2f(900,650);
        glVertex2f(1040,770);
        glVertex2f(1180,650);

        glVertex2f(1250,650);
        glVertex2f(1400,750);
        glVertex2f(1550,650);

        glVertex2f(1180,650);
        glVertex2f(1180,650);
        glVertex2f(1180,650);

        glVertex2f(600,650);
        glVertex2f(700,750);
        glVertex2f(800,650);

        glVertex2f(650,650);
        glVertex2f(750,750);
        glVertex2f(850,650);

        glVertex2f(1600,650);
        glVertex2f(1697,697);
        glVertex2f(1770,650);
    glEnd();

    //round mountain
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {
                glColor3ub(70, 116, 135);
                float local_pi=3.1416;
                float A=(i*2*local_pi)/200;
                float r=15.044;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x+1740,y+667);
            }

        for(int i=0;i<200;i++)
        {
            glColor3ub(70, 116, 135);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=22.74;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1660,y+675);
        }

        for(int i=0;i<200;i++)
        {
            glColor3ub(70, 116, 135);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=44;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1470.14,y+695.67);
        }

        for(int i=0;i<200;i++)
        {
            glColor3ub(70, 116, 135);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=46;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1330,y+700);
        }

        for(int i=0;i<200;i++)
        {
            glColor3ub(70, 116, 135);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=51.68;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1112.07,y+704.65);
        }

        for(int i=0;i<200;i++)
        {
            glColor3ub(70, 116, 135);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=50.14;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+977.37,y+709.95);
        }
    glEnd();

    glColor3ub(67, 128, 153);
    glBegin(GL_TRIANGLES);
        glColor3ub(67, 128, 153);
        glVertex2f(682.189,646.974);
        glVertex2f(860,820);
        glVertex2f(1050,650);

        glVertex2f(1050,650);
        glVertex2f(1210,800);
        glVertex2f(1400,650);

        glVertex2f(1400,650);
        glVertex2f(1550,760);
        glVertex2f(1700,650);

        glVertex2f(1700,650);
        glVertex2f(1800,700);
        glVertex2f(1900,650);
    glEnd();
}

void s3_sky() //F06
{
    glColor3ub(135,200,245);
    glBegin(GL_QUADS);
        glVertex2f(1900,650);
        glVertex2f(1900,1000);
        glVertex2f(0, 1000);
        glVertex2f(0, 650);
    glEnd();
}

void s3_sun() //F07
{
    if (s3_fogOn) {
        // Fog on: s3_sun is hidden behind haze — draw a large soft glow instead
        // Outer diffuse glow (very faint)
        float glowAlpha = s3_fogDensity * 0.35f;
        glColor4f(0.95f, 0.95f, 0.80f, glowAlpha);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float local_pi=3.1416f;
            float A=(i*2*local_pi)/200;
            float r=90;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+620,y+900);
        }
        glEnd();

        // Inner glow (slightly brighter but still faded)
        float innerAlpha = s3_fogDensity * 0.25f;
        glColor4f(0.98f, 0.97f, 0.75f, innerAlpha);
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            float local_pi=3.1416f;
            float A=(i*2*local_pi)/200;
            float r=50;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+620,y+900);
        }
        glEnd();
    } else {
        // Normal bright s3_sun
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(232, 232, 71);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=40;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+620,y+900);
        }
        glEnd();
    }
}

//Right-side-s3_Land
void s3_Land2() //F08
{
    glBegin(GL_POLYGON);
    glColor3ub(103, 201, 93);
        glVertex2f(1143.90,0);
        glVertex2f(1152.7237927948174, 27.0344574388035);
        glVertex2f(1208.474897889481, 60.1723777565807);
        glVertex2f(1289.2284229293941, 117.4813310107123);
        glVertex2f(1400, 200);
        glVertex2f(1508.0444262633519, 211.2596181538367);
        glVertex2f(1600, 200);
        glVertex2f(1685.1811908670318, 255.5438093047565);
        glVertex2f(1697.4814499427823, 286.3387025047113);
        glVertex2f(1719.106888060049, 303.4758421448046);
        glVertex2f(1747.2607603259241, 349.9909354536293);
        glVertex2f(1758.6855200859895, 387.1214046738315);
        glVertex2f(1840, 420);
        glVertex2f(1860, 420);
        glVertex2f(1873.6455573721416, 428.2477037326754);
        glVertex2f(1900,446.55555);
        glVertex2f(1900,0);
        glVertex2f(1143.90,0);
    glEnd();
}

void s3_Bridge() //F9.1
{
    //Bridge_Road
    glBegin(GL_QUADS);
    glColor3ub(87, 111, 126);
        glVertex2f(1900,500);
        glVertex2f(1900,530);
        glVertex2f(0,530);
        glVertex2f(0,500);

    //s3_Bridge Pillar
    glColor3ub(87, 111, 126);
        glVertex2f(1780,500);
        glVertex2f(1820,500);
        glVertex2f(1820,300);
        glVertex2f(1780,300);

        glVertex2f(1460,500);
        glVertex2f(1500,500);
        glVertex2f(1500,300);
        glVertex2f(1460,300);

        glVertex2f(1140,500);
        glVertex2f(1180,500);
        glVertex2f(1180,300);
        glVertex2f(1140,300);

        glVertex2f(820,500);
        glVertex2f(860,500);
        glVertex2f(860,300);
        glVertex2f(820,300);

        glVertex2f(500,500);
        glVertex2f(540,500);
        glVertex2f(540,300);
        glVertex2f(500,300);

        glVertex2f(180,500);
        glVertex2f(220,500);
        glVertex2f(220,300);
        glVertex2f(180,300);

        //pillar_design
        glVertex2f(1760, 300);
        glVertex2f(1760, 280);
        glVertex2f(1840,280);
        glVertex2f(1840, 300);

        glVertex2f(1820,460);
        glVertex2f(1860,500);
        glVertex2f(1880,500);
        glVertex2f(1820,440);

        glVertex2f(1740,500);
        glVertex2f(1780,460);
        glVertex2f(1780,440);
        glVertex2f(1720,500);

         //pillar_2_design
        glVertex2f(1440,300);
        glVertex2f(1520,300);
        glVertex2f(1520,290);
        glVertex2f(1440,290);

        glVertex2f(1500,460);
        glVertex2f(1540,500);
        glVertex2f(1560,500);
        glVertex2f(1500,440);

        glVertex2f(1420,500);
        glVertex2f(1460,460);
        glVertex2f(1460,440);
        glVertex2f(1400,500);

        glVertex2f(1120,300);
        glVertex2f(1200,300);
        glVertex2f(1200,290);
        glVertex2f(1120,290);

        glVertex2f(1180,460);
        glVertex2f(1220,500);
        glVertex2f(1240,500);
        glVertex2f(1180,440);

        glVertex2f(1100,500);
        glVertex2f(1140,460);
        glVertex2f(1140,440);
        glVertex2f(1080,500);

        glVertex2f(800,300);
        glVertex2f(880,300);
        glVertex2f(880,290);
        glVertex2f(800,290);

        glVertex2f(860,460);
        glVertex2f(900,500);
        glVertex2f(920,500);
        glVertex2f(860,440);

        glVertex2f(780,500);
        glVertex2f(820,460);
        glVertex2f(820,440);
        glVertex2f(760,500);

        glVertex2f(480,300);
        glVertex2f(560,300);
        glVertex2f(560,290);
        glVertex2f(480,290);

        glVertex2f(540,460);
        glVertex2f(580,500);
        glVertex2f(600,500);
        glVertex2f(540,440);

        glVertex2f(460,500);
        glVertex2f(500,460);
        glVertex2f(500,440);
        glVertex2f(440,500);

        glVertex2f(160, 300);
        glVertex2f(160, 280);
        glVertex2f(240, 280);
        glVertex2f(240, 300);

        glVertex2f(180, 440);
        glVertex2f(120, 500);
        glVertex2f(140, 500);
        glVertex2f(180, 460);

        glVertex2f(220, 440);
        glVertex2f(280, 500);
        glVertex2f(260, 500);
        glVertex2f(220, 460);

    //s3_Bridge Road line design
    glColor3ub(169, 66, 40);
        glVertex2f(1900,520);
        glVertex2f(1900,530);
        glVertex2f(0,530);
        glVertex2f(0,520);

    glColor3ub(114, 44, 26);
        glVertex2f(0,520);
        glVertex2f(1900,520);
        glVertex2f(1900,524);
        glVertex2f(0,524);
    glEnd();
}

//s3_bridge_structure
void s3_bridge_structure(float a, float b, float c) //F9.2
{
    glPushMatrix();
    glTranslatef(a,b,c);

    glBegin(GL_QUADS);
    glColor3ub(169, 66, 40);
        glVertex2f(120, 530);
        glVertex2f(140,530);
        glVertex2f(240, 620);
        glVertex2f(240, 640);

    glColor3ub(169, 66, 40);
        glVertex2f(600, 530);
        glVertex2f(580,530);
        glVertex2f(480, 620);
        glVertex2f(480, 640);

        glVertex2f(240, 625);
        glVertex2f(480, 625);
        glVertex2f(480, 640);
        glVertex2f(240, 640);

        glVertex2f(380, 530);
        glVertex2f(486, 624);
        glVertex2f(475, 630);
        glVertex2f(360,530);

        glVertex2f(230, 620);
        glVertex2f(240, 630);
        glVertex2f(360, 530);
        glVertex2f(340,530);

        glVertex2f(354, 530);
        glVertex2f(366, 530);
        glVertex2f(366, 640);
        glVertex2f(354,640);

        glVertex2f(235, 530);
        glVertex2f(245, 530);
        glVertex2f(245, 635);
        glVertex2f(235, 635);

        glVertex2f(475, 530);
        glVertex2f(488, 530);
        glVertex2f(488, 635);
        glVertex2f(475, 635);
    glEnd();

    s3_bridge_blinkinglight();
    s3_bridge_blinkinglight2();

    glPopMatrix();
}

void s3_pilar_Shadow() //F9.3
{
    if(!s3_fogOn)
    {
    glBegin(GL_QUADS);

        glColor3ub(54, 138, 161);

        glVertex2f(560, 100);
        glVertex2f(600, 100);
        glVertex2f(540, 290);
        glVertex2f(500, 290);

        glVertex2f(900, 100);
        glVertex2f(940, 100);
        glVertex2f(860, 290);
        glVertex2f(820, 290);

        glVertex2f(1220, 100);
        glVertex2f(1260, 100);
        glVertex2f(1180, 290);
        glVertex2f(1140, 290);

        glVertex2f(1540, 100);
        glVertex2f(1580, 100);
        glVertex2f(1500, 290);
        glVertex2f(1460, 290);

    glEnd();
    }
}

float bridgeLightOn;

void s3_updateBridgeLight(int value) //F10.1 //AF10.1
{
    bridgeLightOn = !bridgeLightOn;  // Toggle the light
    glutPostRedisplay();
    glutTimerFunc(100, s3_updateBridgeLight, 0); // Blink every 500ms
}

//bridge_lights
void s3_bridge_blinkinglight() //F10.2
{
    glBegin(GL_QUADS);
    glColor3ub(99, 99, 89);
        glVertex2f(240,640);
        glVertex2f(255,640);
        glVertex2f(255,645);
        glVertex2f(240,645);

        if (s3_train_speed == 0)
        {
            glColor3ub(0, 255, 0);
        }
        else if (bridgeLightOn)
        {
            glColor3ub(237, 42, 14);
        }
        else
        {
            glColor3ub(72, 68, 67);
        }

        glVertex2f(242, 645);
        glVertex2f(253, 645);
        glVertex2f(253, 654);
        glVertex2f(242, 654);
    glEnd();
}

void s3_bridge_blinkinglight2() //F10.3
{
    glBegin(GL_QUADS);
    glColor3ub(99, 99, 89);
        glVertex2f(480, 640);
        glVertex2f(480, 645);
        glVertex2f(465, 645);
        glVertex2f(465, 640);

        if (s3_train_speed == 0)
        {
            glColor3ub(0, 255, 0);
        }
        else if (bridgeLightOn)
        {
            glColor3ub(237, 42, 14);
        }
        else
        {
            glColor3ub(72, 68, 67);
        }

        glVertex2f(467, 645);
        glVertex2f(478, 645);
        glVertex2f(478, 654);
        glVertex2f(467, 654);
    glEnd();
}
//---------------------------oK-----------------------
//Highway s3_road
void s3_road() //F11
{
    glBegin(GL_QUADS);            // These vertices form a closed polygon

	glColor3ub(111,111,111);
	glVertex2f(0,180);
    glVertex2f(0,0);
    glVertex2f(1900,0);
	glVertex2f(1900,180);

	glColor3ub(255,255,255);
	glVertex2f(0,92);
    glVertex2f(0,88);
    glVertex2f(1900,88);
	glVertex2f(1900,92);

	glColor3ub(11, 11, 11 );
	glVertex2f(0,188);
	glVertex2f(1900,188);
	glVertex2f(1900,200);
	glVertex2f(0,200);

	glEnd();
}

void s3_road_piller(float a, float b, float c) //F12.1 //AF12.1
{
    glPushMatrix();
    glTranslatef(a,b,c);

    glColor3ub(232, 229, 44);
    glBegin(GL_QUADS);
    glVertex2f(4, 188);
    glVertex2f(16, 188);
    glVertex2f(28, 200);
    glVertex2f(16, 200);

    glEnd();

    glPopMatrix();
}

void s3_road_piller2(float a, float b, float c) //F12.2 //AF12.2
{

    glPushMatrix();
    glTranslatef(a,b,c);

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(8, 180);
    glVertex2f(16, 180);
    glVertex2f(16, 188);
    glVertex2f(8, 188);
    glEnd();

    glPopMatrix();
}

void s3_Left_tree(float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x,y,z);

    const float local_pi = 3.1416f;

    // Leaves cluster
    for (int k = 0; k < 4; k++)
    {
        glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
        {
            glColor3ub(83, 148, 40);
            float A=(i*2*local_pi)/200;
            float r=50 + k*2;
            float cx = r * cos(A);
            float cy = r * sin(A);
            glVertex2f(cx + 1700 + k*30, cy + 250 + k*10);
        }
        glEnd();
    }

    // Trunk
    glBegin(GL_QUADS);
    glColor3ub(43, 83, 16);
        glVertex2f(1745, 180);
        glVertex2f(1750, 180);
        glVertex2f(1750, 335);
        glVertex2f(1745, 330);
    glEnd();

    glPopMatrix();
}

void s3_left_tree2(float a, float b, float c) //F25
{
    //s3_road behind trees
    glPushMatrix();
    glTranslatef(a, b, c);

    const float local_pi = 3.1416f;

    // === Left Leaf Cluster 1 ===
    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * local_pi) / 200;
        float r = 21.346;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1280, y + 280);
    }
    glEnd();

    // === Middle Leaf Cluster 2 ===
    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * local_pi) / 200;
        float r = 21.346;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1310, y + 280);
    }
    glEnd();

    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * local_pi) / 200;
        float r = 21.346;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1340, y + 280);
    }
    glEnd();

    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * local_pi) / 200;
        float r = 21.346;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1370, y + 280);
    }
    glEnd();

    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * local_pi) / 200;
        float r = 21.5;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1309.1705724952164, y + 94.1404763441744);
    }
    glEnd();

    glColor3ub(83, 148, 40);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++) {
        float A = (i * 2 * local_pi) / 200;
        float r = 21.5;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + 1340.272465162276, y +294.2203932665632);
    }
    glEnd();
    glPopMatrix();
}

float busPosition3= 0.0;
float busSpeed3 = -5;
void s3_updateBus(int value) //F16.1 //AF16.1
{
    busPosition3 +=busSpeed3;
    if (busPosition3 < -1900.0f) {
        busPosition3 = 1900.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(16, s3_updateBus, 0); // Match the  boat's speed
}

void s3_bus7() //F16.2 /AF16.2
{
    if(!s3_fogOn)
    {

    glPushMatrix();
    glTranslatef(busPosition3,0, 0.0f);

    glColor3ub(184, 184, 155);
    glBegin(GL_POLYGON);
    glVertex2f(293.2196882808259, 245.9414998523724);
    glVertex2f(290.1360700549508, 244.1785483912489);
    glVertex2f(287.9150887013691, 242.5074109985556);
    glVertex2f(286.4627446426588, 241.2259309467524);
    glVertex2f(285.6084246081234, 239.2609948673208);
    glVertex2f(284.9541551042008, 237.2180912428628);
    glVertex2f(284.5705456704102, 235.9123580061443);
    glVertex2f(284.3269445563203, 233.0244586152117);
    glVertex2f(284.1250713856748, 222.8801505117827);
    glVertex2f(283.6810938087068, 207.7048513645968);
    glVertex2f(282.4489127153978, 191.5136314738558);
    glVertex2f(280.8507844378561, 181.924861808605);
    glVertex2f(279.8519542643925, 172.1363261086616);
    //E_1
    glVertex2f(279.1918997751287, 163.6784872875481);
    glVertex2f(278.8197647781487, 157.3521923388886);
    glVertex2f(278.2225562124638, 146.1372694103335);
    glVertex2f(278.7402379486613, 140.2702097334286);

    glVertex2f(279.6567386855583, 137.3444270459453);
    glVertex2f(280.9113149475691, 135.3729500627852);
    glVertex2f(282.3451163898671, 133.8495360303434);
    glVertex2f(284.0477556025961, 132.3261219979015);
    glVertex2f(285.9296199956123, 131.0715457358905);
    glVertex2f(288.2595473393466, 130.1754198344541);
    glVertex2f(290.8583124535119, 129.6377442935923);

    glVertex2f(294.737546725494, 129.4049774265173);
    glVertex2f(317.9610923664113, 129.2922443196746);
    glVertex2f(270.75327551,129.24241026);
    glVertex2f(527.3220793121917, 128.9339672041073);
    glVertex2f(596.783473233727, 129.0780637917456);
    glVertex2f(624.4234475826452, 129.4942318943237);
    glVertex2f(631.3954995646527, 130.4843634026661);
    glVertex2f(635.5858322650652, 131.1459948816786);
    glVertex2f(640.2172526181528, 131.5870825343536);
    glVertex2f(644.052855245998, 132.3167532597233);
    glVertex2f(648.2753890982393, 133.1563855923162);
    //L_2
    glVertex2f(648.7334642506796, 182.2973830057418);
    glVertex2f(648.5362318042933, 238.4897020954715);
    glVertex2f(648.3511004426362, 240.0941738964999);
    glVertex2f(647.8574168115505, 241.328382974214);
    glVertex2f(646.9317600032649, 242.5008815980424);
    glVertex2f(645.9443927410937, 243.3648279524423);
    glVertex2f(644.8336045711511, 244.1053533990707);
    glVertex2f(643.5272004334358, 245.1202805499473);
    glVertex2f(641.8495600899967, 245.6500617110334);
    glVertex2f(638.8510193300478, 245.8736097977383);
    glVertex2f(293.2196882808259, 245.9414998523724);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(68, 131, 168);
    glVertex2f(280.8507844378561, 181.924861808605);
    glVertex2f(279.8519542643925, 172.1363261086616);
    glVertex2f(279.1918997751287, 163.6784872875481);

    glVertex2f(280.5931734315271, 163.0558412054765);
    glVertex2f(281.6889709498011, 162.3209836698938);
    glVertex2f(283.1149910317125, 161.7949324053838);

    glVertex2f(284.4497134729927, 161.5029858852443);
    glVertex2f(287.0832961028051, 161.3274137099234);
    glVertex2f(289.5998306157368, 161.6200340021248);
    glVertex2f(292.2334132455491, 161.9711783527665);
    glVertex2f(295.1010921091225, 162.4393708202887);
    glVertex2f(297.4420544467334, 162.7319911124901);
    glVertex2f(299.6659686674638, 163.2001835800124);
    glVertex2f(301.421690420672, 163.6098519890943);
    glVertex2f(303.1774121738802, 164.0780444566165);
    glVertex2f(305.0501820439689, 164.3121406903777);
    glVertex2f(307.1570481478187, 164.6047609825791);
    glVertex2f(308.6786736672658, 164.8973812747805);
    glVertex2f(310, 165);
    glVertex2f(311.4878284723989, 165.2485256254221);
    glVertex2f(313.009453991846, 165.424097800743);
    glVertex2f(314.8048058712338, 165.6789302284238);
    glVertex2f(316.7024534405552, 166.0715469669042);
    glVertex2f(318.8945635637367, 166.4314456438445);
    glVertex2f(321.2829820561584, 166.6931901361647);
    glVertex2f(323.4750921793399, 166.8567804438648);
    glVertex2f(326.7872165378002, 167.1217503925414);
    glVertex2f(331.5566756139833, 167.6516902898952);
    glVertex2f(336.8107917710806, 167.6662091211863);
    glVertex2f(342.817898432749, 168.1816301872489);
    glVertex2f(348.1027656201716, 168.2747586100595);
    glVertex2f(352.971161531157, 168.2747586100595);
    glVertex2f(357.8395574421423, 168.4776084396839);
    glVertex2f(362.9784197926269, 168.4099918298091);
    glVertex2f(367.8468157036123, 168.6128416594335);
    glVertex2f(374.3803635580623, 168.1934187367058);
    glVertex2f(412.8090528767715, 169.4602986043557);
    glVertex2f(476.3051144170423, 170.3572035801235);
    glVertex2f(496.4593743341977, 171.0864482165499);
    glVertex2f(505.1534982216732, 171.9015223310008);
    glVertex2f(509.7722515368943, 172.7165964454515);
    glVertex2f(513.0284780399352, 173.3497515988207);
    glVertex2f(517.3701133773232, 174.0733574883854);
    glVertex2f(521.6212979785154, 174.4351604331678);
    glVertex2f(525.6906536832734, 174.6941362948168);
    glVertex2f(529.9405059104903, 175.2464683114943);
    glVertex2f(536.9768326068195, 176.1642500544938);
    glVertex2f(582.4416481159291, 177.6807536620541);
    glVertex2f(593.1281276731935, 177.951297448314);
    glVertex2f(602.1913445128988, 178.6276569139637);
    glVertex2f(612.0661927113836, 179.0334725933536);
    glVertex2f(632.0061350464532, 180.4082148949601);
    glVertex2f(648.7334642506796, 182.2973830057418);
    //////
    glVertex2f(648.2753890982393, 133.1563855923162);
    glVertex2f(644.052855245998, 132.3167532597233);
    glVertex2f(640.2172526181528, 131.5870825343536);
    glVertex2f(635.5858322650652, 131.1459948816786);
    glVertex2f(631.3954995646527, 130.4843634026661);
    glVertex2f(624.4234475826452, 129.4942318943237);
    glVertex2f(596.783473233727, 129.0780637917456);
    glVertex2f(527.3220793121917, 128.9339672041073);
    glVertex2f(270.75327551,129.24241026);
    glVertex2f(317.9610923664113, 129.2922443196746);
    glVertex2f(294.737546725494, 129.4049774265173);
    glVertex2f(290.8583124535119, 129.6377442935923);
    glVertex2f(288.2595473393466, 130.1754198344541);
    glVertex2f(285.9296199956123, 131.0715457358905);
    glVertex2f(284.0477556025961, 132.3261219979015);
    glVertex2f(282.3451163898671, 133.8495360303434);
    glVertex2f(280.9113149475691, 135.3729500627852);
    glVertex2f(279.6567386855583, 137.3444270459453);
    glVertex2f(278.7402379486613, 140.2702097334286);
    glVertex2f(278.2225562124638, 146.1372694103335);
    glVertex2f(278.8197647781487, 157.3521923388886);
    glVertex2f(279.1918997751287, 163.6784872875481);
    glVertex2f(279.8519542643925, 172.1363261086616);
    glVertex2f(280.8507844378561, 181.924861808605);
    glEnd();

    //Bus light
    glBegin(GL_POLYGON);
    glColor3ub(242, 238, 13);
    glVertex2f(279.3880021579443, 161.7574683416311);
    glVertex2f(280.7024248649635, 161.4401938951092);
    glVertex2f(281.6089232835974, 161.0775945276556);
    glVertex2f(282.560746623163, 160.7603200811337);
    glVertex2f(283.4219201208652, 160.4430456346118);
    glVertex2f(284, 160);
    glVertex2f(284.3737434604308, 159.355247532251);
    glVertex2f(284.3737434604308, 158.3580992717536);
    glVertex2f(284.4643933022942, 157.542250694983);
    glVertex2f(284.2377686976357, 156.635752276349);
    glVertex2f(283.8298444092505, 155.729253857715);
    glVertex2f(283.4219201208652, 154.7321055972176);
    glVertex2f(282.8326961487531, 153.8709320995153);
    glVertex2f(282.3341220185045, 152.9191087599496);
    glVertex2f(281.7448980463925, 151.9219604994522);
    glVertex2f(281.1103491533488, 151.0154620808182);
    glVertex2f(280.3851504184416, 149.7916892156623);
    glVertex2f(279.433327078876, 148.5679163505064);
    glVertex2f(279.3880021579443, 161.7574683416311);


    glEnd();


    //bus window
    glBegin(GL_QUADS);
    glColor3ub(37, 36, 28);
    glVertex2f(292, 186);
    glVertex2f(640, 186);
    glVertex2f(640, 230);
    glVertex2f(292, 230);

    glVertex2f(292, 170);
    glVertex2f(334, 170);
    glVertex2f(334, 186);
    glVertex2f(292, 186);

    glColor3ub(75, 74, 59);
    glVertex2f(296, 190);
    glVertex2f(636, 190);
    glVertex2f(636, 226);
    glVertex2f(296, 226);

    glVertex2f(295, 172);
    glVertex2f(332, 172);
    glVertex2f(332, 186);
    glVertex2f(295, 186);
    glEnd();

//Tier_1

    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i++) {
        float local_pi = 3.1416f;
        float A = (i  * local_pi)/180;
        float r = 30.59467;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+344.4811931299393, y+128.3698554974698);
    }
    glEnd();

      glColor3ub(71, 71, 61);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 24.5619;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+344.4811931299393, y+128.3698554974698);
    }
    glEnd();

      glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 13.6464;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+344.4811931299393, y+128.3698554974698);
    }
    glEnd();



      glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 2.898989;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+344.4811931299393, y+128.3698554974698);
    }
    glEnd();

//tier_2

  glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i++) {
        float local_pi = 3.1416f;
        float A = (i  * local_pi)/180;
        float r = 30.59467;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+554.1837922334446, y+128.3698554974698);
    }
    glEnd();

      glColor3ub(71, 71, 61);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 24.5619;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+554.1837922334446, y+128.3698554974698);
    }
    glEnd();

      glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 13.6464;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+554.1837922334446, y+128.3698554974698);
    }
    glEnd();

      glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 2.898989;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+554.1837922334446, y+128.3698554974698);
    }
    glEnd();

  s3_windowline(0,0,0);
  s3_windowline(10,0,0);
  s3_windowline(90,0,0);
  s3_windowline(170,0,0);
  s3_windowline(250,0,0);

    glPopMatrix();
    }
}

//Cargo
void s3_cargo_Truck(float a, float b, float c) //F18.1 //AF18.1
{
   glPushMatrix();
    glTranslatef(a,b,c);

    glColor3ub(184, 184, 155);
    glBegin(GL_POLYGON);

    glVertex2f(1416.3478318479406, 211.2074167866959);
    glVertex2f(1418.103832166352, 213.7536172483928);
    glVertex2f(1419.1267453713285, 215.2751710252012);
    glVertex2f(1419.8598324847637, 216.2998177100898);
    glVertex2f(1421.3476490837627, 217.4153146026379);
    glVertex2f(1422.4060329464605, 218.4070180921839);
    glVertex2f(1423.689692998693, 219.3131777750817);
    glVertex2f(1425, 220);
    glVertex2f(1426.3547774536141, 220.1207791250578);
    glVertex2f(1427.4854193435806, 220.2419193275542);
    glVertex2f(1428.8987217060387, 220.3630595300506);
    glVertex2f(1431.337748335297, 220.562264503412);
    glVertex2f(1435.9278007875755, 220.4788090042797);
    glVertex2f(1496.6194991389016, 220.7225507647267);
    glVertex2f(1498.4729914019088, 220.4107722880759);
    glVertex2f(1499.939596315875, 219.6831529442048);
    glVertex2f(1501.1681530437002, 218.9743702166134);
    glVertex2f(1501.829683589452, 218.3128396708613);
    glVertex2f(1502.491214135204, 217.6985613069487);
    glVertex2f(1503.1527446809562, 216.8007698519995);
    glVertex2f(1504, 216);
    glVertex2f(1504.695215332897, 215.0904746211566);
    glVertex2f(1505.164969785406, 213.9341559688266);
    glVertex2f(1505.6012395071966, 212.4446931960381);
    glVertex2f(1505.8454340299916, 207.9677936114649);
    glVertex2f(1505.8746452187925, 128.0308219831911);//G12
    glVertex2f(1505.662111340404, 98.9667428780445);
    glVertex2f(1437.641251025874, 99.0271087850153);
    glVertex2f(1437.5687932247324, 95.7665077336737);
    glVertex2f(1397.5382342898386, 95.397337088145);
    glVertex2f(1396.590481314157, 95.8408725246947);
    glVertex2f(1395.8121229877909, 96.3597780756054);
    glVertex2f(1395.3144293434655, 96.7158263205975);
    glVertex2f(1394.817436565195, 97.0981284577285);
    glVertex2f(1394.2439833594988, 97.6333514497119);
    glVertex2f(1393.7469905812284, 98.1685744416952);
    glVertex2f(1393.135307161819, 98.8184880748179);
    glVertex2f(1392.7630403162984, 99.600301403512);
    glVertex2f(1392.3974584448029, 100.6450971692826);
    glVertex2f(1392.1993611514547, 101.6851079593554);
    glVertex2f(1391.9593883368395, 147.8285282229797);
    glVertex2f(1392.4002836340808, 149.2089534820164);
    glVertex2f(1392.8294008193286, 150.3675698821862);
    glVertex2f(1393.3014297231016, 151.5690980008807);
    glVertex2f(1393.8163703453993, 152.7277144010504);
    glVertex2f(1394.3742226862216, 154.0579776753193);
    glVertex2f(1394.974986745569, 155.3882409495883);
    glVertex2f(1395.5328390863913, 156.761415942382);
    glVertex2f(1397.245933718825, 160.1598689365257);
    glVertex2f(1416.3478318479406, 211.2074167866959);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(85, 85, 76);
    glVertex2f(1505.8746452187925, 128.0308219831911);
    glVertex2f(1505.662111340404, 98.9667428780445);
    glVertex2f(1437.641251025874, 99.0271087850153);
    glVertex2f(1437.5408807531264, 101.874890439603);
    glVertex2f(1437.3488501781844, 105.1874178573535);
    glVertex2f(1437.5408807531264, 107.4437771129227);
    glVertex2f(1437.876934259275, 109.5561134372853);
    glVertex2f(1438.3090030528947, 110.9963427493508);
    glVertex2f(1438.7612701964479, 112.0929076113974);
    glVertex2f(1439.2552878433467, 113.2527751302032);
    glVertex2f(1439.6204313214891, 114.3052475083788);
    glVertex2f(1440.0070538277578, 115.1429296052941);
    glVertex2f(1440.6299456434128, 116.2598390678479);
    glVertex2f(1441.240580889169, 117.1745426721021);
    glVertex2f(1442.057344039589, 118.2978974342417);
    glVertex2f(1442.7326892351048, 119.1733449099102);
    glVertex2f(1443.3580088605822, 119.9237284604833);
    glVertex2f(1444.1334051961742, 120.6991247960754);
    glVertex2f(1444.9088015317664, 121.3994827766102);
    glVertex2f(1445.809261792454, 122.2749302522788);
    glVertex2f(1447.048566413197, 123.2066855996915);
    glVertex2f(1447.6298324045626, 123.5699768442951);
    glVertex2f(1448.3927440182301, 124.1149137112004);
    glVertex2f(1449.7369216232632, 125.0231418227093);
    glVertex2f(1451.0810992282964, 125.8223825608372);
    glVertex2f(1452.1346438376468, 126.2946611788218);
    glVertex2f(1453.3335049448383, 126.8032689212668);
    glVertex2f(1455.2226194167768, 127.3118766637118);
    glVertex2f(1456.9664173908739, 127.747826157236);
    glVertex2f(1458.528569742669, 127.8931426550775);
    glVertex2f(1505.8746452187925, 128.0308219831911);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(62, 74, 76);

    glVertex2f(1506.6954956079746, 105.2986022513748);
    glVertex2f(1506.5517116398253, 124.9970058878235);
    glVertex2f(1867.4551461201995, 125.0912066079358);
    glVertex2f(1867.4551461201995, 106.7161401194707);
    glVertex2f(1506.6954956079746, 105.2986022513748);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(68, 131, 168);

    glVertex2f(1867.4551461201995, 125.0912066079358);
    glVertex2f(1867.4551461201995, 245.6329081355784);
    glVertex2f(1517.0097818190761, 247.7297237078259);
    glVertex2f(1517.3687072631194, 125.6858649571181);
    glVertex2f(1867.4551461201995, 125.0912066079358);

    glEnd();

      glColor3ub(77, 78, 57);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 180; i++)
    {
        float local_pi = 3.1416f;
        float A = (i  * local_pi)/180;
        float r = 27;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1471.6119970872421, y+100.4636886787952);
    }
    glEnd();

     glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 25.787;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1471.6119970872421, y+100.4636886787952);
    }
    glEnd();

     glColor3ub(122, 123, 100);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 16;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1471.6119970872421, y+100.4636886787952);
    }
    glEnd();

    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1471.6119970872421, y+100.4636886787952);
    }
    glEnd();

    //2nd
    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 25.787;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1614.9954282917631, y+100.4636886787952);
    }
    glEnd();

    glColor3ub(122, 123, 100);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 16;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1614.9954282917631, y+100.4636886787952);
    }
    glEnd();


    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1614.9954282917631, y+100.4636886787952);
    }
    glEnd();

    //3rd
    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 25.787;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1670, y+100.4636886787952);
    }
    glEnd();

    glColor3ub(122, 123, 100);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 16;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1670, y+100.4636886787952);
    }
    glEnd();

    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1670, y+100.4636886787952);
    }
    glEnd();

//4th
 glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 25.787;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1820, y+100.4636886787952);
    }
    glEnd();

    glColor3ub(122, 123, 100);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 16;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1820, y+100.4636886787952);
    }
    glEnd();

    glColor3ub(45, 45, 34);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float local_pi = 3.1416f;
        float A = (i *2 * local_pi)/180;
        float r = 7;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+1820, y+100.4636886787952);
    }
    glEnd();

   glBegin(GL_POLYGON);
    glColor3ub(57, 79, 78);

    glVertex2f(1427.7236020448165, 201.4632575200066);
    glVertex2f(1428.220789392821, 202.6878670558897);
    glVertex2f(1428.8940484192724, 203.715472938368);
    glVertex2f(1429.6027421313265, 204.7076441352437);
    glVertex2f(1430.5594786425995, 205.6998153321193);
     glVertex2f(1431.693388581886, 206.5502477865841);
    glVertex2f(1432.7918638355698, 207.2589414986382);
    glVertex2f(1472.1366699261596, 206.7418199666927);
    glVertex2f(1473.5385500165112, 206.4379457842937);
    glVertex2f(1474.6598656432618, 205.8942776016267);
     glVertex2f(1475.3734301330123, 205.4185679417931);
    glVertex2f(1475.849139792846, 204.9428582819595);
    glVertex2f(1476.290870191263, 204.3312315764591);
    glVertex2f(1476.7665798510966, 203.8555219166255);
    glVertex2f(1477.1063724652636, 203.3458329953752);
     glVertex2f(1477.4121858180138, 202.7681855512916);
    glVertex2f(1477.6160613865138, 202.0886003229578);
    glVertex2f(1477.7859576935973, 201.4090150946241);
    glVertex2f(1477.833851641767, 162.7471230055758);
    glVertex2f(1477.27353493353, 161.8137039142078);
    glVertex2f(1476.8252815669402, 160.9732288518516);
     glVertex2f(1476.3770282003502, 160.1887854603193);
    glVertex2f(1475.7046481504651, 159.5724370812581);
    glVertex2f(1474.9274567746775, 158.8146352461552);
    glVertex2f(1474, 158);
    glVertex2f(1473.316617939604, 157.5755284499449);
    glVertex2f(1472.4905467421304, 157.1624928512082);
     glVertex2f(1471.9536004637725, 156.8320643722188);
    glVertex2f(1471.375350625541, 156.5842430129767);
    glVertex2f(1470.4253687484463, 156.3364216537347);
    glVertex2f(1468.4427978745098, 156.2538145339873);
    glVertex2f(1426.7225327050603, 154.4973028486219);
    glVertex2f(1425.9202206643076, 154.4973028486219);
     glVertex2f(1425.342555994966, 154.4652103669918);
    glVertex2f(1424.7969838072543, 154.529395330252);
    glVertex2f(1424.30139231451, 154.8267502258964);
    glVertex2f(1423.880421877956, 155.6686910990034);
    glVertex2f(1423.760144610369, 157.7735432817724);
     glVertex2f(1423.6985403717197, 159.6792839611967);
    glVertex2f(1427.7236020448165, 201.4632575200066);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(57, 79, 78);

    glVertex2f(1415.1768705551851, 206.6410986769221);
    glVertex2f(1416.6683085910524, 206.8896716828999);
    glVertex2f(1417.9111736209416, 206.942905676951);
    glVertex2f(1418.867265038707, 206.7741836620513);
    glVertex2f(1419.710875113206, 206.3242582889853);
    glVertex2f(1420.385763172805, 205.7618515726528);
    glVertex2f(1421.0044105607708, 205.0869635130538);
    glVertex2f(1421.4543359338368, 204.3558347818216);
    glVertex2f(1421.6230579487367, 203.0060586626236);
    glVertex2f(1421.285613918937, 201.4875605285259);
    glVertex2f(1405.7821663116506, 159.9340316041417);
    glVertex2f(1405.0018629750657, 159.1762195201007);
    glVertex2f(1404.0756890255827, 159.0787275254183);
    glVertex2f(1403.247007070782, 159.0787275254183);
    glVertex2f(1402.1745951292755, 159.2249655174419);

    glVertex2f(1400.8097072037215, 159.4686955041479);
    glVertex2f(1399.2010892914616, 159.8099174855364);
    glVertex2f(1397.245933718825, 160.1598689365257);
    glVertex2f(1415.1768705551851, 206.6410986769221);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(241, 234, 28);

    glVertex2f(1392.6193914373703, 126.581021808021);
    glVertex2f(1401.8745869730228, 126.8183345140634);
    glVertex2f(1403.4162543294024, 125.6818820783787);
    glVertex2f(1403.7546544573945, 124.5990016688041);
    glVertex2f(1403.4162543294024, 123.583801284828);
    glVertex2f(1402.6040940222215, 122.5009208752535);
    glVertex2f(1401.3181735358517, 122.2302007728599);
    glVertex2f(1392.5810823478832, 122.2507601602716);
    glVertex2f(1392.6193914373703, 126.581021808021);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(1486.6525348548382, 129.2086633522481);
    glVertex2f(1486.8252786284745, 206.4251301676146);

    glVertex2f(1486.8252786284745, 206.4251301676146);
    glVertex2f(1505.7159706419352, 205.7897166163279);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(52, 52, 50);

    glVertex2f(1523.1124745323111, 112.5624418865387);
    glVertex2f(1523.3937115355948, 113.4998985641507);
    glVertex2f(1523.6749485388784, 114.2029910723597);
    glVertex2f(1524.0968040438038, 114.9060835805687);
    glVertex2f(1524.5655323826097, 115.6560489226583);
    glVertex2f(1525.1748792230576, 116.2185229292255);
    glVertex2f(1525.690480395744, 116.7809969357927);
    glVertex2f(1526.3125810068966, 117.2040086210724);
    glVertex2f(1577.7003378133325, 117.293115461337);
    glVertex2f(1578.9625221473716, 117.0082839328178);
    glVertex2f(1580.1336180720618, 116.6442407256758);
     glVertex2f(1581.3502582014266, 115.7520379641416);
    glVertex2f(1582.1613516210032, 114.7787258606498);
    glVertex2f(1582.2424609629609, 113.562085731285);
    glVertex2f(1582.2424609629609, 112.183226918005);
    glVertex2f(1582.6723150302164, 103.758152020036);
    glVertex2f(1582.4583585669695, 102.5599958258528);
    glVertex2f(1581.6025327139814, 101.404630924319);
    glVertex2f(1580.9606633242406, 100.5060137786816);
    glVertex2f(1580, 100);
     glVertex2f(1579.3246753557291, 99.5975297073834);
    glVertex2f(1578.8244222817736, 99.4132259432946);
    glVertex2f(1578.1661945528847, 99.3079095066723);
    glVertex2f(1527.0954797599147, 99.3930619899087);

     glVertex2f(1525, 100);
    glVertex2f(1524.1283577396132, 100.9707668474999);
    glVertex2f(1523.574828734149, 101.9671190573353);
    glVertex2f(1523.1320055297776, 102.742059664985);

     glVertex2f(1522.7998881264994, 103.959823477006);
    glVertex2f(1522.63382942486, 105.3436459906663);
    glVertex2f(1523.1124745323111, 112.5624418865387);

    glEnd();

     glBegin(GL_LINES);
    glColor3ub(115, 115, 109);

    glVertex2f(1534.4897018972124, 99.1432773227808);
    glVertex2f(1534.1443402051266, 117.5337874263493);

    glVertex2f(1552.0168077705698, 99.4886390148666);
    glVertex2f(1551.5851056554625, 117.7928086954136);

     glVertex2f(1569.338480351273, 99.7081349053607);
    glVertex2f(1569.4619634772212, 117.3662219159706);

    glEnd();

     glBegin(GL_POLYGON);
    glColor3ub(0,0,0);

    glVertex2f(1468.5303467639903, 148.1948863767132);
    glVertex2f(1481.9959230097734, 148.1948863767132);
    glVertex2f(1481.6368409765525, 153.2220348418047);
    glVertex2f(1468.1712647307693, 152.6834117919735);
    glVertex2f(1468.5303467639903, 148.1948863767132);

    glEnd();

    s3_cargo_design(0,0,0);
    s3_cargo_design(17,0,0);
    s3_cargo_design(34,0,0);
    s3_cargo_design(51,0,0);
    s3_cargo_design(68,0,0);
    s3_cargo_design(85,0,0);
    s3_cargo_design(102,0,0);
    s3_cargo_design(119, 0, 0);
    s3_cargo_design(136, 0, 0);
    s3_cargo_design(153, 0, 0);
    s3_cargo_design(170, 0, 0);
    s3_cargo_design(187, 0, 0);
    s3_cargo_design(204, 0, 0);
    s3_cargo_design(221, 0, 0);
    s3_cargo_design(238, 0, 0);
    s3_cargo_design(255, 0, 0);
    s3_cargo_design(272, 0, 0);
    s3_cargo_design(289, 0, 0);
    s3_cargo_design(306, 0, 0);
    s3_cargo_design(323, 0, 0);

    glPopMatrix();
}

void s3_updatecargo(int value) //F18.2 //AF18.2
{
    s3_cargoPosition3 += s3_cargoSpeed3;
    if ( s3_cargoPosition3 < -1900.0f) {
         s3_cargoPosition3 = 1900.0f; // Reset boat position when it exits the screen
    }
    glutPostRedisplay();
    glutTimerFunc(16, s3_updatecargo, 0);

}

void s3_cargo_design(float a, float b, float c) //F18.3 //AF18.3
{
    glPushMatrix();
    glTranslatef(a,b,c);

    glBegin(GL_POLYGON);
    glColor3ub(84, 124, 144);
    glVertex2f(1526.1819928254556, 132.465352720328);
    glVertex2f(1539.5511814570696, 132.3318714310318);
    glVertex2f(1539.5511814570696, 239.5467277508209);
    glVertex2f(1526.210253846322, 239.630458631985);
    glVertex2f(1526.1819928254556, 132.465352720328);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(29, 111, 150);
    glVertex2f(1530, 135);
    glVertex2f(1536.2796369555647, 134.9557017994453);
    glVertex2f(1536.3954588235447, 235.5194732375784);
    glVertex2f(1529.8612879839807, 235.5194732375784);
    glVertex2f(1530, 135);

    glEnd();

    glPopMatrix();

}

void s3_windowline(float a,float b,float c)//F17.2 //AF17.2
{
    glPushMatrix();
    glTranslatef(a,b,c);
    glColor3ub(37, 36, 28);
    glBegin(GL_QUADS);
    glVertex2f(330, 186);
    glVertex2f(334, 186);
    glVertex2f(334, 230);
    glVertex2f(330, 230);


    glEnd();
    glPopMatrix();

}

void s3_car1wheels(float x,float y,float z) //19.3 //AF19.3
{
glPushMatrix();
glTranslatef(x,y,z);

glBegin(GL_POLYGON);      //PICKUPWHEELS
	for(int i=0;i<200;i++)
        {
            glColor3ub(56, 59, 61);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=32.35;
            float cx = r * cos(A);
            float cy = r * sin(A);
            glVertex2f(cx + 1478.6931, cy + 80.2590);
            glVertex2f(x+1478.6931354112655,y+80.2590875832457);
        }

glEnd();

glBegin(GL_POLYGON);      //PICKUPWHEELS
	for(int i=0;i<200;i++)
        {
            glColor3ub(215,223,193);
            float local_pi=3.1416;
            float A=(i*2*local_pi)/200;
            float r=21.43;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+1478.6931354112655,y+80.2590875832457);
        }

glEnd();

glPopMatrix();
}

//Car
void s3_car7777777() //F17.3 //AF17.3
{
    if(!s3_fogOn)
    {

    glPushMatrix();
    glScalef(0.7f, 0.7f, 1.0f);
    glTranslatef(s3_car2_move,-50,0);

    glTranslatef(0, 55, 0);
    glTranslatef(1000, 0, 0);
    glScalef(-1, 1, 1);
    glTranslatef(-500, 0, 0);

    glBegin(GL_POLYGON);     //carbody
    glColor3ub(62, 74, 76);
        glVertex2f(1445.3914501733782, 68.2694392845542);
        glVertex2f(1417.8347698810774, 68.6233942201061);
        glVertex2f(1412.5848265311313, 68.9172722026063);
        glVertex2f(1407.5287533023597, 70.7476562692573);

        glVertex2f(1404, 74);
        glVertex2f(1401.4815281513606, 77.1782374353524);
        glVertex2f(1399.0765104056989, 80.3284719472784);
        glVertex2f(1397.135542428811, 83.2077912637028);
        glVertex2f(1395.4248936800652, 86.9401158064242);
        glVertex2f(1394.57284243499, 89.1202643590344);
        glVertex2f(1394.3063251723167, 91.7528308634571);
        glVertex2f(1394.1753733798755, 95.5993247188406);

        glVertex2f(1394.3605267467328, 99.8505046212322);
        glVertex2f(1395.3894466352883, 103.8975895162202);
        glVertex2f(1397.4909277367262, 108.6098400246408);
        glVertex2f(1399.544320048372, 113.4489827551592);
        glVertex2f(1403.0627876823619, 119.8216498046152);
        glVertex2f(1407.8025325521214, 126.1026792285339);
        glVertex2f(1412.7273184863648, 131.3792355866571);

        glVertex2f(1420.231754195688, 135.4832238651974);
        glVertex2f(1429.846812448258, 138.531900872113);
        glVertex2f(1439.968795646134, 141.291273842492);
        glVertex2f(1449.9807616397675, 143.218293283439);
        glVertex2f(1459.4897344309513, 144.2988583733473);
        glVertex2f(1471.8773448160798, 146.0344145199286);
        glVertex2f(1486.3958051696413, 146.5680450621549);

        glVertex2f(1498.8773107433544, 147.2870340296344);
        glVertex2f(1502.883304948859, 148.6145071443052);
        glVertex2f(1532.318165735683, 163.7917417584851);
        glVertex2f(1559.4790431030087, 177.070362371119);
        glVertex2f(1564.0732027144431, 180.8724254978272);
        glVertex2f(1568.3505237319857, 182.9318763581275);
        glVertex2f(1574.5771546949857, 185.3093168880597);

        glVertex2f(1582.9689798153718, 186.8585769102864);
        glVertex2f(1661.0775059358884, 187.1167869139908);
        glVertex2f(1675.5525210180344, 184.8647460558638);
        glVertex2f(1690, 180);
        glVertex2f(1697.2701263961007, 173.57674175902);
        glVertex2f(1749.2432643645523, 147.6555269619759);
        glVertex2f(1755.8351739670582, 152.1211742596365);

        glVertex2f(1782.5729083578212, 152.2029942764171);
        glVertex2f(1788.51523598853, 149.3968951174685);
        glVertex2f(1792.146658429519, 146.2606666457024);
        glVertex2f(1794.4575636192392, 141.9689855790752);
        glVertex2f(1793.7973049936047, 136.6869165739955);
        glVertex2f(1794.127434306422, 132.560300163777);
        glVertex2f(1792.8069170551532, 116.3839638357204);

        glVertex2f(1795.3251842333177, 111.5987988449264);
        glVertex2f(1797.2898412806421, 105.5537002377684);
        glVertex2f(1798.4988610020725, 98.6018368395367);
        glVertex2f(1798.196606071715, 91.6499734413049);
        glVertex2f(1797.3714042762872, 84.1274081644645);
        glVertex2f(1793.1215589523954, 77.044332624638);

        glVertex2f(1787.7384215421325, 74.6360869410969);
        glVertex2f(1777.3507011244442, 71.2476085707634);
        glVertex2f(1765.7553343992636, 69.0598035282744);
        glVertex2f(1750.2219185976066, 68.2694392845542);
        glVertex2f(1445.3914501733782, 68.2694392845542);
        glEnd();


        glBegin(GL_POLYGON);     //car1window
        glColor3ub(1,1,1);
            glVertex2f(1498.8773107433544, 147.2870340296344);
            glVertex2f(1499.6518848551293, 144.1870506571307);
            glVertex2f(1502.5451355171451, 142.0314249301202);
            glVertex2f(1511.089669110188, 140.322557292427);
            glVertex2f(1520, 140);
            glVertex2f(1574.466435014054, 173.3993479651365);
            glVertex2f(1567.8791907763243, 176.0862502200024);
            glVertex2f(1559.4790431030087, 177.070362371119);
            glVertex2f(1532.318165735683, 163.7917417584851);
            glVertex2f(1502.883304948859, 148.6145071443052);
        glEnd();


        glBegin(GL_POLYGON);     //car1window
        glColor3ub(71, 79, 83);
            glVertex2f(1502.883304948859, 148.6145071443052);
            glVertex2f(1501.5288554246495, 147.4286306316465);
            glVertex2f(1500.5011668760699, 146.0155654949025);
            glVertex2f(1502.6060801592628, 144.568437612706);
            glVertex2f(1506.3554569449502, 143.1870882706093);
            glVertex2f(1510.1371093465286, 142.552056656911);
            glVertex2f(1516.6209930098469, 142.2214253229734);
            glVertex2f(1520.2620272609333, 142.0133662229111);
            glVertex2f(1570.2352295596447, 173.1837594400908);
            glVertex2f(1556.0078707457812, 175.0145864297436);
            glVertex2f(1532.318165735683, 163.7917417584851);
        glEnd();


        glBegin(GL_POLYGON);     //car1window
        glColor3ub(1,1,1);
            glVertex2f(1524.1483347907554, 133.994360190737);
            glVertex2f(1535.4110606622778, 143.2772036416665);
            glVertex2f(1547.689697981596, 150.9513519662475);
            glVertex2f(1560, 160);

            glVertex2f(1569.2791803415869, 164.3031251611475);
            glVertex2f(1581.8339033668685, 169.6388824468972);
            glVertex2f(1595.6440986946784, 173.2483653166691);
            glVertex2f(1602.7978916125548, 174.3440730354614);
            glVertex2f(1656.9707398075304, 174.5248232454774);
            glVertex2f(1669.4081774477581, 172.1557875044794);
            glVertex2f(1682.4378740232348, 167.6151356675665);

            glVertex2f(1693.4933741478817, 162.4822248954042);
            glVertex2f(1704.5488742725286, 155.7699569625765);
            glVertex2f(1708.1595958205676, 151.0768028803541);
            glVertex2f(1702.5592961417688, 133.994360190737);
        glEnd();


        glBegin(GL_POLYGON);     //car1window
        glColor3ub(71, 79, 83);
            glVertex2f(1529.118748398073, 136.2659465428214);
            glVertex2f(1536.1150746958594, 141.7566021428575);
            glVertex2f(1548.6417152247784, 149.8192961769936);
            glVertex2f(1561.4319036445743, 157.9414627780736);

            glVertex2f(1570.1899305015477, 162.738660496958);
            glVertex2f(1582.8322230975498, 167.0752625710467);
            glVertex2f(1588.9156372093396, 168.5791526531986);
            glVertex2f(1617.1455110206016, 168.5811748936898);
            glVertex2f(1617.1455110206016, 136.2659465428214);
        glEnd();

        glBegin(GL_POLYGON);     //car1window
        glColor3ub(71, 79, 83);
            glVertex2f(1623.5754616901531, 136.2659465428214);
            glVertex2f(1623.5754616901531, 168.5791526531986);
            glVertex2f(1665.1643591615732, 168.5791526531986);
            glVertex2f(1665.1643591615732, 136.2659465428214);
        glEnd();

        glBegin(GL_POLYGON);     //car1window
        glColor3ub(71, 79, 83);
            glVertex2f(1671.1860706412433, 168.5791526531986);
            glVertex2f(1680.1631308221351, 164.3727953642939);
            glVertex2f(1688.9166527416528, 159.6977028434082);
            glVertex2f(1696.0796547827226, 155.4957621912506);

            glVertex2f(1702.7011529347023, 150.7553714688049);
            glVertex2f(1700.1151217748984, 136.2659465428214);
            glVertex2f(1671.1860706412433, 136.2659465428214);
        glEnd();

        glBegin(GL_POLYGON);     //car1window
        glColor3ub(71, 79, 83);
            glVertex2f(1690, 180);
            glVertex2f(1710.7855424140707, 172.1947626717054);
            glVertex2f(1755.8351739670582, 152.1211742596365);
            glVertex2f(1749.2432643645523, 147.6555269619759);
            glVertex2f(1697.2701263961007, 173.57674175902);
            glVertex2f(1690, 180);
        glEnd();

        glBegin(GL_POLYGON);    //lights
        glColor3ub(246, 241, 233);
            glVertex2f(1397.4909277367262, 108.6098400246408);
            glVertex2f(1399.544320048372, 113.4489827551592);
            glVertex2f(1403.0627876823619, 119.8216498046152);
            glVertex2f(1409.0700478732963, 119.3096427225466);

            glVertex2f(1408.042232157768, 111.7551972134043);
            glVertex2f(1403.57123379522, 106.2049923495446);
            glVertex2f(1399.716924861989, 106.7702909930859);
        glEnd();

        glBegin(GL_POLYGON);    //lights
        glColor3ub(246, 241, 233);
            glVertex2f(1409.0700478732963, 119.3096427225466);
            glVertex2f(1415.3855076255454, 121.4067857224794);
            glVertex2f(1425.5962390394982, 122.4070792806691);
            glVertex2f(1447.5622578880725, 123.0784816663039);

            glVertex2f(1448.6530649384088, 119.6969798102579);
            glVertex2f(1447.2350157729718, 115.9882358391107);

            glVertex2f(1443.4171910967955, 113.6975410334022);
            glVertex2f(1437.6359137300144, 111.6250076377611);
            glVertex2f(1431.8889935900922, 111.0033055295769);
            glVertex2f(1408.042232157768, 111.7551972134043);
        glEnd();

        glBegin(GL_POLYGON);    //lights
        glColor3ub(246, 33, 4);
            glVertex2f(1769.9933727601763, 130.6568686206931);
            glVertex2f(1776.7801484960298, 116.0168238190482);
            glVertex2f(1792.983752010349, 115.636075046198);
            glVertex2f(1794.127434306422, 132.560300163777);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
            glVertex2f(1592.4750086040583, 125.0013707315354);
            glVertex2f(1606.6307709094756, 125.0013707315354);
            glVertex2f(1609.3675516218561, 123.3026792548834);
            glVertex2f(1608.5182058835312,118.9615788145503);

            glVertex2f(1593.135610844978, 118.9615788145503);
            glVertex2f(1591.2481758709223, 122.0758465217458);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
            glVertex2f(1676.1522173517546, 118.9615788145503);
            glVertex2f(1691.732813267159, 118.9615788145503);
            glVertex2f(1694.167281378941, 124.0776407984034);
            glVertex2f(1691.61108986157, 125.0013707315354);

            glVertex2f(1676.5173875685218, 125.0013707315354);
            glVertex2f(1674.204642862329, 124.0776407984034);
            glVertex2f(1676.1522173517546, 118.9615788145503);
        glEnd();

        glLineWidth(1);

        glBegin(GL_LINES);
        glColor3ub(147,171,139);
            glVertex2f(1524.803558586959, 131.5142331552398);
            glVertex2f(1525.4458107735977, 73.6250267323157);

            glVertex2f(1525.4458107735977, 73.6250267323157);
            glVertex2f(1667.24603273276, 73.6250267323157);

            glVertex2f(1667.24603273276, 73.6250267323157);
            glVertex2f(1707.582886131696, 131.5142331552398);

            glVertex2f(1615.1843923056524, 131.5142331552398);
            glVertex2f(1615.1843923056524, 73.6250267323157);
        glEnd();

        s3_car1wheels(0,0,0);
        s3_car1wheels(237.14,0,0);

        glPopMatrix();
    }

}

void s3_updateCar777(int value) //17.1
{
    s3_car2_move += s3_car2_speed;

    // Reset position if car moves out of screen (adjust limit based on your scene width)
    if (s3_car2_move > 3000) {
        s3_car2_move = -500; // Reset from left side
    }

    glutPostRedisplay(); // Request redraw
    glutTimerFunc(16, s3_updateCar777, 0); // ~60 FPS (1000ms / 60 = ~16ms)
}

void s3_drawFog()
{
    if (!s3_fogOn) return;

    glColor4f(0.90f, 0.92f, 0.95f, s3_fogDensity * 0.75f);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(1900,0);
        glVertex2f(1900,1000);
        glVertex2f(0,1000);
    glEnd();

    float gndAlpha = s3_fogDensity * 0.15f;
    glColor4f(0.93f, 0.94f, 0.97f, gndAlpha);
    glBegin(GL_QUADS);
        glVertex2f(0,0);
        glVertex2f(1900,0);
        glVertex2f(1900,280);
        glVertex2f(0,280);
    glEnd();

    float riverAlpha = s3_fogDensity * 0.73f;
    glColor4f(0.88f, 0.90f, 0.94f, riverAlpha);
    glBegin(GL_QUADS);
        glVertex2f(0,280);
        glVertex2f(1900,280);
        glVertex2f(1900,650);
        glVertex2f(0,650);
    glEnd();

    float skyAlpha = s3_fogDensity * 1.25f;
    glColor4f(0.88f, 0.90f, 0.94f, skyAlpha);
    glBegin(GL_QUADS);
        glVertex2f(0,650);
        glVertex2f(1900,650);
        glVertex2f(1900,1000);
        glVertex2f(0,1000);
    glEnd();
}

// ============================================================
// SCENARIO 3 DISPLAY FUNCTION
// ============================================================
void displayScenario3()
{
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);  // Sky blue background (same as original s3_init)
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, winWidth, winHeight);

    // Enable alpha blending for fog overlay
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1900, 0, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // SKY (top layer background)
    s3_sky();

    s3_Cloud2(s3_cloud2, 40, 0);

    // BACK MOUNTAINS
    s3_backgroundmountain();

    // Birds
    for(int i = 0; i < 4; i++)
    {
        s3_drawBird(s3_birdX[i], s3_birdY[i]);
    }

    // Boat
    s3_boat27();

    // FRONT MOUNTAINS
    s3_Mountain();

    s3_sun();

    // CLOUDS (animated)
    s3_Cloud1(s3_cloud1, 0, 0);

    // LAND + RIVER
    s3_Land();
    s3_Land2();

    // BRIDGE + STRUCTURE
    s3_Bridge();
    s3_bridge_structure(0,0,0);
    s3_pilar_Shadow();

    // TREES
    s3_tree3(0,0,0);
    s3_tree3(-30,0,0);
    s3_tree3(60,0,0);
    s3_tree3(60,25,0);
    s3_tree3(120,0,0);
    s3_tree3(120,30,0);
    s3_tree3(180,0,0);
    s3_tree3(180,20,0);
    s3_tree3(240,0,0);
    s3_tree3(300,0,0);
    s3_tree3(360,0,0);
    s3_tree3(420,0,0);
    s3_tree3(480,0,0);
    s3_tree3(540,0,0);
    s3_tree3(600,0,0);
    s3_tree3(660,0,0);
    s3_tree3(720,0,0);
    s3_tree3(780,0,0);
    s3_tree3(840,0,0);
    s3_tree3(900,0,0);
    s3_tree3(960,0,0);
    s3_tree3(1020,0,0);
    s3_tree3(1080,0,0);
    s3_tree3(1120,0,0);

    s3_tree3detailing(0,0,0);
    s3_tree3detailing(3,-3,0);
    s3_tree3detailing(6,-6,0);
    s3_tree3detailing(50,0,0);
    s3_tree3detailing(50,-3,0);
    s3_tree3detailing(50,-6,0);
    s3_tree3detailing(50,-9,0);
    s3_tree3detailing(50,-12,0);
    s3_tree3detailing(100,0,0);
    s3_tree3detailing(100,-3,0);
    s3_tree3detailing(100,-6,0);
    s3_tree3detailing(150,0,0);
    s3_tree3detailing(150,-3,0);
    s3_tree3detailing(200,0,0);
    s3_tree3detailing(200,-3,0);
    s3_tree3detailing(200,-6,0);
    s3_tree3detailing(250,0,0);
    s3_tree3detailing(250,-3,0);
    s3_tree3detailing(250,-6,0);
    s3_tree3detailing(250,-9,0);
    s3_tree3detailing(300,0,0);
    s3_tree3detailing(300,-3,0);
    s3_tree3detailing(300,-6,0);
    s3_tree3detailing(350,0,0);
    s3_tree3detailing(350,-3,0);
    s3_tree3detailing(350,-6,0);
    s3_tree3detailing(400,0,0);
    s3_tree3detailing(400,-3,0);
    s3_tree3detailing(400,-6,0);
    s3_tree3detailing(400,-9,0);
    s3_tree3detailing(400,3,0);
    s3_tree3detailing(450,0,0);
    s3_tree3detailing(450,-3,0);
    s3_tree3detailing(450,-6,0);
    s3_tree3detailing(500,0,0);
    s3_tree3detailing(500,-3,0);
    s3_tree3detailing(500,-6,0);
    s3_tree3detailing(500,-9,0);
    s3_tree3detailing(500,-12,0);
    s3_tree3detailing(550,0,0);
    s3_tree3detailing(550,3,0);
    s3_tree3detailing(550,-3,0);
    s3_tree3detailing(550,-6,0);
    s3_tree3detailing(550,-9,0);
    s3_tree3detailing(550,-12,0);
    s3_tree3detailing(550,-15,0);
    s3_tree3detailing(600,0,0);
    s3_tree3detailing(600,-3,0);
    s3_tree3detailing(600,-6,0);
    s3_tree3detailing(650,0,0);
    s3_tree3detailing(650,-3,0);
    s3_tree3detailing(650,-6,0);
    s3_tree3detailing(700,0,0);
    s3_tree3detailing(700,-3,0);
    s3_tree3detailing(700,-9,0);
    s3_tree3detailing(750,0,0);
    s3_tree3detailing(750,-3,0);
    s3_tree3detailing(750,-6,0);
    s3_tree3detailing(800,0,0);
    s3_tree3detailing(800,-3,0);
    s3_tree3detailing(800,-6,0);
    s3_tree3detailing(800,-9,0);
    s3_tree3detailing(850,0,0);
    s3_tree3detailing(850,-3,0);
    s3_tree3detailing(850,-6,0);
    s3_tree3detailing(850,-9,0);
    s3_tree3detailing(850,-12,0);
    s3_tree3detailing(900,0,0);
    s3_tree3detailing(900,-3,0);
    s3_tree3detailing(900,-6,0);
    s3_tree3detailing(900,-9,0);
    s3_tree3detailing(950,0,0);
    s3_tree3detailing(950,-3,0);
    s3_tree3detailing(950,-6,0);
    s3_tree3detailing(1000,0,0);
    s3_tree3detailing(1000,-3,0);
    s3_tree3detailing(1000,-6,0);
    s3_tree3detailing(1000,-9,0);
    s3_tree3detailing(1050,0,0);
    s3_tree3detailing(1050,-3,0);
    s3_tree3detailing(1050,-6,0);
    s3_tree3detailing(1050,-9,0);
    s3_tree3detailing(1050,-12,0);
    s3_tree3detailing(1100,0,0);
    s3_tree3detailing(1100,-3,0);
    s3_tree3detailing(1100,-6,0);
    s3_tree3detailing(1150,0,0);
    s3_tree3detailing(1150,3,0);
    s3_tree3detailing(1150,-3,0);
    s3_tree3detailing(1200,0,0);
    s3_tree3detailing(1250,0,0);

    s3_Trees(0,0,0);
    s3_Trees(50,0,0);
    s3_Trees(-50,0,0);
    s3_Trees(-100,0,0);
    s3_Trees(-200,0,0);
    s3_Trees(-200,-100,0);
    s3_Trees(200,20,0);
    s3_Trees(-300,0,0);
    s3_Trees(-300,100,0);
    s3_Trees(-300,150,0);
    s3_Trees(-150,150,0);
    s3_Trees(-150,180,0);
    s3_Trees(-150,210,0);
    s3_Trees(-150,260,0);
    s3_Trees(-300,300,0);
    s3_Trees(-250,370,0);

    s3_tree2(0,0,0,1,1,1);
    s3_tree2(30,-240,0,1,1,1);
    s3_tree2(200,-200,0,1,1,1);
    s3_tree2(350,-200,0,1,1,1);
    s3_tree2(320,-100,0,1,1,1);
    s3_tree2(150,300,0,0.7,0.7,1);
    s3_tree2(200,300,0,0.7,0.7,1);
    s3_tree2(250,400,0,0.6,0.6,1);
    s3_tree2(300,500,0,0.5,0.5,1);
    s3_tree2(250,250,0,0.7,0.7,1);
    s3_tree2(320,250,0,0.7,0.7,1);
    s3_tree2(250,200,0,0.7,0.7,1);
    s3_tree2(350,200,0,0.7,0.7,1);

    s3_pilar_Shadow();
    s3_river();

    s3_Land2();

    // LEFT TREES
    s3_Left_tree(0,100,0);
    s3_Left_tree(100,120,0);
    s3_Left_tree(100,200,0);
    s3_Left_tree(100,280,0);
    s3_Left_tree(-1700,30,0);

    s3_Bridge();
    s3_bridge_structure(0,0,0);
    s3_bridge_structure(640,0,0);
    s3_bridge_structure(1280,0,0);

    s3_BackFlower(0,400,0);
    s3_BackFlower(100,500,0);
    s3_BackFlower(-70,480,0);
    s3_BackFlower(250,280,0);
    s3_BackFlower(280,290,0);
    s3_BackFlower(20,250,0);
    s3_BackFlower(210,600,0);

    s3_Train();

    s3_left_tree2(-1100,-110,0);
    s3_left_tree2(-1300,-100,0);
    s3_left_tree2(-1200,-105,0);
    s3_left_tree2(150,-90,0);
    s3_left_tree2(200,-90,0);
    s3_left_tree2(300,-100,0);
    s3_left_tree2(400,-110,0);
    s3_left_tree2(480,-110,0);
    s3_left_tree2(50,-105,0);

    s3_road();
    s3_road_piller(0,0,0);
    s3_road_piller(25,0,0);
    s3_road_piller(50,0,0);
    s3_road_piller(75,0,0);
    s3_road_piller(100,0,0);
    s3_road_piller(125,0,0);
    s3_road_piller(150,0,0);
    s3_road_piller(175,0,0);
    s3_road_piller(200,0,0);
    s3_road_piller(225,0,0);
    s3_road_piller(250,0,0);
    s3_road_piller(275,0,0);
    s3_road_piller(300,0,0);
    s3_road_piller(325,0,0);
    s3_road_piller(350,0,0);
    s3_road_piller(375,0,0);
    s3_road_piller(400,0,0);
    s3_road_piller(425,0,0);
    s3_road_piller(450,0,0);
    s3_road_piller(475,0,0);
    s3_road_piller(500,0,0);
    s3_road_piller(525,0,0);
    s3_road_piller(550,0,0);
    s3_road_piller(575,0,0);
    s3_road_piller(600,0,0);
    s3_road_piller(625,0,0);
    s3_road_piller(650,0,0);
    s3_road_piller(675,0,0);
    s3_road_piller(700,0,0);
    s3_road_piller(725,0,0);
    s3_road_piller(750,0,0);
    s3_road_piller(775,0,0);
    s3_road_piller(800,0,0);
    s3_road_piller(825,0,0);
    s3_road_piller(850,0,0);
    s3_road_piller(875,0,0);
    s3_road_piller(900,0,0);
    s3_road_piller(925,0,0);
    s3_road_piller(950,0,0);
    s3_road_piller(975,0,0);
    s3_road_piller(1000,0,0);
    s3_road_piller(1025,0,0);
    s3_road_piller(1050,0,0);
    s3_road_piller(1075,0,0);
    s3_road_piller(1100,0,0);
    s3_road_piller(1125,0,0);
    s3_road_piller(1150,0,0);
    s3_road_piller(1175,0,0);
    s3_road_piller(1200,0,0);
    s3_road_piller(1225,0,0);
    s3_road_piller(1250,0,0);
    s3_road_piller(1275,0,0);
    s3_road_piller(1300,0,0);
    s3_road_piller(1325,0,0);
    s3_road_piller(1350,0,0);
    s3_road_piller(1375,0,0);
    s3_road_piller(1400,0,0);
    s3_road_piller(1425,0,0);
    s3_road_piller(1450,0,0);
    s3_road_piller(1475,0,0);
    s3_road_piller(1500,0,0);
    s3_road_piller(1525,0,0);
    s3_road_piller(1550,0,0);
    s3_road_piller(1575,0,0);
    s3_road_piller(1600,0,0);
    s3_road_piller(1625,0,0);
    s3_road_piller(1650,0,0);
    s3_road_piller(1675,0,0);
    s3_road_piller(1700,0,0);
    s3_road_piller(1725,0,0);
    s3_road_piller(1750,0,0);
    s3_road_piller(1775,0,0);
    s3_road_piller(1800,0,0);
    s3_road_piller(1825,0,0);
    s3_road_piller(1850,0,0);
    s3_road_piller(1875,0,0);
    s3_road_piller(1900,0,0);

    s3_road_piller2(0,0,0);
    s3_road_piller2(100,0,0);
    s3_road_piller2(200,0,0);
    s3_road_piller2(300,0,0);
    s3_road_piller2(400,0,0);
    s3_road_piller2(500,0,0);
    s3_road_piller2(600,0,0);
    s3_road_piller2(700,0,0);
    s3_road_piller2(800,0,0);
    s3_road_piller2(900,0,0);
    s3_road_piller2(1000,0,0);
    s3_road_piller2(1100,0,0);
    s3_road_piller2(1200,0,0);
    s3_road_piller2(1300,0,0);
    s3_road_piller2(1400,0,0);
    s3_road_piller2(1500,0,0);
    s3_road_piller2(1600,0,0);
    s3_road_piller2(1700,0,0);
    s3_road_piller2(1800,0,0);
    s3_road_piller2(1880,0,0);

    s3_Left_tree(-1600,0,0);
    s3_Left_tree(0,0,0);

    glColor3ub(180, 0, 0);
    s3_Flower(0,0,0);
    s3_Flower(-70,-20,0);
    s3_Flower(-130,10,0);

    s3_RightFlower(1700,110,0);
    s3_RightFlower(1600,80,0);
    s3_RightFlower(1570,75,0);
    s3_RightFlower(1585,60,0);
    s3_RightFlower(1530,15,0);

    s3_bus7();
    s3_cargo_Truck(s3_cargoPosition3, 20, 0);
    s3_car7777777();

    // FOG OVERLAY (drawn last so it covers everything)
    s3_drawFog();

    glutSwapBuffers();
    glFlush();
}

// ============================================================
// UNIFIED DISPLAY MAIN (3 Scenarios)
// ============================================================
void displayMain()
{
    if (currentScenario == 1)
        displayScenario1();
    else if (currentScenario == 12)
        displayScenario1Rain();
    else if (currentScenario == 2)
        displayScenario2();
    else if (currentScenario == 3)
        displayScenario3();
}

// ============================================================
// UNIFIED KEYBOARD HANDLER (3 Scenarios)
// ============================================================
void handleKeypress(unsigned char key, int x, int y)
{
    // --- Scenario Switch Keys (work always) ---
    if (key == '0') { currentScenario = 1; glutPostRedisplay(); return; }
    if (key == '9') { currentScenario = 2; glutPostRedisplay(); return; }
    if (key == '8') { currentScenario = 3; glutPostRedisplay(); return; }

    // --- Scenario 1 Keys ---
    if (currentScenario == 1 || currentScenario == 12)
    {
        switch (key)
        {
        case 'a': speed = 0.0; break;
        case 's':
            if (speed == 0) speed = 1.0;
            if (speed >= 1 && speed <= 4) speed *= 2.0;
            else speed = 1.1;
            break;
        case 't': currentScenario = 1; break;
        case 'r': currentScenario = 12; break;
        }
    }

    // --- Scenario 2 Keys ---
    if (currentScenario == 2)
    {
        switch (key)
        {
        case 'r': hlCar1 = !hlCar1; break;
        case 'a':
            if (dirCar1 == -1) speedCar1 += accel;
            else { speedCar1 -= accel; if (speedCar1 <= 0) { speedCar1 = 0; dirCar1 = -1; } }
            break;
        case 'q':
            if (dirCar1 == 1) speedCar1 += accel;
            else { speedCar1 -= accel; if (speedCar1 <= 0) { speedCar1 = 0; dirCar1 = 1; } }
            break;
        case 'z': speedCar1 = 0; wheelSpeed1 = 0; break;
        case 'f': hlCar2 = !hlCar2; break;
        case 'w':
            if (dirCar2 == 1) speedCar2 += accel;
            else { speedCar2 -= accel; if (speedCar2 <= 0) { speedCar2 = 0; dirCar2 = 1; } }
            break;
        case 's':
            if (dirCar2 == -1) speedCar2 += accel;
            else { speedCar2 -= accel; if (speedCar2 <= 0) { speedCar2 = 0; dirCar2 = -1; } }
            break;
        case 'x': speedCar2 = 0; wheelSpeed2 = 0; break;
        case 'e': callStars = -1 * callStars; break;
        case 'd': callMoon = -1 * callMoon; break;
        case 'c': moveLeaf = -1 * moveLeaf; break;
        case 'v': nlRoad = -1 * nlRoad; break;
        case '1': nlBuilding1 *= -1; break;
        case '2': nlBuilding2 *= -1; break;
        case '3': nlBuilding3 *= -1; break;
        case '4': nlBuilding4 *= -1; break;
        case '5': nlBuilding5 *= -1; break;
        case '6': nlBuilding6 *= -1; break;
        case '7': nlBuilding7 *= -1; break;
        case 'y': nlBackBuilding1 *= -1; break;
        case 'h': nlBackBuilding2 *= -1; break;
        case 'n': nlBackBuilding3 *= -1; break;
        case 'u': nlBackBuilding4 *= -1; break;
        case 't': moveBoat = moveBoat * -1; break;
        case 'g': nlBoat = nlBoat * -1; break;
        case 'b':
            nightSky = nightSky * -1;
            if (nightSky == -1) {
                nlRoad = -1; nlBuilding2 = -1; nlBuilding3 = -1; nlBuilding6 = -1;
                nlBackBuilding3 = -1; hlCar1 = -1; hlCar2 = -1; nlBoat = -1; ntWindow = -1;
            } else {
                nlRoad = 1; callStars = 1;
                nlBuilding1 = 1; nlBuilding2 = 1; nlBuilding3 = 1;
                nlBuilding4 = 1; nlBuilding5 = 1; nlBuilding6 = 1; nlBuilding7 = 1;
                nlBackBuilding1 = 1; nlBackBuilding2 = 1;
                nlBackBuilding3 = 1; nlBackBuilding4 = 1;
                hlCar1 = 1; hlCar2 = 1; nlBoat = 1; ntWindow = 1;
            }
            break;
        }
        if (speedCar1 > maxSpeed) speedCar1 = maxSpeed;
        if (speedCar2 > maxSpeed) speedCar2 = maxSpeed;
    }

    // --- Scenario 3 Keys ---
    if (currentScenario == 3)
    {
        // Fog toggle
        if (key == 'f' || key == 'F') { s3_fogOn = !s3_fogOn; }
        if (key == '+' && s3_fogDensity < 0.9f) s3_fogDensity += 0.05f;
        if (key == '-' && s3_fogDensity > 0.1f) s3_fogDensity -= 0.05f;

        switch (key)
        {
        // Train control
        case 't': s3_train_speed += 1.0f; break;
        case 'g': s3_train_speed -= 1.0f; break;
        case 's': s3_train_speed = 0.0f; break;
        case 'r': s3_train_speed = 7.0f; break;
        // Car control
        case 'c': s3_car2_speed += 1.0f; break;
        case 'v': s3_car2_speed -= 1.0f; break;
        case 'b': s3_car2_speed = 0.0f; break;
        case 'a': s3_car2_speed = 6.0f; break;
        }
    }

    glutPostRedisplay();
}

// ============================================================
// UNIFIED MOUSE HANDLER (3 Scenarios)
// ============================================================
void handleMouse(int button, int state, int x, int y)
{
    if (currentScenario == 1 || currentScenario == 12)
    {
        if (button == GLUT_LEFT_BUTTON)  cloudSpeed += 1.1;
        if (button == GLUT_RIGHT_BUTTON) cloudSpeed -= 1.1;
        if (cloudSpeed < 0.1) cloudSpeed = 0.1;
        if (cloudSpeed > 10.0) cloudSpeed = 10.0;
    }
    else if (currentScenario == 2)
    {
        if (state == GLUT_DOWN) {
            if (button == GLUT_LEFT_BUTTON)       moveClouds = 1;
            else if (button == GLUT_RIGHT_BUTTON) { moveClouds = -1; speedCloud = 0.0f; }
            else if (button == 3)                 { moveClouds = 1; speedCloud += 0.2f; }
            else if (button == 4)                   speedCloud -= 0.2f;
        }
        if (speedCloud > 5)  speedCloud = 5;
        if (speedCloud < -5) speedCloud = -5;
    }
    else if (currentScenario == 3)
    {
        if (button == GLUT_LEFT_BUTTON)  s3_boatSpeed2 += 0.1f;
        if (button == GLUT_RIGHT_BUTTON) s3_boatSpeed2 -= 0.1f;
    }
    glutPostRedisplay();
}

// ============================================================
// MAIN
// ============================================================
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1450, 780);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("A BEAUTIFUL CITY  |  Press 0=City  9=River City  8=Train & Bridge");

    // Enable alpha blending globally (needed for Scenario 3 fog)
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 700, 0, 800, -10.0, 10.0);

    // Initialize rain drops (Scenario 1)
    for (int i = 0; i < totalDrops; i++) {
        dropX[i] = rand() % 1900;
        dropY[i] = rand() % 1000;
    }

    glutDisplayFunc(displayMain);
    glutReshapeFunc(reshape);
    glutMouseFunc(handleMouse);
    glutKeyboardFunc(handleKeypress);

    // Scenario 1 timers
    glutTimerFunc(16, updateTime, 0);
    glutTimerFunc(16, sc1_updateBird, 0);
    glutTimerFunc(16, updateRain, 0);

    // Scenario 2 timers
    glutTimerFunc(30, timer, 0);
    glutTimerFunc(20, updateWheelRotation, 0);
    glutTimerFunc(20, moveSunMoonLocation, 0);
    glutTimerFunc(20, moveCloud, 0);
    glutTimerFunc(20, moveRiver, 0);
    glutTimerFunc(20, moveCar, 0);
    glutTimerFunc(20, BoatMovement, 0);

    // Scenario 3 timers
    glutTimerFunc(16, s3_train_update, 0);
    glutTimerFunc(80, s3_updateboat2, 0);
    glutTimerFunc(5,  s3_updateCloud, 0);
    glutTimerFunc(16, s3_updateBridgeLight, 0);
    glutTimerFunc(16, s3_updateBus, 0);
    glutTimerFunc(16, s3_updatecargo, 0);
    glutTimerFunc(16, s3_updateCar777, 0);
    glutTimerFunc(16, s3_updateWave, 0);
    glutTimerFunc(16, s3_updateBird, 0);

    glutMainLoop();
    return 0;
}
