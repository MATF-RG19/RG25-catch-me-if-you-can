#ifndef TABLE_H
#define TABLE_H

static void table(void){

    GLfloat ambient_coeffs[] = { 0.2125, 0.1275, 0.054, 1.0 };
    GLfloat diffuse_coeffs[] = { 0.714, 0.4284, 0.18144, 1.0 };
    GLfloat specular_coeffs[] = { 0.393548, 0.271906, 0.166721, 1.0 };
    GLfloat shininess = 10;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);
    
    glPushMatrix();
        glScalef(2, 2, 2);
        
        /* top of the table */
        glPushMatrix();
            glScalef(1, -0.10, 2);
            glutSolidCube(8);
        glPopMatrix();
        
        /* table legs */
        float k,v;
        for(k = -3; k <= 3; k += 6){
            for(v = -6; v <= 6; v += 12){
                glPushMatrix();
                    glTranslatef(k, -2.4, v);
                    glScalef(-0.5, 2, -0.5);
                    glutSolidCube(2);
                glPopMatrix();
            }
        }

    glPopMatrix();

}

#endif
