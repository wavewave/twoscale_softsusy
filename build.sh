#!/bin/bash 

cd micromegas_2.2.CPC ; make

cd ../softsusy-3.0.7-iw0630 ; ./configure ; make 

cd ../lexyacc ; make

