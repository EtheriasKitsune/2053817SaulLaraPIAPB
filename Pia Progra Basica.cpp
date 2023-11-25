#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h> 
#include <Windows.h>

using namespace std;

struct Ticket
{
	string nombredelcliente;
	string comida;
	string nombre, status, statusbaja;
	int pedido = 0, pedido2 = 0, pedido3 = 0, pedido4 = 0, pedido5 = 0, pedido6 = 0;
	int precio = 0, precio2 = 0, precio3 = 0, precio4 = 0, precio5 = 0, precio6 = 0;
	float Subtotal;
	float IVA;
	float PrecioFinal;
};

int alta;
//declaro mi puntero
Ticket* restaurante;

void Alta();
void Eliminar();
void Listas();
void Modificar();
void Archivos();

int main()
{
	int opc;
	printf(" 1.-Alta \n 2.-Mostrar \n 3.-Limpiar pantalla \n 4.-Modificar \n 5.-Eliminar \n 6.-Salir \n");
	scanf_s("%d", &opc);
	switch (opc)
	{
	case 1:
		Alta();
		return main();
		break;
	case 2:
		Listas();
		return main();
		break;
	case 3:
		system("cls");
		return main();
		break;
	case 4:
		Modificar();
		return main();
		break;
	case 5:
		Eliminar();
		return main();
		break;
	case 6:
		Archivos();
		exit(1);
		break;
	}
}

