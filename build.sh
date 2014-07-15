#!/bin/bash 

cd micromegas_2.2.CPC ; make

cd ../softsusy-3.3.9-iw20140627 ; ./configure ; make 

cd ../lexyacc ; make

cd micromegas_2.2.CPC/MSSM/work/ ; mkdir so_generated 
