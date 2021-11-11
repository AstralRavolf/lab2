#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//округление y
double round_y(double y, int firstdec) {
        return round(y * pow(10, firstdec)) / pow(10, firstdec);
    }
//функция
const double f(double x, double y){
    return 2.0*x*sqrt(y)-y;  
}

//нахождение кол-ва цифр после запятой у погрешности для дальнейшего округления
unsigned int firstdecplace( double error ) 
{
  if( error <= 0 )
  {
    printf( "Погрешность меньше или равна 0\n" );
    exit(1);
  }

  unsigned int  firstdec = 0; 

  while( error < 1 )
  {
    firstdec++;
    error *= 10;
  }

  return firstdec; 
}

int main(){
    int i, n;
    double y, xi, yi, h, a, b, s, eps;
    printf("Введите значение a = ");
    scanf("%lf",&a);
    xi=a;

    printf("Введите значение b = ");
    scanf("%lf",&b);

    printf("Введите значение s = ");
    scanf("%lf",&s);
    yi=s;

    printf("Введите значение eps = ");
    scanf("%lf",&eps); 

//Метод Эйлера  
  int epsflag = 0;
  double approx; // приблизительная точность y(b)
  int iter_count = 0; //кол-во итераций
  for( n = 1; n < 10000; ++n )  
  {
    xi = a;
    for( int iteration = 0; iteration < n; ++iteration )
    {       
      h=(b-a)/n;
      y=yi+h*f(xi,yi);
      iter_count=iter_count+1;
  
      if( fabs(y-yi) < eps ){
        printf("\nМодуль разности меньше погрешности\n");
        n--;
        epsflag = 1;
        break;
      }
      yi=y;
      xi=xi+h; 
    }  
    if(epsflag == 1)
    {
      break;
    }
    approx = y;
    if (y <= 0.0){
      printf("\nОШИБКА ОДЗ!\nПожалуйста введите новый интервал\n");
      break;
    }
     
  }

  if(n == 10000){
    printf("\nДостигнуть заданной точности не удалось\n");
  }
  printf("___________________________________\n");
  printf("Значение y равно: %lf\n", round_y(approx, firstdecplace(eps)));
  printf("Погрешность равна: %lf\n",eps);
  printf("Кол-во интераций для прближения y(b): %d\n", n);
  printf("Кол-во всех итераций: %d\n",iter_count);
}