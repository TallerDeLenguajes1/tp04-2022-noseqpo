#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea
{
    int TareaID; // n en ciclo
    char *Descripcion;
    int Duracion; // 10-100
} typedef tarea;

int pedirInt(char *str);

tarea *nuevaTarea(int id);
tarea **nuevoArray(int tam);
tarea **pedirTareas(int tam);
void mostrarArray(tarea **l, int tam);
void preguntar(tarea **pen, tarea **real, int tam);
void mover(tarea **pen, tarea **real, int id);

int main(int argc, char const *argv[])
{
    int tam = pedirInt("tareas");
    tarea **tareasPendientes = pedirTareas(tam);
    mostrarArray(tareasPendientes, tam);
    printf("\n---------");
    tarea **tareasRealizadas = nuevoArray(tam);
    preguntar(tareasPendientes, tareasRealizadas, tam);
    mostrarArray(tareasPendientes, tam);
    mostrarArray(tareasRealizadas, tam);
    // freeTodo();
    return 0;
}

tarea **nuevoArray(int tam)
{
    // devuelve un *tarea[tam]
    tarea **tmp = (tarea **)malloc(sizeof(tarea) * tam);
    for (int i = 0; i < tam; i++)
    {
        *(tmp + i) = NULL;
    }
    return tmp;
}

int pedirInt(char *str)
{
    int temp = 0;
    printf("\nIngrese el numero de %s a realizar: ", str);
    scanf("%d", &temp);
    return temp;
}

tarea **pedirTareas(int tam)
{
    tarea **array = nuevoArray(tam);

    for (int i = 0; i < tam; i++)
    {
        *(array + i) = nuevaTarea(i);
    }

    return array;
}

tarea *nuevaTarea(int id)
{
    tarea *temp = (tarea *)malloc(sizeof(tarea));
    temp->TareaID = id;
    temp->Duracion = 10 + rand() % 100;
    temp->Descripcion = "Descripcion random lmao";
    return temp;
    // FALTA FREE
}

void mostrarArray(tarea **l, int tam)
{

    for (int i = 0; i < tam; i++)
    {
        tarea *temp = *(l + i);
        if (temp != NULL)
        {
            printf("\nLugar N %d", temp->TareaID);
            printf("\n      Descripcion: %s", temp->Descripcion);
            printf("\n      Duracion: %d", temp->Duracion);
            printf("\n");
        }
        else
            printf("\nVACIO LUGAR %d\n\n", i);
    }
}

void preguntar(tarea **pen, tarea **real, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        tarea *temp = *(pen + i);
        char *resp = malloc(sizeof(char) * 10);
        printf("\nLa tarea %d se encuentra realizada?\nSI/NO\n", temp->TareaID);
        fflush(stdin);
        gets(resp);
        if (strcmp(resp, "SI")==0)
        {
            mover(pen, real, i);
        }
        printf("\n");
        free(resp);
    }
}

void mover(tarea **pen, tarea **real, int id) // problema acá
{
    int i = 0;
    while (*(real + i) = NULL)
    {
        i++;
    }
    *(real + i) = *(pen + id);
    *(pen + id) = NULL;
}