void Alta()
{
	printf("cuantos registros desea dar de alta \n");
	scanf_s("%d", &alta);
	cin.ignore();
	restaurante = new Ticket[alta]; //arreglo dinamico

	//arreglo
	int op = 0;
	for (int i = 0; i < 120; i++)
	{
		printf("-");
	}

	for (int i = 0; i < alta; i++)
	{
		cout << "REGISTRO NUM: " << i + 1 << endl;
		printf("Ingrese el nombre del cliente: \n");
		getline(cin, restaurante[i].nombredelcliente);
		printf("Que desea ordenar: \n");
		do
		{
			printf(" 1. Tacos..............$90 \n 2. Hamburguesa........$70 \n 3. Gringa............$100 \n 4. Campechana........$100 \n 5. Papa Asada.........$90 \n 6. Refresco...........$20 \n");
			/*getline(cin, restaurante[i].comida);*/
			scanf_s("%i", &op);
			switch (op)
			{
			case 1: //Tacos//
			{
				printf("cuantas ordenes desea? \n");
				scanf_s("%i", &restaurante[i].pedido);
				cin.ignore();

				break;
			}
			case 2: //Hamburguesa
			{
				printf("cuantas desea? \n");
				scanf_s("%i", &restaurante[i].pedido2);
				cin.ignore();
				break;
			}
			case 3: //Gringa//
			{
				printf("cuantas desea? \n");
				scanf_s("%i", &restaurante[i].pedido3);
				cin.ignore();
				break;
			}
			case 4: //Campechana//
			{
				printf("cuantas desea? \n");
				scanf_s("%i", &restaurante[i].pedido4);
				cin.ignore();
				break;
			}
			case 5: //Papa Asada//
			{
				printf("cuantas desea? \n");
				scanf_s("%i", &restaurante[i].pedido5);
				cin.ignore();
				break;
			}
			case 6: //refresco//
			{
				printf("cuantos desea? \n");
				scanf_s("%i", &restaurante[i].pedido6);
				cin.ignore();
				break;
			}
			default:
				break;
			}
			printf("desea agregar algo mas? \n");
			printf("1. Si ");
			printf("2. No \n");
			scanf_s("%i", &op);
			cin.ignore();
		} while (op == 1);
		int op = 0;
		for (int i = 0; i < 120; i++)
		{
			printf("-");
		}
	}
}
void Listas()
{
	for (int i = 0; i < alta; i++)
	{
		float Subtotal = 0;
			if (restaurante[i].statusbaja == "ELIMINADO")
			{
				cout << "REGISTRO ELIMINADO " << i + 1 << endl;
			}
			else
			{
				int op = 0;
				for (int i = 0; i < 120; i++)
				{
					printf("-");
				}
				cout << "REGISTRO " << i + 1 << endl;
				cout << restaurante[i].nombredelcliente << endl;
				int precio = 0, precio2 = 0, precio3 = 0, precio4 = 0, precio5 = 0, precio6 = 0;
				if (restaurante[i].pedido > 0)
				{
					precio = 0;
					precio = restaurante[i].pedido * 90;
					cout << restaurante[i].pedido << " Tacos " << "............" << precio << endl;
					Subtotal = Subtotal + precio;
				}
				if (restaurante[i].pedido2 > 0)
				{
					precio2 = 0;
					precio2 = restaurante[i].pedido2 * 70;
					cout << restaurante[i].pedido2 << " Hambuerguesa " << "............" << precio2 << endl;
					Subtotal = Subtotal + precio2;
				}
				if (restaurante[i].pedido3 > 0)
				{
					precio3 = 0;
					precio3 = restaurante[i].pedido3 * 100;
					cout << restaurante[i].pedido3 << " Gringa " << "............" << precio3 << endl;
					Subtotal = Subtotal + precio3;
				}
				if (restaurante[i].pedido4 > 0)
				{
					precio4 = 0;
					precio4 = restaurante[i].pedido4 * 100;
					cout << restaurante[i].pedido4 << " Campechana " << "............" << precio4 << endl;
					Subtotal = Subtotal + precio4;
				}
				if (restaurante[i].pedido5 > 0)
				{
					precio5 = 0;
					precio5 = restaurante[i].pedido5 * 90;
					cout << restaurante[i].pedido5 << " Papa Asada " << "............" << precio5 << endl;
					Subtotal = Subtotal + precio5;
				}
				if (restaurante[i].pedido6 > 0)
				{
					precio6 = 0;
					precio6 = restaurante[i].pedido6 * 20;
					cout << restaurante[i].pedido6 << " Refresco " << "............" << precio6 << endl;
					Subtotal = Subtotal + precio6;
				}

				restaurante[i].Subtotal = Subtotal;
				cout << " Subtotal " << "............" << restaurante[i].Subtotal << endl;
				restaurante[i].IVA = Subtotal * 0.16;
				cout << " IVA " << "............" << restaurante[i].IVA << endl;
				restaurante[i].PrecioFinal = restaurante[i].Subtotal + restaurante[i].IVA;
				cout << " Precio con IVA " << "............" << restaurante[i].PrecioFinal << endl;
				
			}

	}
}
void Modificar()
{
	int modificar, opcion;
	printf("ingrese el registro a modificar");
	cin >> modificar;
	modificar = modificar - 1;
	for (int i = modificar; i == modificar; i++)
	{
		if (restaurante[i].statusbaja == "Eliminado")
		{
			cout << "EL REGISTRO SE HA ELIMINADO" << i + 1 << endl;
			printf("Ingrese un registro valido \n");
			return Modificar();
		}
		cout << "ingrese que desea modificar 1.-Nombre, 2.-Agregar Producto" << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			cout << "Ingrese Nombre" << endl;
			cin >> restaurante[i].nombredelcliente;
			break;
		case 2:
			printf("Que desea agregar: \n");
			int op = 0;
			do
			{
				printf(" 1. Tacos..............$90 \n 2. Hamburguesa........$70 \n 3. Gringa............$100 \n 4. Campechana........$100 \n 5. Papa Asada.........$90 \n 6. Refresco...........$20 \n");
				scanf_s("%i", &op);
				switch (op)
				{
				case 1: //Tacos//
				{
					printf("cuantas ordenes desea? \n");
					scanf_s("%i", &restaurante[i].pedido);
					cin.ignore();

					break;
				}
				case 2: //Hamburguesa
				{
					printf("cuantas desea? \n");
					scanf_s("%i", &restaurante[i].pedido2);
					cin.ignore();
					break;
				}
				case 3: //Gringa//
				{
					printf("cuantas desea? \n");
					scanf_s("%i", &restaurante[i].pedido3);
					cin.ignore();
					break;
				}
				case 4: //Campechana//
				{
					printf("cuantas desea? \n");
					scanf_s("%i", &restaurante[i].pedido4);
					cin.ignore();
					break;
				}
				case 5: //Papa Asada//
				{
					printf("cuantas desea? \n");
					scanf_s("%i", &restaurante[i].pedido5);
					cin.ignore();
					break;
				}
				case 6: //refresco//
				{
					printf("cuantos desea? \n");
					scanf_s("%i", &restaurante[i].pedido6);
					cin.ignore();
					break;
				}
				default:
					break;
				}
				printf("desea agregar algo mas? \n");
				printf("1. Si ");
				printf("2. No \n");
				scanf_s("%i", &op);
				cin.ignore();
			} while (op == 1);

			break;
		}
	}
}
void Eliminar()
{

	int baja;
	cout << "ingrese el  registro a eliminar";
	cin >> baja;
	baja = baja - 1;

	for (int i = baja; i == baja; i++)
	{
		cout << "Eliminando registro " << baja + 1 << endl;
		restaurante[i].statusbaja = "ELIMINADO";

	}

}
void Archivos()
{
	ofstream archivo;
	string nombrearchivo;
	nombrearchivo = "Ticket.txt";
	archivo.open(nombrearchivo.c_str(), ios::binary);
	if (archivo.fail())
	{
		cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
		exit(1);
	}
	archivo << "REGISTRO" << "\t\t\t\t";
	archivo << "NOMBRE" << "\t\t\t\t";
	archivo << "SUBTOTAL" << "\t\t\t";
	archivo << "IVA" << "\t\t\t";
	archivo << "PrecioFinal" << "\t\t\t";
	archivo << "STATUS REGISTRO" << "\n";


	for (int i = 0; i < alta; i++)
	{
		archivo << i + 1 << "\t\t\t\t";
		archivo << restaurante[i].nombredelcliente << "\t\t\t\t";
		archivo << restaurante[i].Subtotal << "\t\t\t\t";
		archivo << restaurante[i].IVA << "\t\t\t\t";
		archivo << restaurante[i].PrecioFinal << "\t\t\t\t";
		archivo << restaurante[i].statusbaja << "\n";
	}

	archivo.close();
}