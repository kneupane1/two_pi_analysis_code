#include <TMath.h>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdio.h> 
#include <math.h>
#include "cuts_sim.h"
#include "global.h"
#include <iostream>



using namespace std;



 bool cuts_sim::Electron_cuts_sim(){
   
   
   

   
   bool cuts_sim;
   Float_t th_min,par1,par2,fid_a,fid_b,a,b;
   Short_t i;
   /*Float_t ph_el_arr[3][6][18] = {{{1000.,1000.,22.,24.,25.,28.,35.,30.,30.,34.,26.,30.,32.,27.,36.,31.,28.,1000.},
                             {1000.,1000.,25.,16.,17.,22.,23.,21.,22.,24.,21.,31.,31.,31.,32.,29.,29.,1000.},
                             {1000.,1000.,20.,23.,24.,23.,19.,23.,31.,28.,27.,28.,32.,34.,35.,37.,37.,1000.},
                             {1000.,1000.,24.,20.,24.,19.,28.,26.,24.,27.,25.,29.,22.,23.,34.,37.,27.,1000.},
                             {1000.,1000.,31.,27.,25.,28.,29.,23.,22.,28.,35.,29.,51.,29.,39.,44.,36.,1000.},
                             {1000.,1000.,28.,28.,22.,22.,30.,30.,28.,46.,27.,39.,38.,29.,41.,42.,36.,1000.}},
			     {{0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.},
                             {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.},
		             {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.},
	                     {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.},
		             {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.},
			     {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.}},
			     
			     {{1000.,1000.,18.,20.,24.,22.,22.,27.,26.,28.,32.,26.,23.,30.,28.,29.,25.,1000.},
                             {1000.,1000.,31.,20.,22.,33.,27.,26.,35.,35.,23.,24.,30.,45.,40.,40.,46.,1000.},
			     {1000.,1000.,23.,26.,28.,23.,23.,28.,24.,29.,25.,27.,29.,35.,37.,29.,36.,1000.},
			     {1000.,1000.,20.,21.,22.,24.,25.,34.,26.,27.,24.,27.,20.,28.,32.,27.,34.,1000.},
			     {1000.,1000.,27.,26.,27.,51.,40.,35.,31.,33.,33.,46.,40.,37.,48.,44.,31.,1000.},
			     {1000.,1000.,31.,21.,28.,33.,31.,28.,32.,38.,38.,36.,29.,35.,90.,35.,36.,1000.}}};*/

Float_t th_vs_seg_cc_arr[2][6][18] = {{{0., 14.9943, 16.1178, 17.944, 19.7594, 21.7965, 24.0849, 25.7348, 27.287, 29.7387, 32.118, 34.554, 37.6616, 39.9555, 41.8899, 43.9917, 44.9401,0.},
                             {0., 14.4619, 15.8294, 17.3894, 19.5803, 21.6848, 23.4877, 25.6689, 27.2811, 29.7402, 32.1088, 34.3413, 37.7965, 39.9164, 41.93, 43.8781, 44.9396,0.},
                             {0., 14.6396, 15.8791, 17.681, 19.5967, 21.4913, 23.4704, 25.7742, 27.3183, 29.4058, 32.1693, 34.3859, 37.7187, 39.9258, 41.8853, 43.7546, 44.8999,0.},
                             {0., 15.0222, 16.1285, 17.8297, 19.7349, 21.93, 24.0715, 25.7447, 27.4221, 29.2554, 31.7778, 34.6932, 37.5713, 39.6431, 41.9178, 43.9135, 44.9405,0.},
                             {0., 15.1934, 17.3943, 18.4212, 19.8698, 21.9927, 24.0866, 25.9066, 28.4957, 30.6615, 33.2479, 35.3405, 37.4675, 38.6754, 41.6704, 44.0829, 44.9731,0.},
                             {0., 14.7309, 16.1419, 17.8516, 19.5722, 21.5672, 23.7528, 25.4896, 27.317, 29.8693, 32.1174, 34.5841, 37.7443, 40.01, 42.0101, 44.3091, 45.0681,0.}},
			     
			     
			     {{0., 9.70842, 11.6354, 13.4193, 15.059, 16.8693, 18.3642, 20.481, 22.5206, 23.9727, 25.4384, 27.9494, 29.6408, 33.1416, 35.9524, 38.0618, 40.6736,0.},
                             {0., 10.0549, 11.7277, 13.3703, 14.522, 16.1756, 18.3656, 20.0143, 22.3117, 23.8772, 25.3239, 27.825, 29.4949, 32.6421, 35.7132, 38.164, 40.3459,0.},
		             {0., 10.0805, 11.7872, 13.4138, 14.878, 16.6669, 18.492, 20.1909, 22.4518, 24.0873, 25.337, 27.7718, 29.7123, 33.1764, 36.0684, 38.3921, 40.5504,0.},
	                     {0., 9.89467, 11.8022, 13.4676, 14.8875, 16.5666, 18.234, 20.494, 22.3551, 24.1051, 25.5014, 27.4897, 29.1652, 32.9201, 35.3268, 37.8445, 40.393,0.},
		             {0., 10.2692, 11.1835, 13.4246, 14.8611, 16.5345, 18.2405, 20.3903, 22.0994, 23.9946, 26.2842, 28.3204, 31.0017, 32.6091, 36.7202, 38.2352, 40.8262,0.},
			     {0., 10.084, 11.641, 13.3442, 14.8961, 16.6584, 18.0017, 20.4061, 22.2266, 23.8465, 25.3002, 27.8278, 29.4927, 32.6927, 35.9115, 38.1519, 40.59,0.}}};
			     
 cuts_sim = false; 
   
   
  
     if (P_EL > 0.461) {
     
  th_min=(9.5+17./(P_EL+0.2));
  par1=0.85+1.1*P_EL;
  par2=-62.8-30.*P_EL;       
   fid_a=37.3*pow((sin((th_EL-th_min)*0.01745)),(par1+par2/th_EL+1525./th_EL/th_EL));
     
   fid_b=-37.3*pow((sin((th_EL-th_min)*0.01745)),(par1+par2/th_EL+1525./th_EL/th_EL));  
   a = fid_a;
   b = fid_b; 
   
//   P_EL = floor((P_EL*1000) + 0.5)/1000;


       switch (sector) {
case 1 : 
if (indtype ==2) hist_z_el_1_sim_2->Fill(z_EL,1.);
/*if ((ph_EL >= 330) && (ph_EL <= 360)){
if ((P_EL < 1.79999) && (P_EL > 0.4)){
if (indtype==2) ph_vs_th_el_sim[0][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-360,1);
};
};
if ((ph_EL >= 0) && (ph_EL <= 30)) {
if ((P_EL < 1.75999) && (P_EL > 0.4)){
if (indtype==2) ph_vs_th_el_sim[0][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL,1);
};
};*/


 if ((ECT/P_EL > (-0.0142786*P_EL*P_EL+0.0622135*P_EL+0.0950293)) && (ECT/P_EL < (-0.0012121*P_EL*P_EL-0.015888*P_EL)+0.328383)) {
 if (indtype==1) hist_ectot_sector1_sim->Fill(P_EL,ECT/P_EL,1.);
// if (nphe > 25.) {


if ((ph_EL >= 330) && (ph_EL <= 360)){

if ((P_EL < 1.79999) && (P_EL > 0.4)){
if (indtype==1) ph_vs_th_el_sim[0][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-360,1);
};
if ((th_EL > th_min) && (th_EL < 50) && (ph_EL > fid_b+360) && (ph_EL < fid_a+360)){
if ((W>1.3)&&(indtype==1)) th_vs_p_e_1_sim[0]->Fill(P_EL,th_EL,1.);
// hist_z_el_1_empty->Fill(z_EL,1.);
//cout <<"segment = " << segment <<"\n";
if ((theta_cc >th_vs_seg_cc_arr[1][0][segment])&&(theta_cc <th_vs_seg_cc_arr[0][0][segment])){

 //~fid cuts in Cherenkov plane
 if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {
//cut on average number of photoelectrons
//if (avrg_nphe_sector1->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 70.) {
//nphe_sector1_after->Fill(nphe,1.);
//if ((theta_cc >1.64786+2.16008*segment-0.00433375*segment*segment)&&(theta_cc <11.3593+1.38551*segment+0.0451710*segment*segment)){

//if (nphe > ph_el_arr[pmt_hit+1][0][segment]){
//if (norm_nphe_s1->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 0.95) {
//if (nphe > 60){
   cuts_sim = true;
//   };
  // }; 
  // };
   };
   };
   };
   };
   };
  
   
   }; //fiducial
   }; //second part of sector 1
   
  if ((ph_EL >= 0) && (ph_EL <= 30)) {
if ((P_EL < 1.75999) && (P_EL > 0.4)){
if (indtype==1) ph_vs_th_el_sim[0][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL,1);
};

if ((th_EL > th_min) && (th_EL < 50) && (ph_EL > fid_b) && (ph_EL < fid_a)){

if ((W>1.3)&&(indtype==1)) th_vs_p_e_1_sim[0]->Fill(P_EL,th_EL,1.); 
//hist_z_el_1_empty->Fill(z_EL,1.);
//cout <<"segment = " << segment <<"\n";
if ((theta_cc >th_vs_seg_cc_arr[1][0][segment])&&(theta_cc <th_vs_seg_cc_arr[0][0][segment])){

//~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {
//cut on average number of photoelectrons
//if (avrg_nphe_sector1->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 70.) {
//nphe_sector1_after->Fill(nphe,1.);
//if ((theta_cc >1.64786+2.16008*segment-0.00433375*segment*segment)&&(theta_cc <11.3593+1.38551*segment+0.0451710*segment*segment)){
//if (norm_nphe_s1->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 0.95) {
//if (nphe > ph_el_arr[pmt_hit+1][0][segment]){
//if (nphe > 60){
   cuts_sim = true; 
//   };
  // };
 // };
 }; 
   };
   };
   };
   };

 }; //fiducial
   }; //first part of sector 1


