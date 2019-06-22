int controller_loadFromText(char* path , LinkedList* pArrayListClientes);
int controller_saveAsTextVentas(char* path, LinkedList* pArrayListVentas);
int controller_loadFromBinary(char* path , LinkedList* pArrayListClientes);
int controller_addClientes(LinkedList* pArrayListClientes);
int controller_editClientes(LinkedList* pArrayListClientes);
int controller_removeClientes(LinkedList* pArrayListClientes);
int controller_ListClientes(LinkedList* pArrayListClientes);
int controller_sortClientes(LinkedList* pArrayListClientes);
int controller_saveAsText(char* path , LinkedList* pArrayListClientes);
int controller_saveAsBinary(char* path , LinkedList* pArrayListClientes);
int idMaxArray(LinkedList* pArrayListClientes);
int controller_removeVentas(LinkedList* pArrayListVentas);
int controller_ListVentas(LinkedList* pArrayListVentas);
int buscarPorIdVentas(LinkedList* pArrayVentas, int id);
int idMaxArrayVentas(LinkedList* pArrayVentas);
int controller_addVentas(LinkedList* pArrayListVentas);

//int controller_aumentoVeintePorcientoSueldos(void* p);
//int controller_menosDeCienHoras(void* p);
