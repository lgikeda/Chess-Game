#include "freeglut.h"
#include "Interfaz.h"

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla
void raton_callback(int button, int state, int x, int y);

Interfaz interfaz;

int main(int argc, char* argv[])
{

	//inicialización de los datos de la simulación

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 700);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 700.0f, 0.1, 134.0f);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(raton_callback);

	//pasarle el control a FREEGLUT,que llamara a los callbacks
	
	glutMainLoop();
	

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(40, 40, 130,  // posicion del ojo
		40.0, 40.0, 0.0,      // hacia que punto mira  (40,40,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    


	//aqui es donde hay que poner el código de dibujo

	interfaz.dibujaInterfaz();

	//no borrar esta linea ni poner nada despues

	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	interfaz.tecla(key);
	glutPostRedisplay();
}

void raton_callback(int button, int state, int x, int y) {
	interfaz.raton(button, state, x, y);
	glutPostRedisplay();
}

void OnTimer(int value)
{
	
}