// }; //nphe cut
//??? 

     
 
 }; // ectot vs p cut
 
 break;
 
case 2 : 
if (indtype ==2) hist_z_el_2_sim_2->Fill(z_EL,1.); 
//if ((P_EL < 1.75999) && (P_EL > 0.4)){
//if (indtype==2) ph_vs_th_el_sim[1][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-60,1);
//};


 if (((ECT/P_EL) > (-0.0255814*P_EL*P_EL+0.0861128*P_EL+0.0854996)) && ((ECT/P_EL) < (0.00583913*P_EL*P_EL-0.0280389*P_EL)+ 0.332004)) {
if (indtype==1) hist_ectot_sector2_sim->Fill(P_EL,ECT/P_EL,1.);  
// if (nphe > 25.) {
if ((P_EL < 1.75999) && (P_EL > 0.4)){
if (indtype==1) ph_vs_th_el_sim[1][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-60,1);
};
 if ((th_EL > th_min) && (th_EL < 50) && (ph_EL > fid_b+60) && (ph_EL < fid_a+60)){
if ((W>1.3)&&(indtype==1)) th_vs_p_e_1_sim[1]->Fill(P_EL,th_EL,1.);
// hist_z_el_2_empty->Fill(z_EL,1.);
if ((theta_cc >th_vs_seg_cc_arr[1][1][segment])&&(theta_cc <th_vs_seg_cc_arr[0][1][segment])){ 

 //~fid cuts in Cherenkov plane
  if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {
//cut on average number of photoelectrons
//if (avrg_nphe_sector2->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 70.) {
//nphe_sector2_after->Fill(nphe,1.);
//if ((theta_cc >1.95003+2.00182*segment+0.00390572*segment*segment)&&(theta_cc <11.1869+1.37368*segment+0.047233*segment*segment)){
//if (norm_nphe_s2->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 0.95) {
//if (nphe > ph_el_arr[pmt_hit+1][1][segment]){
///if (nphe > 60){
   cuts_sim = true; 
//   };
 //  };
 //  };
   };
   };
   };
   };
   }; 
   
   }; //fiducial 

 //}; //nphe cut
 
 
  
 
 }; // ectot vs p cut

 break; 
 
case 3 : 
  
if (indtype ==2) hist_z_el_3_sim_2->Fill(z_EL,1.); 
//if ((P_EL < 1.75999) && (P_EL > 0.4)){
//if (indtype==2) ph_vs_th_el_sim[2][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-120,1);
//};


if (((ECT/P_EL) > ( -0.0220529*P_EL*P_EL+0.0782505*P_EL+0.0891699)) && ((ECT/P_EL) < (0.00430305*P_EL*P_EL-0.0235676*P_EL)+ 0.328366)) { 
 if (indtype==1) hist_ectot_sector3_sim->Fill(P_EL,ECT/P_EL,1.); 
// if (nphe > 25.) {

if ((P_EL < 1.75999) && (P_EL > 0.4)){
if (indtype==1) ph_vs_th_el_sim[2][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-120,1);
};

if ((th_EL > th_min) && (th_EL < 50) && (ph_EL > fid_b+120) && (ph_EL < fid_a+120)){
//hist_z_el_3_empty->Fill(z_EL,1.);
if ((W>1.3)&&(indtype==1)) th_vs_p_e_1_sim[2]->Fill(P_EL,th_EL,1.);
 //~fid cuts in Cherenkov plane
 
 if ((theta_cc >th_vs_seg_cc_arr[1][2][segment])&&(theta_cc <th_vs_seg_cc_arr[0][2][segment])){
 
  if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {
//cut on average number of photoelectrons
//if (avrg_nphe_sector3->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 70.) {
//nphe_sector3_after->Fill(nphe,1.);
//if ((theta_cc >1.9837+2.0442*segment+0.0022649*segment*segment)&&(theta_cc <11.2718+1.35251*segment+0.047262*segment*segment)){

//if (nphe > ph_el_arr[pmt_hit+1][2][segment]){
//if (norm_nphe_s3->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 0.95) {
//if (nphe > 60){
   cuts_sim = true; 
//   };
  // };
 //  };
   };
   };
   };
   };
   }; 
   
   }; //fiducial  

// }; //nphe cut
 
 
 
 }; // ectot vs p cut

 break;  
 
case 4 : 

//if ((P_EL < 1.75999) && (P_EL > 0.4)){
//if (indtype==2) ph_vs_th_el_sim[3][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-180,1);
//};
if (indtype ==2) hist_z_el_4_sim_2->Fill(z_EL,1.); 

 if (((ECT/P_EL) > (-0.00769439*P_EL*P_EL+ 0.050589*P_EL+ 0.0988211)) && ((ECT/P_EL) < ( -0.008573*P_EL*P_EL-0.00365415*P_EL)+0.323908)) {
if (indtype==1) hist_ectot_sector4_sim->Fill(P_EL,ECT/P_EL,1.);   
// if (nphe > 25.) {

if ((P_EL < 1.75999) && (P_EL > 0.4)){
if (indtype==1) ph_vs_th_el_sim[3][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-180,1);
};

if ((th_EL > th_min) && (th_EL < 50) && (ph_EL > fid_b+180) && (ph_EL < fid_a+180)){
if ((W>1.3)&&(indtype==1)) th_vs_p_e_1_sim[3]->Fill(P_EL,th_EL,1.);
//hist_z_el_4_empty->Fill(z_EL,1.);

if ((theta_cc >th_vs_seg_cc_arr[1][3][segment])&&(theta_cc <th_vs_seg_cc_arr[0][3][segment])){

//~fid cuts in Cherenkov plane
  if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {
//cut on average number of photoelectrons
//if (avrg_nphe_sector4->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 70.) {
//nphe_sector4_after->Fill(nphe,1.);
//if ((theta_cc >1.36283+2.27581*segment-0.0137087*segment*segment)&&(theta_cc <11.7047+1.27222*segment+0.0517623*segment*segment)){
//if (nphe > ph_el_arr[pmt_hit+1][3][segment]){
//if (norm_nphe_s4->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 0.95) {
//if (nphe > 60){
   cuts_sim = true; 
 //  };
 // }; 
   };
  // };
   };
   };
   };
   };
   
   
     }; //fiducial 
     
        

 //}; //nphe cut
 
  
 }; // ectot vs p cut

 break;  
 
