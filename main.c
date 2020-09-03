#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>

#include "stage.h"
#include "table.h"
#include "hat.h"
#include "rabbit.h"
#include "magic_wand.h"

#define TIMER_ID_PLAY (0)
#define TIMER_ID_RABBIT_JUPM (1)
#define TIMER_ID_TIME (2)

#define TIME_TO_PLAY (20)

static void on_special_keyboard(int key, int x, int y);
static void on_keyboard(unsigned char key, int x, int y);
static void on_keyboard_up(unsigned char key, int x, int y);
static void on_reshape(int sirina, int visina);
static void on_display(void);
static void on_timer(int id);

static void hats_in_place(void);
static void rabbit_in_place(void);

static int animation_ongoing = 0;
static int rabbit_position = 0;

int timer = 0;

static int rabbit_jump = 0;
static int magic_wand_x = 0;
static int magic_wand_z = 0;
static int magic_wand_angle = 0;
static int magic = 0;

static int points = 0;
static int got_a_point = 0;

static int width;
static int height;


int main(int argc, char **argv){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Catch me if you can!");
    
    glutSpecialFunc(on_special_keyboard);
    glutKeyboardFunc(on_keyboard);
    glutKeyboardUpFunc(on_keyboard_up);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    
    glClearColor(0, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    
    GLfloat light_position[] = {0, 15, 35, 1};
    GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 0 };
    GLfloat light_diffuse[] = { 1, 1, 1, 0 };
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    
    srand(time(NULL));
    
    glutMainLoop();
    
    return 0;
}

static void hats_in_place(void){
    
    float k,v;
    for(k = -5; k <= 5; k += 5){
        for(v = -14; v <= 14; v += 7){
            glPushMatrix();
                glTranslatef(k, 0, v);
                hat();
            glPopMatrix();
        }
    }
}

static int hat_number(int lower, int upper){
    return (rand() % (upper - lower + 1)) + lower; 
}

static void on_special_keyboard(int key, int x, int y){
    if(animation_ongoing){
        switch(key){
            case GLUT_KEY_LEFT:
                if(magic_wand_x > -25 ){
                    magic_wand_x -= 5;
                    glutPostRedisplay();
                }
                break;
            case GLUT_KEY_RIGHT:
                if(magic_wand_x < 25){
                    magic_wand_x += 5;
                    glutPostRedisplay();
                }
                break;
            case GLUT_KEY_UP:
                if(magic_wand_z > -35){
                    magic_wand_z -= 7;
                    glutPostRedisplay();
                }
                break;
            case GLUT_KEY_DOWN:
                if(magic_wand_z < 20){
                    magic_wand_z += 7;
                    glutPostRedisplay();
                }
                break;
            }
    }
}

static void on_keyboard_up(unsigned char key, int x1, int y){
    switch (key) {
    case 32:
        if(animation_ongoing){
            magic_wand_angle -= 45;
            magic = 0;
            glutPostRedisplay();
        }
        break;
    }
    
}

static void on_keyboard(unsigned char key, int x1, int y){
    
    switch (key) {
    case 32:
        if(animation_ongoing){
            magic_wand_angle += 45;
            magic = 1;
            glutPostRedisplay();
        }
        break;
    case 'q':
    case 'Q':
        exit(0);
        break;
    case 's':
    case 'S':
        if(!animation_ongoing){
            animation_ongoing = 1;
            glutTimerFunc(100, on_timer, TIMER_ID_RABBIT_JUPM);
            glutTimerFunc(1000, on_timer, TIMER_ID_TIME);
            glutTimerFunc(2000, on_timer, TIMER_ID_PLAY);
        }
        break;
    case 'p':
    case 'P':
        animation_ongoing = 0;
        break;
    case 'r':
    case 'R':
        magic_wand_angle = 0;
        rabbit_position = 0;
        timer = 0;
        rabbit_jump = 0;
        got_a_point = 0;
        points = 0;
        glutPostRedisplay();
        break;
    }
    
}

void drawText(float x, float y, char *text) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        
            glLoadIdentity();
            
            gluOrtho2D(0, width, height, 0);
            
            glRasterPos2f(x, y);
            
            int i;
            for (i = 0; i < strlen(text); i++) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);  
            }
            
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    
    glutPostRedisplay();
}

