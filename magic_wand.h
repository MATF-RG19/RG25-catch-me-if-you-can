#ifndef MAGIC_WAND_H
#define MAGIC_WAND_H

static void magic_wand(void){    
    glDisable(GL_LIGHTING);
    
    glRotatef(45, 0, 0, 1);
    
    glPushMatrix();
        glColor3f(1, 1, 1);
        glRotatef(90, 0, 0, 1);
        glRotatef(90, 0, 1, 0);
        gluCylinder(gluNewQuadric(), 0.2, 0.2, 4, 20, 20);
    glPopMatrix();
    
    glPushMatrix();
        glColor3f(0.2, 0.2, 0.2);
        glTranslatef(0, 4, 0);
        glRotatef(90, 0, 0, 1);
        glRotatef(90, 0, 1, 0);
        gluCylinder(gluNewQuadric(), 0.2, 0.2, 1, 20, 20);
    glPopMatrix();
 
    glEnable(GL_LIGHTING);
}

#endif