case 5 : 
if (indtype ==2) hist_z_el_5_sim_2->Fill(z_EL,1.); 
//if ((P_EL < 1.75999) && (P_EL > 0.4)){
//if (indtype==2) ph_vs_th_el_sim[4][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-240,1);
//}; 
 
 if (((ECT/P_EL) > (-0.0313504 *P_EL*P_EL+ 0.0973497 *P_EL+ 0.0785652)) && ((ECT/P_EL) < ( 0.0170638*P_EL*P_EL-0.0500158*P_EL)+ 0.343076)) {
 if (indtype==1) hist_ectot_sector5_sim->Fill(P_EL,ECT/P_EL,1.);   
 //if (nphe > 25.) {
 
if ((P_EL < 1.75999) && (P_EL > 0.4)){
if (indtype==1) ph_vs_th_el_sim[4][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-240,1);
};

if ((th_EL > th_min) && (th_EL < 50) && (ph_EL > fid_b+240) && (ph_EL < fid_a+240)){

if ((th_EL > (9.5+17./((P_EL+0.32)+0.2))+25.)||(th_EL < (9.5+17./((P_EL+0.3)+0.2))+21.8)){

if ((W>1.3)&&(indtype==1)) th_vs_p_e_1_sim[4]->Fill(P_EL,th_EL,1.);
//hist_z_el_5_empty->Fill(z_EL,1.);
//~fid cuts in Cherenkov plane

if ((theta_cc >th_vs_seg_cc_arr[1][4][segment])&&(theta_cc <th_vs_seg_cc_arr[0][4][segment])){

if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {
//cut on average number of photoelectrons
//if (avrg_nphe_sector5->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 70.) {
//nphe_sector5_after->Fill(nphe,1.);
//if ((theta_cc >2.17772+1.95055*segment+0.00993131*segment*segment)&&(theta_cc <11.9184+1.34684*segment+0.0471248*segment*segment)){
//if (norm_nphe_s5->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 0.95) {
//if (nphe > ph_el_arr[pmt_hit+1][4][segment]){
//if (nphe > 60){
   cuts_sim = true; 
//   };
 //  };
 //  };
   };
   };
   };
   };
   };
   };//th_vs_p
     }; //fiducial     

 //}; //nphe cuts
 
 
 }; // ectot vs p cut

 break;   
 
