#ifndef STAGE_H
#define STAGE_H

static void stage(void){
    
    /* floor */
    glPushMatrix();
    
        GLfloat ambient_coeffs[] = { 0.3803921569, 0.6039215686, 0.6901960784, 0 };
        GLfloat diffuse_coeffs[] = { 1, 0.2901960784, 0.2901960784, 0 };
        GLfloat specular_coeffs[] = { 0.297254, 0.30829, 0.306678, 0.8 };
        GLfloat shininess = 10;
    
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    
        glBegin(GL_POLYGON);
            glNormal3f(0, 1, 0);
            glVertex3f(30, -8.8, -35);
            glVertex3f(-30, -8.8, -35);
            glVertex3f(-30, -8.8, 35);
            glVertex3f(30, -8.8, 35);
        glEnd();
        
    glPopMatrix();
    
    /* walls */
    GLfloat ambient_coeffs1[] = { 0.831372549, 0.6431372549, 0.4392156863, 0 };
    GLfloat diffuse_coeffs1[] = { 1, 0.768627451, 0.5215686275, 0 };
    GLfloat specular_coeffs1[] = { 0.04, 0.7 ,0.7, 1.0 };
    GLfloat shininess1 = 50;
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs1);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs1);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs1);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess1);

    /* left wall */
    glPushMatrix();
        glBegin(GL_POLYGON);
            glNormal3f(0.5, -0.5, 1.5);
            glVertex3f(-30, -8.8, -35);
            glVertex3f(-30, 40, -35);
            glVertex3f(-30, 40, 35);
            glVertex3f(-30, -8.8, 35);
        glEnd();
    glPopMatrix();
    
    /* right wall */
    glPushMatrix();
        glBegin(GL_POLYGON);
            glNormal3f(-0.5, -0.5, 1.5);
            glVertex3f(30, -8.8, -35);
            glVertex3f(30, 40, -35);
            glVertex3f(30, 40, 35);
            glVertex3f(30, -8.8, 35);
        glEnd();
    glPopMatrix();
    
    /* central wall */
    glPushMatrix();
        glBegin(GL_POLYGON);
            glNormal3f(0, -0.2, 1);
            glVertex3f(30, -8.8, -35);
            glVertex3f(30, 40, -35);
            glVertex3f(-30, 40, -35);
            glVertex3f(-30, -8.8, -35);
        glEnd();
    glPopMatrix();
}

#endif
