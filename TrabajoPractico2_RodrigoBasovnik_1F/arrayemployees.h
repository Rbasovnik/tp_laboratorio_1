
typedef struct{
    int sectorid;
    char sectordesc[51];
}Sector;

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/** \brief Funcion fgets personal
 *
 * \param char cad[] Cadena de caracteres
 * \param int in Tamaño de la cadena
 * \return
 *
 */
void customfgets (char cad[], int in);

/** \brief Muestra el menu principal de opciones y pide una opcion.
 *
 * \return int Retorna la opcion
 *
 */
int showMainManu();

/** \brief Inicializa los datos de los empleados
 *
 * \param Employee eList[] Estructura empleados
 * \param int eLen Tamaño de estructura empleados
 * \return
 *
 */
void initEmployee (Employee eList[], int eLen);

/** \brief Muestra el menu de sectores y pide una opcion
 *
 * \param sList[] Sector Estructura de sectores
 * \return int Opcion ingresada
 *
 */
int showSectorsMenu(Sector sList[]);

/** \brief Busca un lugar libre en la estructura
 *
 * \param ifList[] Employee Estructura empleados
 * \param ifLen int Tamaño estructura empleados
 * \return int Retorna el indice en el cual se encuentra un lugar libre
 *
 */
int isFreeEmployee(Employee ifList[], int ifLen);

/** \brief Alta de un empleado
 *
 * \param Employee aList[] Estructura empleados
 * \param Sector asList[] Estructura sectores
 * \param int aLen Tamaño estructura empleados
 * \param int aId Id empleado
 * \return Retorna el legajo en el cual se realizo el alta
 *
 */
int addEmployee (Employee aList[], Sector asList[], int aLen, int aId);

/** \brief Busca un empleado segun el Id otorgado
 *
 * \param fList[] Employee Estructura empleados
 * \param fLen int Tamaño estructura empleados
 * \param fId int Id empleado
 * \return int Retorna el indice en el cual se encuentra el empleado
 *
 */
int findEmployeeById(Employee fList[], int fLen, int fId);

/** \brief Muestra el menu de modificaciones y toma la opcion a realizar
 *
 * \return Opcion ingresada
 *
 */
int showModificationMenu (void);

/** \brief Modifica los datos de un empleado
 *
 * \param Employee mList[] Estructura empleados
 * \param Sector msList[] Estructura sectores
 * \param int mLen Tamaño estructura
 * \return
 *
 */
void modifyEmployee (Employee mList[], Sector msList[], int mLen);

/** \brief Baja logica de un empleado
 *
 * \param rList[] Employee Estructura empleados
 * \param rLen int Tamaño estructura empleados
 * \return void
 *
 */
void removeEmployee(Employee rList[], int rLen);

/** \brief Cambia de lugar en la lista a dos empleados segun los indices
 *
 * \param swlist[] Employee Estructura empleados
 * \param i int Primer indice
 * \param j int Segundo indice
 * \return void
 *
 */
void swapEmployees(Employee swlist[], int i, int j);

/** \brief Ordena los empleados alfabeticamente segun el orden
 *
 * \param sList[] Employee Estructura empleados
 * \param sLen int Tamaño estructura empleados
 * \param order int Orden ascendente o descendente
 * \return int Si se ordeno con exito retorna 0, caso contrario retorna -1
 *
 */
int sortEmployees(Employee sList[], int sLen, int order);

/** \brief Imprime los datos de un empleado
 *
 * \param pOList Employee Estructura empleados
 * \return void
 *
 */
void printEmployee(Employee pOList);

/** \brief Imprime los datos de los empleados en pantalla si han sido dados de alta.
 *
 * \param pAList[] Employee Estructura de empleados
 * \param pLen int Tamaño estructura
 * \return void
 *
 */
void printEmployees(Employee pAList[], int pLen);