case 6 : 
if (indtype ==2) hist_z_el_6_sim_2->Fill(z_EL,1.);
//if ((P_EL < 1.75999) && (P_EL > 0.4)){
//if (indtype==2) ph_vs_th_el_sim[5][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-300,1);
//}; 
 
 if (((ECT/P_EL) > (-0.0347159*P_EL*P_EL+ 0.102172*P_EL+ 0.0753431)) && ((ECT/P_EL) < (0.0150959*P_EL*P_EL-0.0458252*P_EL)+ 0.33942)) {
 if (indtype==1) hist_ectot_sector6_sim->Fill(P_EL,ECT/P_EL,1.); 
 //if (nphe > 25.) {
 
if ((P_EL < 1.75999) && (P_EL > 0.4)){
if (indtype==1) ph_vs_th_el_sim[5][int((P_EL*100-40)/20)]->Fill(th_EL,ph_EL-300,1);
};

if ((th_EL > th_min) && (th_EL < 50) && (ph_EL > fid_b+300) && (ph_EL < fid_a+300)){
//hist_z_el_6_empty->Fill(z_EL,1.);
if ((W>1.3)&&(indtype==1)) th_vs_p_e_1_sim[5]->Fill(P_EL,th_EL,1.);

if ((theta_cc >th_vs_seg_cc_arr[1][5][segment])&&(theta_cc <th_vs_seg_cc_arr[0][5][segment])){

//~fid cuts in Cherenkov plane
if  (theta_cc > 7.0+0.0032*ph_cc+0.0499*ph_cc*ph_cc) {
if ((pow((theta_cc-45.5)/34.5,2)+pow((ph_cc)/21.,2)) <= 1.) {
if ((pow((theta_cc-45.5)/1.75,2)+pow((ph_cc)/21.,2)) > 1.) {
if  (theta_cc < 45.) {
//cut on average number of photoelectrons
//if (avrg_nphe_sector6->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 70.) {
//nphe_sector6_after->Fill(nphe,1.);
//if ((theta_cc >2.18831+2.01682*segment+0.00288938*segment*segment)&&(theta_cc <11.5751+1.25302*segment+0.0536114*segment*segment)){

//if (nphe > ph_el_arr[pmt_hit+1][5][segment]){
//if (norm_nphe_s6->GetBinContent(int((theta_cc+5.)*200./60.),int((ph_cc+30.)*200./60.)) > 0.95) {
//if (nphe > 60){
   cuts_sim = true; 
//   };
//   };
  // };
 };
   };
   };
   };
   };
   
      }; //fiducial   

 //}; //nphe cut
     
 
 }; // ectot vs p cut
 break;      
 
   
   }; // end of switch
   };  // end of calorimeter threshold cut
  
   

   
   
   return cuts_sim;
   
   };
   
   
   //////////////////////
   
      bool cuts_sim::Proton_cuts_sim(){
       
   bool cuts_sim;
   Float_t m_p,p_fid_a,p_fid_b, beta_nom_p;
   m_p=0.938272;   
   p_fid_a = 24.*(1-exp(-1.*0.08*(th_P-9.)));
   p_fid_b = -1.*25.*(1-exp(-1.*0.1*(th_P-10.)));
   beta_nom_p = P_P/sqrt(m_p*m_p+P_P*P_P);
   cuts_sim = false; 
   



if ((n_P == 1)&& (beta_P < 0.9496*P_P/sqrt(m_p*m_p+0.9497*P_P*P_P-0.06649) + 0.04136) && (beta_P > 1.045*P_P/sqrt(m_p*m_p+0.896*P_P*P_P - 0.2) - 0.139)){

//&& (beta_P < 0.9675*P_P/sqrt(m_p*m_p+0.9386*P_P*P_P-0.1723) + 0.0063) && (beta_P > 0.9408*P_P/sqrt(m_p*m_p+0.7455*P_P*P_P - 0.2544) - 0.1126)

if ((ph_P >= 330)&& (ph_P <= 360)&&(PdHit_P !=48) ) {

//&&( PdHit_P != 42)&&(PdHit_P != 45)&&(PdHit_P != 47)&&(PdHit_P !=48)
// &&( PdHit_P != 42)&&(PdHit_P != 45)&&(PdHit_P != 47)&&(PdHit_P !=48)
//if ((W >= 1.2) && (npart >= 3) && (npart <=4)) {

if ((P_P > 0.2) && (P_P < 1.2)&&(indtype==2)) ph_vs_th_p_sim[0]->Fill(th_P,ph_P-360,1);

  if ((ph_P > p_fid_b+360) && (ph_P < p_fid_a+360)){
if (indtype==1) beta_vs_p_p_sim[0][PdHit_P-1]->Fill(P_P,beta_P,1);
if (indtype==1) time_p_sim[0][PdHit_P-1]->Fill(P_P,P_dist/30.*(1./beta_nom_p-1./beta_P),1.);
if (indtype==1) th_vs_p_p_1_sim[0] -> Fill(P_P,th_P,1);
cuts_sim = true;
};//end of fiducial cut for the first part of the first sector
  
 //};//end of W-cut
 
 };//end of the first part of the first sector
 
 if ((ph_P >= 0) && (ph_P <= 30)&&(PdHit_P !=48)) {
 
 if ((P_P > 0.2) && (P_P < 1.2)&&(indtype==2)) ph_vs_th_p_sim[0]->Fill(th_P,ph_P,1);
 
 //&&( PdHit_P != 42)&&(PdHit_P != 45)&&(PdHit_P != 47)&&(PdHit_P !=48)
 //&&( PdHit_P != 42)&&(PdHit_P != 45)&&(PdHit_P != 47)&&(PdHit_P !=48)
//if ((W >= 1.2) && (npart >= 3) && (npart <=4)) {
if ((ph_P > p_fid_b) && (ph_P < p_fid_a)){

if (indtype==1) beta_vs_p_p_sim[0][PdHit_P-1]->Fill(P_P,beta_P,1);
if (indtype==1) time_p_sim[0][PdHit_P-1]->Fill(P_P,P_dist/30.*(1./beta_nom_p-1./beta_P),1.);
if (indtype==1) th_vs_p_p_1_sim[0] -> Fill(P_P,th_P,1);
cuts_sim = true;
};//end of fiducial cut for the second part of the first sector
//};//end of W-cut
  };//end of the second part of the first sector
 
 
 
 if ((ph_P >= 30) && (ph_P <=90)&&(PdHit_P !=48)){ 
 //&&(PdHit_P!=24)&&(PdHit_P!=41)&&(PdHit_P!=42)&&(PdHit_P!=43)&&(PdHit_P!=44)&&(PdHit_P!=45)&&(PdHit_P!=46)&&(PdHit_P!=48)
 //&&(PdHit_P!=45)&&(PdHit_P!=46)&&(PdHit_P!=47)&&(PdHit_P!=41)&&(PdHit_P!=42)&&(PdHit_P!=43)&&(PdHit_P!=44)&&(PdHit_P!=48)
//if ((W >= 1.2) && (npart >= 3) && (npart <=4)) { 

if ((P_P > 0.2) && (P_P < 1.2)&&(indtype==2)) ph_vs_th_p_sim[1]->Fill(th_P,ph_P-60,1);

 if ((ph_P > p_fid_b+60) && (ph_P < p_fid_a+60)){
 
 if ((th_P >26.5087*P_P*P_P*P_P -116.557*P_P*P_P+ 175.167*P_P-61.7717+2.7 ) || (th_P <26.5087*P_P*P_P*P_P -116.557*P_P*P_P+ 175.167*P_P-61.7717-2.8)){
 
if (indtype==1) beta_vs_p_p_sim[1][PdHit_P-1]->Fill(P_P,beta_P,1);
if (indtype==1) time_p_sim[1][PdHit_P-1]->Fill(P_P,P_dist/30.*(1./beta_nom_p-1./beta_P),1.);
if (indtype==1) th_vs_p_p_1_sim[1] -> Fill(P_P,th_P,1);
cuts_sim = true;
};//th_vs_p
};//end of the fiducial cut for sector2
//};//end of W-cut
 
 };//end of the sector2
 
 if ((ph_P >=90) && (ph_P <=150)&&(PdHit_P !=44)&&(PdHit_P !=48)) {
 
 //&&(PdHit_P!=25)&&(PdHit_P!=40)&&(PdHit_P!=42)&&(PdHit_P!=44)&&(PdHit_P!=46)&&(PdHit_P!=48)
 //&&(PdHit_P!=40)&&(PdHit_P!=41)&&(PdHit_P!=42)&&(PdHit_P!=43)&&(PdHit_P!=46)&&(PdHit_P!=47)&&(PdHit_P!=44)&&(PdHit_P!=25)&&(PdHit_P!=48)
//if ((W >= 1.2) && (npart >= 3) && (npart <=4)){

if ((P_P > 0.2) && (P_P < 1.2)&&(indtype==2)) ph_vs_th_p_sim[2]->Fill(th_P,ph_P-120,1);

if ((ph_P > p_fid_b+120) && (ph_P < p_fid_a+120)){
if (indtype==1) beta_vs_p_p_sim[2][PdHit_P-1]->Fill(P_P,beta_P,1);
if (indtype==1) time_p_sim[2][PdHit_P-1]->Fill(P_P,P_dist/30.*(1./beta_nom_p-1./beta_P),1.);
if (indtype==1) th_vs_p_p_1_sim[2] -> Fill(P_P,th_P,1);
cuts_sim = true;
};//end of the fiducial cut for sector3
//}; //end of W-cut
  };//end of the sector3
 
 if ((ph_P >= 150) && (ph_P <= 210)&&(PdHit_P !=48)) {
 
//&&(PdHit_P!=42)&&(PdHit_P!=39)&&(PdHit_P!=48) 
 //&&(PdHit_P!=42)&&(PdHit_P!=43)&&(PdHit_P!=46)&&(PdHit_P!=39)&&(PdHit_P!=48)
//if ((W >= 1.2) && (npart >= 3) && (npart <=4)){

if ((P_P > 0.2) && (P_P < 1.2)&&(indtype==2)) ph_vs_th_p_sim[3]->Fill(th_P,ph_P-180,1);

if ((ph_P > p_fid_b+180) && (ph_P < p_fid_a+180)){
if (indtype==1) beta_vs_p_p_sim[3][PdHit_P-1]->Fill(P_P,beta_P,1);
if (indtype==1) time_p_sim[3][PdHit_P-1]->Fill(P_P,P_dist/30.*(1./beta_nom_p-1./beta_P),1.);
if (indtype==1) th_vs_p_p_1_sim[3] -> Fill(P_P,th_P,1);
cuts_sim = true;
};//end of the fiducial cut for sector4
//}; //end of W-cut

};//end of the sector4

if ((ph_P >= 210) && (ph_P <=270)&&(PdHit_P !=17)&&(PdHit_P !=48)) {

//&&(PdHit_P!=40)&&(PdHit_P!=42)&&(PdHit_P!=43)&&(PdHit_P!=17)&&(PdHit_P!=48)
//&&(PdHit_P!=40)&&(PdHit_P!=42)&&(PdHit_P!=44)&&(PdHit_P!=46)&&(PdHit_P!=47)&&(PdHit_P!=17)&&(PdHit_P!=48)
//if ((W >= 1.2) && (npart >= 3) && (npart <=4)) {

if ((P_P > 0.2) && (P_P < 1.2)&&(indtype==2)) ph_vs_th_p_sim[4]->Fill(th_P,ph_P-240,1);

 if ((P_P<=0.321436)||(th_P > pow((P_P -0.321436),(0.0704348))*88.0419-46.9342) || (th_P < 31.2482*(P_P-0.01)*(P_P-0.01)*(P_P-0.01) -135.817*(P_P-0.01)*(P_P-0.01)+ 198.038*(P_P-0.01)-66.968-2.5)||((th_P > 31.2482*(P_P+0.045)*(P_P+0.045)*(P_P+0.045) -135.817*(P_P+0.045)*(P_P+0.045)+ 198.038*(P_P+0.045)-66.968+1.8)&&(th_P < pow((P_P-0.371051),(  0.0649747))*87.0943  -49.9895 -1.))){
 
 if ((ph_P > p_fid_b+240) && (ph_P < p_fid_a+240)){
if (indtype==1) beta_vs_p_p_sim[4][PdHit_P-1]->Fill(P_P,beta_P,1);
if (indtype==1) time_p_sim[4][PdHit_P-1]->Fill(P_P,P_dist/30.*(1./beta_nom_p-1./beta_P),1.);
if (indtype==1) th_vs_p_p_1_sim[4] -> Fill(P_P,th_P,1);
 cuts_sim = true;

 };//end of the fiducial cut for sector5
  };//th_vs_p
// };//end of W-cut
 
 };//end of the sector5
 
 if ((ph_P >= 270) && (ph_P <=330)&&(PdHit_P !=48)) {
 
 //&&(PdHit_P!=40)&&(PdHit_P!=45)&&(PdHit_P!=31)&&(PdHit_P!=48)&&(PdHit_P!=47)
 //&&(PdHit_P!=40)&&(PdHit_P!=43)&&(PdHit_P!=44)&&(PdHit_P!=45)&&(PdHit_P!=31)&&(PdHit_P!=48)&&(PdHit_P!=47)
//if ((W >= 1.2) && (npart >= 3) && (npart <=4)){

if ((P_P > 0.2) && (P_P < 1.2)&&(indtype==2)) ph_vs_th_p_sim[5]->Fill(th_P,ph_P-300,1);

if ((ph_P > p_fid_b+300) && (ph_P < p_fid_a+300)){
if (indtype==1) beta_vs_p_p_sim[5][PdHit_P-1]->Fill(P_P,beta_P,1);
if (indtype==1) time_p_sim[5][PdHit_P-1]->Fill(P_P,P_dist/30.*(1./beta_nom_p-1./beta_P),1.);
if (indtype==1) th_vs_p_p_1_sim[5] -> Fill(P_P,th_P,1);
cuts_sim = true;
 };//end of the fiducial cut for sector6
// };//end of W-cut
 };//end of the sector6
 
 
 
};
 

    return cuts_sim;
    };  
    
    
    ///////////////////////////////
    
    bool cuts_sim::PIp_cuts_sim(){
       
   bool cuts_sim;
   Float_t m_pip,pip_fid_a,pip_fid_b,beta_nom_pip;
   m_pip = 0.13957;
  pip_fid_a = 24.*(1-exp(-1.*0.08*(th_PIp-9.)));
  pip_fid_b = -1.*25.*(1-exp(-1.*0.1*(th_PIp-10.)));
  beta_nom_pip = P_PIp/sqrt(m_pip*m_pip+P_PIp*P_PIp);
   cuts_sim = false; 
     //cout << th_PIp<< " rgdgdf "<<ph_PIp<<" iiiiii "<<beta_PIp<<" riuthy "<<P_PIp<<"\n";
   if ((n_PIp == 1)&& (PIp_dist*(1./beta_nom_pip-1/beta_PIp)/30. < 0.0001769/(P_PIp*P_PIp*P_PIp*P_PIp+0.0001471)+0.8465)&&(PIp_dist*(1./beta_nom_pip-1/beta_PIp)/30. > -0.0002121/(P_PIp*P_PIp*P_PIp*P_PIp+5.685e-05)-0.8411)) {
   
   
   //(beta_PIp < 0.8*P_PIp/sqrt(m_pip*m_pip+0.9108*P_PIp*P_PIp-0.001768) + 0.2) && (beta_PIp > 1.054*P_PIp/sqrt(m_pip*m_pip+0.7001*P_PIp*P_PIp - 0.006497) - 0.2999)
   //&& (beta_PIp < 0.8*P_PIp/sqrt(m_pip*m_pip+0.91*P_PIp*P_PIp-0.0034) + 0.2) && (beta_PIp > 1.05*P_PIp/sqrt(m_pip*m_pip+0.7*P_PIp*P_PIp - 0.0056) - 0.297)
   
   //&& (beta_PIp < 0.8*P_PIp/sqrt(m_pip*m_pip+0.91*P_PIp*P_PIp-0.0034) + 0.2) && (beta_PIp > 1.05*P_PIp/sqrt(m_pip*m_pip+0.7*P_PIp*P_PIp - 0.0056) - 0.297)
   
     
   if ((ph_PIp >= 330) && (ph_PIp <=360)&&(PdHit_PIp !=48)){
    if ((th_PIp > (304.23*(P_PIp+0.1)*(P_PIp+0.1)*(P_PIp+0.1) -255.798*(P_PIp+0.1)*(P_PIp+0.1)+497.462*(P_PIp+0.1) +38.0385)*exp(-1.85*(P_PIp+0.1)) +9.5) || (th_PIp < pow((P_PIp -0.454098),(0.0912936))*58.2946-20.4843+0.9)||((th_PIp < (pow((P_PIp-0.103718),(0.0703664))*252.822-133.024)*exp(-0.5*P_PIp)+0.1)&&((th_PIp > pow((P_PIp-0.416536),(0.108376))*67.4593-21.4374)||(P_PIp<=0.416536)))||((th_PIp < (304.23*(P_PIp+0.15)*(P_PIp+0.15)*(P_PIp+0.15) -255.798*(P_PIp+0.15)*(P_PIp+0.15)+497.462*(P_PIp+0.15) +38.0385)*exp(-1.85*(P_PIp+0.15)) -3)&&(th_PIp > (pow((P_PIp-0.0575818),( 0.075643))*238.248-115.039)*exp(-0.5*P_PIp)-0.1))){
   
   //&&(PdHit_PIp != 42)&&(PdHit_PIp != 45)&&(PdHit_PIp != 46)&&(PdHit_PIp != 47)&&(PdHit_PIp !=48)
   //&&(PdHit_PIp != 42)&&(PdHit_PIp != 45)&&(PdHit_PIp != 47)&&(PdHit_PIp !=48)
 
  if ((P_PIp > 0) && (P_PIp < 1.2)&&(indtype==2)) ph_vs_th_pip_sim[0]->Fill(th_PIp,ph_PIp-360,1); 
  
   if ((ph_PIp > pip_fid_b+360) && (ph_PIp < pip_fid_a+360)){
  if (indtype==1) beta_vs_p_pip_sim[0][PdHit_PIp-1]->Fill(P_PIp,beta_PIp,1); 
  if (indtype==1) time_pip_sim[0][PdHit_PIp-1]->Fill(P_PIp,PIp_dist*(1./beta_nom_pip-1/beta_PIp)/30.,1.);
  if (indtype==1) th_vs_p_pip_1_sim[0]->Fill(P_PIp,th_PIp,1.);
   cuts_sim = true;
   
   };//th_vs_p
   };//end of the fiducial cut for first part of sector1
  }; //end of the first part of sector1
  
  if ((ph_PIp >= 0) && (ph_PIp <=30)&&(PdHit_PIp !=48)){
  
  if ((th_PIp > (304.23*(P_PIp+0.1)*(P_PIp+0.1)*(P_PIp+0.1) -255.798*(P_PIp+0.1)*(P_PIp+0.1)+497.462*(P_PIp+0.1) +38.0385)*exp(-1.85*(P_PIp+0.1)) +9.5) || (th_PIp < pow((P_PIp -0.454098),(0.0912936))*58.2946-20.4843+0.9)||((th_PIp < (pow((P_PIp-0.103718),(0.0703664))*252.822-133.024)*exp(-0.5*P_PIp)+0.1)&&((th_PIp > pow((P_PIp-0.416536),(0.108376))*67.4593-21.4374)||(P_PIp<=0.416536)))||((th_PIp < (304.23*(P_PIp+0.15)*(P_PIp+0.15)*(P_PIp+0.15) -255.798*(P_PIp+0.15)*(P_PIp+0.15)+497.462*(P_PIp+0.15) +38.0385)*exp(-1.85*(P_PIp+0.15)) -3)&&(th_PIp > (pow((P_PIp-0.0575818),( 0.075643))*238.248-115.039)*exp(-0.5*P_PIp)-0.1))){
  
  //&&(PdHit_PIp != 42)&&(PdHit_PIp != 45)&&(PdHit_PIp != 46)&&(PdHit_PIp != 47)&&(PdHit_PIp !=48)
  //&&( PdHit_PIp != 42)&&(PdHit_PIp != 45)&&(PdHit_PIp != 47)&&(PdHit_PIp !=48)
 
if ((P_PIp > 0) && (P_PIp < 1.2)&&(indtype==2)) ph_vs_th_pip_sim[0]->Fill(th_PIp,ph_PIp,1);

 if ((ph_PIp > pip_fid_b) && (ph_PIp < pip_fid_a)){
  
  
 if (indtype==1) beta_vs_p_pip_sim[0][PdHit_PIp-1]->Fill(P_PIp,beta_PIp,1); 
 if (indtype==1) time_pip_sim[0][PdHit_PIp-1]->Fill(P_PIp,PIp_dist*(1./beta_nom_pip-1/beta_PIp)/30.,1.);
 if (indtype==1) th_vs_p_pip_1_sim[0]->Fill(P_PIp,th_PIp,1.);
cuts_sim = true;
};//th_vs_p
   };//end of the fiducial cut for second part of sector1
   }; //end of the second part of sector1
  
  
  if ((ph_PIp >= 30) && (ph_PIp <=90)&&(PdHit_PIp !=48)) {
  
 //&&(PdHit_PIp!=24)&&(PdHit_PIp!=45)&&(PdHit_PIp!=46)&&(PdHit_PIp!=47)&&(PdHit_PIp!=41)&&(PdHit_PIp!=42)&&(PdHit_PIp!=43)&&(PdHit_PIp!=44)&&(PdHit_PIp!=48) //&&(PdHit_PIp!=45)&&(PdHit_PIp!=46)&&(PdHit_PIp!=47)&&(PdHit_PIp!=41)&&(PdHit_PIp!=42)&&(PdHit_PIp!=43)&&(PdHit_PIp!=44)&&(PdHit_PIp!=48)
if ((P_PIp > 0) && (P_PIp < 1.2)&&(indtype==2)) ph_vs_th_pip_sim[1]->Fill(th_PIp,ph_PIp-60,1);
if ((ph_PIp > pip_fid_b+60) && (ph_PIp < pip_fid_a+60)){

if ((P_PIp<=0.415068)||(th_PIp >  pow((P_PIp-0.415068),(0.226449))*48.7564 + 2.79478-1.) || (th_PIp < (387.289*P_PIp*P_PIp*P_PIp -758.466*P_PIp*P_PIp+ 842.881*P_PIp-299.953-15.)*exp(-2*P_PIp))||((th_PIp > (387.289*P_PIp*P_PIp*P_PIp -758.466*P_PIp*P_PIp+ 842.881*P_PIp-299.953+15.)*exp(-2*P_PIp) )&&(th_PIp < pow((P_PIp-0.449975),( 0.315164 ))*36.608 +  9.74262-1.))){
 if (indtype==1) beta_vs_p_pip_sim[1][PdHit_PIp-1]->Fill(P_PIp,beta_PIp,1);
  if (indtype==1) time_pip_sim[1][PdHit_PIp-1]->Fill(P_PIp,PIp_dist*(1./beta_nom_pip-1/beta_PIp)/30.,1.);
  if (indtype==1) th_vs_p_pip_1_sim[1]->Fill(P_PIp,th_PIp,1.);
cuts_sim = true;
};//th_vs_p
 };//end of the fiducial cut for sector2
};//end of the sector2
  
  
if ((ph_PIp >= 90) && (ph_PIp <=150)&&(PdHit_PIp !=44)&&(PdHit_PIp !=48)) {

//&&(PdHit_PIp!=40)&&(PdHit_PIp!=41)&&(PdHit_PIp!=42)&&(PdHit_PIp!=43)&&(PdHit_PIp!=46)&&(PdHit_PIp!=47)&&(PdHit_PIp!=44)&&(PdHit_PIp!=25)&&(PdHit_PIp!=48)
//&&(PdHit_PIp!=40)&&(PdHit_PIp!=41)&&(PdHit_PIp!=42)&&(PdHit_PIp!=43)&&(PdHit_PIp!=46)&&(PdHit_PIp!=47)&&(PdHit_PIp!=44)&&(PdHit_PIp!=25)&&(PdHit_PIp!=48)
if ((P_PIp > 0) && (P_PIp < 1.2)&&(indtype==2)) ph_vs_th_pip_sim[2]->Fill(th_PIp,ph_PIp-120,1);
if ((ph_PIp > pip_fid_b+120) && (ph_PIp < pip_fid_a+120)){

if ((th_PIp < pow((P_PIp -0.454898),( 0.289291))* 35.7267+6.65908+1.5) || (th_PIp > (10000*P_PIp*P_PIp*P_PIp-3607.41*P_PIp*P_PIp+ 1725.72*P_PIp-10.6776)*exp(-4.7*P_PIp))||((th_PIp < (10000*P_PIp*P_PIp*P_PIp-4505.62*P_PIp*P_PIp+  2056.24  *P_PIp -77.4077 +5.)*exp(-4.7*P_PIp))&&((th_PIp > pow((P_PIp-0.416536),(0.108376))*67.4593-21.4374)||(P_PIp <= 0.416536)))){
 if (indtype==1) beta_vs_p_pip_sim[2][PdHit_PIp-1]->Fill(P_PIp,beta_PIp,1);
   if (indtype==1) time_pip_sim[2][PdHit_PIp-1]->Fill(P_PIp,PIp_dist*(1./beta_nom_pip-1/beta_PIp)/30.,1.);
   if (indtype==1) th_vs_p_pip_1_sim[2]->Fill(P_PIp,th_PIp,1.);
cuts_sim = true;
};//th_vs_p
 };//end of the fiducial cut for sector3
};  //end of the sector3
  
 if ((ph_PIp >= 150) && (ph_PIp <=210)&&(PdHit_PIp !=48)){
 
 //&&(PdHit_PIp!=42)&&(PdHit_PIp!=43)&&(PdHit_PIp!=46)&&(PdHit_PIp!=39)&&(PdHit_PIp!=48)
 //&&(PdHit_PIp!=42)&&(PdHit_PIp!=43)&&(PdHit_PIp!=46)&&(PdHit_PIp!=39)&&(PdHit_PIp!=48)
 if ((P_PIp > 0) && (P_PIp < 1.2)&&(indtype==2)) ph_vs_th_pip_sim[3]->Fill(th_PIp,ph_PIp-180,1);
 if ((ph_PIp > pip_fid_b+180) && (ph_PIp < pip_fid_a+180)){
 
 if ((th_PIp <pow((P_PIp-0.452908),(0.102883))*84.0374  -40.301+ 1.3) ||(th_PIp> (304.23*(P_PIp+0.18)*(P_PIp+0.18)*(P_PIp+0.18) -255.798*(P_PIp+0.18)*(P_PIp+0.18)+497.462*(P_PIp+0.18) +38.0385)*exp(-1.85*(P_PIp+0.18)) +5.)|| ((th_PIp< (304.23*(P_PIp+0.18)*(P_PIp+0.18)*(P_PIp+0.18) -255.798*(P_PIp+0.18)*(P_PIp+0.18)+497.462*(P_PIp+0.18) +38.0385)*exp(-1.85*(P_PIp+0.18)) - 2.)&&(th_PIp >(1600*(P_PIp+0.03)*(P_PIp+0.03)*(P_PIp+0.03) -1068.36*(P_PIp+0.03)*(P_PIp+0.03)+ 775.016*(P_PIp+0.03)-1.13034)*exp(-2.75*(P_PIp+0.03))))||((th_PIp < (pow((P_PIp-0.103718),(0.0703664))*252.822-133.024)*exp(-0.45*P_PIp)-7.)&&((th_PIp >pow((P_PIp-0.412699),(0.214407))*52.0544 -0.0995427-2.1 )||(P_PIp <=0.412699)))){ 
 
 if (indtype==1) beta_vs_p_pip_sim[3][PdHit_PIp-1]->Fill(P_PIp,beta_PIp,1);
   if (indtype==1) time_pip_sim[3][PdHit_PIp-1]->Fill(P_PIp,PIp_dist*(1./beta_nom_pip-1/beta_PIp)/30.,1.);
    if (indtype==1) th_vs_p_pip_1_sim[3]->Fill(P_PIp,th_PIp,1.);
cuts_sim = true;
};//th_vs_p
 };//end of the fiducial cut for sector4
 
 }; //end of the sector4
  
if ((ph_PIp >= 210) && (ph_PIp <=270)&&(PdHit_PIp !=17)&&(PdHit_PIp !=48)) {

//&&(PdHit_PIp!=40)&&(PdHit_PIp!=42)&&(PdHit_PIp!=44)&&(PdHit_PIp!=46)&&(PdHit_PIp!=47)&&(PdHit_PIp!=17)&&(PdHit_PIp!=48)
//&&(PdHit_PIp!=40)&&(PdHit_PIp!=42)&&(PdHit_PIp!=44)&&(PdHit_PIp!=46)&&(PdHit_PIp!=47)&&(PdHit_PIp!=17)&&(PdHit_PIp!=48)
if ((P_PIp > 0) && (P_PIp < 1.2)&&(indtype==2)) ph_vs_th_pip_sim[4]->Fill(th_PIp,ph_PIp-240,1);
if ((ph_PIp > pip_fid_b+240) && (ph_PIp < pip_fid_a+240)){

if ((th_PIp < (525.498*(P_PIp-0.02)*(P_PIp-0.02)*(P_PIp-0.02) -1284.98*(P_PIp-0.02)*(P_PIp-0.02)+1460.67*(P_PIp-0.02)-499.999)*exp(-1.94*(P_PIp-0.02)) -4.7) || (th_PIp > (304.23*(P_PIp)*(P_PIp)*(P_PIp) -255.798*(P_PIp)*(P_PIp)+497.462*(P_PIp) +38.0385)*exp(-1.85*(P_PIp)) ) ||((th_PIp < (304.23*(P_PIp+0.03)*(P_PIp+0.03)*(P_PIp+0.03) -255.798*(P_PIp+0.03)*(P_PIp+0.03)+497.462*(P_PIp+0.03) +38.0385)*exp(-1.85*(P_PIp+0.03)) -11.)&&((th_PIp > pow((P_PIp-0.304992),(0.0758186))*91.5643-48.2057 - 1.)||(P_PIp <=0.304992))) || ((th_PIp < pow((P_PIp -0.36848),( 0.0864219))*70.4769  -34.9998+ 1.5)&&(th_PIp > (525.498*(P_PIp+0.03)*(P_PIp+0.03)*(P_PIp+0.03) -1284.98*(P_PIp+0.03)*(P_PIp+0.03)+1460.67*(P_PIp+0.03)-499.999)*exp(-1.94*(P_PIp+0.03))))){
if (indtype==1) beta_vs_p_pip_sim[4][PdHit_PIp-1]->Fill(P_PIp,beta_PIp,1);
if (indtype==1) time_pip_sim[4][PdHit_PIp-1]->Fill(P_PIp,PIp_dist*(1./beta_nom_pip-1/beta_PIp)/30.,1.);
if (indtype==1) th_vs_p_pip_1_sim[4]->Fill(P_PIp,th_PIp,1.);
cuts_sim = true;
};//th_vs_p
 };//end of the fiducial cut for sector5

}; //end of the sector5
  
  
 if ((ph_PIp >= 270) && (ph_PIp <=330)&&(PdHit_PIp !=48)){
 
 //&&(PdHit_PIp!=40)&&(PdHit_PIp!=44)&&(PdHit_PIp!=45)&&(PdHit_PIp!=31)&&(PdHit_PIp!=48)&&(PdHit_PIp!=47)
 //&&(PdHit_PIp!=40)&&(PdHit_PIp!=43)&&(PdHit_PIp!=44)&&(PdHit_PIp!=45)&&(PdHit_PIp!=31)&&(PdHit_PIp!=48)&&(PdHit_PIp!=47)
if ((P_PIp > 0) && (P_PIp < 1.2)&&(indtype==2)) ph_vs_th_pip_sim[5]->Fill(th_PIp,ph_PIp-300,1);
 if ((ph_PIp > pip_fid_b+300) && (ph_PIp < pip_fid_a+300)){
 
if ((th_PIp < pow((P_PIp -0.454098),(0.0912936))*58.2946-20.4843+1.5) || (P_PIp<=0.05+0.0942469)||(th_PIp > pow((P_PIp-0.05-0.0942469),( 0.0582707))*114.358-50 -0.5)||((th_PIp < pow((P_PIp-0.05-0.126994),( 0.0706829))* 110.073-50+2.) &&((th_PIp > pow((P_PIp-0.416536),(0.108376))*67.4593-21.4374-1.)||(P_PIp<=0.416536)))){ 
if (indtype==1) beta_vs_p_pip_sim[5][PdHit_PIp-1]->Fill(P_PIp,beta_PIp,1);
if (indtype==1) time_pip_sim[5][PdHit_PIp-1]->Fill(P_PIp,PIp_dist*(1./beta_nom_pip-1/beta_PIp)/30.,1.);
if (indtype==1) th_vs_p_pip_1_sim[5]->Fill(P_PIp,th_PIp,1.);
cuts_sim = true;
};//th_vs_p
 };//end of the fiducial cut for sector6
 
 }; //end of the sector6
  
  
  
  
  };
    return cuts_sim;
   };
   
   
   
   //////////////////////////////////////////
   
   
   
  bool cuts_sim::PIm_cuts_sim(){
       
   bool cuts_sim;
   Float_t m_pim,th_min,par1,par2,pim_fid_a,pim_fid_b,beta_nom_pim;
   
    
   m_pim = 0.13957; 
  th_min=(11.09+8./(0.472*P_PIm+0.117));
  par1=0.705+1.1*P_PIm;
  par2=-63.2-29.3*P_PIm;       
   pim_fid_a=35.*pow((sin((th_PIm-th_min)*0.007)),(par1+par2/th_PIm+1350./th_PIm/th_PIm))-1;
    beta_nom_pim = P_PIm/sqrt(m_pim*m_pim+P_PIm*P_PIm); 
   pim_fid_b=-35.*pow((sin((th_PIm-th_min)*0.007)),(par1+par2/th_PIm+1350./th_PIm/th_PIm))+1; 
   cuts_sim = false; 
  
     
   
 
   if ((n_PIm == 1)&& (PIm_dist*(1./beta_nom_pim-1/beta_PIm)/30. < 0.001284/(P_PIm*P_PIm*P_PIm*P_PIm+0.00206)+0.6335)&&(PIm_dist*(1./beta_nom_pim-1/beta_PIm)/30. > -0.002811/(P_PIm*P_PIm*P_PIm*P_PIm+0.002855)-0.5364)) {
   
   //&& (beta_PIm < 0.8*P_PIm/sqrt(m_pim*m_pim+1.2*P_PIm*P_PIm+0.008756) + 0.02963) && (beta_PIm > 0.7686*P_PIm/sqrt(m_pim*m_pim+0.4188*P_PIm*P_PIm - 0.01057)-0.2111)
   
   //&& (beta_PIm < 0.2338*P_PIm/sqrt(m_pim*m_pim+0.0518*P_PIm*P_PIm-0.0187) + 0.0001728) && (beta_PIm > 0.9659*P_PIm/sqrt(m_pim*m_pim+0.9729*P_PIm*P_PIm + 0.008634)-0.0003043)
   //&& (beta_PIm < 0.1717*P_PIm/sqrt(m_pim*m_pim+0.028*P_PIm*P_PIm-0.02) + 0.00023) && (beta_PIm > 0.112*P_PIm/sqrt(m_pim*m_pim+0.015*P_PIm*P_PIm - 0.02))
   
   
 if ((ph_PIm >= 330) && (ph_PIm <=360)&&(PdHit_PIm!=48)){
 
 //&&(PdHit_PIm!=42)&&(PdHit_PIm!=45)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)
 //&&(PdHit_PIm!=42)&&(PdHit_PIm!=45)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)



  if ((ph_PIm > pim_fid_b+360) && (ph_PIm < pim_fid_a+360)){
   if ((P_PIm > 0) && (P_PIm < 2.)&&(indtype==1)) ph_vs_th_pim_sim[0][int(P_PIm/0.4)]->Fill(th_PIm,ph_PIm-360,1);
   if ((th_PIm < (11.09+8./(0.472*(P_PIm+0.25)+0.117))+75.) || (th_PIm >(11.09+8./(0.472*(P_PIm+0.25)+0.117))+85. )){
  
 if (indtype==1) beta_vs_p_pim_sim[0][PdHit_PIm-1]->Fill(P_PIm,beta_PIm,1);
 if (indtype==1) time_pim_sim[0][PdHit_PIm-1]->Fill(P_PIm,PIm_dist/30.*(1./beta_nom_pim-1./beta_PIm),1.);
 if (indtype==1) th_vs_p_pim_1_sim[0]->Fill(P_PIm,th_PIm,1.);
   cuts_sim = true;
   };//th_vs_p
   };//end of the fiducial cut for first part of sector1
  }; //end of the first part of sector1
  
  if ((ph_PIm >= 0) && (ph_PIm <=30)&&(PdHit_PIm!=48)){
  
  //&&(PdHit_PIm!=42)&&(PdHit_PIm!=45)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)
  //&&(PdHit_PIm!=42)&&(PdHit_PIm!=45)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)

 
 if ((ph_PIm > pim_fid_b) && (ph_PIm < pim_fid_a)){
  if ((P_PIm > 0) && (P_PIm < 2.)&&(indtype==1)) ph_vs_th_pim_sim[0][int(P_PIm/0.4)]->Fill(th_PIm,ph_PIm,1);
if ((th_PIm < (11.09+8./(0.472*(P_PIm+0.25)+0.117))+75.) || (th_PIm >(11.09+8./(0.472*(P_PIm+0.25)+0.117))+85. )){ 
if (indtype==1) beta_vs_p_pim_sim[0][PdHit_PIm-1]->Fill(P_PIm,beta_PIm,1);
if (indtype==1) time_pim_sim[0][PdHit_PIm-1]->Fill(P_PIm,PIm_dist/30.*(1./beta_nom_pim-1./beta_PIm),1.);
if (indtype==1) th_vs_p_pim_1_sim[0]->Fill(P_PIm,th_PIm,1.);
cuts_sim = true;
};//th_vs_p
   };//end of the fiducial cut for second part of sector1
   };//end of the second part of sector1
  
    if ((ph_PIm >= 30) && (ph_PIm <=90)&&(PdHit_PIm!=48)) {
    
 //  &&(PdHit_PIm!=16)&&(PdHit_PIm!=24)&&(PdHit_PIm!=41)&&(PdHit_PIm!=42)&&(PdHit_PIm!=43)&&(PdHit_PIm!=44)&&(PdHit_PIm!=45)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48) //&&(PdHit_PIm!=16)&&(PdHit_PIm!=24)&&(PdHit_PIm!=41)&&(PdHit_PIm!=42)&&(PdHit_PIm!=43)&&(PdHit_PIm!=44)&&(PdHit_PIm!=45)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)


if ((ph_PIm > pim_fid_b+60) && (ph_PIm < pim_fid_a+60)){
 if ((P_PIm > 0) && (P_PIm < 2.)&&(indtype==1)) ph_vs_th_pim_sim[1][int(P_PIm/0.4)]->Fill(th_PIm,ph_PIm-60,1);
if ((th_PIm < 36.152+3.69909e-05/(5.40783e-06*P_PIm+1.81169e-07)-2.5) || (th_PIm > 36.152+3.69909e-05/(5.40783e-06*P_PIm+1.81169e-07)+2.)){ 
if (indtype==1) beta_vs_p_pim_sim[1][PdHit_PIm-1]->Fill(P_PIm,beta_PIm,1);
if (indtype==1) time_pim_sim[1][PdHit_PIm-1]->Fill(P_PIm,PIm_dist/30.*(1./beta_nom_pim-1./beta_PIm),1.);
if (indtype==1) th_vs_p_pim_1_sim[1]->Fill(P_PIm,th_PIm,1.);
cuts_sim = true;
};//th_vs_p
 };//end of the fiducial cut for sector2
};//end of the sector2
    
if ((ph_PIm >= 90) && (ph_PIm <=150)&&(PdHit_PIm!=44)&&(PdHit_PIm!=48)) {

//&&(PdHit_PIm!=25)&&(PdHit_PIm!=40)&&(PdHit_PIm!=41)&&(PdHit_PIm!=42)&&(PdHit_PIm!=43)&&(PdHit_PIm!=44)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)
//&&(PdHit_PIm!=25)&&(PdHit_PIm!=40)&&(PdHit_PIm!=41)&&(PdHit_PIm!=42)&&(PdHit_PIm!=43)&&(PdHit_PIm!=44)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)


 if ((ph_PIm > pim_fid_b+120) && (ph_PIm < pim_fid_a+120)){
  if ((P_PIm > 0) && (P_PIm < 2.)&&(indtype==1)) ph_vs_th_pim_sim[2][int(P_PIm/0.4)]->Fill(th_PIm,ph_PIm-120,1); 
if ((th_PIm <36.152+3.69909e-05/(5.40783e-06*(P_PIm+0.08)+1.81169e-07)+ 71) || (th_PIm >36.152+3.69909e-05/(5.40783e-06*(P_PIm+0.1)+1.81169e-07)+ 80. )){  
if (indtype==1) beta_vs_p_pim_sim[2][PdHit_PIm-1]->Fill(P_PIm,beta_PIm,1);
if (indtype==1) time_pim_sim[2][PdHit_PIm-1]->Fill(P_PIm,PIm_dist/30.*(1./beta_nom_pim-1./beta_PIm),1.);
if (indtype==1) th_vs_p_pim_1_sim[2]->Fill(P_PIm,th_PIm,1.);
cuts_sim = true;
};//th_vs_p
 };//end of the fiducial cut for sector3
};  //end of the sector3
  
 if ((ph_PIm >= 150) && (ph_PIm <=210)&&(PdHit_PIm!=48)){
 
 //&&(PdHit_PIm!=39)&&(PdHit_PIm!=42)&&(PdHit_PIm!=43)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)
 //&&(PdHit_PIm!=39)&&(PdHit_PIm!=42)&&(PdHit_PIm!=43)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)
 

 if ((ph_PIm > pim_fid_b+180) && (ph_PIm < pim_fid_a+180)){
  if ((P_PIm > 0) && (P_PIm < 2.)&&(indtype==1)) ph_vs_th_pim_sim[3][int(P_PIm/0.4)]->Fill(th_PIm,ph_PIm-180,1);
if ((th_PIm < 36.152+3.69909e-05/(5.40783e-06*(P_PIm+0.31)+1.81169e-07)+62.) || ((th_PIm>36.152+3.69909e-05/(5.40783e-06*(P_PIm+0.31)+1.81169e-07)+66.)&&(th_PIm <36.152+3.69909e-05/(5.40783e-06*(P_PIm+0.15)+1.81169e-07)+77.)) || (th_PIm > 36.152+3.69909e-05/(5.40783e-06*(P_PIm+0.15)+1.81169e-07)+83.)){  
if (indtype==1) beta_vs_p_pim_sim[3][PdHit_PIm-1]->Fill(P_PIm,beta_PIm,1);
if (indtype==1) time_pim_sim[3][PdHit_PIm-1]->Fill(P_PIm,PIm_dist/30.*(1./beta_nom_pim-1./beta_PIm),1.);
if (indtype==1) th_vs_p_pim_1_sim[3]->Fill(P_PIm,th_PIm,1.);
cuts_sim = true;
};//th_vs_p
 };//end of the fiducial cut for sector4
 }; //end of the sector4
  
if ((ph_PIm >= 210) && (ph_PIm <=270)&&(PdHit_PIm!=17)&&(PdHit_PIm!=48)) {

//&&(PdHit_PIm!=17)&&(PdHit_PIm!=40)&&(PdHit_PIm!=42)&&(PdHit_PIm!=43)&&(PdHit_PIm!=44)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)
//&&(PdHit_PIm!=17)&&(PdHit_PIm!=40)&&(PdHit_PIm!=42)&&(PdHit_PIm!=43)&&(PdHit_PIm!=44)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)

if ((ph_PIm > pim_fid_b+240) && (ph_PIm < pim_fid_a+240)){
 if ((P_PIm > 0) && (P_PIm < 2.)&&(indtype==1)) ph_vs_th_pim_sim[4][int(P_PIm/0.4)]->Fill(th_PIm,ph_PIm-240,1);
if ((th_PIm <36.152+3.69909e-05/(5.40783e-06*(P_PIm)+1.81169e-07)-1.5) || ((th_PIm < 36.152+3.69909e-05/(5.40783e-06*(P_PIm+0.2)+1.81169e-07)+82)&&(th_PIm > 36.152+3.69909e-05/(5.40783e-06*(P_PIm+0.2)+1.81169e-07)+72)) || ((th_PIm< 36.152+3.69909e-05/(5.40783e-06*(P_PIm+0.03)+1.81169e-07)+60)&&(th_PIm >36.152+3.69909e-05/(5.40783e-06*(P_PIm)+1.81169e-07)+4 ))){  

if (indtype==1) beta_vs_p_pim_sim[4][PdHit_PIm-1]->Fill(P_PIm,beta_PIm,1);
if (indtype==1) time_pim_sim[4][PdHit_PIm-1]->Fill(P_PIm,PIm_dist/30.*(1./beta_nom_pim-1./beta_PIm),1.);
if (indtype==1) th_vs_p_pim_1_sim[4]->Fill(P_PIm,th_PIm,1.);
cuts_sim = true;
};//th_vs_p
 };//end of the fiducial cut for sector5
}; //end of the sector5
    
 if ((ph_PIm >= 270) && (ph_PIm <=330)&&(PdHit_PIm!=48)){
 
 //&&(PdHit_PIm!=31)&&(PdHit_PIm!=40)&&(PdHit_PIm!=43)&&(PdHit_PIm!=44)&&(PdHit_PIm!=45)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48) //&&(PdHit_PIm!=31)&&(PdHit_PIm!=40)&&(PdHit_PIm!=43)&&(PdHit_PIm!=44)&&(PdHit_PIm!=45)&&(PdHit_PIm!=46)&&(PdHit_PIm!=47)&&(PdHit_PIm!=48)

 
 if ((ph_PIm > pim_fid_b+300) && (ph_PIm < pim_fid_a+300)){
  if ((P_PIm > 0) && (P_PIm < 2.)&&(indtype==1)) ph_vs_th_pim_sim[5][int(P_PIm/0.4)]->Fill(th_PIm,ph_PIm-300,1);
 if ((th_PIm <36.152+3.69909e-05/(5.40783e-06*(P_PIm+0.15)+1.81169e-07)+70) || (th_PIm > 36.152+3.69909e-05/(5.40783e-06*(P_PIm+0.15)+1.81169e-07)+75 )){  
if (indtype==1) beta_vs_p_pim_sim[5][PdHit_PIm-1]->Fill(P_PIm,beta_PIm,1);
if (indtype==1) time_pim_sim[5][PdHit_PIm-1]->Fill(P_PIm,PIm_dist/30.*(1./beta_nom_pim-1./beta_PIm),1.);
if (indtype==1) th_vs_p_pim_1_sim[5]->Fill(P_PIm,th_PIm,1.);
cuts_sim = true;
};//th_vs_p
 };//end of the fiducial cut for sector6
 }; //end of the sector6
  
   
  
  
   };
    return cuts_sim;
   };   
