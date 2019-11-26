
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this=(LinkedList*)malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size=0;
        this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode=NULL;
    int len;
    int i;

    if(this!=NULL && nodeIndex>=0)//se verifica que la lista sea distinta de NULL, y que el nodo que recibe sea mayor o igual a 0
    {
        len=ll_len(this); //se averigua el largo de la lista
        if(nodeIndex<len)//si el nodo es menor al largo de la lista
        {
            pNode=this->pFirstNode; //accedo al primer nodo. y a partir de ahi recorro los nodos en busca del que se me pidio.
            for(i=0; i<nodeIndex; i++) //como el nodo que obtengo, esta dentro del rango en el que trabajo, solo recorro la lista hasta ese nodo.
            {
                pNode=pNode->pNextNode;//
            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    /** Al crear un nuevo nodo, el largo aumenta al "len" y el size aumenta.  */

    int returnAux = -1;
    int len;
    Node* pNode=NULL;
    Node* pNodeAux=NULL;

    if(this!=NULL && nodeIndex >=0)
    {
        len=ll_len(this);
        if(nodeIndex<=len)
        {
            pNode=(Node*)malloc(sizeof(Node));
            if(pNode!=NULL)
            {
                pNode->pElement=pElement;
                if(nodeIndex==0)
                {
                    pNode->pNextNode=this->pFirstNode;
                    this->pFirstNode=pNode;
                }
                else if(nodeIndex==len)
                {
                    pNodeAux = getNode(this,nodeIndex-1);
                    pNodeAux->pNextNode=pNode;
                    pNode->pNextNode=NULL;
                }
                else
                {
                    pNodeAux=getNode(this,nodeIndex-1);
                    pNode->pNextNode=pNodeAux->pNextNode;
                    pNodeAux->pNextNode=pNode;
                }
                len++;
                this->size=len;
                returnAux=0;
            }
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    if(this!=NULL)
    {
        len=ll_len(this);
        returnAux=addNode(this,len,pElement);
    }

    return returnAux;
}

/** \brief
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode=NULL;
    int len;

    if(this!=NULL)
    {
        len=ll_len(this);
        if(index >= 0 && index<len)//en este caso el index tiene que ser menor al len. ya que el len es la cantidad de elementos, y el index la posicion de estos.
        {
            pNode=getNode(this,index);
            returnAux=pNode->pElement;//Busco a la persona y la obtengo.
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* auxNode=NULL;
    if(this!=NULL)
    {
        len=ll_len(this);
        if(index>=0 && index < len)
        {
            auxNode=getNode(this,index);
            auxNode->pElement=pElement;//Busco a la persona y le asigno el nuevo nombre.
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len;
    Node* pNode=NULL;
    Node* pAux=NULL;
    if(this!=NULL && index >=0)
    {
        len=ll_len(this);//obtengo el largo de la lista.
        if(index<len)
        {
            pAux=getNode(this,index-1);//obtengo el nodo anterior al que quiero eliminar
            pNode=getNode(this,index);//obtengo el elemento a elminar, que hace refrencia al siguiente.
            if(index==0)
            {
                this->pFirstNode=pNode->pNextNode;
                free(pNode);
                pNode=NULL;
            }
            else if(index >0 && index < len)
            {
                pAux->pNextNode=pNode->pNextNode;
                free(pNode);
                pNode=NULL;
            }
            len--;
            this->size=len;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len;
    if(this!=NULL)
    {
        len=ll_len(this);
        for(i=0;i<len;i++)
        {
            ll_remove(this,i);
        }

        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        this=NULL;
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* elemento;
    int i;
    int len;
    if(this!=NULL)
    {
        len=ll_len(this);
        for(i=0;i<len;i++)
        {
            elemento=ll_get(this,i);
            if(elemento==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;

    if(this!=NULL)
    {
        len=ll_len(this);  //se va a utilizar ademas para verificar que hayan elementos en la lista.
        if(len==0)
        {
            returnAux=1;
        }else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;
    if(this!=NULL && index >=0)
    {
        len=ll_len(this);
        if(index<=len)
        {
            returnAux=addNode(this,index,pElement);
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len;

    if(this!=NULL)
    {
        len=ll_len(this);
        if(index>=0 && index<len)
        {
            returnAux=ll_get(this,index);
            if(returnAux!=NULL)
            {
                ll_remove(this,index);
            }

        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int exist;
    if(this!=NULL)
    {
        exist=ll_indexOf(this,pElement);
        {
            if(exist==-1)
            {
                returnAux=0;
            }else
            {
                returnAux=1;
            }
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len;
    int i;
    int exist=0;
    void* pElement=NULL;

    if(this!=NULL  && this2!=NULL)
    {
        len=ll_len(this);
        returnAux=1;
        for(i=0;i<len;i++)
        {

            pElement=ll_get(this2,i);
            exist=ll_contains(this,pElement);
            if(exist!=1)
            {

                returnAux=0;
                  break;
            }
        }

    }


    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement=NULL;
    int len;
    int i;
    if(this!=NULL)
    {
        len=ll_len(this);
        if(from>=0 && from<=len && to>=from && to<=len)
        {
            cloneArray=ll_newLinkedList();
            if(cloneArray!=NULL)
            {
                 for(i=from;i<to;i++)
                 {
                     pElement=ll_get(this,i);
                     ll_add(cloneArray,pElement);
                 }
            }

        }
    }


    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;
    if(this!=NULL)
    {
         len=ll_len(this);
         cloneArray=ll_subList(this,0,len);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    void* pAux=NULL;
    void* pElementoI=NULL;
    void* pElementoJ=NULL;
    int len;
    if(this!=NULL && pFunc!=NULL && (order == 0 || order == 1))
    {
        len=ll_len(this);
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                pElementoI=ll_get(this,i);
                pElementoJ=ll_get(this,j);
                if(order==1)
                {
                    if(pFunc(pElementoI,pElementoJ)==1)
                    {
                        pAux=pElementoI;
                        pElementoI=pElementoJ;
                        pElementoJ=pAux;
                    }
                }else
                {
                    if(pFunc(pElementoI,pElementoJ)==-1)
                    {
                        pAux=pElementoJ;
                        pElementoJ=pElementoI;
                        pElementoI=pAux;
                    }
                }
                ll_set(this,i,pElementoI);
                ll_set(this,j,pElementoJ);

            }
        }
        returnAux=0;
    }

    return returnAux;

}

LinkedList* ll_filter(LinkedList* this,int (*pFun)(void*))
{
    LinkedList* this2=NULL;
    void* pElement=NULL;
    int len;
    int i;
    if(this!=NULL && pFun != NULL)
    {
        len=ll_len(this);
        this2=ll_newLinkedList();
        for(i=0;i<len;i++)
        {
            pElement=ll_get(this,i);
            if(pFun(pElement)==1)
            {
                ll_add(this2,pElement);
            }
        }
    }
    return this2;
}
