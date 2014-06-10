
/** \file main.h
   - Project:     SOFTSUSY 
   - Author:      Ben Allanach 
   - Manual:      hep-ph/0104145, Comp. Phys. Comm. 143 (2002) 305 
   - Webpage:     http://hepforge.cedar.ac.uk/softsusy/

   \brief a main C++ program to calculate Higgs masses as a function of tan
   beta 
*/

/** \mainpage Detailed SOFTSUSY Documentation 

    \section install Installation or downloads
    For installation instructions or a download, please go to the 
    <a href="http://projects.hepforge.org/softsusy/">
    SOFTSUSY Homepage</a>

    \section manual Official manual
    If you use SOFTSUSY to write a paper, please cite 
    <a href="http://xxx.arxiv.org/abs/hep-ph/0104145">
    B.C. Allanach, Comput. Phys. Commun. 143 (2002) 305-331, hep-ph/0104145, 
    </a> which is the SOFTSUSY manual.
    If you use the R-parity violating aspects, please cite
    <a href="http://arxiv.org/abs/0903.1805">B.C. Allanach and M.A. Bernhardt, 
    arXiv:0903.1805</a>.

    \section documentation Documentation
    These web-pages contain the documentation of the latest SOFTSUSY code.
    There are class diagrams and cross-referenced links a la doxygen to help 
    you navigate.

    \section updates Official Updates
    Updates will be posted on the    
    <a href="http://projects.hepforge.org/softsusy/">
    SOFTSUSY Homepage</a>, and the manuals
    [ <a href="http://xxx.arxiv.org/abs/hep-ph/0104145">1</a> |
      <a href="arxiv.org/abs/0903.1805">2</a> ]
    will also be updated.
 */

#include <iostream>
#include <mycomplex.h>
#include <def.h>
#include <linalg.h>
#include <lowe.h>
#include <rge.h>
#include <softsusy.h>
#include <softpars.h>
#include <susy.h>
#include <utils.h>
#include <numerics.h>
#include <rpvsoft.h>
