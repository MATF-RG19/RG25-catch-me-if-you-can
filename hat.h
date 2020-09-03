#ifndef HAT_H
#define HAT_H

static void hat(void){
    
    GLfloat ambient_coeffs[] = { 0.02, 0.02, 0.02, 1.0 };
    GLfloat diffuse_coeffs[] = { 0.01, 0.01, 0.01, 1.0 };
    GLfloat specular_coeffs[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat shininess = 10;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
        
    glPushMatrix();
        glTranslatef(0, 4, 0);
        glRotatef(90, 0, 0, 1);
        glRotatef(90, 0, 1, 0);
        gluDisk(gluNewQuadric(), 1.9, 2.5, 40, 40);
    glPopMatrix();
    
    glPushMatrix();
        glRotatef(90, 0, 0, 1);
        glRotatef(90, 0, 1, 0);
        gluCylinder(gluNewQuadric(), 2, 2, 4, 20, 20);
    glPopMatrix();
}

#endif
