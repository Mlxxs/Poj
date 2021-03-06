/*
*/

#include <iostream>
using namespace std;

__int64 extended_gcd(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
	int ret, tmp;
	if (b == 0)
	{
		x = 1;
		y = 0; 
		return a; 
	}
	ret = extended_gcd(b, a % b, x, y);
	tmp = x; 
	x = y;
	y = tmp - 1.0 * a / b * y;
	return ret;

}


int main()
{
	__int64 x, y, n, m, l;
	__int64 a, b, c, k1, k2;
	while(scanf("%I64d %I64d %I64d %I64d %I64d",&x, &y, &n, &m, &l) != EOF)
	{
		a = m -n; 
		b = l;
		c = x - y;                                 //a * k2 + b * k2 = c
		__int64 r = extended_gcd(a, b, k1, k2);    //a * k1 + b * k2 = gcd(a, b)

		if(r % c != 0)
			printf("Impossible\n");
		else
		{
			a /= r;
			b /= r;
			c /= r;
			__int64 t;
			t = 1.0 * b / r;
			k1 *= 1.0 * c / r;

			k1 = (k1 % t + t )% t;	


		/*	t = c * k1 / b;
			k1 = c * k1 - t * b;
			if(k1 < 0) 
				k1+= b;*/
			printf("%I64d\n",k1);

		
		}
	}
	return 0;
}

//1 2 3 4 5