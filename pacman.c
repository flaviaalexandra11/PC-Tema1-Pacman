//Popescu Flavia Alexandra 311CD

#include <stdio.h>
#include <stdlib.h>

char sens (char s, char c) // schimba caracterul jucatorului 
{
    if( s == 'w') return '^';
    if( s == 's') return 'v';
    if( s == 'a') return '<';
    if( s == 'd') return '>';
    return c; 

}

int noul_y ( char s, int y, int n ) //schimba coordonata y a jucatorului 
{
     int z=y;

     if( s == 'd' && y < n ) z=z+1; 
     if( s == 'a' && y > 1 ) z=z-1;

     return z;
}

int noul_x ( char s, int x, int m ) //schimba coordonata x a jucatorului 
{
    int z=x;

    if( s == 'w' && x > 1) z=z-1;
    if( s == 's' && x < m) z=z+1;

    return z;
}

int noul_l1 ( int x, int l1 ) //schimba coordonata l1 a unui obstacol mobil 
{
    int z=l1;

    if( x < l1 ) z=z-1;
       else if( x > l1)
          z=z+1;

    return z;
}

int noul_c1 ( int y, int c1 ) //schimba coordonata c1 a unui obstacol mobil 
{
    int z=c1;

    if( y < c1 ) z=z-1;
       else if( y > c1) 
        z=z+1;

    return z;
}

void afisare_tabla (int m, int n, int x, int y, char c, int l1, int c1,int l2, int c2,int l3, int c3 ) //afiseaza tabla cu tot cu jucator si obstacole 
{
    int i,j;

    for ( i = 0; i <= m+1; i++ )
        {
          if ( i == 0 || i == m+1)
              for ( j = 0; j < n+2; j++) printf("*");

          else { printf("*");
                 for ( j = 1; j <= n; j++) 
                       if ( l1 == i && c1 == j)  printf ("x");
                       else if ( l2 == i && c2 == j) printf ("x");
                            else if ( l3 == i && c3 == j) printf ("x");
                                 else if ( x == i && y == j) printf ("%c", c);
   						              else printf (" ");

                 printf("*");
               }
         printf("\n");
        }
}
void pacman (int M, int N, int x, int y, int P) // jocul in sine 
{   
    int l1 = 0,l2 = 0, l3 = 0, c1 = 0,c2 = 0,c3 = 0,k=0;
    char c='v', s='s', m1 = 'f', m2 = 'f', m3 = 'f';

    if (P == 1) //citirea obstacolelor
    {
      scanf("%d %d %c", &l1, &c1, &m1);
    } else if (P == 2) 
    {
      scanf("%d %d %c", &l1, &c1, &m1);
      scanf("%d %d %c", &l2, &c2, &m2);
    } else if (P == 3) 
    {
      scanf("%d %d %c", &l1, &c1, &m1);
      scanf("%d %d %c", &l2, &c2, &m2);
      scanf("%d %d %c", &l3, &c3, &m3);
    }
     
     afisare_tabla (M, N, x, y, c, l1,c1,l2,c2,l3,c3);

    do
    {
        scanf(" %c", &s);
         
	 //verific daca mutarea e valida si abia apoi schimb caracterul jucatorului
         if (x != noul_x(s,x,M)) c=sens(s,c); 
         if (y != noul_y(s,y,N)) c=sens(s,c);
         x=noul_x (s,x,M);
         y=noul_y (s,y,N);

	k++; //contorizam numarul de mutari ale jucatorului
        if( k % 2 == 0 )//pentru ca obstacolele sa se miste o data la fiecare 2 mutari ale jucatorului 
       {
          if( m1 == 'm' )
          {
              l1=noul_l1 (x,l1);
              c1=noul_c1 (y,c1);
          }
          if( m2 == 'm') 
          {
            l2=noul_l1 (x,l2);
            c2=noul_c1 (y,c2);
          }
          if( m3 == 'm')
          {
            l3=noul_l1 (x,l3);
            c3=noul_c1 (y,c3);
          }
       }
        

      	//daca jucatorul se loveste de un obstacol
        if(( x == l1 && y == c1) || ( x == l2 && y == c2) ||
        	( x == l3 && y == c3))
        {
        	printf("GAME OVER\n");
        	break;
        }
	
	//daca jucatorul a ajuns in capat
      if(y == N && x == M)
      {
        afisare_tabla (M, N, x, y, c, l1,c1,l2,c2,l3,c3);
            printf("GAME COMPLETED\n");
            break;
        }

       if( s != 'q') afisare_tabla (M, N, x, y, c, l1,c1,l2,c2,l3,c3); // ca sa nu mai afiseze inca o data tabla cand se citeste 'q'
        

       } while ( s != 'q');

}

int main()
{
    int N, M, x, y, P;
   
    scanf("%d %d %d %d %d",&M,&N,&x,&y,&P);
    pacman(M, N, y, x, P);
   
    return 0;
}
