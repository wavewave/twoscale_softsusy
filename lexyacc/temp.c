    if( valuelist[C_ALPHAM].isDefined == True && 
	valuelist[C_M32 ].isDefined == False ) { 
      if ( insert_real( C_M32 , 
			     find_out_m32_in_mirage( valuelist[C_ALPHAM].real, 
						     valuelist[C_M0].real, 1e-3 ) )) return -1;  
    }
    else if( valuelist[C_ALPHAM].isDefined == False &&
	     valuelist[C_M32].isDefined == True) { 
      if ( insert_real( C_ALPHAM, 
			valuelist[C_M32].real/(valuelist[C_M0].real*log(2.4e18/valuelist[C_M32].real))) ) 
	return -1;
    }


    if( valuelist[C_M0].isDefined == True && 
	valuelist[C_M32 ].isDefined == False ) { 
      if ( insert_real( C_M32 , find_out_m32_in_mirage( valuelist[C_ALPHAM].real, 
							valuelist[C_M0].real, 1e-3 )) ) return -1;  
    }
    else if( valuelist[C_M0].isDefined == False &&
	     valuelist[C_M32].isDefined == True) { 
      if( insert_real( C_M0, valuelist[C_M32].real/(valuelist[C_ALPHAM].real*log(2.4e18/valuelist[C_M32].real))) ) return -1;
    }

    printf("fordebug\n"); 

    if( valuelist[C_M0].isDefined == True && 
	valuelist[C_ALPHAM ].isDefined == False ) { 
      if ( insert_real( C_ALPHAM , valuelist[C_M32].real/(valuelist[C_M0].real*log(2.4e18/valuelist[C_M32].real)) )) return -1;  
    }
    else if( valuelist[C_M0].isDefined == False &&
	     valuelist[C_ALPHAM].isDefined == True) { 
      if( insert_real( C_M0, valuelist[C_M32].real/(valuelist[C_ALPHAM].real*log(2.4e18/valuelist[C_M32].real))) ) return -1;
    }



  else if ( code == C_M0 ) { 

    if( insert_real( C_M0, val )) return -1; 


    
  }
