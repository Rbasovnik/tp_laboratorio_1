/** \brief Imprime el menu de opciones, pide los datos para cambiar en caso de que los
 *  operandos hayan sido ingresados, escanea y retorna la opcion elegida a main.
 *
 * \param operA Es el operandoA pedido al usuario
 * \param operB Es el operandoB pedido al usuario
 * \param flagA Indica si el operandoA fue ingresado para cambiar "x" por dicho operando
 * \param flagB Indica si el operandoB fue ingresado para cambiar "y" por dicho operando.
 * \return La opcion elegida por el usuario
 *
 */
int mostrarMenu(int a, int b, int flagA, int flagB);

/** \brief Ingresan los operandos A y B para realizar la suma de los mismos y retorna el resultado.
 *
 * \param operA Es el operando A pedido al usuario
 * \param operB Es el operando B pedido al usuario
 * \return El resultado de la suma
 *
 */
int sumaOperandos(int a, int b);

/** \brief Ingresan los operandos A y B para realizar la resta de los mismos y retorna el resultado.
 *
 * \param operA Es el operando A pedido al usuario
 * \param operB Es el operando B pedido al usuario
 * \return El resultado de la resta
 *
 */
int restaOperandos(int a, int b);

/** \brief Ingresan los operandos A y B para realizar la division de los mismos y retorna el resultado.
 *
 * \param operA Es el operando A pedido al usuario
 * \param operB Es el operando B pedido al usuario
 * \return El resultado de la division
 *
 */
float divisionOperandos(int a, int b);

/** \brief Ingresan los operandos A y B para realizar la multiplicacion de los mismos y retorna el resultado.
 *
 * \param operA Es el operando A pedido al usuario
 * \param operB Es el operando B pedido al usuario
 * \return El resultado de la muliplicacion
 *
 */
int multiplicacionOperandos(int a, int b);

/** \brief Ingresa el operando A  para realizar el factorial del mismo retorna el resultado.
 *
 * \param operA Es el operando A pedido al usuario
 * \return El resultado del factorial de A!
 *
 */
long factorialOperandoA(int a);

/** \brief Ingresa el operando B  para realizar el factorial del mismo retorna el resultado.
 *
 * \param operB Es el operando B pedido al usuario
 * \return El resultado del factorial de B!
 *
 */
long factorialOperandoB(int b);

