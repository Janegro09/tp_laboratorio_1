#define BARRA_SEPARADORA "*********************************************\n"

int utn_getEntero(char* pTexto, char* pTextoError, int intentos, int maximo, int minimo, int* pOperador);
int utn_getFloat(char* pTexto, char* pTextoError, int intentos, float maximo, float minimo, float* pOperador);
int utn_getEnteroSinMaxMin(char* pTexto, char* pTextoError, int reintentos, int* pOperador);
int utn_getCadenaValida(char* pTexto, char* pTextoError, int reintentos, int sizeOperador, char* pOperador);
