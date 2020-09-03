#ifndef RABBIT_H
#define RABBIT_H

static void rabbit(void){
    
    glDisable(GL_LIGHTING);
    
    /* rabbit ears */
    
    /* left ear */
    glPushMatrix();
        glColor3f(0.75, 0.2, 0.2);
        glTranslatef(-0.6, 7, -0.1);
        glScalef(0.25, 1.5, 0.25);
        glutSolidSphere(1, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(-0.6, 7, -0.5);
        glScalef(0.5, 3, 0.5);
        glutSolidSphere(1, 40, 40);
    glPopMatrix();

    /* right ear */
    glPushMatrix();
        glColor3f(0.75, 0.2, 0.2);
        glTranslatef(0.6, 7, -0.1);
        glScalef(0.25, 1.5, 0.25);
        glutSolidSphere(1, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(0.6, 7, -0.5);
        glScalef(0.5, 3, 0.5);
        glutSolidSphere(1, 40, 40);
    glPopMatrix();
    
    
    /* head of a rabbit */
    glPushMatrix();
        glColor3f(1, 1, 1);
        glTranslatef(0, 4, 0);
        glutSolidSphere(1.5, 40, 40);
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(0, 3.25, 1.5);
        glPushMatrix();
            /* nose of a rabbit */
            glColor3f(0, 0, 0);
            glBegin(GL_LINE_STRIP);
                glVertex3f(-0.2, 0.3, 0);
                glVertex3f(0, 0, 0);
                glVertex3f(0.2, 0.3, 0);
            glEnd();
            
            glColor3f(0.75, 0.2, 0.2);
            glBegin(GL_LINES);
                glVertex3f(0, 0, 0);
                glVertex3f(0, -0.3, 0);
            glEnd();
            
            /* mouth of a rabbit */
            glColor3f(0.75, 0.2, 0.2);
            glBegin(GL_LINE_STRIP);
                glVertex3f(-0.2, -0.3, 0);
                glVertex3f(0, 0, 0);
                glVertex3f(0.2, -0.3, 0);
            glEnd();
            
            /* rabbit mustache */
            glColor3f(0.7, 0.7, 0.7);
            glBegin(GL_LINES);
                glVertex3f(0, 0, 0);
                glVertex3f(-2, 0, 0);
            glEnd();
            
            glBegin(GL_LINES);
                glVertex3f(0, 0, 0);
                glVertex3f(-2, 0.3, 0);
            glEnd();
            
            glBegin(GL_LINES);
                glVertex3f(0, 0, 0);
                glVertex3f(-2, -0.3, 0);
            glEnd();

            glBegin(GL_LINES);
                glVertex3f(0, 0, 0);
                glVertex3f(2, 0, 0);
            glEnd();

            glBegin(GL_LINES);
                glVertex3f(0, 0, 0);
                glVertex3f(2, 0.3, 0);
            glEnd();
            
            glBegin(GL_LINES);
                glVertex3f(0, 0, 0);
                glVertex3f(2, -0.3, 0);
            glEnd();
            
        glPopMatrix();
    glPopMatrix();
    
    /* eyes of a rabbit */
    /* left eye */
    glPushMatrix();
        glColor3f(0, 0, 0);
        glTranslatef(-0.6, 4, 1.4);
        glutSolidSphere(0.25, 40, 40);
    glPopMatrix();

    /* right eye */
    glPushMatrix();
        glColor3f(0, 0, 0);
        glTranslatef(0.6, 4, 1.4);
        glutSolidSphere(0.25, 40, 40);
    glPopMatrix();

    
    /* body of a rabbit */
    glScalef(2, 3, 2);
    glColor3f(1, 1, 1);
    glutSolidSphere(1, 40, 40);
    
    glEnable(GL_LIGHTING);
}


#endif