static void on_reshape(int width1, int height1){
    width = width1;
    height = height1;
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    

    gluPerspective(60, (float) width / height, 1, 100);
}
static void on_timer(int id){
    
    switch(id){
        case TIMER_ID_PLAY:
            if(animation_ongoing && timer < TIME_TO_PLAY){
                rabbit_position = hat_number(1, 15);
                rabbit_jump = 0;
                if(got_a_point){
                    points += 1;
                    got_a_point = 0;
                }
                glutTimerFunc(100, on_timer, 1);
                glutTimerFunc(2000, on_timer, 0);
            }
            break;
        case TIMER_ID_RABBIT_JUPM:
            if(animation_ongoing && timer < TIME_TO_PLAY){
                if(rabbit_jump == 3){
                    rabbit_jump = 3;
                } else {
                    rabbit_jump += 1;
                    glutTimerFunc(100, on_timer, 1);
                    
                }
            }
            break;
        case TIMER_ID_TIME:
            if(animation_ongoing && timer < TIME_TO_PLAY){
                timer += 1;
                glutTimerFunc(1000, on_timer, 2);
            } else {
                if(timer >= TIME_TO_PLAY){
                    animation_ongoing = 0;        
                    return;
                }
                
            }
            break;
        default:
            return;
    }

    glutPostRedisplay();
   
}

static void rabbit_in_place(void){
    switch(rabbit_position){
        case 1:
            glTranslatef(-5, 0, 14);
            if(magic && magic_wand_x == 0 && magic_wand_z == 14){
                got_a_point = 1;
            }
            break;
        case 2:
            glTranslatef(0, 0, 14);
            if(magic && magic_wand_x == 5 && magic_wand_z == 14){
                got_a_point = 1;
            }
            break;
        case 3:
            glTranslatef(5, 0, 14);
            if(magic && magic_wand_x == 10 && magic_wand_z == 14){
                got_a_point = 1;
            }
            break;
        case 4:
            glTranslatef(-5, 0, 7);
            if(magic && magic_wand_x == 0 && magic_wand_z == 7){
                got_a_point = 1;
            }
            break;
        case 5:
            glTranslatef(0, 0, 7);
            if(magic && magic_wand_x == 5 && magic_wand_z == 7){
                got_a_point = 1;
            }
            break;
        case 6:
            glTranslatef(5, 0, 7);
            if(magic && magic_wand_x == 10 && magic_wand_z == 7){
                got_a_point = 1;
            }
            break;
        case 7:
            glTranslatef(-5, 0, 0);
            if(magic && magic_wand_x == 0 && magic_wand_z == 0){
                got_a_point = 1;
            }
            break;
        case 8:
            glTranslatef(0, 0, 0);
            if(magic && magic_wand_x == 5 && magic_wand_z == 0){
                got_a_point = 1;
            }
            break;
        case 9:
            glTranslatef(5, 0, 0);
            if(magic && magic_wand_x == 10 && magic_wand_z == 0){
                got_a_point = 1;
            }
            break;
        case 10:
            glTranslatef(-5, 0, -7);
            if(magic && magic_wand_x == 0 && magic_wand_z == -7){
                got_a_point = 1;
            }
            break; 
        case 11:
            glTranslatef(0, 0, -7);
            if(magic && magic_wand_x == 5 && magic_wand_z == -7){
                got_a_point = 1;
            }
            break;
        case 12:
            glTranslatef(5, 0, -7);
            if(magic && magic_wand_x == 10 && magic_wand_z == -7){
                got_a_point = 1;
            }
            break;
        case 13:
            glTranslatef(-5, 0, -14);
            if(magic && magic_wand_x == 0 && magic_wand_z == -14){
                got_a_point = 1;
            }
            break;
        case 14:
            glTranslatef(0, 0, -14);
            if(magic && magic_wand_x == 5 && magic_wand_z == -14){
                got_a_point = 1;
            }
            break;
         case 15:
             glTranslatef(5, 0, -14);
             if(magic && magic_wand_x == 10 && magic_wand_z == -14){
                got_a_point = 1;
            }
            break;
    }
    
    glTranslatef(0, rabbit_jump, 0);
    glScalef(0.5, 0.5, 0.5);
    rabbit();
}


static void on_display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    gluLookAt(0, 15, 35, 0, 0, 0, 0, 1, 0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPushMatrix();
        char textT[15]; 
        char text_time[3];
        sprintf(text_time, "%d", timer);
        strcpy(textT, "Time: ");
        strcat(textT, text_time);
        drawText(20, 40, textT);
    glPopMatrix();
    
    glPushMatrix();
        char textP[11]; 
        char text_point[2];
        sprintf(text_point, "%d", points);
        strcpy(textP, "Points: ");
        strcat(textP, text_point);
        drawText(20, 20, textP);
    glPopMatrix();
    
    if(timer >= 20){
        glPushMatrix();
            char text[] = {"Time's up!"}; 
            drawText(width/2-50, 20, text);
        glPopMatrix();
    }
    
    stage();
    table();
    hats_in_place();
    
    glPushMatrix();
        glTranslatef(magic_wand_x, 5, magic_wand_z);
        glRotatef(magic_wand_angle, 0, 0, 1);
        magic_wand();
    glPopMatrix();
    
    glPushMatrix();
        if(rabbit_position){
            rabbit_in_place();
        }
    glPopMatrix();
    
    glutSwapBuffers();
    
}
