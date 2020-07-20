//Laboratorio suma binarios con acarreo
/*
plantear un programa que dados 2 valores numericos enteros 0 o positivos A y B en decimal realice la suma binaria con acarreo para un N=8 bits. 
El programa debe mostrar A, B y S donde S es la suma en un formato:

 A
+B
__
S

tanto en decimal como  en binario.
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	//Declaramos variables y arreglos
	int 
	a,
	b,
	i_in_a,
	i_in_b,
	i_in_s,
	discount_a=0,
	discount_b=0,
	res_b=0,
	i,
	j,
	aux,
	carry=0,
	bin_a[8],//los arreglos van de 8 espacios porque manejaremos 8 bits
	bin_b[8],
	s[8];
	
	//solicitamos valores al usuario
	cout<<"Ingrese los valores a sumar A y B"<<endl;
	cin>>a;
	cin>>b;
	
	if(a<0 || b<0)//verificamos q sean positivos
	{cout<<"A y B deben ser numeros positivos"<<endl;}
	else if(a+b>255)//verificamos q la suma no desborde los 8 bits
	{cout<<"El total a la suma no puede ser mayor a 255 o excederia los 8 bits"<<endl;}
	else
	{
//CONVIRTIENDO A EN BINARIO
		j=0;
		
		for(i=0;pow(2,i)<=a;i++)//buscamos la potencia de 2 mas grande que quepa en A probando todos los numeros desde 0 en forma ascendente
		{i_in_a = i;}//i_in_a = al mayor exponente posible = cantidad de digitos necesarios para A en decimal
		
		
		for(i=i_in_a;i>=0;i--)//Para cada i, contando desde el maximo exponente(i=i_in_a) en forma descendente (i--)... (armamos el numero binario de izquierda a derecha)
		{
			if(pow(2,i) <= (a-discount_a)) //si 2 a la i cabe en A - lo que vamos descontando
			{
				bin_a[j]=1;//asignamos un 1 al numero
				discount_a += pow(2,i);//y sumamos el resultado de la potencia al descuento
			}
			else//si no,...
			{
				bin_a[j]=0;//...asignamos un 0
			}
			
			j++;
			//y vamos al siguiente exponente hasta llegar a 0
		}
		//Aqui ya tenemos el numero A en binario dentro del arreglo bin_a. Un digito en cada espacio del arreglo
		
		//imprimimos A...
		cout<<"A en binario es ";
		for(i=0;i<8-i_in_a-1;i++)//si el binario tiene menos de 8 bits...
		{
			cout<<" ";//ponemos algunos espacios vacios para que los numeros se ubiquen bien uno bajo el otro en la impresion de pantalla (como 0 a la izquierda)
		}
		for(i=0;i<=i_in_a;i++)//este bucle imprime A en binario recorriendo todo el arreglo bin_a
		{
			cout<<bin_a[i];
		}
		cout<<endl;
	
		for (i=0;i<=((i_in_a)/2);i++)//este bucle invierte el arreglo del numero binario para prepararlo para la suma de derecha a izquierda
		{
			aux=bin_a[i];
			bin_a[i]=bin_a[i_in_a-i];
			bin_a[i_in_a-i]=aux;
		}
		
//CONVIRTIENDO B EN BINARIO
		//Repetimos el mismo proceso para B...
		j=0;
		
		for(i=0;pow(2,i)<=b;i++)
		{i_in_b = i;}
		
		
		for(i=i_in_b;i>=0;i--)
		{
			if(pow(2,i) <= (b-discount_b))
			{
				bin_b[j]=1;
				discount_b += pow(2,i);
			}
			else
			{
				bin_b[j]=0;
			}
			
			j++;
		}
		
		cout<<"B en binario es ";
		
		for(i=0;i<8-i_in_b-1;i++)
		{
			cout<<" ";
		}
		
		for(i=0;i<=i_in_b;i++)
		{
			cout<<bin_b[i];
		}
		cout<<endl;
	
		for (i=0;i<=((i_in_b)/2);i++)
		{
			aux=bin_b[i];
			bin_b[i]=bin_b[i_in_b-i];
			bin_b[i_in_b-i]=aux;
		}
		
//SUMA
		
		if(i_in_a>=i_in_b)//Si A binario tiene mas digitos que B binario...
		{
			i_in_s=i_in_a;//asignamos la misma cantdad de digitos para S (S = resultado de la suma)
			
			for(i=0;i<=i_in_a;i++)//Por cada digito en A decimal
			{
				if(i<=i_in_b)//si existe digito en la misma posicion en B...
				{
					if((bin_a[i] + bin_b[i] + carry)==3)//si la suma del digito en A + el digito en B + el acarreo es igual a 3
					{
						s[i]=1;//asignar un 1 en esa posicion en el arreglo S
						carry=1;//y asignar 1 en el acarreo
					}
					else if((bin_a[i] + bin_b[i] + carry)==2)//si la suma del digito en A + el digito en B + el acarreo es igual a 2
					{
						s[i]=0;//asignar un 0 en esa posicion en el arreglo S
						carry=1;//y asignar 1 en el acarreo
					}
					else//si otro...(1 o 0)
					{
						s[i]=bin_a[i] + bin_b[i] + carry;//asignar el resultado de la suma en esa posicion en el arreglo S
						carry=0;//y asignar 0 en el acarreo
					}
				}
				else//si NO existe digito en la misma posicion en B...
				{
					if((bin_a[i] + carry)==3)//si la suma del digito en A + el acarreo es igual a 3
					{
						s[i]=1;//asignar un 1 en esa posicion en el arreglo S
						carry=1;//y asignar 1 en el acarreo
					}
					else if((bin_a[i] + carry)==2)//si la suma del digito en A + el acarreo es igual a 2
					{
						s[i]=0;//asignar un 0 en esa posicion en el arreglo S
						carry=1;//y asignar 1 en el acarreo
					}
					else//si otro...(1 o 0)
					{
						s[i]=bin_a[i] + carry;//asignar el resultado de la suma en esa posicion en el arreglo S
						carry=0;//y asignar 0 en el acarreo
					}
				}
			}
			
			if(carry==1)//Si al finalizar, aun tenemos algo en el acarreo...
			{
				s[i_in_a+1]=1;//colocamos el 1 del acarreo en la siguiente posicion
				i_in_s += 1;//añadimos un digito al total de digitos en s
			}
		}
		else //Si B binario tiene mas digitos que A binario...
		{
			i_in_s=i_in_b;
			
			for(i=0;i<=i_in_b;i++)
			{
				if(i<=i_in_a)
				{
					if((bin_b[i] + bin_a[i] + carry)==3)
					{
						s[i]=1;
						carry=1;
					}
					else if((bin_b[i] + bin_a[i] + carry)==2)
					{
						s[i]=0;
						carry=1;
					}
					else
					{
						s[i]=bin_b[i] + bin_a[i] + carry;
						carry=0;
					}
				}
				else
				{
					if((bin_b[i] + carry)==3)
					{
						s[i]=1;
						carry=1;
					}
					else if((bin_b[i] + carry)==2)
					{
						s[i]=0;
						carry=1;
					}
					else
					{
						s[i]=bin_b[i] + carry;
						carry=0;
					}
				}
			}
			
			if(carry==1)
			{
				s[i_in_b+1]=1;
				i_in_s += 1;
			}
		}
		//Para este punto ya tenemos el resultado de la suma en el arrelgo S pero esta al reves asi que intertiremos el arreglo
	
		for (i=0;i<=((i_in_s)/2);i++)//este bucle invierte el arreglo del numero binario resultado de la suma para prepararlo para imprimirlo en pantalla
		{
			aux=s[i];
			s[i]=s[i_in_s-i];
			s[i_in_s-i]=aux;
		}
		
		cout<<"                ________ +"<<endl;//imprimimos la línea de la suma y el simbolo
		cout<<"S en binario es ";
		for(i=0;i<8-i_in_s-1;i++)
		{
			cout<<" ";//ponemos los espacios a la izquierda necesarios en el resultado para que se posicione correctamente cada digito en pantalla
		}
		
		for(i=0;i<=i_in_s;i++)
		{
			cout<<s[i];//imprimimos el resultado de la suma en binario
		}
		cout<<endl<<endl;
		cout<<"S en decimal es "<<a+b<<endl;//imprimimos el resultado de la suma en decimal
	}
	
	system("pause");
	return 0;
}
