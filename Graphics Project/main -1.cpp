#include <iostream>
#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define pi 3.142857
#include<iostream>
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


void handleMouse(int button, int state, int x, int y) {

 if (button == GLUT_LEFT_BUTTON)
	{
	    cloudSpeed += 1.1;
    }
 if (button == GLUT_RIGHT_BUTTON)
	{
	    cloudSpeed -= 1.1;
	}
 if (cloudSpeed < 0.1)
        cloudSpeed = 0.1;
 if (cloudSpeed > 10.0)
        cloudSpeed = 10.0;
glutPostRedisplay();
}

void updateTime(int value) {
   // Move the bus right
     cloudposition+=cloudSpeed;

     busPosition2+=0.90;
     busPosition +=speed;
     sunPosY += speedY;
     angle -= 1.0f;

 if (busPosition > 800)      busPosition = -100.0;
 if (busPosition2 > 800)     busPosition2 = -100.0;
 if (cloudposition > 800)    cloudposition = -450.0;
 if (sunPosY > 705)          sunPosY = 705;
 if (angle < -360)           angle += 360;

    glutPostRedisplay();
    glutTimerFunc(16, updateTime, 0);
}

void display ()
{
    glClear(GL_COLOR_BUFFER_BIT);

    background();//1
    road();//2
    tree1();//3
    tree2();//4
    tree3();//5
    tree4();//6
    tree5();//7
    tree6();//8
    tree7();//9
    firstBuilding();//10
    secondBuilding();//11
    tower(angle);//12 A1
    thirdBuilding();//13
    forthBuilding();//14
    sun();//15 A2
    foodCourt();//16
    triangleTree5();//17
    triangleTree6();//28
    triangleTree();//18
    triangleTree1();//19
    triangleTree2();//20
    triangleTree3();//21
    triangleTree4();//22
    sunCoverCloud();//23
    cloud();//24 A3
    cloud2();//25
    bus();//26 A4
    bus2();//27 A5

    glutPostRedisplay();
    glutSwapBuffers();

    glFlush();
}

void display2(){
     glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);
    glColor3f(0.3f, 0.4f, 0.3f); // Rain color (light blue)

    background1();//29
    road();//2
    tree1();//3
    tree2();//4
    tree3();//5
    tree4();//6
    tree5();//7
    tree6();//8
    tree7();//9
    firstBuilding();//10
    secondBuilding();//11
    tower(angle);//12 A1
    thirdBuilding();//13
    forthBuilding();//14
    foodCourt();//16
    triangleTree5();//17
    triangleTree6();//28
    triangleTree();//18
    triangleTree1();//19
    triangleTree2();//20
    triangleTree3();//21
    triangleTree4();//22

    cloud();//24 A3
    cloud2();//25
   drawRainfall();//30 A6
   drawRainfall();//30 A6


 glutSwapBuffers();
}
void handleKeypress(unsigned char key, int x, int y) {

    switch (key) {
        case 'a':
            speed = 0.0;
            break;
        case 's':

       if (speed ==0)
           speed = 1.0;

        if(speed>=1 && speed<=4)
        speed*=2.0;

            else
                speed =1.1;

        break;

case 't':
    glutDisplayFunc(display);
    glutPostRedisplay();
    break;
case 'r':
    glutDisplayFunc(display2);
    glutPostRedisplay();
    break;


    }
    glutPostRedisplay();  // Redraw the window after key press
}

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1450, 750);
    glutInitWindowPosition(100, 0);

    glutCreateWindow("A BEAUTIFUL CITY");
    myInit();
     glutDisplayFunc(display2);
    glutDisplayFunc(display);

    glutMouseFunc(handleMouse);
    glutKeyboardFunc(handleKeypress);

    glutTimerFunc(16, updateTime, 0);
    glutTimerFunc(16, updateRain, 0);
    glutMainLoop();
}
