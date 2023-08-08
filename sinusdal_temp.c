#include "udf.h"

DEFINE_PROFILE(sinusoidaltemp,thread,n)
{
		face_t f;
		real yy[ND_ND];
		real l;
		real b;
		real pi;
		pi=3.1415; 		     			 /*length*/
		l=0.01; 			
		/*landa=0;                     /*Pi/2 ,pi can be use*/
		
		
		begin_f_loop(f,thread)
		{
			F_CENTROID(yy,f,thread);
			b=yy[0]/l;			      /*dimonsionless length*/ 
			F_PROFILE(f,thread,n)=300+sin(2*pi*b);
		}
		end_f_loop(f,thread)
}				