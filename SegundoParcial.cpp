#include <iostream>
#include <string.h>
#include <cstring>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct conduent{
	int id;
	string nm, ln, pst;
	float bs;
}planilla, *planilla_conduent  = &planilla;

void menu();
void askdata(int x);
void showdata(conduent *);
void search();
void modify();
	
	int *codigo_empleado = new int[30];
	string *nombres = new string[30];
	string *apellidos= new string[30]; 
	string *puesto= new string[30];
	float *base= new float[30];
	int bonificacion = 250;
	
int x;
int y;
int lookup;
int entero = 0;
int save = 0;
main (){
menu ();
	return 0;
}

void menu(){
	int option;
	do{
	cout<<"\t.:MENU:.\n";
	cout<<"1. Insertar elementos a la lista\n";
	cout<<"2. Mostrar los elementos de la lista\n";
	cout<<"3. Buscar\n";
	cout<<"4. Modificar\n";
	cout<<"5. Salir\n";
	cout<<"opcion: "; cin>>option;
	switch(option){
		case 1:
				int employees;
				askdata(employees);
				cout<<"\n";
			system("pause");
		break;
		case 2 :
			cout<<"------ P L A N I L L A ------"<<endl;
			showdata(planilla_conduent);
			cout<<"\n";
			system("pause");	
		break;
		case 3:
			search();
			system("pause");
		break;
		case 4: 
			modify();
			system("pause");
		break; 
		}
		system ("cls");
	}while (option != 5);
}

void askdata(int x){
	conduent cndt;
	int compare = 0;
	int ii = 0;
	cout<<"Cuantos empleados le gustaria agregar: "; cin>>x;
	for (int i = save; i < save + x; i++){
	cout<<"Digite codigo de empleado: "; cin>>cndt.id;
	do {
	compare = 0; 
	if (cndt.id == codigo_empleado[ii]){
		cout<<"Codigo ya en uso"<<endl;
		cout<<"Ingrese uno nuevo: "; cin>>cndt.id;
		compare = 1;
	}
	ii++;
	}while (compare == 1);
	cin.ignore();
	cout<<"Primer y Segundo Nombre: "; getline(cin,cndt.nm);
	cout<<"Primer y Segundo Apellido: "; getline(cin,cndt.ln);
	cout<<"Puesto: "; getline(cin,cndt.pst);
	cout<<"Sueldo Base: "; cin>>cndt.bs;
	cout<<"--------------------"<<endl;	
	codigo_empleado[i] = cndt.id;
	nombres[i] = cndt.nm;
	apellidos[i] = cndt.ln;
	puesto[i] = cndt.pst;
	base[i] = cndt.bs;
	}
	y = x;
	save = x + save;
}

void showdata(conduent *planilla_conduent){
	for (int i =0 ; i< save; i++){
	cout<<"-----------------------"<<endl;
	cout<<"ID: "<<codigo_empleado[i]<<endl;
	cout<<"Nombres: "<<nombres[i]<<endl;
	cout<<"Apellidos: "<<apellidos[i]<<endl;
	cout<<"Cargo: "<<puesto[i]<<endl;
	cout<<"Sueldo base: "<<base[i]<<endl;
	cout<<"bonificacion de ley: "<<bonificacion<<endl;
	cout<<"Sueldo total: "<<base[i] + bonificacion<<endl;
	}
}

void search(){
	entero = 0;
	cout<<"Valor a buscar: "; cin>>lookup;
	for (int i =0 ; i< y; i++){
	if (lookup == codigo_empleado[i]){
	cout<<"-----------------------"<<endl;
	cout<<"ID: "<<codigo_empleado[i]<<endl;
	cout<<"Nombres: "<<nombres[i]<<endl;
	cout<<"Apellidos: "<<apellidos[i]<<endl;
	cout<<"Cargo: "<<puesto[i]<<endl;
	cout<<"Sueldo base: "<<base[i]<<endl;
	cout<<"bonificacion de ley: "<<bonificacion<<endl;
	cout<<"Sueldo total: "<<base[i] + bonificacion<<endl;
	entero = 1;
}
	}
	if (entero == 0 ){
		cout<<"Valor no encontrado"<<endl;
	}
}

void modify(){
	search();
	if (entero == 1 ){
	int change;
	cout<<"--------------------"<<endl;
	cout<<"Valores a reemplazar: "<<endl;
	cout<<"1. Nombres: \n";
	cout<<"2. Apellidos: \n";
	cout<<"3. Cargo: \n";
	cout<<"4. Sueldo Base: \n";
	cout<<"Que valor desea reemplazar: "; cin>>change;
	cin.ignore();
	switch (change){
		case 1:
			cout<<"Nuevo Nombre: "; 
			getline(cin,nombres[lookup-1]);
			break;
		case 2:
			cout<<"Nuevo Apellido: "; 
			getline(cin,apellidos[lookup-1]);
			break;
		case 3: 
			cout<<"Nuevo Cargo: "; 
			getline(cin,puesto[lookup-1]);
			break;
		case 4: 
			cout<<"Nuevo Salario: "; 
			cin>>base[lookup-1];
			break;
		}
	}
}
